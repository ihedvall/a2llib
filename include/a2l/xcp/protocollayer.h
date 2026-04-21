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

#include "a2l/xcp/communicationmode.h"
#include "a2l/xcp/ecustate.h"

namespace a2l::xcp {

enum class XcpTimer : uint16_t {
  T1 = 0,
  T2 = 1,
  T3 = 2,
  T4 = 3,
  T5 = 4,
  T6 = 5,
  T7 = 6,
};

enum class XcpByteOrder : uint8_t {
  LittleEndian = 0,
  BigEndian = 1,
};

enum class XcpAddressGranularity : uint8_t {
  BYTE = 1,
  WORD = 2,
  DWORD = 4,
};

enum class XcpCommand : uint8_t {
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

enum class XcpCommandLevel1 : uint8_t {
  GET_VERSION = 0x00,
  SET_DAQ_PACKED_MODE = 0x01,
  GET_DAQ_PACKED_MODE = 0x02,
  SW_DBG_COMMAND_SPACE = 0xFC,
  POD_COMMAND_SPACE = 0xFD
};


using OptionalCommandList = std::set<XcpCommand>;
using OptionalCommandLevel1List = std::set<XcpCommandLevel1>;
using EcuStateList = std::vector<EcuState>;

class ProtocolLayer {
 public:
  ProtocolLayer() = default;
  ~ProtocolLayer() = default;

  void Version(uint16_t version) { version_ = version; }
  [[nodiscard]] uint16_t Version() const { return version_; }
  [[nodiscard]] std::string VersionAsString() const;

  void Timer(XcpTimer timer, uint16_t time_ms) {
    timers_[static_cast<size_t>(timer)] = time_ms;
  }
  [[nodiscard]] uint16_t Timer(XcpTimer timer) const {
    return timers_[static_cast<size_t>(timer)];
  }

  void MaxCto(uint8_t max_cto) { max_cto_ = max_cto; }
  [[nodiscard]] uint8_t MaxCto() const { return max_cto_; }

  void MaxDto(uint16_t max_dto) { max_dto_ = max_dto; }
  [[nodiscard]] uint16_t MaxDto() const { return max_dto_; }

  void ByteOrder(const std::string& order);
  [[nodiscard]] XcpByteOrder ByteOrder() const { return byte_order_; }

  void AddressGranularity(const std::string& granularity);
  [[nodiscard]] XcpAddressGranularity AddressGranularity() const {
    return address_granularity_;
  }

  void SetOptionalCommand(const std::string& command);
  [[nodiscard]] const OptionalCommandList& OptionalCommands() const {
    return optional_command_list_;
  }

  void SetOptionalCommandLevel1(const std::string& command);
  [[nodiscard]] const OptionalCommandLevel1List& OptionalCommandsLevel1() const {
    return optional_command_level1_list_;
  }

  void SlaveMode(bool slave_mode) {slave_mode_ = slave_mode; }
  [[nodiscard]] bool SlaveMode() const { return slave_mode_; }

  void MasterMode(bool master_mode) {master_mode_ = master_mode; }
  [[nodiscard]] bool MasterMode() const { return master_mode_; }

  void MaxBs(uint8_t max_bs) {max_bs_ = max_bs; }
  [[nodiscard]] uint8_t MaxBs() const { return max_bs_; }

  void MinSt(uint8_t min_st) {min_st_ = min_st; }
  [[nodiscard]] uint8_t MinSt() const { return min_st_; }

  void Interleaved(uint8_t interleaved) {interleaved_ = interleaved; }
  [[nodiscard]] uint8_t Interleaved() const { return interleaved_; }

  void SeedAndKeyFunction(std::string function) {
    seed_and_key_function_ = std::move(function);
  }
  [[nodiscard]] const std::string& SeedAndKeyFunction() const {
    return seed_and_key_function_;
  }

  void MaxDtoStim(uint16_t max_dto_stim) {max_dto_stim_ = max_dto_stim; }
  [[nodiscard]] uint16_t MaxDtoStim() const { return max_dto_stim_; }

  void EcuStates(std::vector<EcuState> ecu_states) {
    ecu_state_list_ = std::move(ecu_states);
  }
  [[nodiscard]] const EcuStateList& EcuStates() const {
    return ecu_state_list_;
  }

 private:
  uint16_t version_ = 0x0100;
  std::array<uint16_t, 7> timers_ = {0, 0, 0, 0, 0, 0, 0};
  uint8_t max_cto_ = 0;
  uint16_t max_dto_ = 0;
  XcpByteOrder byte_order_ = XcpByteOrder::LittleEndian;
  XcpAddressGranularity address_granularity_ = XcpAddressGranularity::BYTE;
  std::set<XcpCommand> optional_command_list_;
  std::set<XcpCommandLevel1> optional_command_level1_list_;
  bool slave_mode_ = false;
  bool master_mode_ = false;
  uint8_t max_bs_ = 0;
  uint8_t min_st_ = 0;
  uint8_t interleaved_ = 0;
  std::string seed_and_key_function_;
  uint16_t max_dto_stim_ = 0;
  EcuStateList ecu_state_list_;
  CommunicationMode communication_mode_;
  
};

}  // namespace a2l

