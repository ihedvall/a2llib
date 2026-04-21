/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>
#include <optional>

namespace a2l::xcp {

enum class XcpEcuAccessType : uint8_t {
  ECU_ACCESS_NOT_ALLOWED = 0,
  ECU_ACCESS_WITHOUT_XCP_ONLY = 1,
  ECU_ACCESS_WITH_XCP_ONLY = 2,
  ECU_ACCESS_DONT_CARE = 3,
};

enum class XcpReadAccessType : uint8_t {
  XCP_READ_ACCESS_NOT_ALLOWED = 0,
  XCP_READ_ACCESS_WITHOUT_ECU_ONLY = 1,
  XCP_READ_ACCESS_WITH_ECU_ONLY = 2,
  XCP_READ_ACCESS_DONT_CARE = 3,
};
enum class XcpWriteAccessType : uint8_t {
  XCP_WRITE_ACCESS_NOT_ALLOWED = 0,
  XCP_WRITE_ACCESS_WITHOUT_ECU_ONLY = 1,
  XCP_WRITE_ACCESS_WITH_ECU_ONLY = 2,
  XCP_WRITE_ACCESS_DONT_CARE = 3,
};

class Page {
public:
private:
  uint8_t number_ = 0;
  XcpEcuAccessType access_type_ = XcpEcuAccessType::ECU_ACCESS_NOT_ALLOWED;
  XcpReadAccessType read_access_type_ =
      XcpReadAccessType::XCP_READ_ACCESS_NOT_ALLOWED;
  XcpWriteAccessType write_access_type_ =
      XcpWriteAccessType::XCP_WRITE_ACCESS_NOT_ALLOWED;
  std::optional<uint8_t> init_segment_;
};

}


