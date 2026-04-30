/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#include "a2l/xcp/page.h"

#include <array>
#include <string_view>

namespace a2l::xcp {

void Page::SetEcuAccessType(const std::string& type) {
  constexpr std::array<std::string_view, 4> kTypeList = {
    "ECU_ACCESS_NOT_ALLOWED",
    "ECU_ACCESS_WITHOUT_XCP_ONLY",
    "ECU_ACCESS_WITH_XCP_ONLY",
    "ECU_ACCESS_DONT_CARE"
  };
  for (size_t index = 0; index < kTypeList.size(); ++index) {
    if (type == kTypeList[index]) {
      ecu_access_type_ = static_cast<EcuAccessType>(index);
      break;
    }
  }
}

void Page::SetReadAccessType(const std::string& type) {
  constexpr std::array<std::string_view, 4> kTypeList = {
    "XCP_READ_ACCESS_NOT_ALLOWED",
    "XCP_READ_ACCESS_WITHOUT_ECU_ONLY",
    "XCP_READ_ACCESS_WITH_ECU_ONLY",
    "XCP_READ_ACCESS_DONT_CARE"
  };
  for (size_t index = 0; index < kTypeList.size(); ++index) {
    if (type == kTypeList[index]) {
      read_access_type_ = static_cast<ReadAccessType>(index);
      break;
    }
  }
}

void Page::SetWriteAccessType(const std::string& type) {
  constexpr std::array<std::string_view, 4> kTypeList = {
    "XCP_WRITE_ACCESS_NOT_ALLOWED",
    "XCP_WRITE_ACCESS_WITHOUT_ECU_ONLY",
    "XCP_WRITE_ACCESS_WITH_ECU_ONLY",
    "XCP_WRITE_ACCESS_DONT_CARE"
  };
  for (size_t index = 0; index < kTypeList.size(); ++index) {
    if (type == kTypeList[index]) {
      write_access_type_ = static_cast<WriteAccessType>(index);
      break;
    }
  }
}

void Page::Reset() {
  number_ = 0;
  ecu_access_type_ = EcuAccessType::ECU_ACCESS_NOT_ALLOWED;
  read_access_type_ = ReadAccessType::XCP_READ_ACCESS_NOT_ALLOWED;
  write_access_type_ = WriteAccessType::XCP_WRITE_ACCESS_NOT_ALLOWED;
  init_segment_.reset();
}

}  // namespace a2l::xcp