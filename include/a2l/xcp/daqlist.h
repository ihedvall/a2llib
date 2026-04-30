/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>
#include <optional>
#include <vector>
#include <string>

namespace a2l::xcp {

enum class DaqListType : uint8_t {
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
  void SetNumber(uint16_t number) { number_ = number; }
  [[nodiscard]] uint16_t GetNumber() const { return number_; }

  void SetType(const std::string& type);
  [[nodiscard]] const std::optional<DaqListType>& GetType() const { return type_; }

  void SetMaxOdt(uint64_t max_odt) {
    max_odt_ = static_cast<uint8_t>(max_odt);
  }
  [[nodiscard]] const std::optional<uint8_t>& GetMaxOdt() const { return max_odt_; }

  void SetMaxOdtEntries(uint64_t max_odt_entries) {
    max_odt_entries_ = static_cast<uint8_t>(max_odt_entries);
  }
  [[nodiscard]] const std::optional<uint8_t>& GetMaxOdtEntries() const {
    return max_odt_entries_;
  }
  void SetFirstPid(uint64_t first_pid) {
    first_pid_ = static_cast<uint8_t>(first_pid);
  }
  [[nodiscard]] const std::optional<uint8_t>& GetFirstPid() const {
    return first_pid_;
  }

  void SetEventFixed(uint64_t event_fixed) {
    event_fixed_ = static_cast<uint16_t>(event_fixed);
  }
  [[nodiscard]] const std::optional<uint16_t>& GetEventFixed() const {
    return event_fixed_;
  }

  void SetDaqPackedModeSupported() { daq_packed_mode_supported_ = true; }
  [[nodiscard]] bool GetDaqPackedModeSupported() const {
    return daq_packed_mode_supported_;
  }

  void SetPredefinedList(OdtList predefined_list) {
    predefined_list_ = std::move(predefined_list);
  }
  [[nodiscard]] const OdtList& GetPredefinedList() const {
    return predefined_list_;
  }

  void Reset();
private:
  uint16_t number_ = 0;
  std::optional<DaqListType> type_;
  std::optional<uint8_t> max_odt_;
  std::optional<uint8_t> max_odt_entries_;
  std::optional<uint8_t> first_pid_;
  std::optional<uint16_t> event_fixed_;
  bool daq_packed_mode_supported_ = false;
  OdtList predefined_list_; // Predefined
};

}


