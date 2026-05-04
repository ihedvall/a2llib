/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>
#include <string>

namespace a2l::ccp {

class DefinedPages {
public:
  void SetNumber(uint64_t number) {
    number_ = static_cast<uint16_t>(number);
  }
  [[nodiscard]] uint16_t GetNumber() const { return number_; }

  void SetName(std::string name) { name_ = std::move(name); }
  [[nodiscard]] const std::string& GetName() const { return name_; }

  void SetAddressExtension(uint64_t address_extension) {
    address_extension_ = static_cast<uint16_t>(address_extension);
  }
  [[nodiscard]] uint16_t GetAddressExtension() const {
    return address_extension_;
  }

  void SetBaseAddress(uint64_t base_address) {
    base_address_ = static_cast<uint32_t>(base_address);
  }
  [[nodiscard]] uint32_t GetBaseAddress() const { return base_address_; }

  void SetLength(uint64_t length) {
    length_ = static_cast<uint32_t>(length);
  }
  [[nodiscard]] uint32_t GetLength() const { return length_; }

  void SetRam() { ram_ = true; }
  [[nodiscard]] bool GetRam() const { return ram_; }

  void SetRom() { rom_ = true; }
  [[nodiscard]] bool GetRom() const { return rom_; }

  void SetFlash() { flash_ = true; }
  [[nodiscard]] bool GetFlash() const { return flash_; }

  void SetEeprom() { eeprom_ = true; }
  [[nodiscard]] bool GetEeprom() const { return eeprom_; }

  void SetRamInitByEcu() { ram_init_by_ecu_ = true; }
  [[nodiscard]] bool GetRamInitByEcu() const { return ram_init_by_ecu_; }

  void SetRamInitByTool() { ram_init_by_tool_ = true; }
  [[nodiscard]] bool GetRamInitByTool() const { return ram_init_by_tool_; }

  void SetAutoFlashBack() { auto_flash_back_ = true; }
  [[nodiscard]] bool GetAutoFlashBack() const { return auto_flash_back_; }

  void SetFlashBack() { flash_back_ = true; }
  [[nodiscard]] bool GetFlashBack() const { return flash_back_; }

  void SetDefault() { default_ = true; }
  [[nodiscard]] bool GetDefault() const { return default_; }

  void Reset();
private:
  uint16_t number_ = 0;
  std::string name_;
  uint16_t address_extension_ = 0;
  uint32_t base_address_ = 0;
  uint32_t length_ = 0;
  bool ram_ = false;
  bool rom_ = false;
  bool flash_ = false;
  bool eeprom_ = false;
  bool ram_init_by_ecu_ = false;
  bool ram_init_by_tool_ = false;
  bool auto_flash_back_ = false;
  bool flash_back_ = false;
  bool default_ = false;
};
}
