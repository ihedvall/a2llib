/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#include "a2l/xcp/daq.h"

#include <array>
#include <string_view>

namespace a2l::xcp {

void DaqStim::SetSize(const std::string& size) {
  constexpr std::array<std::string_view, 9> kTypeList = {
    "",
    "GRANULARITY_ODT_ENTRY_SIZE_STIM_BYTE",
    "GRANULARITY_ODT_ENTRY_SIZE_STIM_WORD",
    "",
    "GRANULARITY_ODT_ENTRY_SIZE_STIM_DWORD",
    "",
    "",
    "",
    "GRANULARITY_ODT_ENTRY_SIZE_STIM_DLONG"
  };
  if (size.empty()) {
    return;
  }
  for (size_t index = 0; index < kTypeList.size(); ++index) {
    if (size == kTypeList[index]) {
      stim_size = static_cast<GranularityOdtEntrySizeStim>(index);
      break;
    }
  }
}

void Daq::SetType(const std::string& type) {
  constexpr std::array<std::string_view,2> kTypeList= {
    "STATIC",
    "DYNAMIC"
  };
  for (size_t index = 0; index < kTypeList.size(); ++index) {
    if (type == kTypeList[index]) {
      type_ = static_cast<DaqType>(index);
      break;
    }
  }

}

void Daq::SetOptimisationType(const std::string& type) {
  constexpr std::array<std::string_view,6> kTypeList= {
    "OPTIMISATION_TYPE_DEFAULT",
    "OPTIMISATION_TYPE_ODT_TYPE_16",
    "OPTIMISATION_TYPE_ODT_TYPE_32",
    "OPTIMISATION_TYPE_ODT_TYPE_64",
    "OPTIMISATION_TYPE_ODT_TYPE_ALIGNMENT",
    "OPTIMISATION_TYPE_MAX_ENTRY_SIZE"
  };
  for (size_t index = 0; index < kTypeList.size(); ++index) {
    if (type == kTypeList[index]) {
      optimisation_type_ = static_cast<OptimisationType>(index);
      break;
    }
  }
}

void Daq::SetAddressExtension(const std::string& extension) {
  constexpr std::array<std::string_view,4> kExtensionList= {
    "ADDRESS_EXTENSION_FREE",
    "ADDRESS_EXTENSION_ODT",
    "",
    "ADDRESS_EXTENSION_DAQ"
  };
  if (extension.empty()) {
    return;
  }
  for (size_t index = 0; index < kExtensionList.size(); ++index) {
    if (extension == kExtensionList[index]) {
      address_extension_ = static_cast<AddressExtension>(index);
      break;
    }
  }
}

void Daq::SetIdentificationFieldType(const std::string& type) {
  constexpr std::array<std::string_view, 4> kTypeList = {
    "IDENTIFICATION_FIELD_TYPE_ABSOLUTE",
    "IDENTIFICATION_FIELD_TYPE_RELATIVE_BYTE",
    "IDENTIFICATION_FIELD_TYPE_RELATIVE_WORD",
    "IDENTIFICATION_FIELD_TYPE_RELATIVE_WORD_ALIGNED"
  };
  for (size_t index = 0; index < kTypeList.size(); ++index) {
    if (type == kTypeList[index]) {
      identification_field_type_ = static_cast<IdentificationFieldType>(index);
      break;
    }
  }
}

void Daq::SetGranularityOdtEntrySizeDaq(const std::string& type) {
  constexpr std::array<std::string_view, 9> kTypeList = {
    "",
    "GRANULARITY_ODT_ENTRY_SIZE_DAQ_BYTE",
    "GRANULARITY_ODT_ENTRY_SIZE_DAQ_WORD",
    "",
    "GRANULARITY_ODT_ENTRY_SIZE_DAQ_DWORD",
    "",
    "",
    "",
    "GRANULARITY_ODT_ENTRY_SIZE_DAQ_DLONG"
  };
  if (type.empty()) {
    return;
  }
  for (size_t index = 0; index < kTypeList.size(); ++index) {
    if (type == kTypeList[index]) {
      granularity_odt_entry_size_daq_ =
             static_cast<GranularityOdtEntrySizeDaq>(index);
      break;
    }
  }
}

void Daq::SetOverloadIndicator(const std::string& indicator) {
  constexpr std::array<std::string_view, 3> kIndicatorList = {
    "NO_OVERLOAD_INDICATION",
     "OVERLOAD_INDICATION_PID",
     "OVERLOAD_INDICATION_EVENT"
  };
  for (size_t index = 0; index < kIndicatorList.size(); ++index) {
    if (indicator == kIndicatorList[index]) {
      overload_indicator_ = static_cast<OverloadIndicator>(index);
      break;
    }
  }
}

void Daq::Reset() {
  type_ = DaqType::STATIC;
  max_daq_ = 0;
  max_event_ = 0;
  min_daq_ = 0;
  optimisation_type_ = OptimisationType::OPTIMISATION_TYPE_DEFAULT;
  address_extension_ = AddressExtension::ADDRESS_EXTENSION_FREE;
  identification_field_type_ = IdentificationFieldType::IDENTIFICATION_FIELD_TYPE_ABSOLUTE;
  granularity_odt_entry_size_daq_ = GranularityOdtEntrySizeDaq::GRANULARITY_ODT_ENTRY_SIZE_DAQ_BYTE;
  max_odt_entry_size_ = 0;
  overload_indicator_ = OverloadIndicator::NO_OVERLOAD_INDICATION;
  daq_alternating_supported_.reset();
  precaler_supported_ = false;
  resume_supported_ = false;
  store_daq_supported_ = false;
  dto_ctr_supported_ = false;
  optimisation_type_odt_strict_ = false;
  stim_.reset();
  timestamp_.reset();
  pid_off_supported_ = false;
  max_daq_total_.reset();
  max_odt_total_.reset();
  max_odt_daq_total_.reset();
  max_odt_stim_total_.reset();
  max_dto_entries_total_.reset();
  max_dto_entries_daq_total_.reset();
  max_dto_entries_stim_total_.reset();
  cpu_load_max_total_.reset();
  core_load_max_total_.reset();
  core_load_max_list_.clear();
  daq_memory_consumption_.reset();
  daq_list_list_.clear();
  event_list_.clear();
}

}  // namespace a2l::xcp