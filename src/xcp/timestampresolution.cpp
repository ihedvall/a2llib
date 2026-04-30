/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#include <array>
#include <string_view>

#include "a2l/xcp/timestampresolution.h"

namespace a2l::xcp {

TimestampResolution StringToTimestampResolution(
              const std::string& resolution) {
  constexpr std::array<std::string_view,12> resolution_list = {
    "UNIT_1NS", "UNIT_10NS", "UNIT_100NS",
    "UNIT_1US", "UNIT_10US", "UNIT_100US",
    "UNIT_1MS", "UNIT_10MS", "UNIT_100MS",
    "UNIT_1S", "UNIT_1PS", "UNIT_10PS"
  };
  for (size_t res = 0; res < resolution_list.size(); ++res) {
    if (resolution_list[res] == resolution) {
      return static_cast<TimestampResolution>(res);
    }
  }
  return TimestampResolution::UNIT_1MS;
}


}  // namespace a2l::xcp