/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>
#include <optional>
#include <vector>
namespace a2l::xcp {

enum class XcpDaqListType : uint8_t {
  DAQ = 1,
  STIM = 2,
  DAQ_STIM = 3,
};

struct OdtEntry {
  uint8_t number = 0;
  uint64_t address = 0;
  uint8_t address_extension = 0;
  uint8_t size = 0;
  uint8_t bit_offset = 0;
};

using OdtEntryList = std::vector<OdtEntry>;

struct Odt {
  uint8_t number = 0;
  OdtEntryList odt_entry_list;
};

using OdtList = std::vector<Odt>;

class DaqList {
public:
  void Number(uint16_t number) { number_ = number; }
  [[nodiscard]] uint16_t Number() const { return number_; }
  void Type(XcpDaqListType type) { type_ = type; }
  [[nodiscard]] const std::optional<XcpDaqListType>& Type() const { return type_; }

  void MaxOdt(uint8_t max_odt) { max_odt_ = max_odt; }
  [[nodiscard]] const std::optional<uint8_t>& MaxOdt() const { return max_odt_; }

  void MaxOdtEntries(uint8_t max_odt_entries) {
    max_odt_entries_ = max_odt_entries;
  }
  [[nodiscard]] const std::optional<uint8_t>& MaxOdtEntries() const {
    return max_odt_entries_;
  }
private:
  uint16_t number_ = 0;
  std::optional<XcpDaqListType> type_;
  std::optional<uint8_t> max_odt_;
  std::optional<uint8_t> max_odt_entries_;
  std::optional<uint8_t> first_pid_;
  std::optional<uint8_t> event_fixed_;
  bool daq_packed_mode_supported_ = false;
  OdtList predefined_list_; // Predefined
};

}


