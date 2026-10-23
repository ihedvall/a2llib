/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#include "a2l/xcp/xcpontcpip.h"

#include <string_view>
#include <array>
#include <sstream>

namespace a2l::xcp {

std::string XcpOnTcpIp::GetVersionAsString() const {
  std::ostringstream temp;
  temp << version_ / 256 << "." << version_ % 256;
  return temp.str();
}

void XcpOnTcpIp::SetPacketAlignment(const std::string& alignment) {
  // 被调用即说明 A2L 中**存在** PACKET_ALIGNMENT 关键字：先无条件置位声明
  // 标志，再做字面量匹配。否则"未声明"与"声明了 8bit"在值上不可区分
  // （未匹配时下面循环不赋值，值保持默认 PACKET_ALIGNMENT_8 = 0）。
  alignment_declared_ = true;
  constexpr std::array<std::string_view, 3> kAlignmentList = {
    "PACKET_ALIGNMENT_8", "PACKET_ALIGNMENT_16", "PACKET_ALIGNMENT_32"
  };
  for (size_t index = 0; index < kAlignmentList.size(); ++index) {
    if (alignment == kAlignmentList[index]) {
      packet_alignment_ = static_cast<TcpPacketAlignment>(index);
      break;;
    }
  }
}

void XcpOnTcpIp::AddSubCmd(const std::string& cmd) {
  // 表项位置即子命令码：码值 = 0xFA + index。空串是**保留槽**，用于让
  // 索引与规范码值对齐（ASAM AE MCD-1 XCP on Ethernet V1.5 表：
  // GET_DAQ_CLOCK_MULTICAST=0xFA、SET_SLAVE_IP_ADDRESS=0xFC、
  // GET_SLAVE_ID_EXTENDED=0xFD、GET_SLAVE_ID=0xFF；
  // 0xFB 与 0xFE 未分配，故各留一个空槽）。
  //
  // 修复记录：此前 `""` 与 `"SET_SLAVE_IP_ADDRESS"` 之间**漏了逗号**，
  // 相邻字符串字面量被拼接成一个元素，导致表退化为 5 个有效项，索引整体
  // 前移——实测 GET_SLAVE_ID 错得 0xFE（应 0xFF）、SET_SLAVE_IP_ADDRESS
  // 错得 0xFB（应 0xFC）、GET_SLAVE_ID_EXTENDED 错得 0xFC（应 0xFD），
  // 与本头文件 `TcpSubCmd` 枚举声明及规范均矛盾。补上逗号后与
  // `XcpOnUdpIp::AddSubCmd` 的同名表完全一致。
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
      optional_tl_subcommand_list_.push_back(static_cast<TcpSubCmd>(kOffset + index));
      break;
    }
  }
}

void XcpOnTcpIp::Reset() {
  Protocol::Reset();
  version_ = 0;
  port_ = 0;
  host_name_.clear();
  address_.clear();
  ipv6_.clear();
  max_bus_load_.reset();
  max_bit_rate_.reset();
  packet_alignment_ = TcpPacketAlignment::PACKET_ALIGNMENT_8;
  alignment_declared_ = false;
  optional_tl_subcommand_list_.clear();
}

}  // namespace a2l::xcp
