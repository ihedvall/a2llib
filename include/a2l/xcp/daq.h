/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>
#include <optional>
#include <string>
#include <vector>

#include "a2l/xcp/timestamp.h"
#include "a2l/xcp/event.h"
#include "a2l/xcp/daqlist.h"

namespace a2l::xcp {

enum class DaqType : uint8_t {
  STATIC = 0,
  DYNAMIC = 1,
};

enum class OptimisationType : uint8_t {
  OPTIMISATION_TYPE_DEFAULT = 0,
  OPTIMISATION_TYPE_ODT_TYPE_16 = 1,
  OPTIMISATION_TYPE_ODT_TYPE_32 = 2,
  OPTIMISATION_TYPE_ODT_TYPE_64 = 3,
  OPTIMISATION_TYPE_ODT_TYPE_ALIGNMENT = 4,
  OPTIMISATION_TYPE_MAX_ENTRY_SIZE = 5,
};

enum class AddressExtension : uint8_t {
  ADDRESS_EXTENSION_FREE = 0,
  ADDRESS_EXTENSION_ODT = 1,
  ADDRESS_EXTENSION_DAQ = 3,
};

enum class IdentificationFieldType : uint8_t {
  IDENTIFICATION_FIELD_TYPE_ABSOLUTE = 0,
  IDENTIFICATION_FIELD_TYPE_RELATIVE_BYTE = 1,
  IDENTIFICATION_FIELD_TYPE_RELATIVE_WORD = 2,
  IDENTIFICATION_FIELD_TYPE_RELATIVE_WORD_ALIGNED = 3,
};

enum class GranularityOdtEntrySizeDaq : uint8_t {
  GRANULARITY_ODT_ENTRY_SIZE_DAQ_BYTE = 1,
  GRANULARITY_ODT_ENTRY_SIZE_DAQ_WORD = 2,
  GRANULARITY_ODT_ENTRY_SIZE_DAQ_DWORD = 4,
  GRANULARITY_ODT_ENTRY_SIZE_DAQ_DLONG = 8,
};

enum class GranularityOdtEntrySizeStim : uint8_t {
  GRANULARITY_ODT_ENTRY_SIZE_STIM_BYTE = 1,
  GRANULARITY_ODT_ENTRY_SIZE_STIM_WORD = 2,
  GRANULARITY_ODT_ENTRY_SIZE_STIM_DWORD = 4,
  GRANULARITY_ODT_ENTRY_SIZE_STIM_DLONG = 8,
};

enum class OverloadIndicator : uint8_t {
  NO_OVERLOAD_INDICATION = 0,
  OVERLOAD_INDICATION_PID = 1,
  OVERLOAD_INDICATION_EVENT = 2,
};

struct DaqStim {
  GranularityOdtEntrySizeStim stim_size =
     GranularityOdtEntrySizeStim::GRANULARITY_ODT_ENTRY_SIZE_STIM_BYTE;
  uint8_t max_odt_entry_size = 0;
  bool bit_stim_supported = false;
  std::optional<uint8_t> min_st_stim;

  void SetSize(const std::string& size);
};

struct CoreLoadMax {
  uint16_t number = 0;
  float max = 0.0;
};

struct BufferReserve {
  uint8_t odt_daq_buffer = 0;
  uint8_t odt_stim_buffer = 0;
};

struct DaqMemoryConsumption {
  uint32_t limit = 0;
  uint16_t daq_size = 0;
  uint16_t odt_size = 0;
  uint16_t odt_entry_size = 0;
  uint16_t odt_daq_buffer_element_size = 0;
  uint16_t odt_stim_buffer_element_size = 0;
  std::optional<BufferReserve> dto_stim_size;
};

using CoreLoadMaxList = std::vector<CoreLoadMax>;

class Daq {
public:
  void SetType(const std::string& type);
  [[nodiscard]] DaqType GetType() const { return type_; }

  void SetMaxDaq(uint64_t max_daq) {
    max_daq_ = static_cast<uint16_t>(max_daq);
  }
  [[nodiscard]] uint16_t GetMaxDaq() const { return max_daq_; }

  void SetMaxEvent(uint64_t max_event) {
    max_event_ = static_cast<uint16_t>(max_event);
  }
  [[nodiscard]] uint16_t GetMaxEvent() const { return max_event_; }

  void SetMinDaq(uint64_t min_daq) {
    min_daq_ = static_cast<uint8_t>(min_daq);
  }
  [[nodiscard]] uint8_t GetMinDaq() const { return min_daq_; }

