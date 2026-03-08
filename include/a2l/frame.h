/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once
#include <map>
#include <memory>
#include <string>
#include <cstdint>
#include <deque>

#include "a2l/a2lobject.h"


namespace a2l {
class Frame : public A2lObject {
 public:
  void ScalingUnit(uint64_t scale) { scaling_unit_ = scale; }
  [[nodiscard]] uint64_t ScalingUnit() const { return scaling_unit_; }

  void Rate(uint64_t rate) { rate_ = rate; }
  [[nodiscard]] uint64_t Rate() const { return rate_; }

  void FrameMeasurement(std::deque<std::string> list) {
    frame_measurement_list_ = std::move(list);
  }
  [[nodiscard]] const std::deque<std::string>& FrameMeasurement() const {
    return frame_measurement_list_;
  }

 private:
  uint64_t scaling_unit_ = 0;
  uint64_t rate_ = 0;
  std::deque<std::string> frame_measurement_list_;
};

using FrameList = std::map<std::string, std::unique_ptr<Frame>>;

} // end namespace a2l
