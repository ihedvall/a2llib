/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>

#include "a2l/xcp/xcptimestampresolution.h"

namespace a2l::xcp {

enum class XcpTimestampSize : uint8_t {
  NO_TIMESTAMP = 0,
  SIZE_BYTE = 1,
  SIZE_WORD = 2,
  SIZE_DWORD = 4,
};

class Timestamp {
public:
private:
  uint16_t ticks_ = 0;
  XcpTimestampSize size_ = XcpTimestampSize::NO_TIMESTAMP;
  XcpTimestampResolution resolution_ = XcpTimestampResolution::UNIT_1MS;
  bool fixed_ = false;
};

}

