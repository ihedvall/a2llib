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
  void SetFixedEventList(DaqEventList list) {
    fixed_event_list_ = std::move(list);
  }
  [[nodiscard]] const DaqEventList& GetFixedEventList() const {
    return fixed_event_list_;
  }
  void SetVariableEventList(DaqEventList list) {
    variable_event_list_ = std::move(list);
  }
  [[nodiscard]] const DaqEventList& GetVariableEventList() const {
    return variable_event_list_;
  }
  void SetDefaultEventList(DaqEventList list) {
    default_event_list_ = std::move(list);
  }
  [[nodiscard]] const DaqEventList& GetDefaultEventList() const {
    return default_event_list_;
  }
  void SetConsistencyEventList(DaqEventList list) {
    consistency_event_list_ = std::move(list);
  }
  [[nodiscard]] const DaqEventList& GetConsistencyEventList() const {
    return consistency_event_list_;
  }

  void Reset();
private:
  DaqEventList fixed_event_list_;
  DaqEventList variable_event_list_;
  DaqEventList default_event_list_;
  DaqEventList consistency_event_list_;

};
}



