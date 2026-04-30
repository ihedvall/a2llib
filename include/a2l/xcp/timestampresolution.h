/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
#pragma once

#include <cstdint>
#include <string>

namespace a2l::xcp {

enum class TimestampResolution : uint8_t {
  UNIT_1NS = 0,
  UNIT_10NS = 1,
  UNIT_100NS = 2,
  UNIT_1US = 3,
  UNIT_10US = 4,
  UNIT_100US = 5,
  UNIT_1MS = 6,
  UNIT_10MS = 7,
  UNIT_100MS = 8,
  UNIT_1S = 9,
  UNIT_1PS = 10,
  UNIT_10PS = 11,
};

TimestampResolution StringToTimestampResolution(
          const std::string& resolution);
}

