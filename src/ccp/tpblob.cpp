/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2l/ccp/tpblob.h"

#include <array>
#include <string_view>
#include <sstream>

namespace {
  constexpr uint32_t kCanIdMask = 0x1FFFFFFF;
}

namespace a2l::ccp {

std::string TpBlob::GetVersionAsString() const {
  std::ostringstream version;
  version << version_ / 256 << "." << version_ % 256;
  return version.str();
}

std::string TpBlob::GetBlobVersionAsString() const {
  std::ostringstream version;
  version << blob_version_ / 256 << "." << blob_version_ % 256;
  return version.str();
}

uint32_t TpBlob::GetTransmitCanId() const {
  return transmit_message_id_ & kCanIdMask;
}

uint32_t TpBlob::GetReceiveCanId() const {
  return receive_message_id_ & kCanIdMask;
}

void TpBlob::SetSyncEdge(const std::string& sync_edge) {
  constexpr std::array<std::string_view, 2> kSyncEdgeList = {
    "SINGLE",
    "DUAL"
  };
  for (size_t index = 0; index < kSyncEdgeList.size(); index++) {
    if (sync_edge == kSyncEdgeList[index]) {
      sync_edge_ = static_cast<SyncEdge>(index);
      break;
    }
  }

}

void TpBlob::SetDaqMode(const std::string& daq_mode) {
  constexpr std::array<std::string_view, 2> kDaqModeList = {
    "ALTERNATING",
    "BURST"
  };
  for (size_t index = 0; index < kDaqModeList.size(); index++) {
    if (daq_mode == kDaqModeList[index]) {
      daq_mode_ = static_cast<DaqMode>(index);
      break;
    }
  }
}

void TpBlob::SetConsistency(const std::string& consistency) {
  constexpr std::array<std::string_view, 2> kConsistencyList = {
    "DAQ",
    "ODT"
  };
  for (size_t index = 0; index < kConsistencyList.size(); index++) {
    if (consistency == kConsistencyList[index]) {
      consistency_ = static_cast<Consistency>(index);
      break;
    }
  }
}

void TpBlob::SetAddressExtension(const std::string& address_extension) {
  constexpr std::array<std::string_view, 2> kAddressExtensionList = {
    "DAQ",
    "ODT"
  };
  for (size_t index = 0; index < kAddressExtensionList.size(); index++) {
    if (address_extension == kAddressExtensionList[index]) {
      address_extension_ = static_cast<AddressExtension>(index);
      break;
    }
  }
}

void TpBlob::Reset() {
  version_ = 0;
  blob_version_ = 0;
  transmit_message_id_ = 0;
  receive_message_id_ = 0;
  address_ = 0;
  byte_order_ = 2;
  can_param_.reset();
  baudrate_.reset();
  sample_point_.reset();
  sample_rate_.reset();
  btl_cycles_.reset();
  sjw_.reset();
  sync_edge_.reset();
  daq_mode_.reset();
  bytes_only_ = false;
  resume_supported_ = false;
  store_supported_ = false;
  consistency_.reset();
  address_extension_.reset();
  checksum_param_.reset();
  defined_pages_list_.clear();
  optional_cmd_list_.clear();
  }

} // a2l::ccp