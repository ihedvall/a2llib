/*
* Copyright 2022 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2l/a2lfile.h"

#include <sstream>
#include <algorithm>
#include <filesystem>
#include <ranges>

#include <boost/locale.hpp>

#include "a2lscanner.h"
#include "a2lhelper.h"


namespace a2l {

A2lFile::~A2lFile() {
  if (parse_thread_.joinable()) {
    parse_thread_.join();
  }
  scanner_ = nullptr;
}

std::string A2lFile::Name() const {
  return A2lHelper::GetStem(filename_);
}

bool A2lFile::ParseFile() {
  last_error_.clear();
  current_lineno_ = 0;
  number_of_lines_ = 0;

  bool parse;
  try {
    // Read in the file into a memory stream and convert to UTF8 coding at
    // the same time
    std::istringstream utf8_stream;
    number_of_lines_ = A2lScanner::ReadAndConvertFile(filename_, utf8_stream);
    A2lScanner scanner(utf8_stream);

    scanner_ = &scanner;
    scanner.InputFile(filename_); // Needed in case of include files.
    scanner.Parent(this);

    // scanner.set_debug(2);
    A2lParser parser(scanner, *this);

    parse = parser.parse() == 0;
    scanner_ = nullptr;

    IsA2lFile(scanner.IsA2lFile());
    last_error_ = scanner.LastError();

  } catch (const std::exception& err) {
    scanner_ = nullptr;
    last_error_ = err.what();
    parse = false;
  } catch (...) {
    scanner_ = nullptr;
    parse = false;
  }

  return parse;
}

void A2lFile::AsynchParseFile(A2lReadyFunction ready_function) {
  if (parse_thread_.joinable()) {
    parse_thread_.join();
  }
  current_lineno_ = 0;
  number_of_lines_ = 0;

  ready_function_ = std::move(ready_function);
  last_error_.clear();
  parse_thread_ = std::thread(&A2lFile::ParseThread, this);
}

void A2lFile::ParseThread() {
  bool parse;
  try {
    // Read in the file into a memory stream and convert to UTF8 coding at
    // the same time
    std::istringstream utf8_stream;
    number_of_lines_ = A2lScanner::ReadAndConvertFile(filename_, utf8_stream);
    A2lScanner scanner(utf8_stream);
    scanner_ = &scanner;
    scanner.InputFile(filename_); // Needed in case of include files.
    scanner.Parent(this);

    // scanner.set_debug(2);
    A2lParser parser(scanner, *this);

    parse = parser.parse() == 0;

    IsA2lFile(scanner.IsA2lFile());

    last_error_ = scanner.LastError();
    scanner_ = nullptr;
  } catch (const std::exception& err) {
    scanner_ = nullptr;
    last_error_ = err.what();
    parse = false;
  } catch (...) {
    scanner_ = nullptr;
    parse = false;
  }

  if (ready_function_) {
    ready_function_(parse);
  }
}

void A2lFile::Merge(A2lFile &include_file) {
  // If this isn't an A2L file i.e. missing the project header, then copy the entire project.
  // Always move the modules
  auto& dest_project = Project();
  auto& remote_project = include_file.Project();
  if (!IsA2lFile()) {
    dest_project.Header() = remote_project.Header();
  }

  ModuleList& source_list = remote_project.Modules();
  for (auto &module : source_list | std::views::values) {
    dest_project.AddModule(module);
  }
  source_list.clear();
}

int A2lFile::LineNo() const {
  if (scanner_ != nullptr) {
    current_lineno_ = scanner_.load()->lineno();
  }
  return current_lineno_;
}

int A2lFile::ProgressInfo() const {
  if (current_lineno_ == 0) {
    return number_of_lines_ == 0 ? 0 : 100;
  }

  if (number_of_lines_ == 0 || scanner_ == nullptr) {
    return 100;
  }
  return static_cast<int>(100 * current_lineno_ / number_of_lines_);
}
}  // namespace a2l