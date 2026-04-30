/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>
#include <string>
#include <optional>

#include "a2l/xcp/protocol.h"

namespace a2l::xcp {

enum class SxiParity : uint8_t {
  PARITY_NONE = 0,
  PARITY_ODD = 1,
  PARITY_EVEN = 2
};

enum class SxiStopBit : uint8_t {
  ONE_STOP_BIT = 1,
  TWO_STOP_BITS = 2
};

enum class SxiHeaderLength : uint8_t {
  HEADER_LEN_BYTE = 0,
  HEADER_LEN_CTR_BYTE = 1,
  HEADER_LEN_FILL_BYTE = 2,
  HEADER_LEN_WORD = 3,
  HEADER_LEN_CTR_WORD = 4,
  HEADER_LEN_FILL_WORD = 5
};

enum class SxiChecksum : uint8_t {
  NO_CHECKSUM = 0,
  CHECKSUM_BYTE = 1,
  CHECKSUM_WORD = 2
};

struct Framing {
  uint8_t sync = 0;
  uint8_t esc = 0;
  void Reset() {
    sync = 0;
    esc = 0;
  }
};

struct AsynchFullDuplexMode {
  SxiParity parity = SxiParity::PARITY_NONE;
  SxiStopBit stop_bit = SxiStopBit::ONE_STOP_BIT;
  std::optional<Framing> framing;

  void SetParity(const std::string& parity_text);
  void SetStopBits(const std::string& bits);
  void Reset() {
    parity = SxiParity::PARITY_NONE;
    stop_bit = SxiStopBit::ONE_STOP_BIT;
    framing.reset();
  }
};


class XcpOnSxi : public Protocol {
public:
  void SetVersion(uint64_t version) { version_ = static_cast<uint16_t>(version); }
  [[nodiscard]] uint16_t GetVersion() const { return version_; }
  [[nodiscard]] std::string GetVersionAsString() const;

  void SetBaudrate(uint64_t baudrate) {
    baudrate_ = static_cast<uint16_t>(baudrate);
  }
  [[nodiscard]] uint16_t GetBaudrate() const { return baudrate_; }

  void SetAsynchFullDuplexMode() {
    asynch_full_duplex_mode_ = current_asynch_;
    current_asynch_.Reset();
  }

  [[nodiscard]] const AsynchFullDuplexMode* GetAsynchFullDuplexMode() const {
    return asynch_full_duplex_mode_.has_value() ?
      &asynch_full_duplex_mode_.value() : nullptr;
  }

  void SetSynchFullDuplexModeByte() { synch_full_duplex_mode_byte_ = true; }
  [[nodiscard]] bool GetSynchFullDuplexModeByte() const {
    return synch_full_duplex_mode_byte_;
  }

  void SetSynchFullDuplexModeWord() { synch_full_duplex_mode_word_ = true; }
  [[nodiscard]] bool GetSynchFullDuplexModeWord() const {
    return synch_full_duplex_mode_word_;
  }

  void SetSynchFullDuplexModeDword() { synch_full_duplex_mode_dword_ = false; }
  [[nodiscard]] bool GetSynchFullDuplexModeDword() const {
    return synch_full_duplex_mode_dword_;
  }

  void SetSynchMasterSlaveModeByte() {synch_master_slave_mode_byte_ = true; }
  [[nodiscard]] bool GetSynchMasterSlaveModeByte() const {
    return synch_master_slave_mode_byte_;
  }

  void SetSynchMasterSlaveModeWord() {synch_master_slave_mode_word_ = true; }
  [[nodiscard]] bool GetSynchMasterSlaveModeWord() const {
    return synch_master_slave_mode_word_;
  }

  void SetSynchMasterSlaveModeDword() {synch_master_slave_mode_dword_ = true; }
  [[nodiscard]] bool GetSynchMasterSlaveModeDword() const {
    return synch_master_slave_mode_dword_;
  }

  void SetHeaderLength(const std::string& header_length);
  [[nodiscard]] SxiHeaderLength GetHeaderLength() const { return header_length_; }

  void SetChecksum(const std::string& checksum);
  [[nodiscard]] SxiChecksum GetChecksum() const { return checksum_; }

  Framing& GetFraming() { return current_framing_; }
  void SetFraming() {
    current_asynch_.framing = current_framing_;
    current_framing_.Reset();
  }

  AsynchFullDuplexMode& GetAsynch() { return current_asynch_; }

  void Reset() override;
private:
  uint16_t version_ = 0;
  uint16_t baudrate_ = 0;
  std::optional<AsynchFullDuplexMode> asynch_full_duplex_mode_;
  bool synch_full_duplex_mode_byte_ = false;
  bool synch_full_duplex_mode_word_ = false;
  bool synch_full_duplex_mode_dword_ = false;
  bool synch_master_slave_mode_byte_ = false;
  bool synch_master_slave_mode_word_ = false;
  bool synch_master_slave_mode_dword_ = false;
  SxiHeaderLength header_length_ = SxiHeaderLength::HEADER_LEN_BYTE;
  SxiChecksum checksum_ = SxiChecksum::NO_CHECKSUM;
  Framing current_framing_;
  AsynchFullDuplexMode current_asynch_;
};

}

