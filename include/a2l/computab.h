/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once
#include <unordered_map>
#include <memory>
#include <string>
#include <cstdint>

#include "a2l/a2lobject.h"


namespace a2l {

class CompuTab : public A2lObject {
 public:
  void Type(A2lConversionType type) { conversion_type_ = type; }
  [[nodiscard]] A2lConversionType Type() const { return conversion_type_; }

  void Rows(uint64_t rows) { rows_ = rows; }
  [[nodiscard]] uint64_t Rows() const { return rows_; }

  void KeyValueList(std::unordered_map<double, double> list) {
    value_list_ = std::move(list);
  }
  [[nodiscard]] const std::unordered_map<double, double>& KeyValueList() const {
    return value_list_;
  }

  void DefaultValue(std::string value);
  [[nodiscard]] const std::string& DefaultValue() const {
    return default_value_;
  }

  void DefaultValueNumeric(double value);
  [[nodiscard]] double DefaultValueNumeric() const {
    return default_value_numeric_;
  }

 private:
  A2lConversionType conversion_type_ = A2lConversionType::UNKNOWN;
  uint64_t rows_ = 0;
  std::unordered_map<double, double> value_list_;
  std::string default_value_; ///< Default value as string
  double default_value_numeric_ = 0.0; ///< Default value as double
};

using CompuTabList = std::unordered_map<std::string, std::unique_ptr<CompuTab>>;

} // end namespace a2l
