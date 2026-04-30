/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include <optional>

#include "a2l/xcp/protocol.h"
#include "a2l/xcp/flxbuffer.h"

namespace a2l::xcp {

enum class HeaderNax : uint8_t {
  HEADER_NAX = 0,
  HEADER_NAX_FILL = 1,
  HEADER_NAX_CTR = 2,
  HEADER_NAX_FILL3 = 3,
  HEADER_NAX_CTR_FILL2 = 4,
  HEADER_NAX_LEN = 5,
  HEADER_NAX_CTR_LEN = 6,
  HEADER_NAX_FILL2_LEN = 7,
  HEADER_NAX_CTR_FILL_LEN = 8
};

enum class PacketAlignment : uint8_t {
  PACKET_ALIGNMENT_8 = 0,
  PACKET_ALIGNMENT_16 = 1,
  PACKET_ALIGNMENT_32 = 2
};

enum class FlxSubCmd : uint8_t {
  FLX_ASSIGN = 0xFF,
  FLX_ACTIVATE = 0xFE,
  FLX_DEACTIVATE = 0xFD,
  GET_DAQ_FLX_BUF = 0xFC,
  SET_DAQ_FLX_BUF = 0xFB,
  GET_DAQ_CLOCK_MULTICAST = 0xFA
};

using PoolBufferList = std::vector<FlxBuffer>;
using FlxSubCmdList = std::vector<FlxSubCmd>;

class XcpOnFlx : public Protocol {
public:
  void SetVersion(uint64_t version) {
    version_ = static_cast<uint16_t>(version);
  }
  [[nodiscard]] uint16_t Version() const { return version_; }
  [[nodiscard]] std::string VersionAsString() const;

  void SetT1Flx(uint64_t t1_flx) {
    t1_flx_ = static_cast<uint16_t>(t1_flx);
  }
  [[nodiscard]] uint16_t GetT1Flx() const { return t1_flx_; }

  void SetFibexFile(std::string fibex_file) {
    fibex_file_ = std::move(fibex_file);
  }
  [[nodiscard]] const std::string& GetFibexFile() const { return fibex_file_; }

  void SetClusterId(std::string cluster_id) {
    cluster_id_ = std::move(cluster_id);
  }
  [[nodiscard]] const std::string& GetClusterId() const { return cluster_id_; }

  void SetNax(uint64_t nax) {
    nax_ = static_cast<uint8_t>(nax);
  }
  [[nodiscard]] uint8_t GetNax() const { return nax_; }

  void SetHeaderNax(const std::string& header_nax);
  [[nodiscard]] HeaderNax GetHeaderNax() const { return header_nax_; }

  void SetPacketAlignment(const std::string& packet_alignment);
  [[nodiscard]] PacketAlignment GetPacketAlignment() const {
    return packet_alignment_;
  }

  void SetInitialCmdBuffer(FlxBuffer buffer) {
    initial_cmd_buffer_ = std::move(buffer);
  }
  [[nodiscard]] const FlxBuffer* GetFlxBuffer() const {
    return initial_cmd_buffer_.has_value() ?
      &initial_cmd_buffer_.value() : nullptr;
  }

  void SetInitialResErrBuffer(FlxBuffer buffer) {
    initial_res_err_buffer_ = std::move(buffer);
  }
  [[nodiscard]] const FlxBuffer* GetResErrBuffer() const {
    return initial_res_err_buffer_.has_value() ?
      &initial_res_err_buffer_.value() : nullptr;
  }

  void AddPoolBuffer(FlxBuffer buffer) {
    pool_buffer_list_.emplace_back(std::move(buffer));
  }
  [[nodiscard]] const PoolBufferList& GetPoolBuffers() const {
    return pool_buffer_list_;
  }

  void AddFlxSubCmd(const std::string& cmd);
  [[nodiscard]] const FlxSubCmdList& GetFlxSubCmds() const {
    return optional_sub_cmd_list_;
  }

  [[nodiscard]] FlxBuffer& GetFlxBuffer() { return flx_buffer_; }

  void Reset() override;
private:
  uint16_t version_ = 0;
  uint16_t t1_flx_ = 0; ///< Timer 1 FlexRay [ms]
  std::string fibex_file_;
  std::string cluster_id_;
  uint8_t nax_ = 0;
  HeaderNax header_nax_ = HeaderNax::HEADER_NAX;
  PacketAlignment packet_alignment_ = PacketAlignment::PACKET_ALIGNMENT_8;
  std::optional<FlxBuffer> initial_cmd_buffer_;
  std::optional<FlxBuffer> initial_res_err_buffer_;
  PoolBufferList pool_buffer_list_;
  FlxSubCmdList optional_sub_cmd_list_;
  FlxBuffer flx_buffer_; ///< Temporary flex buffer
};
}
