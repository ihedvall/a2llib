/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>
#include <vector>

#include "a2l/xcp/clock.h"

namespace a2l::xcp {

enum class DaqTimestampsRelateTo : uint8_t {
  XCP_SLAVE_CLOCK = 0,
  ECU_CLOCK = 1,
};

using ClockList = std::vector<Clock>;

class TimeCorrelation {
public:
  void SetTimestampsRelateTo(const std::string& relation);
  [[nodiscard]] DaqTimestampsRelateTo TimestampsRelateTo() const {
    return timestamps_relate_to_;
  }

  void AddClock(Clock clock) {
    clock_list_.emplace_back(std::move(clock));
  }
  [[nodiscard]] const ClockList& GetClocks() const {
    return clock_list_;
  }

  void Reset();
private:
  DaqTimestampsRelateTo timestamps_relate_to_ =
    DaqTimestampsRelateTo::XCP_SLAVE_CLOCK;
  ClockList clock_list_;
};

}



