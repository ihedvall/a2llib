/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#include "a2l/xcp/timecorrelation.h"

namespace a2l::xcp {
void TimeCorrelation::SetTimestampsRelateTo(const std::string& relation) {
  if (relation == "XCP_SLAVE_CLOCK") {
    timestamps_relate_to_ = DaqTimestampsRelateTo::XCP_SLAVE_CLOCK;
  } else if (relation == "ECU_CLOCK") {
    timestamps_relate_to_ = DaqTimestampsRelateTo::ECU_CLOCK;
  }
}

void TimeCorrelation::Reset() {
  timestamps_relate_to_ = DaqTimestampsRelateTo::XCP_SLAVE_CLOCK;
  clock_list_.clear();
}

}  // namespace a2l::xcp
