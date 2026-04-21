/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>
#include <string>

namespace a2l::xcp {

enum class XcpReadAccess {
  READ_ACCESS_NOT_ALLOWED = 0,
  READ_ACCESS_ALLOWED = 1,
};

enum class XcpWriteAccess {
  WRITE_ACCESS_NOT_ALLOWED = 0,
  WRITE_ACCESS_ALLOWED = 1,
};

class MemoryAccess {
public:
  void Segment(uint8_t segment) { segment_ = segment; }
  [[nodiscard]] uint8_t Segment() const { return segment_; }

  void Page(uint8_t page) { page_ = page; }
  [[nodiscard]] uint8_t Page() const { return page_; }

  void ReadAccess(const std::string& access);
  [[nodiscard]] XcpReadAccess ReadAccess() const { return read_access_; }

  void WriteAccess(const std::string& access);
  [[nodiscard]] XcpWriteAccess WriteAccess() const { return write_access_; }


private:
  uint8_t segment_ = 0;
  uint8_t page_ = 0;
  XcpReadAccess read_access_ = XcpReadAccess::READ_ACCESS_NOT_ALLOWED;
  XcpWriteAccess write_access_ = XcpWriteAccess::WRITE_ACCESS_NOT_ALLOWED;
};


}  // namespace a2l::xcp
