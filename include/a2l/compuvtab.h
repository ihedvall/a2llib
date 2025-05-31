/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once
#include <map>
#include <memory>
#include <string>
#include <cstdint>

#include "a2l/a2lobject.h"


namespace a2l {

class CompuVtab : public A2lObject {
 public:
  void Type(A2lConversionType type) { conversion_type_ = type; }
  [[nodiscard]] A2lConversionType Type() const { return conversion_type_; }

  void Rows(uint64_t rows) { rows_ = rows; }
  [[nodiscard]] uint64_t Rows() const { return rows_; }

  void KeyValueList(const std::map<double, std::string>& list) {
    value_list_ = list;
  }
  [[nodiscard]] const std::map<double, std::string>& KeyValueList() const {
    return value_list_;
  }

  void DefaultValue(const std::string& value) { default_value_ = value; }
  [[nodiscard]] const std::string& DefaultValue() const {
    return default_value_;
  }

 private:
  A2lConversionType conversion_type_ = A2lConversionType::TAB_VERB;
  uint64_t rows_ = 0;
  std::map<double, std::string> value_list_;
  std::string default_value_;
};

using CompuVtabList = std::map<std::string, std::unique_ptr<CompuVtab>>;

} // end namespace a2l
