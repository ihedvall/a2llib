/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once
#include <memory>
#include <vector>
#include <cstdint>

#include "a2l/a2lobject.h"
#include "a2l/a2lenums.h"


namespace a2l {
class AxisDescr : public A2lObject {
 public:
  void AxisType(A2lAxisType type) { axis_type_ = type; }
  [[nodiscard]] A2lAxisType AxisType() const { return axis_type_; }

  void InputQuantity(const std::string& quantity) {
    if (quantity != "NO_INPUT_QUANTITY") {
      input_quantity_ = quantity;
    } else {
      input_quantity_.clear();
    }
  }
  [[nodiscard]] const std::string& InputQuantity() const {
    return input_quantity_;
  }

  void Conversion(const std::string& conversion) {
    if (conversion != "NO_COMPU_METHOD") {
      conversion_ = conversion;
    } else {
      conversion_.clear();
    }
  }
  [[nodiscard]] const std::string& Conversion() const {
    return conversion_;
  }

  void MaxAxisPoints(uint64_t nof) { max_axis_points_ = nof; }
  [[nodiscard]] uint64_t MaxAxisPoints() const { return max_axis_points_; }

  void LowerLimit(double limit) { lower_limit_ = limit; }
  [[nodiscard]] double LowerLimit() const { return lower_limit_; }

  void UpperLimit(double limit) { upper_limit_ = limit; }
  [[nodiscard]] double UpperLimit() const { return upper_limit_; }

  void AxisPtsRef(const std::string& ref) { axis_pts_ref_ = ref; }
  [[nodiscard]] const std::string& AxisPtsRef() const { return axis_pts_ref_; }

  void CurveAxisRef(const std::string& ref) { curve_axis_ref_ = ref; }
  [[nodiscard]] const std::string& CurveAxisRef() const {
    return curve_axis_ref_;
  }
  void Deposit(A2lDeposit deposit) {
    deposit_ = deposit;
  }
  [[nodiscard]] A2lDeposit Deposit() const {
    return deposit_;
  }

  void FixAxisPar(const A2lFixAxisPar& axis_par) {
    fix_axis_par_ = axis_par;
  }
  [[nodiscard]] const A2lFixAxisPar& FixAxisPar() const {
    return fix_axis_par_;
  }

  void FixAxisParDist(const A2lFixAxisParDist& axis_par_dist) {
    fix_axis_par_dist_ = axis_par_dist;
  }
  [[nodiscard]] const A2lFixAxisParDist& FixAxisParDist() const {
    return fix_axis_par_dist_;
  }

  void FixAxisParList(const std::vector<double>& list) {
    fix_axis_par_list_ = list;
  }
  [[nodiscard]] const std::vector<double>& FixAxisParList() const {
    return fix_axis_par_list_;
  }

  void MaxGradient(double max) { max_grad_ = max; }
  [[nodiscard]] double MaxGrad() const { return max_grad_; }

  void Monotony(A2lMonotony monotony) { monotony_ = monotony; }
  [[nodiscard]] A2lMonotony Monotony() const { return monotony_; }
 private:
  A2lAxisType axis_type_ = A2lAxisType::UNKNOWN;
  std::string input_quantity_;
  std::string conversion_;
  uint64_t max_axis_points_ = 0;

  double lower_limit_ = 0.0;
  double upper_limit_ = 0.0;

  std::string axis_pts_ref_;
  std::string curve_axis_ref_;
  A2lDeposit deposit_ = A2lDeposit::UNKNOWN;

  A2lFixAxisPar fix_axis_par_ = {};
  A2lFixAxisParDist fix_axis_par_dist_ = {};
  std::vector<double> fix_axis_par_list_;
  double max_grad_ = 0.0;
  A2lMonotony monotony_ = A2lMonotony::UNKNOWN;
};

using AxisDescrList = std::vector<std::unique_ptr<AxisDescr>>;
} // end namespace a2l