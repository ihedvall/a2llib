/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2l/amlsection.h"

#include <sstream>
#include <fstream>
#include <filesystem>

#include "amlparser.hpp"
#include "amlscanner.h"

using namespace std::filesystem;

namespace a2l {

AmlSection::AmlSection(std::string a2ml)
: aml_string_(std::move(a2ml)) {
  Parse();
}

void AmlSection::Parse() {
  try {
    parse_ = false;
    last_error_.clear();

    if (aml_string_.empty()) {
      throw std::runtime_error("Nothing to parse");
    }
    std::istringstream temp(aml_string_);;

    AmlScanner scanner(temp);
    AmlParser parser(scanner);
    parse_ = parser.parse() == 0;
    last_error_ = scanner.LastError();
    definition_list_ = scanner.DefintionList();
  } catch (const std::exception& err) {
    last_error_ = err.what();
    parse_ = false;
  }
}

void AmlSection::ParseFile(const std::string& filename) {
  try {
    path fullname(filename);
    if (!exists(fullname)) {
      throw std::runtime_error(
        "The file doesn't exist. File: " + fullname.string());
    }
    const size_t size = file_size(fullname);
    aml_string_.resize(size, '\0');
    std::ifstream input_file(filename);
    input_file.read(aml_string_.data(), size);
  } catch (const std::exception& err) {
    last_error_ = err.what();
    parse_ = false;
    return;
  }
  Parse();
}

const AmlDefinition* AmlSection::GetDefinitionByTag(const std::string& tag) const {
  const auto itr = std::ranges::find_if(definition_list_,
    [&] (const AmlDefinition& definition) -> bool {
      return definition.Tag() == tag;
  });
  if (itr != definition_list_.cend()) {
    return &*itr;
  }
  return nullptr;
}

const AmlDefinition* AmlSection::GetDefinitionByIdentity(const std::string& identity) const {
  const auto itr = std::ranges::find_if(definition_list_,
    [&] (const AmlDefinition& definition) -> bool {
      return definition.Identity() == identity;
  });
  if (itr != definition_list_.cend()) {
    return &*itr;
  }
  return nullptr;
}

}  // namespace a2l