/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>

namespace a2l::xcp {
class Pag {
public:
  void SetMaxSegments(uint64_t max_segments) {
    max_segments_ = static_cast<uint8_t>(max_segments);
  }
  [[nodiscard]] uint8_t GetMaxSegments() const { return max_segments_; }

  void SetFreezeSupported() { freeze_supported_ = true; }
  [[nodiscard]] bool GetFreezeSupported() const { return freeze_supported_; }

  void Reset();
private:
  uint8_t max_segments_ = 0;
  bool freeze_supported_ = false;
};

}


