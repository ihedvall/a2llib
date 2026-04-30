/*
* Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#include "a2l/xcp/event.h"

#include <array>
#include <string_view>

namespace a2l::xcp {

void DaqPackedMode::SetGroup(const std::string& type) {
  if (type == "ELEMENT_GROUPED") {
    group = DaqPackedGroup::ELEMENT_GROUPED;
  } else if (type == "EVENT_GROUPED") {
    group = DaqPackedGroup::EVENT_GROUPED;
  }
}

void DaqPackedMode::SetTimestampMode(const std::string& type) {
  if (type == "STS_LAST") {
    timestamp_mode = DaqPackedTimestampMode::STS_LAST;
  } else if (type == "STS_FIRST") {
    timestamp_mode = DaqPackedTimestampMode::STS_FIRST;
  }
}

void DaqPackedMode::SetUsage(const std::string& type) {
  if (type == "OPTIONAL") {
    usage = DaqPackedUsage::OPTIONAL;
  } else if (type == "MANDATORY") {
    usage = DaqPackedUsage::MANDATORY;
  }
}

void CpuLoadConsumption::Reset() {
  daq_factor = 0.0F;
  odt_factor = 0.0F;
  odt_entry_factor = 0.0F;
  odt_element_load = 0.0F;
  odt_entry_size_factors.clear();
  core_load_ep.reset();
}

void Event::SetType(const std::string& type) {
  constexpr std::array<std::string_view, 3> kTypeList = {
    "DAQ",
    "STIM",
    "DAQ_STIM"
  };
  for (size_t index = 0; index < kTypeList.size(); ++index) {
    if (type == kTypeList[index]) {
      constexpr size_t kOffset = 1;
      type_ = static_cast<EventType>(kOffset + index);
      break;
    }
  }
}

void Event::SetConsistency(const std::string& consistency) {
  constexpr std::array<std::string_view, 4> kConsistencyList = {
    "DAQ",
    "EVENT",
    "ODT",
    "NONE"
  };

  for (size_t index = 0; index < kConsistencyList.size(); ++index) {
    if (consistency == kConsistencyList[index]) {
      consistency_ = static_cast<Consistency>(index);
      break;
    }
  }
}

void Event::SetDtoCtrDaqMode(const std::string& dto_ctr_daq_mode) {
  constexpr std::array<std::string_view, 2> kModeList = {
    "INSERT_COUNTER",
    "INSERT_STIM_COUNTER_COPY"
  };

  for (size_t index = 0; index < kModeList.size(); ++index) {
    if (dto_ctr_daq_mode == kModeList[index]) {
      dto_ctr_daq_mode_ = static_cast<DtoCtrDaqMode>(index);
      break;
    }
  }
}

void Event::SetDtoCtrStimMode(const std::string& dto_ctr_stim_mode) {
  constexpr std::array<std::string_view, 2> kModeList = {
    "DO_NOT_CHECK_COUNTER",
    "CHECK_COUNTER"
  };
  for (size_t index = 0; index < kModeList.size(); ++index) {
    if (dto_ctr_stim_mode == kModeList[index]) {
      dto_ctr_stim_mode_ = static_cast<DtoCtrStimMode>(index);
      break;
    }
  }
}

void Event::Reset() {
  name_.clear();
  short_name_.clear();
  number_ = 0;
  type_ = EventType::DAQ;
  max_daq_list_ = 0;
  time_cycle_ = 0;
  time_unit_ = 0;
  priority_ = 0;
  complementary_bypass_number_.reset();
  consistency_.reset();
  event_counter_present_ = false;
  related_number_.reset();
  related_number_fixed_ = false;
  dto_ctr_daq_mode_.reset();
  dto_ctr_daq_mode_fixed_ = false;
  dto_ctr_stim_mode_.reset();
  dto_ctr_stim_mode_fixed_ = false;
  stim_dto_ctr_copy_present_ = false;
  daq_packed_mode_.reset();
  min_cycle_time_.reset();
  buffer_reserve_event_.reset();
  cpu_load_max_.reset();
  cpu_load_consumption_daq_.reset();
  cpu_load_consumption_stim_.reset();
  cpu_load_consumption_queue_.reset();
  cpu_load_consumption_queue_stim_.reset();
}

}  // namespace a2l::xcp