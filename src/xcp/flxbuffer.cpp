/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#include "a2l/xcp/flxbuffer.h"

#include <array>
#include <string_view>
namespace {

a2l::xcp::FlxPacketAssignmentType ToType(const std::string& type) {
  constexpr std::array<std::string_view,4> kTypeList = {
    "NOT_ALLOWED", "FIXED", "VARIABLE_INITIALISED", "VARIABLE"
  };
  for (size_t index = 0; index < kTypeList.size(); ++index) {
    if (type == kTypeList[index]) {
      return static_cast<a2l::xcp::FlxPacketAssignmentType>(index);;
    }
  }
  return a2l::xcp::FlxPacketAssignmentType::NOT_ALLOWED;
}

}
namespace a2l::xcp {

void FlxBuffer::SetCmd(const std::string& type) {
  cmd_ = ToType(type);
}

void FlxBuffer::SetResErr(const std::string& type) {
  res_err_ = ToType(type);
}

void FlxBuffer::SetEvServ(const std::string& type) {
  ev_serv_ = ToType(type);
}

void FlxBuffer::SetDaq(const std::string& type) {
  daq_ = ToType(type);
}

void FlxBuffer::SetStim(const std::string& type) {
  stim_ = ToType(type);
}

void FlxBuffer::SetMulticast(const std::string& type) {
  multicast_ = ToType(type);
}
void FlxBuffer::Reset() {
  buffer_no_ = 0;
  max_flx_len_buf_.reset();
  flx_slot_id_.reset();
  offset_.reset();
  cycle_repetition_.reset();
  channel_.reset();
  cmd_.reset();
  res_err_.reset();
  ev_serv_.reset();
  daq_.reset();
  stim_.reset();
  multicast_.reset();
  current_variable_fixed_.Reset();
}

}  // namespace a2l::xcp