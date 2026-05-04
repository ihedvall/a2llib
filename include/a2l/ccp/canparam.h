/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>
namespace a2l::ccp {

class CanParam {
public:
  void SetFrequency(uint64_t frequency) {
    frequency_ = static_cast<uint16_t>(frequency);
  }
  [[nodiscard]] uint16_t GetFrequency() const { return frequency_; }

  void SetBtr0(uint64_t btr0) {
    btr0_ = static_cast<uint8_t>(btr0);
  }
  [[nodiscard]] uint8_t GetBtr0() const { return btr0_; }

  void SetBtr1(uint64_t btr1) {
    btr1_ = static_cast<uint8_t>(btr1);
  }
  [[nodiscard]] uint8_t GetBtr1() const { return btr1_; }

private:
  uint16_t frequency_ = 0;
  uint8_t btr0_ = 0;
  uint8_t btr1_ = 0;
};

}  // namespace a2l::ccp


