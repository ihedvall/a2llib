/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>
#include <vector>

#include "a2l/xcp/clock.h"

namespace a2l::xcp {

enum class XcpDaqTimestampsRelateTo : uint8_t {
  XCP_SLAVE_CLOCK = 0,
  ECU_CLOCK = 1,
};

using ClockList = std::vector<Clock>;

class TimeCorrelation {
public:
private:
  XcpDaqTimestampsRelateTo timestamps_relate_to_ =
    XcpDaqTimestampsRelateTo::XCP_SLAVE_CLOCK;
  ClockList clock_list_;
};

}



