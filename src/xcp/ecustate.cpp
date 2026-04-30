/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#include <array>
#include <string_view>

#include "a2l/xcp/ecustate.h"

namespace a2l::xcp {

void EcuState::SetCalPagResource(const std::string& resource) {
  constexpr std::array<std::string_view,3> resource_list= {
    "NOT_ACTIVE", "ACTIVE", "GETTER_ONLY"
  };
  for (size_t value = 0; value < resource_list.size(); ++value) {
    if (resource == resource_list[value]) {
      cal_pag_resource_ = static_cast<CalPagResource>(value);
      break;
    }
  }
}

void EcuState::SetDaqResource(const std::string& resource) {
  constexpr std::array<std::string_view,2> resource_list= {
    "NOT_ACTIVE", "ACTIVE"
  };
  for (size_t value = 0; value < resource_list.size(); ++value) {
    if (resource == resource_list[value]) {
      daq_resource_ = static_cast<DaqResource>(value);
      break;
    }
  }
}

void EcuState::SetPgmResource(const std::string& resource) {
  constexpr std::array<std::string_view,2> resource_list= {
    "NOT_ACTIVE", "ACTIVE"
  };
  for (size_t value = 0; value < resource_list.size(); ++value) {
    if (resource == resource_list[value]) {
      pgm_resource_ = static_cast<PgmResource>(value);
      break;
    }
  }
}

void EcuState::SetStimResource(const std::string& resource) {
  constexpr std::array<std::string_view,2> resource_list= {
    "NOT_ACTIVE", "ACTIVE"
  };
  for (size_t value = 0; value < resource_list.size(); ++value) {
    if (resource == resource_list[value]) {
      stim_resource_ = static_cast<StimResource>(value);
      break;
    }
  }
}

}  // namespace a2l::xcp
