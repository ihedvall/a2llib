/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>


namespace a2l::ccp {

class AddressMapping {
 public:
  void SetFromAddress(uint64_t address) {
    from_address_ = static_cast<uint32_t>(address);
  }
  [[nodiscard]] uint32_t GetFromAddress() const { return from_address_; }

  void SetToAddress(uint64_t address) {
    to_address_ = static_cast<uint32_t>(address);
  }
  [[nodiscard]] uint32_t GetToAddress() const { return to_address_; }

  void SetLength(uint64_t length) {
    length_ = static_cast<uint32_t>(length);
  }
  [[nodiscard]] uint32_t GetLength() const { return length_; }

 private:
  uint32_t from_address_ = 0;
  uint32_t to_address_ = 0;
  uint32_t length_ = 0;
};

}  // namespace a2l::ccp


