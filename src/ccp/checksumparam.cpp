/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2l/ccp/checksumparam.h"

#include <array>
#include <string_view>
namespace a2l::ccp {
void ChecksumParam::SetCalculation(const std::string& calculation) {
  constexpr std::array<std::string_view, 2> kTypeList = {
    "ACTIVE_PAGE",
    "BIT_OR_WITH_OPT_PAGE"
  };

  for (size_t index = 0; index < kTypeList.size(); index++) {
    if (calculation == kTypeList[index]) {
      calculation_ = static_cast<ChecksumCalculation>(index);
      break;
    }
  }

}
} // a2l::ccp