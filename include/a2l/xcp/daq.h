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
#include "a2l/xcp/xcptimestampresolution.h"

namespace a2l::xcp {

enum class XcpDaqType : uint8_t {
  STATIC = 0,
  DYNAMIC = 1,
};

enum class XcpOptimisationType : uint8_t {
  OPTIMISATION_TYPE_DEFAULT = 0,
  OPTIMISATION_TYPE_ODT_TYPE_16 = 1,
  OPTIMISATION_TYPE_ODT_TYPE_32 = 2,
  OPTIMISATION_TYPE_ODT_TYPE_64 = 3,
  OPTIMISATION_TYPE_ODT_TYPE_ALIGNMENT = 4,
  OPTIMISATION_TYPE_MAX_ENTRY_SIZE = 5,
};

enum class XcpAddressExtension : uint8_t {
  ADDRESS_EXTENSION_FREE = 0,
  ADDRESS_EXTENSION_ODT = 1,
  ADDRESS_EXTENSION_DAQ = 3,
};

enum class XcpIdentificationFieldType : uint8_t {
  IDENTIFICATION_FIELD_TYPE_ABSOLUTE = 0,
  IDENTIFICATION_FIELD_TYPE_RELATIVE_BYTE = 1,
  IDENTIFICATION_FIELD_TYPE_RELATIVE_WORD = 2,
  IDENTIFICATION_FIELD_TYPE_RELATIVE_WORD_ALIGNED = 3,
};

enum class XcpGranularityOdtEntrySizeDaq : uint8_t {
  GRANULARITY_ODT_ENTRY_SIZE_DAQ_BYTE = 1,
  GRANULARITY_ODT_ENTRY_SIZE_DAQ_WORD = 2,
  GRANULARITY_ODT_ENTRY_SIZE_DAQ_DWORD = 4,
  GRANULARITY_ODT_ENTRY_SIZE_DAQ_DLONG = 8,
};

enum class XcpGranularityOdtEntrySizeStim : uint8_t {
  GRANULARITY_ODT_ENTRY_SIZE_STIM_BYTE = 1,
  GRANULARITY_ODT_ENTRY_SIZE_STIM_WORD = 2,
  GRANULARITY_ODT_ENTRY_SIZE_STIM_DWORD = 4,
  GRANULARITY_ODT_ENTRY_SIZE_STIM_DLONG = 8,
};

enum class XcpOverloadIndicator : uint8_t {
  NO_OVERLOAD_INDICATION = 0,
  OVERLOAD_INDICATION_PID = 1,
  OVERLOAD_INDICATION_EVENT = 2,
};


struct CoreLoadMax {
  uint16_t number = 0;
  float max = 0.0;
  std::optional<float> core_load_max_total;
};

struct BufferReserve {
  uint8_t odt_daq_buffer_element_reserve = 0;
  uint8_t odt_stim_buffer_element_reserve = 0;
};

struct DaqMemoryConsumption {
  uint32_t limit_ = 0;
  uint16_t daq_size_ = 0;
  uint16_t odt_size_ = 0;
  uint16_t odt_entry_size_ = 0;
  uint16_t odt_daq_buffer_element_size_ = 0;
  uint16_t odt_stim_buffer_element_size_ = 0;
  std::optional<BufferReserve> dto_stim_size_;
};

using CoreLoadMaxList = std::vector<CoreLoadMax>;

class Daq {
public:
  void Type(const std::string& type);
  [[nodiscard]] XcpDaqType Type() const { return type_; }

  void MaxDaq(uint16_t max_daq) { max_daq_ = max_daq; }
  [[nodiscard]] uint16_t MaxDaq() const { return max_daq_; }

  void MaxEvent(uint16_t max_event) { max_event__ = max_event; }
  [[nodiscard]] uint16_t MaxEvent() const { return max_event__; }

  void MinDaq(uint16_t min_daq) { min_daq_ = min_daq; }
  [[nodiscard]] uint16_t MinDaq() const { return min_daq_; }

  void OptimisationType(const std::string& optimisation_type);
  [[nodiscard]] XcpOptimisationType OptimisationType() const {
    return optimisation_type_;
  }

  void AddressExtension(const std::string& address_extension);
  [[nodiscard]] XcpAddressExtension AddressExtension() const {
    return address_extension_;
  }

  void IdentificationFieldType(const std::string& identification_field_type);
  [[nodiscard]] XcpIdentificationFieldType IdentificationFieldType() const {
    return identification_field_type_;
  }

  void GranularityOdtEntrySizeDaq(const std::string& granularity_odt_entry_size_daq);
  [[nodiscard]] XcpGranularityOdtEntrySizeDaq GranularityOdtEntrySizeDaq() const {
    return granularity_odt_entry_size_daq_;
  }

  void MaxOdtEntrySize(uint8_t max_odt_entry_size) {
    max_odt_entry_size_ = max_odt_entry_size;
  }
  [[nodiscard]] uint8_t MaxOdtEntrySize() const { return max_odt_entry_size_; }

  void OverloadIndicator(const std::string& overload_indicator);
  [[nodiscard]] XcpOverloadIndicator OverloadIndicator() const {
    return overload_indicator_;
  }
private:
  XcpDaqType type_ = XcpDaqType::STATIC;
  uint16_t max_daq_ = 0;
  uint16_t max_event__ = 0;
  uint16_t min_daq_ = 0;
  XcpOptimisationType optimisation_type_ =
    XcpOptimisationType::OPTIMISATION_TYPE_DEFAULT;
  XcpAddressExtension address_extension_ =
    XcpAddressExtension::ADDRESS_EXTENSION_FREE;
  XcpIdentificationFieldType identification_field_type_ =
    XcpIdentificationFieldType::IDENTIFICATION_FIELD_TYPE_ABSOLUTE;
  XcpGranularityOdtEntrySizeDaq granularity_odt_entry_size_daq_ =
    XcpGranularityOdtEntrySizeDaq::GRANULARITY_ODT_ENTRY_SIZE_DAQ_BYTE;
  uint8_t max_odt_entry_size_ = 0;
  XcpOverloadIndicator overload_indicator_ =
    XcpOverloadIndicator::NO_OVERLOAD_INDICATION;

  bool daq_alternating_supported_ = false;
  uint16_t display_event_channel_ = 0;

  bool precaler_supported_ = false;
  bool resume_supported_ = false;
  bool store_daq_supported_ = false;
  bool dto_ctr_supported_ = false;
  bool optimisation_type_odt_strict_ = false;

  bool stim_supported = false;
  XcpGranularityOdtEntrySizeStim granularity_odt_entry_size_stim_ =
    XcpGranularityOdtEntrySizeStim::GRANULARITY_ODT_ENTRY_SIZE_STIM_BYTE;
  uint8_t max_odt_entry_size_stim_ = 0;
  bool bit_stim_supported_ = false;
  bool min_st_stim_supported_ = false;
  uint8_t separation_time_between_dto_ = 0;

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

};

}
