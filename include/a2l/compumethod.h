/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include <memory>
#include <string>
#include <vector>
#include <map>

#include "a2l/a2lobject.h"
#include "a2l/a2lenums.h"

namespace a2l {

class CompuMethod : public A2lObject {
 public:
  void Type(A2lConversionType type) { conversion_type_ = type; }
  [[nodiscard]] A2lConversionType Type() const { return conversion_type_; }

  void Coeffs(const std::vector<double>& list) { coeffs_ = list; }
  [[nodiscard]] const std::vector<double>& Coeffs() const { return coeffs_; }

  void CoeffsLinear(const std::vector<double>& list) {
    coeffs_linear_ = list;
  }
  [[nodiscard]] const std::vector<double>& CoeffsLinear() const {
    return coeffs_linear_;
  }

  void CompuTabRef(const std::string& ref) { compu_tab_ref_ = ref; }
  [[nodiscard]] const std::string& CompuTabRef() const {
    return compu_tab_ref_;
  }

  void Formula(const std::string& formula) { formula_ = formula; }
  [[nodiscard]] const std::string& Formula() const { return formula_; }

  void FormulaInv(const std::string& formula) { formula_inv_ = formula; }
  [[nodiscard]] const std::string& FormulaInv() const { return formula_inv_; }

  void RefUnit(const std::string& unit) { ref_unit_ = unit; }
  [[nodiscard]] const std::string& RefUnit() const { return ref_unit_; }

  void StatusStringRef(const std::string& ref) { status_string_ref_ = ref; }
  [[nodiscard]] const std::string& StatusStringRef() const {
    return status_string_ref_;
  }
 private:
  A2lConversionType conversion_type_ = A2lConversionType::UNKNOWN;
  std::vector<double> coeffs_;
  std::vector<double> coeffs_linear_;
  std::string compu_tab_ref_;
  std::string formula_;
  std::string formula_inv_;
  std::string ref_unit_;
  std::string status_string_ref_;
};

using CompuMethodList = std::map<std::string, std::unique_ptr<CompuMethod>>;

}
