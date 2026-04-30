

#include "a2l/xcp/xcponflx.h"

#include <sstream>
#include <array>
#include <string_view>

namespace a2l::xcp {
std::string XcpOnFlx::VersionAsString() const {
  std::ostringstream temp;
  temp << version_ / 256 << "." << version_ % 256;
  return temp.str();
}

void XcpOnFlx::SetHeaderNax(const std::string& header_nax) {
  constexpr std::array<std::string_view,9> kHeaderNaxList = {
    "HEADER_NAX", "HEADER_NAX_FILL", "HEADER_NAX_CTR",
    "HEADER_NAX_FILL3", "HEADER_NAX_CTR_FILL2", "HEADER_NAX_LEN",
    "HEADER_NAX_CTR_LEN", "HEADER_NAX_FILL2_LEN", "HEADER_NAX_CTR_FILL_LEN"
  };
  for (size_t index = 0; index < kHeaderNaxList.size(); ++index) {
    if (header_nax == kHeaderNaxList[index]) {
      header_nax_ = static_cast<HeaderNax>(index);
      return;
    }
  }
}

void XcpOnFlx::SetPacketAlignment(const std::string& packet_alignment) {
  constexpr std::array<std::string_view,3> kPacketAlignmentList = {
    "PACKET_ALIGNMENT_8", "PACKET_ALIGNMENT_16", "PACKET_ALIGNMENT_32"
  };
  for (size_t index = 0; index < kPacketAlignmentList.size(); ++index) {
    if (packet_alignment == kPacketAlignmentList[index]) {
      packet_alignment_ = static_cast<PacketAlignment>(index);
      return;
    }
  }
}

void XcpOnFlx::AddFlxSubCmd(const std::string& cmd) {
  constexpr size_t offset = 0xFA;
  constexpr std::array<std::string_view,6> kFlxSubCmdList = {
    "GET_DAQ_CLOCK_MULTICAST",
    "SET_DAQ_FLX_BUF",
    "GET_DAQ_FLX_BUF",
    "FLX_DEACTIVATE",
    "FLX_ACTIVATE",
    "FLX_ASSIGN"
  };
  size_t select = 0;
  for (size_t index = 0; index < kFlxSubCmdList.size(); ++index) {
    if (cmd == kFlxSubCmdList[index]) {
      select = index + offset;
      break;
    }
  }
  if (select >= offset) {
    optional_sub_cmd_list_.push_back(static_cast<FlxSubCmd>(select));
  }
}

void XcpOnFlx::Reset() {
  Protocol::Reset();
  version_ = 0;
  t1_flx_ = 0;
  fibex_file_ = "";
  cluster_id_ = "";
  nax_ = 0;
  header_nax_ = HeaderNax::HEADER_NAX;
  packet_alignment_ = PacketAlignment::PACKET_ALIGNMENT_8;
  initial_cmd_buffer_.reset();
  optional_sub_cmd_list_.clear();
  pool_buffer_list_.clear();
  optional_sub_cmd_list_.clear();
  flx_buffer_.Reset();
}

}  // namespace a2l::xcp