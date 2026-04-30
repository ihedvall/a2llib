/*
* Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>

#include "a2l/xcp/timestampresolution.h"

namespace a2l::xcp {

enum class TimestampCharacteristicSize : uint8_t {
  SIZE_FOUR_BYTE = 4,
  SIZE_EIGHT_BYTE = 8,
};

class TimestampCharacteristic {
public:
  void SetTicks(uint16_t ticks) { ticks_ = ticks; }
  [[nodiscard]] uint16_t GetTicks() const { return ticks_; }

  void SetResolution(const std::string& resolution);
  [[nodiscard]] TimestampResolution GetResolution() const {
    return resolution_;
  }

  void SetSize(const std::string& size);
  [[nodiscard]] TimestampCharacteristicSize GetSize() const { return size_; }
private:
  uint16_t ticks_ = 0;
  TimestampResolution resolution_ = TimestampResolution::UNIT_1MS;
  TimestampCharacteristicSize size_ =
    TimestampCharacteristicSize::SIZE_FOUR_BYTE;
};

}

