/*
* Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#include "a2l/xcp/xcponcan.h"

#include <sstream>
#include <array>
#include <string_view>

namespace {
a2l::xcp::CanSyncEdge StringToSynchEdge(const std::string& tdc) {
  constexpr std::array<std::string_view, 2> kSyncEdgeList = {
    "SINGLE",
    "DUAL"
  };
  for (size_t index = 0; index < kSyncEdgeList.size(); ++index) {
    if (tdc == kSyncEdgeList[index]) {
      constexpr size_t kOffset = 1;
      return static_cast<a2l::xcp::CanSyncEdge>(index + kOffset);
    }
  }
  return a2l::xcp::CanSyncEdge::SINGLE;
}
}

namespace a2l::xcp {

void CanFd::SetSyncEdge(const std::string& tdc) {
  sync_edge = StringToSynchEdge(tdc);
}

void CanFd::SetTransceiverDelayCompensation(const std::string& tdc) {
  constexpr std::array<std::string_view, 2> kTdcList = {
    "OFF",
    "ON"
  };
  for (size_t index = 0; index < kTdcList.size(); ++index) {
    if (tdc == kTdcList[index]) {
      transceiver_delay_compensation =
        static_cast<TransceiverDelayCompensation>(index);
      break;
    }
  }
}

void CanFd::Reset() {
  max_dlc.reset();
  baudrate.reset();
  sample_point.reset();
  btl_cycles.reset();
  sjw.reset();
  sync_edge.reset();
  max_dlc_required = false;
  secondary_sample_point.reset();
  transceiver_delay_compensation.reset();
}

std::string XcpOnCan::GetVersionAsString() const {
  std::ostringstream temp;
  temp << version_ / 256 << "." << version_ % 256;
  return temp.str();

}
void XcpOnCan::SetSampleRate(const std::string& sample_rate) {
  constexpr std::array<std::string_view, 4> kSampleRateList = {
    "",
    "SINGLE",
    "",
    "TRIPLE"
  };
  if (sample_rate.empty()) {
    return;
  }
  for (size_t index = 0; index < kSampleRateList.size(); ++index) {
    if (sample_rate == kSampleRateList[index]) {
      sample_rate_ = static_cast<CanSampleRate>(index);
      break;
    }
  }
}

void XcpOnCan::SetSyncEdge(const std::string& sync_edge) {
  constexpr std::array<std::string_view, 3> kSyncEdgeList = {
    "",
    "SINGLE",
    "DUAL"
  };
  if (sync_edge.empty()) {
    return;
  }
  for (size_t index = 0; index < kSyncEdgeList.size(); ++index) {
    if (sync_edge == kSyncEdgeList[index]) {
      sync_edge_ = static_cast<CanSyncEdge>(index);
      break;
    }
  }
}

void XcpOnCan::AddSubCmd(const std::string& cmd) {
  constexpr std::array<std::string_view, 6> kSubCmdList = {
    "GET_DAQ_CLOCK_MULTICAST",
    "SET_DAQ_ID",
    "GET_DAQ_ID",
    "",
    "",
    "GET_SLAVE_ID"
  };
  if (cmd.empty()) {
    return;
  }
  for (size_t index = 0; index < kSubCmdList.size(); ++index) {
    if (cmd == kSubCmdList[index]) {
      constexpr size_t kOffset = 0xFA;
      optional_tl_subcmd_list_.push_back(
        static_cast<CanSubCmd>(kOffset + index));
      break;
    }
  }
}

void XcpOnCan::Reset() {
  Protocol::Reset();
  version_ = 0;
  can_id_broadcast_.reset();
  can_id_master_.reset();
  can_id_master_incremental_ = false;
  can_id_slave_.reset();
  can_id_get_daq_clock_multicast_.reset();
  baudrate_.reset();
  sample_point_.reset();
  sample_rate_.reset();
  btl_cycles_.reset();
  sjw_.reset();
  sync_edge_.reset();
  max_dlc_required_ = false;
  daq_list_can_id_list_.clear();
  event_can_id_list_.clear();
  max_bus_load_.reset();
  measurement_split_allowed_ = false;
  can_fd_.reset();
  optional_tl_subcmd_list_.clear();
  current_fd_.Reset();
}
} // a2l::xcp
