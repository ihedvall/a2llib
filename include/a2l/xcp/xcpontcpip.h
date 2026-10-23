/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "a2l/xcp/protocol.h"

namespace a2l::xcp {

enum class TcpPacketAlignment : uint8_t {
  PACKET_ALIGNMENT_8 = 0,
  PACKET_ALIGNMENT_16 = 1,
  PACKET_ALIGNMENT_32 = 2
};

enum class TcpSubCmd : uint8_t {
  GET_SLAVE_ID = 0xFF,
  GET_SLAVE_ID_EXTENDED = 0xFD,
  SET_SLAVE_IP_ADDRESS = 0xFC,
  GET_DAQ_CLOCK_MULTICAST = 0xFA
};

using TcpSubCmdList = std::vector<TcpSubCmd>;

class XcpOnTcpIp : public Protocol {
public:
  void SetVersion(uint64_t version) { version_ = static_cast<uint16_t>(version); }
  [[nodiscard]] uint16_t GetVersion() const { return version_; }
  [[nodiscard]] std::string GetVersionAsString() const;

  void SetPort(uint64_t port) { port_ = static_cast<uint16_t>(port); }
  [[nodiscard]] uint16_t GetPort() const { return port_; }

  void SetHostName(std::string host_name) { host_name_ = std::move(host_name); }
  [[nodiscard]] std::string GetHostName() const { return host_name_; }

  void SetAddress(std::string address) { address_ = std::move(address); }
  [[nodiscard]] std::string GetAddress() const { return address_; }

  void SetIpv6(std::string ipv6) { ipv6_ = std::move(ipv6); }
  [[nodiscard]] std::string GetIpv6() const { return ipv6_; }

  void SetMaxBusLoad(uint64_t max_bus_load) { max_bus_load_ = static_cast<uint32_t>(max_bus_load); }
  [[nodiscard]] const std::optional<uint32_t>& GetMaxBusLoad() const { return max_bus_load_; }

  void SetMaxBitRate(uint64_t max_bit_rate) { max_bit_rate_ = static_cast<uint32_t>(max_bit_rate); }
  [[nodiscard]] const std::optional<uint32_t>& GetMaxBitRate() const { return max_bit_rate_; }

  void SetPacketAlignment(const std::string& alignment);
  [[nodiscard]] TcpPacketAlignment GetPacketAlignment() const { return packet_alignment_; }
  /// @brief A2L 是否**显式声明**了 PACKET_ALIGNMENT 关键字
  /// @details 上游 SetPacketAlignment() 只匹配 3 个精确字面量，未匹配时
  /// 静默保持默认值 PACKET_ALIGNMENT_8(=0)，因此单看 GetPacketAlignment()
  /// 无法区分"未声明"与"声明了 8bit"，甚至无法发现"声明了非法字面量"。
  /// 本标志在 SetPacketAlignment() 被调用时无条件置位，用于恢复该事实。
  [[nodiscard]] bool IsAlignmentDeclared() const { return alignment_declared_; }

  void AddSubCmd(const std::string& cmd);
  [[nodiscard]] const TcpSubCmdList& GetSubCmds() const {
    return optional_tl_subcommand_list_;
  }

  void Reset() override;
private:
  uint16_t version_ = 0;
  uint16_t port_ = 0;
  std::string host_name_;
  std::string address_;
  std::string ipv6_;
  std::optional<uint32_t> max_bus_load_;
  std::optional<uint32_t> max_bit_rate_;
  TcpPacketAlignment packet_alignment_ = TcpPacketAlignment::PACKET_ALIGNMENT_8;
  /// @brief PACKET_ALIGNMENT 是否在 A2L 中被显式声明（见 IsAlignmentDeclared）
  bool alignment_declared_ = false;
  TcpSubCmdList optional_tl_subcommand_list_;

};
}
