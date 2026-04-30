/*
* Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>
#include <optional>
#include <string>

namespace a2l::xcp {

enum class FlxPacketAssignmentType : uint8_t {
  NOT_ALLOWED = 0,
  FIXED = 1,
  VARIABLE_INITIALISED = 2,
  VARIABLE = 3
};

enum class FlxChannel : uint8_t {
  A = 0,
  B = 1,
};

struct FlxVariableFixed {
  std::optional<uint64_t> fixed;
  std::optional<uint64_t> variable;
  std::optional<uint64_t> initial_value;
  std::optional<FlxChannel> initial_channel;

  void InitialChannel(const std::string& channel) {
    if (channel == "A") {
      initial_channel = FlxChannel::A;
    } else if (channel == "B") {
      initial_channel = FlxChannel::B;
    }
  }
  void Reset() {
    fixed.reset();
    variable.reset();
    initial_value.reset();
    initial_channel.reset();
  }
};

class FlxBuffer {
public:
  void SetBufferNo(uint64_t buffer_no) {
    buffer_no_ = static_cast<uint8_t>(buffer_no);
  }
  [[nodiscard]] uint8_t GetBufferNo() const { return buffer_no_; }

  void SetMaxFlxLenBuffer(FlxVariableFixed max_flx_len_buf) {
    max_flx_len_buf_ = std::move(max_flx_len_buf);
  }
  [[nodiscard]] const FlxVariableFixed* GetMaxFlxLenBuffer() const {
    return max_flx_len_buf_.has_value() ?
      &max_flx_len_buf_.value() : nullptr;
  }

  void SetFlxSlotId(FlxVariableFixed flx_slot_id) {
    flx_slot_id_ = std::move(flx_slot_id);
  }
  [[nodiscard]] const FlxVariableFixed* GetFlxSlotId() const {
    return flx_slot_id_.has_value() ?
      &flx_slot_id_.value() : nullptr;
  }

  void SetOffset(FlxVariableFixed offset) {
    offset_ = std::move(offset);
  }
  [[nodiscard]] const FlxVariableFixed* GetOffset() const {
    return offset_.has_value() ?
      &offset_.value() : nullptr;
  }

  void SetCycleRepetition(FlxVariableFixed cycle_repetition) {
    cycle_repetition_ = std::move(cycle_repetition);
  }
  [[nodiscard]] const FlxVariableFixed* GetCycleRepetition() const {
    return cycle_repetition_.has_value() ?
      &cycle_repetition_.value() : nullptr;
  }

  void SetChannel(FlxVariableFixed channel) {
    channel_ = std::move(channel);
  }
  [[nodiscard]] const FlxVariableFixed* GetChannel() const {
    return channel_.has_value() ?
      &channel_.value() : nullptr;
  }

  void SetCmd(const std::string& type);
  [[nodiscard]] const std::optional<FlxPacketAssignmentType>& GetCmd() const {
    return cmd_;
  }

  void SetResErr(const std::string& type);
  [[nodiscard]] const std::optional<FlxPacketAssignmentType>& GetResErr() const {
    return res_err_;
  }

  void SetEvServ(const std::string& type);
  [[nodiscard]] const std::optional<FlxPacketAssignmentType>& GetEvServ() const {
    return ev_serv_;
  }

  void SetDaq(const std::string& type);
  [[nodiscard]] const std::optional<FlxPacketAssignmentType>& GetDaq() const {
    return daq_;
  }


  void SetStim(const std::string& type);
  [[nodiscard]] const std::optional<FlxPacketAssignmentType>& GetStim() const {
    return stim_;
  }

  void SetMulticast(const std::string& type);
  [[nodiscard]] const std::optional<FlxPacketAssignmentType>& GetMulticast() const {
    return multicast_;
  }

  void Reset();
  [[nodiscard]] FlxVariableFixed& GetVariableFixed() {
    return current_variable_fixed_;
  };
private:
  uint8_t buffer_no_ = 0;
  std::optional<FlxVariableFixed> max_flx_len_buf_;
  std::optional<FlxVariableFixed> flx_slot_id_;
  std::optional<FlxVariableFixed> offset_;
  std::optional<FlxVariableFixed> cycle_repetition_;
  std::optional<FlxVariableFixed> channel_;

  std::optional<FlxPacketAssignmentType> cmd_;
  std::optional<FlxPacketAssignmentType> res_err_;
  std::optional<FlxPacketAssignmentType> ev_serv_;
  std::optional<FlxPacketAssignmentType> daq_;
  std::optional<FlxPacketAssignmentType> stim_;
  std::optional<FlxPacketAssignmentType> multicast_;

  FlxVariableFixed current_variable_fixed_;
};



}
