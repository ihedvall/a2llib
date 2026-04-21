/*
* Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>

#include "a2l/xcp/xcptimestampresolution.h"

namespace a2l::xcp {

enum class TimestampCharacteristicSize : uint8_t {
  SIZE_FOUR_BYTE = 4,
  SIZE_EIGHT_BYTE = 8,
};

class TimestampCharacteristic {
public:
private:
  uint16_t tickas_ = 0;
  XcpTimestampResolution resolution_ = XcpTimestampResolution::UNIT_1MS;
  TimestampCharacteristicSize size_ =
    TimestampCharacteristicSize::SIZE_FOUR_BYTE;
};
}

