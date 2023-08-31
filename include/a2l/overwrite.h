/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include "a2l/a2lobject.h"
#include <map>
#include <memory>

namespace a2l {

class Overwrite : public A2lObject {
 public:
  void AxisNo(uint64_t axis) { axis_no_ = axis; }
  [[nodiscard]] uint64_t AxisNo() const { return axis_no_; }

  void Conversion(const std::string& conversion) { conversion_ = conversion; }
  [[nodiscard]] const std::string& Conversion() const { return conversion_; }

  void InputQuantity(const std::string& quantity) {
    input_quantity_ = quantity;
  }
  [[nodiscard]] const std::string& InputQuantity() const {
    return input_quantity_;
  }

  void Limits(double limit) { limits_ = limit; }
  [[nodiscard]] double Limits() const { return limits_; }

  void Monotony(A2lMonotony monotony) { monotony_ = monotony; }
  [[nodiscard]] A2lMonotony Monotony() const { return monotony_; }

 private:
  uint64_t axis_no_ = 0;
  std::string conversion_;
  std::string input_quantity_;
  double limits_ = 0.0;
  A2lMonotony monotony_ = A2lMonotony::UNKNOWN;

};

using OverwriteList = std::map<std::string, std::unique_ptr<Overwrite>>;

} // end namespace a2l
