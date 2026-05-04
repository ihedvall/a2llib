/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>
#include <string>
#include <optional>

#include "a2l/ccp/qpblob.h"

namespace a2l::ccp {

class Source {
public:
  void SetName(std::string name) { name_ = std::move(name); }
  [[nodiscard]] const std::string& GetName() const { return name_; }

  void SetScalingUnit(int64_t scaling_unit) {
    scaling_unit_ = static_cast<int16_t>(scaling_unit);
  }
  [[nodiscard]] int16_t GetScalingUnit() const { return scaling_unit_; }

  void SetRate(int64_t rate) {
    rate_ = static_cast<int32_t>(rate);
  }
  [[nodiscard]] int32_t GetRate() const { return rate_; }

  void SetDisplayIdentifier(std::string display_identifier) {
    display_identifier_ = std::move(display_identifier);
  }
  [[nodiscard]] const std::string& GetDisplayIdentifier() const { return display_identifier_; }

  void SetQpBlob(QpBlob qp_blob) { qp_blob_ = std::move(qp_blob); }
  [[nodiscard]] const QpBlob* GetQpBlob() const {
    return qp_blob_.has_value() ? &qp_blob_.value() : nullptr;
  }

  void Reset();

private:
  std::string name_;
  int16_t scaling_unit_ = 0;
  int32_t rate_ = 0;
  std::string display_identifier_;
  std::optional<QpBlob> qp_blob_;

};

}  // namespace a2l::ccp


