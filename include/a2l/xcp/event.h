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

enum class EventType : uint16_t {
  DAQ = 1,
  STIM = 2,
  DAQ_STIM = 3
};

enum class Consistency : uint8_t {
  DAQ = 0,
  EVENT = 1,
  ODT = 2,
  NONE = 3
};

enum class DtoCtrDaqMode : uint8_t {
  INSERT_COUNTER = 0,
  INSERT_STIM_COUNTER_COPY = 1,
};

enum class DtoCtrStimMode : uint8_t {
  DO_NOT_CHECK_COUNTER = 0,
  CHECK_COUNTER = 1,
};

enum class DaqPackedGroup : uint8_t {
  ELEMENT_GROUPED = 1,
  EVENT_GROUPED = 2,
};

enum class DaqPackedTimestampMode : uint8_t {
  STS_LAST = 0,
  STS_FIRST = 1,
};

enum class DaqPackedUsage : uint8_t {
  OPTIONAL = 0,
  MANDATORY = 1,
};

struct DaqPackedMode {
  DaqPackedGroup group = DaqPackedGroup::ELEMENT_GROUPED;
  DaqPackedTimestampMode timestamp_mode = DaqPackedTimestampMode::STS_LAST;
  DaqPackedUsage usage = DaqPackedUsage::OPTIONAL;
  uint16_t sample_count = 0;
  std::vector<uint16_t> alt_sample_count;

  void SetGroup(const std::string& type);
  void SetTimestampMode(const std::string& type);
  void SetUsage(const std::string& type);

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
  float odt_element_load = 0.0F;
  std::vector<OdtEntrySizeFactor> odt_entry_size_factors;
  std::optional<CoreLoadEp> core_load_ep;

  void Reset();
};


class Event {
public:
  void SetName(std::string name) { name_ = std::move(name); }
  [[nodiscard]] const std::string& GetName() const { return name_; }

  void SetShortName(std::string short_name) { short_name_ = std::move(short_name); }
  [[nodiscard]] const std::string& GetShortName() const { return short_name_; }

  void SetNumber(uint64_t number) {
    number_ = static_cast<uint16_t>(number);
  }
  [[nodiscard]] uint16_t GetNumber() const { return number_; }

  void SetType(const std::string& type);
  [[nodiscard]] EventType GetType() const { return type_; }

  void SetMaxDaqList(uint64_t max_daq_list) {
    max_daq_list_ = static_cast<uint8_t>(max_daq_list);
  }
  [[nodiscard]] uint8_t GetMaxDaqList() const { return max_daq_list_; }

  void SetTimeCycle(uint64_t time_cycle) {
    time_cycle_ = static_cast<uint8_t>(time_cycle);
  }
  [[nodiscard]] uint8_t GetTimeCycle() const { return time_cycle_; }

  void SetTimeUnit(uint64_t time_unit) {
    time_unit_ = static_cast<uint8_t>(time_unit);
  }
  [[nodiscard]] uint8_t GetTimeUnit() const { return time_unit_; }

  void SetPriority(uint64_t priority) {
    priority_ = static_cast<uint8_t>(priority);
  }
  [[nodiscard]] uint8_t GetPriority() const { return priority_; }

  void SetComplementaryBypassNumber(uint64_t complementary_bypass_number) {
    complementary_bypass_number_ = static_cast<uint16_t>(complementary_bypass_number);
  }
  [[nodiscard]] const std::optional<uint16_t>& GetComplementaryBypassNumber() const {
    return complementary_bypass_number_;
  }

  void SetConsistency(const std::string& consistency);
  [[nodiscard]] const std::optional<Consistency>& GetConsistency() const {
    return consistency_;
  }

  void SetEventCounterPresent() { event_counter_present_ = true; }
  [[nodiscard]] bool GetEventCounterPresent() const { return event_counter_present_; }

  void SetRelatedNumber(uint64_t related_number) {
    related_number_ = static_cast<uint16_t>(related_number);
  }
  [[nodiscard]] const std::optional<uint16_t>& GetRelatedNumber() const {
    return related_number_;
  }

  void SetRelatedNumberFixed() { related_number_fixed_ = true; }
  [[nodiscard]] bool GetRelatedNumberFixed() const { return related_number_fixed_; }

  void SetDtoCtrDaqMode(const std::string& dto_ctr_daq_mode);
  [[nodiscard]] const std::optional<DtoCtrDaqMode>& GetDtoCtrDaqMode() const {
    return dto_ctr_daq_mode_;
  }

