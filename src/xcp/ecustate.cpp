/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#include <array>
#include <string_view>

#include "a2l/xcp/ecustate.h"

namespace a2l::xcp {

void EcuState::CalPagResource(const std::string& resource) {
  constexpr std::array<std::string_view,3> resource_list= {
    "NOT_ACTIVE", "ACTIVE", "GETTER_ONLY"
  };
  for (size_t value = 0; value < resource_list.size(); ++value) {
    if (resource == resource_list[value]) {
      cal_pag_resource_ = static_cast<XcpCalPagResource>(value);
      return;
    }
  }
}

void EcuState::DaqResource(const std::string& resource) {
  constexpr std::array<std::string_view,2> resource_list= {
    "NOT_ACTIVE", "ACTIVE"
  };
  for (size_t value = 0; value < resource_list.size(); ++value) {
    if (resource == resource_list[value]) {
      daq_resource_ = static_cast<XcpDaqResource>(value);
      return;
    }
  }
}

void EcuState::PgmResource(const std::string& resource) {
  constexpr std::array<std::string_view,2> resource_list= {
    "NOT_ACTIVE", "ACTIVE"
  };
  for (size_t value = 0; value < resource_list.size(); ++value) {
    if (resource == resource_list[value]) {
      pgm_resource_ = static_cast<XcpPgmResource>(value);
      return;
    }
  }
}

void EcuState::StimResource(const std::string& resource) {
  constexpr std::array<std::string_view,2> resource_list= {
    "NOT_ACTIVE", "ACTIVE"
  };
  for (size_t value = 0; value < resource_list.size(); ++value) {
    if (resource == resource_list[value]) {
      stim_resource_ = static_cast<XcpStimResource>(value);
      return;
    }
  }
}

}  // namespace a2l::xcp