  void SetOptimisationType(const std::string& type);
  [[nodiscard]] OptimisationType GetOptimisationType() const {
    return optimisation_type_;
  }

  void SetAddressExtension(const std::string& extension);
  [[nodiscard]] AddressExtension GetAddressExtension() const {
    return address_extension_;
  }

  void SetIdentificationFieldType(const std::string& type);
  [[nodiscard]] IdentificationFieldType GetIdentificationFieldType() const {
    return identification_field_type_;
  }

  void SetGranularityOdtEntrySizeDaq(const std::string& type);
  [[nodiscard]] GranularityOdtEntrySizeDaq GetGranularityOdtEntrySizeDaq() const {
    return granularity_odt_entry_size_daq_;
  }

  void SetMaxOdtEntrySize(uint64_t max_odt_entry_size) {
    max_odt_entry_size_ = static_cast<uint8_t>(max_odt_entry_size);
  }
  [[nodiscard]] uint8_t GetMaxOdtEntrySize() const { return max_odt_entry_size_; }

  void SetOverloadIndicator(const std::string& indicator);
  [[nodiscard]] OverloadIndicator GetOverloadIndicator() const {
    return overload_indicator_;
  }

  void SetDaqAlternatingSupported(uint64_t channel) {
    daq_alternating_supported_ = static_cast<uint16_t>(channel);
  }
  [[nodiscard]] const std::optional<uint16_t>& GetDaqAlternatingSupported() const {
    return daq_alternating_supported_;
  }

  void SetPrecalerSupported() { precaler_supported_ = true; }
  [[nodiscard]] bool GetPrecalerSupported() const { return precaler_supported_; }

  void SetResumeSupported() { resume_supported_ = true; }
  [[nodiscard]] bool GetResumeSupported() const { return resume_supported_; }

  void SetStoreDaqSupported() { store_daq_supported_ = true; }
  [[nodiscard]] bool GetStoreDaqSupported() const { return store_daq_supported_; }

  void SetDtoCtrSupported() { dto_ctr_supported_ = true; }
  [[nodiscard]] bool GetDtoCtrSupported() const { return dto_ctr_supported_; }

  void SetOptimisationTypeOdtStrict() { optimisation_type_odt_strict_ = true; }
  [[nodiscard]] bool GetOptimisationTypeOdtStrict() const {
    return optimisation_type_odt_strict_;
  }

  void SetStim(const DaqStim& stim) { stim_ = stim; }
  [[nodiscard]] const DaqStim* GetStim() const {
    return stim_.has_value() ? &stim_.value() : nullptr;
  }

  void SetTimestamp(const Timestamp& timestamp) { timestamp_ = timestamp; }
  [[nodiscard]] const Timestamp* GetTimestamp() const {
    return timestamp_.has_value() ? &timestamp_.value() : nullptr;
  }

  void SetPidOffSupported() { pid_off_supported_ = true; }
  [[nodiscard]] bool GetPidOffSupported() const { return pid_off_supported_; }

  void SetMaxDaqTotal(uint64_t max_daq_total) {
    max_daq_total_ = static_cast<uint16_t>(max_daq_total);
  }
  [[nodiscard]] const std::optional<uint16_t>& GetMaxDaqTotal() const {
    return max_daq_total_;
  }

  void SetMaxOdtTotal(uint64_t max_odt_total) {
    max_odt_total_ = static_cast<uint16_t>(max_odt_total);
  }
  [[nodiscard]] const std::optional<uint16_t>& GetMaxOdtTotal() const {
    return max_odt_total_;
  }

  void SetMaxOdtDaqTotal(uint64_t max_odt_daq_total) {
    max_odt_daq_total_ = static_cast<uint16_t>(max_odt_daq_total);
  }
  [[nodiscard]] const std::optional<uint16_t>& GetMaxOdtDaqTotal() const {
    return max_odt_daq_total_;
  }

  void SetMaxOdtStimTotal(uint64_t max_odt_stim_total) {
    max_odt_stim_total_ = static_cast<uint16_t>(max_odt_stim_total);
  }
  [[nodiscard]] const std::optional<uint16_t>& GetMaxOdtStimTotal() const {
    return max_odt_stim_total_;
  }

  void SetMaxDtoEntriesTotal(uint64_t max_dto_entries_total) {
    max_dto_entries_total_ = static_cast<uint16_t>(max_dto_entries_total);
  }
  [[nodiscard]] const std::optional<uint16_t>& GetMaxDtoEntriesTotal() const {
    return max_dto_entries_total_;
  }

