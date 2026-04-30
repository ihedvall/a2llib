/*
* Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#include "a2l/xcp/timestamp.h"

#include <array>
#include <string_view>

namespace a2l::xcp {

void Timestamp::SetSize(const std::string& size) {
  constexpr std::array<std::string_view, 5> kTypeList = {
    "NO_TIME_STAMP",
    "SIZE_BYTE",
    "SIZE_WORD",
    "",
    "SIZE_DWORD"
  };

  if (size.empty()) {
    return;
  }
  for (size_t index = 0; index < kTypeList.size(); ++index) {
    if (size == kTypeList[index]) {
      size_ = static_cast<TimestampSize>(index);
      break;
    }
  }
}

void Timestamp::SetResolution(const std::string& resolution) {
  resolution_ = StringToTimestampResolution(resolution);
}

}  // namespace a2l::xcp