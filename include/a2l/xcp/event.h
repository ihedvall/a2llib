/*
* Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>
#include <string>
#include <optional>
#include <vector>

namespace a2l::xcp {

enum class XcpEventType : uint16_t {
  DAQ = 1,
  STIM = 2,
  DAQ_STIM = 3
};

enum class XcpConsistency : uint8_t {
  DAQ = 0,
  EVENT = 1,
  ODT = 2,
  NONE = 3
};

enum class XcpDtoCtrDaqMode : uint8_t {
  INSERT_COUNTER = 0,
  INSERT_STIM_COUNTER_COPY = 1,
};

enum class XcpDtoCtrStimMode : uint8_t {
  DO_NOT_CHECK_COUNTER = 0,
  CHECK_COUNTER = 1,
};

enum class XcpDaqPackedGroup : uint8_t {
  ELEMENT_GROUPED = 1,
  EVENT_GROUPED = 2,
};

enum class XcpDaqPackedTimestampMode : uint8_t {
  STS_LAST = 0,
  STS_FIRST = 1,
};

enum class XcpDaqPackedUsage : uint8_t {
  OPTIONAL = 0,
  MANDATORY = 1,
};

struct DaqPackedMode {
  XcpDaqPackedGroup group = XcpDaqPackedGroup::ELEMENT_GROUPED;
  XcpDaqPackedTimestampMode timestamp_mode = XcpDaqPackedTimestampMode::STS_LAST;
  XcpDaqPackedUsage usage = XcpDaqPackedUsage::OPTIONAL;
  uint16_t sample_count_ = 0;
  std::optional<uint16_t> alt_sample_count_;
};

struct MinCycleTime {
  uint8_t time_cycle = 0;
  uint8_t time_unit = 0;
};

struct BufferReserveEvent {
  uint8_t odt_daq_buffer_element_reserve = 0;
  uint8_t odt_stim_buffer_element_reserve = 0;
};

struct OdtEntrySizeFactor {
  uint16_t size = 0;
  float factor = 0.0F;
};

struct CoreLoadEp {
  uint16_t number = 0;
  float max = 0.0F;
};

struct CpuLoadConsumption {
  float daq_factor = 0.0F;
  float odt_factor = 0.0F;
  float odt_entry_factor = 0.0F;
  std::vector<OdtEntrySizeFactor> odt_entry_size_factors;
  std::optional<CoreLoadEp> core_load_ep;
};


class Event {
public:
private:
  std::string name_;
  std::string short_name_;
  uint16_t number_ = 0;
  XcpEventType type_ = XcpEventType::DAQ;
  uint8_t max_daq_list_ = 0;
  uint8_t time_cycle_ = 0;
  uint8_t time_unit_ = 0;
  uint8_t priority_ = 0;
  std::optional<uint16_t> complementary_bypass_number_;
  std::optional<XcpConsistency> consistency_;
  bool event_counter_present_ = false;
  std::optional<uint16_t> related_number_;
  bool related_number_fixed_ = false;
  std::optional<XcpDtoCtrDaqMode> dto_ctr_daq_mode_;
  bool dto_ctr_daq_mode_fixed_ = false;
  std::optional<XcpDtoCtrStimMode> dto_ctr_stim_mode_;
  bool dto_ctr_stim_mode_fixed_ = false;
  bool stim_dto_ctr_copy_present_ = false;
  std::optional<DaqPackedMode> daq_packed_mode_;
  std::optional<MinCycleTime> min_cycle_time_;
  std::optional<BufferReserveEvent> buffer_reserve_event_;
  std::optional<float> cpu_load_max_;
  std::optional<CpuLoadConsumption> cpu_load_consumption_daq_;
  std::optional<CpuLoadConsumption> cpu_load_consumption_stim_;
  std::optional<CpuLoadConsumption> cpu_load_consumption_queue_;
  std::optional<CpuLoadConsumption> cpu_load_consumption_queue_stim_;
};

}


