/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include "a2l/a2lobject.h"
#include <map>
#include <memory>

namespace a2l {

class CompuVtabRange : public A2lObject {
 public:
  void Rows(uint64_t rows) { rows_ = rows; }
  [[nodiscard]] uint64_t Rows() const { return rows_; }

  void KeyValueList(const std::map<std::pair<double, double>,
      std::string>& list) {
    value_list_ = list;
  }
  [[nodiscard]] const std::map<std::pair<double,double>,
        std::string>& KeyValueList() const {
    return value_list_;
  }

  void DefaultValue(const std::string& value) { default_value_ = value; }
  [[nodiscard]] const std::string& DefaultValue() const {
    return default_value_;
  }

 private:
  uint64_t rows_ = 0;
  std::map<std::pair<double, double>, std::string> value_list_;
  std::string default_value_;
};

using CompuVtabRangeList = std::map<std::string,
                                    std::unique_ptr<CompuVtabRange>>;

} // end namespace a2l
