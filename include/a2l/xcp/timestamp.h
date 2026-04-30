/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>
#include <string>
#include "a2l/xcp/timestampresolution.h"

namespace a2l::xcp {

enum class TimestampSize : uint8_t {
  NO_TIMESTAMP = 0,
  SIZE_BYTE = 1,
  SIZE_WORD = 2,
  SIZE_DWORD = 4,
};

class Timestamp {
public:
  void SetTicks(uint64_t ticks) {
    ticks_ = static_cast<uint16_t>(ticks);
  }
  [[nodiscard]] uint16_t GetTicks() const { return ticks_; }

  void SetSize(const std::string& size);
  [[nodiscard]] TimestampSize GetSize() const { return size_; }

  void SetResolution(const std::string& resolution);
  [[nodiscard]] TimestampResolution GetResolution() const {
    return resolution_;
  }

  void SetFixed() { fixed_ = true; }
  [[nodiscard]] bool GetFixed() const { return fixed_; }

private:
  uint16_t ticks_ = 0;
  TimestampSize size_ = TimestampSize::NO_TIMESTAMP;
  TimestampResolution resolution_ = TimestampResolution::UNIT_1MS;
  bool fixed_ = false;
};

}

