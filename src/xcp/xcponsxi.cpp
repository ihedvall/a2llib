/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#include "a2l/xcp/xcponsxi.h"

#include <array>
#include <sstream>
#include <string_view>

#include "a2l/xcp/xcponusb.h"

namespace a2l::xcp {
void AsynchFullDuplexMode::SetParity(const std::string& parity_text) {
  constexpr std::array<std::string_view,3> kParityList = {
    "PARITY_NONE",
    "PARITY_ODD",
    "PARITY_EVEN"
  };
  for (size_t index = 0; index < kParityList.size(); ++index) {
    if (kParityList[index] == parity_text) {
      parity = static_cast<SxiParity>(index);
      break;
    }
  }
}

void AsynchFullDuplexMode::SetStopBits(const std::string& bits) {
  constexpr std::array<std::string_view,2> kStopBitList = {
    "ONE_STOP_BIT",
    "TWO_STOP_BITS"
  };
  for (size_t index = 0; index < kStopBitList.size(); ++index) {
    if (kStopBitList[index] == bits) {
      constexpr size_t kOffset = 1;
      stop_bit = static_cast<SxiStopBit>(kOffset + index);
      break;
    }
  }
}

std::string XcpOnSxi::GetVersionAsString() const {
  std::ostringstream temp;
  temp << version_ / 256 << "." << version_ % 256;
  return temp.str();
}

void XcpOnSxi::SetHeaderLength(const std::string& header_length) {
  constexpr std::array<std::string_view,6> kHeaderLengthList = {
    "HEADER_LEN_BYTE",
    "HEADER_LEN_CTR_BYTE",
    "HEADER_LEN_FILL_BYTE",
    "HEADER_LEN_WORD",
    "HEADER_LEN_CTR_WORD",
    "HEADER_LEN_FILL_WORD"
  };
  for (size_t index = 0; index < kHeaderLengthList.size(); ++index) {
    if (header_length == kHeaderLengthList[index]) {
      header_length_ = static_cast<SxiHeaderLength>(index);
      break;
    }
  }
}

void XcpOnSxi::SetChecksum(const std::string& checksum) {
  constexpr std::array<std::string_view,3> kChecksumList = {
    "NO_CHECKSUM",
    "CHECKSUM_BYTE",
    "CHECKSUM_WORD"
  };
  for (size_t index = 0; index < kChecksumList.size(); ++index) {
    if (checksum == kChecksumList[index]) {
      checksum_ = static_cast<SxiChecksum>(index);
      break;
    }
  }
}

void XcpOnSxi::Reset() {
  Protocol::Reset();
  version_ = 0;
  baudrate_ = 0;
  asynch_full_duplex_mode_.reset();
  synch_full_duplex_mode_byte_ = false;
  synch_full_duplex_mode_word_ = false;
  synch_full_duplex_mode_dword_ = false;
  synch_master_slave_mode_byte_ = false;
  synch_master_slave_mode_word_ = false;
  synch_master_slave_mode_dword_ = false;
  header_length_ = SxiHeaderLength::HEADER_LEN_BYTE;
  checksum_ = SxiChecksum::NO_CHECKSUM;
}

}  // namespace a2l::xcp