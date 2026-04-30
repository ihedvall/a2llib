/*
* Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#include "a2l/xcp/timestampcharacteristic.h"

namespace a2l::xcp {

void TimestampCharacteristic::SetResolution(const std::string& resolution) {
  resolution_ = StringToTimestampResolution(resolution);
}

void TimestampCharacteristic::SetSize(const std::string& size) {
  if (size == "SIZE_FOUR_BYTE") {
    size_ = TimestampCharacteristicSize::SIZE_FOUR_BYTE;
  } else if (size == "SIZE_EIGHT_BYTE") {
    size_ = TimestampCharacteristicSize::SIZE_EIGHT_BYTE;
  }
}

}  // namespace a2l::xcp