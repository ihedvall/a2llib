/*
* Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#include "a2l/xcp/memoryaccess.h"

#include <array>
#include <string_view>

namespace a2l::xcp {

void MemoryAccess::SetReadAccess(const std::string& access) {
  constexpr std::array<std::string_view,2> access_list= {
    "READ_ACCESS_NOT_ALLOWED", "READ_ACCESS_ALLOWED"
  };
  for (size_t value = 0; value < access_list.size(); ++value) {
    if (access == access_list[value]) {
      read_access_ = static_cast<ReadAccess>(value);
      break;
    }
  }
}

void MemoryAccess::SetWriteAccess(const std::string& access) {
  constexpr std::array<std::string_view,2> access_list= {
    "WRITE_ACCESS_NOT_ALLOWED", "WRITE_ACCESS_ALLOWED"
  };
  for (size_t value = 0; value < access_list.size(); ++value) {
    if (access == access_list[value]) {
      write_access_ = static_cast<WriteAccess>(value);
      break;
    }
  }
}

}
