/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <array>
#include <cstdint>
#include <set>
#include <string>
#include <vector>
#include <optional>

#include "a2l/xcp/communicationmode.h"
#include "a2l/xcp/ecustate.h"

namespace a2l::xcp {

enum class ProtocolTimer : uint16_t {
  T1 = 0,
  T2 = 1,
  T3 = 2,
  T4 = 3,
  T5 = 4,
  T6 = 5,
  T7 = 6,
};

enum class ByteOrder : uint8_t {
  BYTE_ORDER_MSB_LAST = 0,  ///< Big Endian
  BYTE_ORDER_MSB_FIRST = 1, ///< Little Endian
};

enum class AddressGranularity : uint8_t {
  BYTE = 1,
  WORD = 2,
  DWORD = 4,
};

enum class Command : uint8_t {
  CONNECT = 0xFF,
  DISCONNECT = 0xFE,
  GET_STATUS = 0xFD,
  SYNCH = 0xFC,
  GET_COMM_MODE_INFO = 0xFB,
  GET_ID = 0xFA,
  SET_REQUEST = 0xF9,
  GET_SEED = 0xF8,
  UNLOCK = 0xF7,
  SET_MTA = 0xF6,
  UPLOAD = 0xF5,
  SHORT_UPLOAD = 0xF4,
  BUILD_CHECKSUM = 0xF3,
  TRANSPORT_LAYER_CMD = 0xF2,
  USER_CMD = 0xF1,
  DOWNLOAD = 0xF0,
  DOWNLOAD_NEXT = 0xEF,
  DOWNLOAD_MAX = 0xEE,
  SHORT_DOWNLOAD = 0xED,
  MODIFY_BITS = 0xEC,
  SET_CAL_PAGE = 0xEB,
  GET_CAL_PAGE = 0xEA,
  GET_PAG_PROCESSOR_INFO = 0xE9,
  GET_SEGMENT_INFO = 0xE8,
  GET_PAGE_INFO = 0xE7,
  SET_SEGMENT_MODE = 0xE6,
  GET_SEGMENT_MODE = 0xE5,
  COPY_CAL_PAGE = 0xE4,
  CLEAR_DAQ_LIST = 0xE3,
  SET_DAQ_PTR = 0xE2,
  WRITE_DAQ = 0xE1,
  SET_DAQ_LIST_MODE = 0xE0,
  GET_DAQ_LIST_MODE = 0xDF,
  START_STOP_DAQ_LIST = 0xDE,
  START_STOP_SYNCH = 0xDD,
  GET_DAQ_CLOCK = 0xDC,
  READ_DAQ = 0xDB,
  GET_DAQ_PROCESSOR_INFO = 0xDA,
  GET_DAQ_RESOLUTION_INFO = 0xD9,
  GET_DAQ_LIST_INFO = 0xD8,
  GET_DAQ_EVENT_INFO = 0xD7,
  FREE_DAQ = 0xD6,
  ALLOC_DAQ = 0xD5,
  ALLOC_ODT = 0xD4,
  ALLOC_ODT_ENTRY = 0xD3,
  PROGRAM_START = 0xD2,
  PROGRAM_CLEAR = 0xD1,
  PROGRAM = 0xD0,
  PROGRAM_RESET = 0xCF,
  GET_PGM_PROCESSOR_INFO = 0xCE,
  GET_SECTOR_INFO = 0xCD,
  PROGRAM_PREPARE = 0xCC,
  PROGRAM_FORMAT = 0xCB,
  PROGRAM_NEXT = 0xCA,
  PROGRAM_MAX = 0xC9,
  PROGRAM_VERIFY = 0xC8,
  WRITE_DAQ_MULTIPLE = 0xC7,
  TIME_CORRELATION_PROPERTIES = 0xC6,
  DTO_CTR_PROPERTIES = 0xC5
};

enum class CommandLevel1 : uint8_t {
  GET_VERSION = 0x00,
  SET_DAQ_PACKED_MODE = 0x01,
  GET_DAQ_PACKED_MODE = 0x02,
  SW_DBG_COMMAND_SPACE = 0xFC,
  POD_COMMAND_SPACE = 0xFD
};


using OptionalCommandList = std::set<Command>;
using OptionalCommandLevel1List = std::set<CommandLevel1>;
using EcuStateList = std::vector<EcuState>;

class ProtocolLayer {
 public:
  ProtocolLayer() = default;
  ~ProtocolLayer() = default;

