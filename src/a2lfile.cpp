/*
* Copyright 2022 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2l/a2lfile.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <filesystem>
#include <array>
#include <boost/locale.hpp>
#include <boost/endian.hpp>
#include "a2lscanner.h"
#include "a2lhelper.h"


namespace a2l {

std::string A2lFile::Name() const {
  return A2lHelper::GetStem(filename_);
}

bool A2lFile::ParseFile() {
  last_error_.clear();
  bool parse = true;
  try {
    // Read in the file into a memory stream and convert to UTF8 coding at
    // the same time
    std::istringstream utf8_stream;
    A2lScanner::ReadAndConvertFile(filename_, utf8_stream);
    A2lScanner scanner(utf8_stream);
    scanner.InputFile(filename_); // Needed in case of include files.
    scanner.Parent(this);

    // scanner.set_debug(2);
    A2lParser parser(scanner, *this);
    parse = parser.parse() == 0;
    IsA2lFile(scanner.IsA2lFile());
    last_error_ = scanner.LastError();

  } catch (const std::exception& err) {
    last_error_ = err.what();
    parse = false;
  } catch (...) {
    parse = false;
  }
  return parse;
}

void A2lFile::Merge(A2lFile &include_file) {
  // If this isn't an A2L file i.e. missing the project header, then copy the entire project.
  // Always move the modules
  auto& dest_project = Project();
  auto& remote_project = include_file.Project();
  if (!IsA2lFile()) {
    dest_project.Header() = remote_project.Header();
  }
  auto& dest_list = dest_project.Modules();
  auto& source_list = remote_project.Modules();
  for (auto& itr : source_list) {
    dest_project.AddModule(itr.second);
  }
  source_list.clear();
}

}  // namespace a2l