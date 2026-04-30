/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#include <sstream>

#include "a2l/xcp/protocollayer.h"

namespace a2l::xcp {

std::string ProtocolLayer::GetVersionAsString() const {
  const int major = version_ >> 8;
  const int minor = version_ & 0xFF;
  std::ostringstream version;
  version << major << "." << minor;
  return version.str();
}

void ProtocolLayer::SetByteOrder(const std::string& order) {
  constexpr std::array<std::string_view,2> order_list= {
    "BYTE_ORDER_MSB_LAST", "BYTE_ORDER_MSB_FIRST"
  };
  for (size_t value = 0; value < order_list.size(); ++value) {
    if (order == order_list[value]) {
      byte_order_ = static_cast<ByteOrder>(value);
      break;
    }
  }
}

void ProtocolLayer::SetAddressGranularity(const std::string& granularity) {
  constexpr std::array<std::string_view,5> granularity_list= {
    "",
    "ADDRESS_GRANULARITY_BYTE",
    "ADDRESS_GRANULARITY_WORD",
    "",
    "ADDRESS_GRANULARITY_DWORD"
  };
  if (granularity.empty()) {
    return;
  }
  for (size_t value = 0; value < granularity_list.size(); ++value) {
    if (granularity == granularity_list[value]) {
      address_granularity_ = static_cast<AddressGranularity>(value);
      break;;
    }
  }
}

void ProtocolLayer::SetOptionalCommand(const std::string& command) {
  // Note that the command value has an offset of 0xC4
  constexpr std::array<std::string_view,60> command_list= {
    "", "DTO_CTR_PROPERTIES", "TIME_CORRELATION_PRPERTIES", "WRITE_DAQ_MULTIPLE",
    "PROGRAM_VERIFY", "PROGRAM_MAX", "PROGRAM_NEXT", "PROGRAM_FORMAT",
    "PROGRAM_PREPARE", "GET_SECTOR_INFO", "GET_PGM_PROCESSOR_INFO", "PROGRAM_RESET",
    "PROGRAM", "PROGRAM_CLEAR", "PROGRAM_START", "ALLOC_ODT_ENTRY",
    "ALLOC_ODT", "ALLOC_DAQ", "FREE_DAQ", "GET_DAQ_EVENT_INFO",
    "GET_DAQ_LIST_INFO", "GET_DAQ_RESOLUTION_INFO", "GET_DAQ_PROCESSOR_INFO", "READ_DAQ",
    "GET_DAQ_CLOCK", "START_STOP_SYNCH", "START_STOP_DAQ_LIST", "GET_DAQ_LIST_MODE",
    "SET_DAQ_LIST_MODE", "WRITE_DAQ", "SET_DAQ_PTR", "CLEAR_DAQ_LIST",
    "COPY_CAL_PAGE", "GET_SEGMENT_MODE", "SET_SEGMENT_MODE", "GET_PAGE_INFO",
    "GET_SEGMENT_INFO", "GET_PAG_PROCESSOR_INFO", "GET_CAL_PAGE", "SET_CAL_PAGE",
    "MODIFY_BITS", "SHORT_DOWNLOAD", "DOWNLOAD_MAX", "DOWNLOAD_NEXT",
    "DOWNLOAD", "USER_CMD", "TRANSPORT_LAYER_CMD", "BUILD_CHECKSUM",
    "SHORT_UPLOAD", "UPLOAD", "SET_MTA", "UNLOCK",
    "GET_SEED", "SET_REQUEST", "GET_ID", "GET_COMM_MODE_INFO",
    "SYNCH", "GET_STATUS", "DISCONNECT", "CONNECT"
  };
  if (command.empty()) {
    return;
  }
  for (size_t value = 0; value < command_list.size(); ++value) {
    if (command_list[value] == command) {
      constexpr size_t kOffset = 0xC4;
      optional_command_list_.emplace( static_cast<Command>(value + kOffset));
      break;;
    }
  }
}

void ProtocolLayer::SetOptionalCommandLevel1(const std::string& command) {
  // Note that the command value has an offset of 0xC4
  constexpr std::array<std::string_view,3> command_list1 = {
    "GET_VERSION", "SET_DAQ_PACKED_MODE", "GET_DAQ_PACKED_MODE"
  };
  // Offset 0xFC
  constexpr std::array<std::string_view,2> command_list2 = {
    "SW_DBG_COMMAND_SPACE", "POD_COMMAND_SPACE"
  };
  for (size_t value = 0; value < command_list1.size(); ++value) {
    if (command_list1[value] == command) {
      optional_command_level1_list_.emplace( static_cast<CommandLevel1>(value));
      return;
    }
  }
  for (size_t value = 0; value < command_list2.size(); ++value) {
    if (command_list2[value] == command) {
      constexpr size_t kOffset = 0xFC;
      optional_command_level1_list_.emplace(
        static_cast<CommandLevel1>(value + kOffset));
      return;
    }
  }
}

void ProtocolLayer::Reset() {
  version_ = 0;
  timers_.fill(0);
  max_cto_ = 0;
  max_dto_ = 0;
  byte_order_ = ByteOrder::BYTE_ORDER_MSB_LAST;
  address_granularity_ = AddressGranularity::BYTE;

  optional_command_list_.clear();
  optional_command_level1_list_.clear();
  communication_mode_.reset();
  seed_and_key_function_.clear();
  max_dto_stim_.reset();
  ecu_state_list_.clear();
}

}  // namespace a2l