  void SetVersion(uint64_t version) {
    version_ = static_cast<uint16_t>(version);
  }
  [[nodiscard]] uint16_t GetVersion() const { return version_; }
  [[nodiscard]] std::string GetVersionAsString() const;

  void SetTimer(ProtocolTimer timer, uint64_t time_ms) {
    const size_t index = static_cast<size_t>(timer);
    if (index < timers_.size()) {
      timers_[static_cast<size_t>(timer)] = static_cast<uint16_t>(time_ms);
    }
  }
  [[nodiscard]] uint16_t GetTimer(ProtocolTimer timer) const {
    const size_t index = static_cast<size_t>(timer);
    return index < timers_.size() ? timers_[static_cast<size_t>(timer)] : 0;
  }

  void SetMaxCto(uint64_t max_cto) {
    max_cto_ = static_cast<uint8_t>(max_cto);
  }
  [[nodiscard]] uint8_t GetMaxCto() const { return max_cto_; }

  void SetMaxDto(uint64_t max_dto) {
    max_dto_ = static_cast<uint16_t>(max_dto);
  }
  [[nodiscard]] uint16_t GetMaxDto() const { return max_dto_; }

  void SetByteOrder(const std::string& order);
  [[nodiscard]] ByteOrder GetByteOrder() const { return byte_order_; }

  void SetAddressGranularity(const std::string& granularity);
  [[nodiscard]] AddressGranularity GetAddressGranularity() const {
    return address_granularity_;
  }

  void SetOptionalCommand(const std::string& command);
  [[nodiscard]] const OptionalCommandList& GetOptionalCommands() const {
    return optional_command_list_;
  }

  void SetOptionalCommandLevel1(const std::string& command);
  [[nodiscard]] const OptionalCommandLevel1List& GetOptionalCommandsLevel1() const {
    return optional_command_level1_list_;
  }

  void SetCommunicationMode(CommunicationMode mode) {
    communication_mode_ = std::move(mode);
  };
  [[nodiscard]] const CommunicationMode* GetCommunicationMode() const {
    return communication_mode_.has_value() ? &communication_mode_.value() : nullptr;
  }

  void SetSeedAndKeyFunction(std::string function) {
    seed_and_key_function_ = std::move(function);
  }
  [[nodiscard]] const std::string& GetSeedAndKeyFunction() const {
    return seed_and_key_function_;
  }

  void SetMaxDtoStim(uint64_t max_dto_stim) {
    max_dto_stim_ = static_cast<uint16_t>(max_dto_stim);
  }
  [[nodiscard]] const std::optional<uint16_t>& GetMaxDtoStim() const {
    return max_dto_stim_;
  }

  void SetEcuStates(std::vector<EcuState> ecu_states) {
    ecu_state_list_ = std::move(ecu_states);
  }
  [[nodiscard]] const EcuStateList& GetEcuStates() const {
    return ecu_state_list_;
  }

  void Reset();

 private:
  uint16_t version_ = 0x0100;
  std::array<uint16_t, 7> timers_ = {0, 0, 0, 0, 0, 0, 0};
  uint8_t max_cto_ = 0;
  uint16_t max_dto_ = 0;
  ByteOrder byte_order_ = ByteOrder::BYTE_ORDER_MSB_LAST;
  AddressGranularity address_granularity_ = AddressGranularity::BYTE;
  std::set<Command> optional_command_list_;
  std::set<CommandLevel1> optional_command_level1_list_;
  std::optional<CommunicationMode> communication_mode_;

  std::string seed_and_key_function_;
  std::optional<uint16_t> max_dto_stim_ = 0;
  EcuStateList ecu_state_list_;
};

}  // namespace a2l

