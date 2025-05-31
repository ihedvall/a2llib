/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once
#include <memory>
#include <map>
#include <cstdint>

#include "a2l/a2lobject.h"
#include "a2l/a2lenums.h"

namespace a2l {


class AxisPts : public A2lObject {
 public:
  void Address(uint64_t address) { address_ = address; }
  [[nodiscard]] uint64_t Address() const { return address_; }

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

  void RefRecord(const std::string& ref) {
    ref_record_ = ref;
  }
  [[nodiscard]] const std::string& RefRecord() const {
    return ref_record_;
  }

  void MaxDiff(double max_diff) { max_diff_ = max_diff; }
  [[nodiscard]] double MaxDiff() const { return max_diff_; }

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

  void Deposit(A2lDeposit deposit) {
    deposit_ = deposit;
  }
  [[nodiscard]] A2lDeposit Deposit() const {
    return deposit_;
  }

  void Monotony(A2lMonotony monotony) { monotony_ = monotony; }
  [[nodiscard]] A2lMonotony Monotony() const { return monotony_; }


 private:
  uint64_t address_ = 0;
  std::string input_quantity_;
  std::string ref_record_; ///< Named deposit in standard
  double max_diff_ = 0.0;
  std::string conversion_;
  uint64_t max_axis_points_ = 0;
  double lower_limit_ = 0.0;
  double upper_limit_ = 0.0;

  A2lDeposit deposit_ = A2lDeposit::UNKNOWN;
  A2lExtendedLimits extended_limits_;
  A2lMonotony monotony_ = A2lMonotony::UNKNOWN;

};

using AxisPtsList = std::map<std::string, std::unique_ptr<AxisPts>>;

}  // namespace a2l
