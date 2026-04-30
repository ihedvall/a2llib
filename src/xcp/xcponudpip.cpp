/*
* Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#include "a2l/xcp/xcponudpip.h"

#include <string_view>
#include <array>
#include <sstream>

namespace a2l::xcp {

std::string XcpOnUdpIp::GetVersionAsString() const {
  std::ostringstream temp;
  temp << version_ / 256 << "." << version_ % 256;
  return temp.str();
}
void XcpOnUdpIp::SetPacketAlignment(const std::string& alignment) {
  constexpr std::array<std::string_view, 3> kAlignmentList = {
    "PACKET_ALIGNMENT_8", "PACKET_ALIGNMENT_16", "PACKET_ALIGNMENT_32"
  };
  for (size_t index = 0; index < kAlignmentList.size(); ++index) {
    if (alignment == kAlignmentList[index]) {
      packet_alignment_ = static_cast<UdpPacketAlignment>(index);
      break;;
    }
  }
}

void XcpOnUdpIp::AddUdpSubCmd(const std::string& cmd) {
  constexpr std::array<std::string_view, 6> kCmdList = {
    "GET_DAQ_CLOCK_MULTICAST",
    "",
    "SET_SLAVE_IP_ADDRESS",
    "GET_SLAVE_ID_EXTENDED",
    "",
    "GET_SLAVE_ID"
  };
  if (cmd.empty()) {
    return;
  }
  for (size_t index = 0; index < kCmdList.size(); ++index) {
    if (cmd == kCmdList[index]) {
      constexpr size_t kOffset = 0xFA;
      optional_tl_subcommand_list_.push_back(static_cast<UdpSubCmd>(kOffset + index));
      break;
    }
  }
}

void XcpOnUdpIp::Reset() {
  Protocol::Reset();
  version_ = 0;
  port_ = 0;
  host_name_.clear();
  address_.clear();
  ipv6_.clear();
  max_bus_load_.reset();
  max_bit_rate_.reset();
  packet_alignment_ = UdpPacketAlignment::PACKET_ALIGNMENT_8;
  optional_tl_subcommand_list_.clear();
}

}  // namespace a2l::xcp
