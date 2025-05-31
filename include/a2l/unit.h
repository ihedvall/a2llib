/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once
#include <map>
#include <memory>
#include <string>


#include "a2l/a2lobject.h"


namespace a2l {

class Unit : public A2lObject {
 public:
  void Type(A2lUnitType type) { type_ = type; }
  [[nodiscard]] A2lUnitType Type() const { return type_; }

  void RefUnit(const std::string& ref) { ref_unit_ = ref; }
  [[nodiscard]] const std::string& RefUnit() const { return ref_unit_; }

  void SiExponents(const A2lSiExponents& exponents) {
    si_exponents_ = exponents;
  }
  [[nodiscard]] const A2lSiExponents& SiExponents() const {
    return si_exponents_;
  }

  void Gradient(double gradient) { gradient_ = gradient; }
  [[nodiscard]] double Gradient() const { return gradient_; }

  void Offset(double offset) { offset_ = offset; }
  [[nodiscard]] double Offset() const { return offset_; }

 private:
  A2lUnitType type_ = A2lUnitType::UNKNOWN;
  std::string ref_unit_;
  A2lSiExponents si_exponents_ = {};
  double gradient_ = 0.0;
  double offset_ = 0.0;
};

using UnitList = std::map<std::string, std::unique_ptr<Unit>>;

} // end namespace a2l
