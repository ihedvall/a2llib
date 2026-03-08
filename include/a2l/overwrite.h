/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include <memory>
#include <cstdint>
#include <string>
#include <deque>

#include "a2l/a2lobject.h"

namespace a2l {

class Overwrite : public A2lObject {
 public:
  void AxisNo(uint64_t axis) { axis_no_ = axis; }
  [[nodiscard]] uint64_t AxisNo() const { return axis_no_; }

  void Conversion(std::string conversion) { conversion_ = std::move(conversion); }
  [[nodiscard]] const std::string& Conversion() const { return conversion_; }

  void InputQuantity(std::string quantity) {
    input_quantity_ = std::move(quantity);
  }
  [[nodiscard]] const std::string& InputQuantity() const {
    return input_quantity_;
  }

  void LowerLimit(double limit) { lower_limit_ = limit; }
  [[nodiscard]] double LowerLimit() const { return lower_limit_; }

  void UpperLimit(double limit) { upper_limit_ = limit; }
  [[nodiscard]] double UpperLimit() const { return upper_limit_; }

  void Monotony(A2lMonotony monotony) { monotony_ = monotony; }
  [[nodiscard]] A2lMonotony Monotony() const { return monotony_; }

 private:
  uint64_t axis_no_ = 0;
  std::string conversion_;
  std::string input_quantity_;
  double lower_limit_ = 0.0;
  double upper_limit_ = 0.0;
  A2lMonotony monotony_ = A2lMonotony::UNKNOWN;

};

using OverwriteList = std::deque<std::unique_ptr<Overwrite>>;

} // end namespace a2l
