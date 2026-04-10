/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include <string>
#include <vector>

#include "a2l/amldefinition.h"

namespace a2l {

using AmlDefinitionList = std::vector<AmlDefinition>;

class AmlSection {
 public:
  AmlSection() = default;
  explicit AmlSection(std::string aml);

  void AmlString(std::string aml) {
    aml_string_ = std::move(aml);
  }
  [[nodiscard]] const std::string& AmlString() const { return aml_string_; }

  void Parse();
  void ParseFile(const std::string& filename);

  [[nodiscard]] bool IsOk() const { return parse_; }
  void DefinitionList(AmlDefinitionList list) {
    definition_list_ = std::move(list);
  }
  [[nodiscard]] const AmlDefinitionList& DefinitionList() const {
    return definition_list_;
  }
  [[nodiscard]] const std::string& LastError() const { return last_error_; }

  [[nodiscard]] const AmlDefinition* GetDefinitionByTag(const std::string& tag) const;
  [[nodiscard]] const AmlDefinition* GetDefinitionByIdentity(const std::string& identity) const;

 private:
  std::string aml_string_;
  bool parse_ = false;
  std::string last_error_;
  AmlDefinitionList definition_list_;

};


}  // namespace a2l