  void SetMaxDtoEntriesDaqTotal(uint64_t max_dto_entries_daq_total) {
    max_dto_entries_daq_total_ = static_cast<uint16_t>(max_dto_entries_daq_total);
  }
  [[nodiscard]] const std::optional<uint16_t>& GetMaxDtoEntriesDaqTotal() const {
    return max_dto_entries_daq_total_;
  }

  void SetMaxDtoEntriesStimTotal(uint64_t max_dto_entries_stim_total) {
    max_dto_entries_stim_total_ = static_cast<uint16_t>(max_dto_entries_stim_total);
  }
  [[nodiscard]] const std::optional<uint16_t>& GetMaxDtoEntriesStimTotal() const {
    return max_dto_entries_stim_total_;
  }

  void SetCpuLoadMaxTotal(double cpu_load_max_total) {
    cpu_load_max_total_ = static_cast<float>(cpu_load_max_total);
  }
  [[nodiscard]] const std::optional<float>& GetCpuLoadMaxTotal() const {
    return cpu_load_max_total_;
  }

  void SetCoreLoadMaxTotal(double core_load_max_total) {
    core_load_max_total_ = static_cast<float>(core_load_max_total);
  }
  [[nodiscard]] const std::optional<float>& GetCoreLoadMaxTotal() const {
    return core_load_max_total_;
  }

  void AddCoreLoadMax(CoreLoadMax core_load_max) {
    core_load_max_list_.emplace_back( core_load_max);
  }
  [[nodiscard]] const CoreLoadMaxList& GetCoreLoadMaxList() const {
    return core_load_max_list_;
  }

  void SetDaqMemoryConsumption(const DaqMemoryConsumption& daq_memory_consumption) {
    daq_memory_consumption_ = daq_memory_consumption;
  }
  [[nodiscard]] const DaqMemoryConsumption* GetDaqMemoryConsumption() const {
    return daq_memory_consumption_.has_value() ?
      &daq_memory_consumption_.value() : nullptr;
  }

  void AddDaqList(DaqList daq_list) {
    daq_list_list_.emplace_back(std::move(daq_list));
  }
  [[nodiscard]] const std::vector<DaqList>& GetDaqList() const {
    return daq_list_list_;
  }

  void AddEvent(Event event) {
    event_list_.emplace_back( std::move(event));
  }
  [[nodiscard]] const std::vector<Event>& GetEventList() const {
    return event_list_;
  }

  void Reset();
private:
  DaqType type_ = DaqType::STATIC;
  uint16_t max_daq_ = 0;
  uint16_t max_event_ = 0;
  uint8_t min_daq_ = 0;
  OptimisationType optimisation_type_ =
    OptimisationType::OPTIMISATION_TYPE_DEFAULT;
  AddressExtension address_extension_ =
    AddressExtension::ADDRESS_EXTENSION_FREE;
  IdentificationFieldType identification_field_type_ =
    IdentificationFieldType::IDENTIFICATION_FIELD_TYPE_ABSOLUTE;
  GranularityOdtEntrySizeDaq granularity_odt_entry_size_daq_ =
    GranularityOdtEntrySizeDaq::GRANULARITY_ODT_ENTRY_SIZE_DAQ_BYTE;
  uint8_t max_odt_entry_size_ = 0;
  OverloadIndicator overload_indicator_ =
    OverloadIndicator::NO_OVERLOAD_INDICATION;

  std::optional<uint16_t> daq_alternating_supported_;
  bool precaler_supported_ = false;
  bool resume_supported_ = false;
  bool store_daq_supported_ = false;
  bool dto_ctr_supported_ = false;
  bool optimisation_type_odt_strict_ = false;
  std::optional<DaqStim> stim_;
  std::optional<Timestamp> timestamp_;
  bool pid_off_supported_ = false;
  std::optional<uint16_t> max_daq_total_;
  std::optional<uint16_t> max_odt_total_;
  std::optional<uint16_t> max_odt_daq_total_;
  std::optional<uint16_t> max_odt_stim_total_;
  std::optional<uint16_t> max_dto_entries_total_;
  std::optional<uint16_t> max_dto_entries_daq_total_;
  std::optional<uint16_t> max_dto_entries_stim_total_;
  std::optional<float> cpu_load_max_total_;
  std::optional<float> core_load_max_total_;
  CoreLoadMaxList core_load_max_list_;
  std::optional<DaqMemoryConsumption> daq_memory_consumption_;
  std::vector<DaqList> daq_list_list_;
  std::vector<Event> event_list_;
};

}
