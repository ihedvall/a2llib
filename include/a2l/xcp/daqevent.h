/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>
#include <vector>

namespace a2l::xcp {

using DaqEventList = std::vector<uint16_t>;

class DaqEvent {
public:
private:
  DaqEventList fixed_event_list_;
  DaqEventList variable_event_list_;
  DaqEventList default_event_list_;
  DaqEventList event_list_;
};
}