  void SetDtoCtrDaqModeFixed() { dto_ctr_daq_mode_fixed_ = true; }
  [[nodiscard]] bool GetDtoCtrDaqModeFixed() const { return dto_ctr_daq_mode_fixed_; }

  void SetDtoCtrStimMode(const std::string& dto_ctr_stim_mode);
  [[nodiscard]] const std::optional<DtoCtrStimMode>& GetDtoCtrStimMode() const {
    return dto_ctr_stim_mode_;
  }

  void SetDtoCtrStimModeFixed() { dto_ctr_stim_mode_fixed_ = true; }
  [[nodiscard]] bool GetDtoCtrStimModeFixed() const { return dto_ctr_stim_mode_fixed_; }

  void SetStimDtoCtrCopyPresent() { stim_dto_ctr_copy_present_ = true; }
  [[nodiscard]] bool GetStimDtoCtrCopyPresent() const { return stim_dto_ctr_copy_present_; }

  void SetDaqPackedMode(DaqPackedMode daq_packed_mode) {
    daq_packed_mode_ = std::move(daq_packed_mode);
  }
  [[nodiscard]] const DaqPackedMode* GetDaqPackedMode() const {
    return daq_packed_mode_.has_value() ? &daq_packed_mode_.value() : nullptr;
  }

  void SetMinCycleTime(MinCycleTime min_cycle_time) {
    min_cycle_time_ = std::move(min_cycle_time);
  }
  [[nodiscard]] const MinCycleTime* GetMinCycleTime() const {
    return min_cycle_time_.has_value() ? &min_cycle_time_.value() : nullptr;
  }

  void SetBufferReserveEvent(BufferReserveEvent buffer_reserve_event) {
    buffer_reserve_event_ = std::move(buffer_reserve_event);
  }
  [[nodiscard]] const BufferReserveEvent* GetBufferReserveEvent() const {
    return buffer_reserve_event_.has_value() ?
      &buffer_reserve_event_.value() : nullptr;
  }

  void SetCpuLoadMax(double cpu_load_max) {
    cpu_load_max_ = static_cast<float>(cpu_load_max);
  };
  [[nodiscard]] const std::optional<float>& GetCpuLoadMax() const {
    return cpu_load_max_;
  }

  void SetCpuLoadConsumptionDaq(CpuLoadConsumption cpu_load) {
    cpu_load_consumption_daq_ = std::move(cpu_load);
  }
  [[nodiscard]] const std::optional<CpuLoadConsumption>& GetCpuLoadConsumptionDaq() const {
    return cpu_load_consumption_daq_;
  }

  void SetCpuLoadConsumptionStim(CpuLoadConsumption cpu_load) {
    cpu_load_consumption_stim_ = std::move(cpu_load);
  };
  [[nodiscard]] const CpuLoadConsumption* GetCpuLoadConsumptionStim() const {
    return cpu_load_consumption_stim_.has_value() ?
      &cpu_load_consumption_stim_.value() : nullptr;
  }

  void SetCpuLoadConsumptionQueue(CpuLoadConsumption cpu_load) {
    cpu_load_consumption_queue_ = std::move(cpu_load);
  }
  [[nodiscard]] const CpuLoadConsumption* GetCpuLoadConsumptionQueue() const {
    return cpu_load_consumption_queue_.has_value() ?
      &cpu_load_consumption_queue_.value() : nullptr;
  }

  void SetCpuLoadConsumptionQueueStim(CpuLoadConsumption cpu_load) {
    cpu_load_consumption_queue_stim_ = std::move(cpu_load);
  }
  [[nodiscard]] const CpuLoadConsumption* GetCpuLoadConsumptionQueueStim() const {
    return cpu_load_consumption_queue_stim_.has_value() ?
      &cpu_load_consumption_queue_stim_.value() : nullptr;
  }

  void Reset();

 private:
  std::string name_;
  std::string short_name_;
  uint16_t number_ = 0;
  EventType type_ = EventType::DAQ;
  uint8_t max_daq_list_ = 0;
  uint8_t time_cycle_ = 0;
  uint8_t time_unit_ = 0;
  uint8_t priority_ = 0;
  std::optional<uint16_t> complementary_bypass_number_;
  std::optional<Consistency> consistency_;
  bool event_counter_present_ = false;
  std::optional<uint16_t> related_number_;
  bool related_number_fixed_ = false;
  std::optional<DtoCtrDaqMode> dto_ctr_daq_mode_;
  bool dto_ctr_daq_mode_fixed_ = false;
  std::optional<DtoCtrStimMode> dto_ctr_stim_mode_;
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


