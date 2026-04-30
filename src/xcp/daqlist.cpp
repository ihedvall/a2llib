/*
* Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#include "a2l/xcp/daqlist.h"

#include <array>
#include <string_view>

namespace a2l::xcp {
void DaqList::SetType(const std::string& type) {
  constexpr std::array<std::string_view,3> kTypeList= {
    "DAQ",
    "STIM",
    "DAQ_STIM"
  };

  for (size_t index = 0; index < kTypeList.size(); ++index) {
    if (type == kTypeList[index]) {
      constexpr size_t kOffset = 1;
      type_ = static_cast<DaqListType>(kOffset + index);
      return;
    }
  }
}

void DaqList::Reset() {
  number_ = 0;
  type_.reset();
  max_odt_.reset();
  max_odt_entries_.reset();
  first_pid_.reset();
  event_fixed_.reset();
  daq_packed_mode_supported_ = false;
  predefined_list_.clear();
}

}  // namespace a2l::xcp
