/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2l/computab.h"

namespace a2l {

void CompuTab::DefaultValue(const std::string& value) {
  default_value_ = value;
  if (default_value_numeric_ == 0.0) {
    try {
      default_value_numeric_ = std::stod(value);
    } catch (const std::exception& ) {}
  }
}

void CompuTab::DefaultValueNumeric(double value) {
  default_value_numeric_ = value;
  if (default_value_.empty()) {
    try {
      default_value_ = std::to_string(default_value_numeric_);
    } catch (const std::exception&) {}
  }
}

} // end namespace a2l
