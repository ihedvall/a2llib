/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include <map>
#include <unordered_map>
#include <memory>
#include <string>
#include <cstdint>
#include <utility>

#include "a2l/a2lobject.h"


namespace a2l {

class CompuVtabRange : public A2lObject {
 public:
  void Rows(uint64_t rows) {
    rows_ = rows;

  }

  [[nodiscard]] uint64_t Rows() const { return rows_; }

  void KeyValueList(std::map<std::pair<double, double>, std::string> list) {
    value_list_ = std::move(list);
  }

  [[nodiscard]] const std::map<std::pair<double,double>,
        std::string>& KeyValueList() const {
    return value_list_;
  }

  void DefaultValue(std::string value) { default_value_ = std::move(value); }
  [[nodiscard]] const std::string& DefaultValue() const {
    return default_value_;
  }

 private:
  uint64_t rows_ = 0;
  std::map<std::pair<double, double>, std::string> value_list_;
  std::string default_value_;
};

using CompuVtabRangeList = std::unordered_map<std::string,
                                    std::unique_ptr<CompuVtabRange>>;

} // end namespace a2l
