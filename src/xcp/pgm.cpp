/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#include "a2l/xcp/pgm.h"

#include <array>
#include <string_view>

namespace a2l::xcp {

void Pgm::SetType(const std::string& type) {
  constexpr std::array<std::string_view, 3> kTypeList = {
    "PGM_MODE_ABSOLUTE",
    "PGM_MODE_FUNCTIONAL",
    "PGM_MODE_ABSOLUTE_AND_FUNCTIONAL"
  };
  for (size_t index = 0; index < kTypeList.size(); ++index) {
    if (type == kTypeList[index]) {
      constexpr size_t kOffset = 1;
      type_ = static_cast<PgmType>(kOffset + index);
      break;;
    }
  }
}

void Pgm::Reset() {
  type_ = PgmType::PGM_MODE_ABSOLUTE;
  max_sectors_ = 0;
  max_cto_pgm_ = 0;
  sector_list_.clear();
  communication_mode_supported_.reset();
}

}  // namespace a2l::xcp
