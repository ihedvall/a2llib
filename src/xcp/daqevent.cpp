/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#include "a2l/xcp/daqevent.h"

namespace a2l::xcp {
void DaqEvent::Reset() {
  fixed_event_list_.clear();
  variable_event_list_.clear();
  default_event_list_.clear();
  consistency_event_list_.clear();
}
}  // namespace a2l::xcp