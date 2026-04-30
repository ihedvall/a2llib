/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>
#include <string>

namespace a2l::xcp {

enum class ReadAccess {
  READ_ACCESS_NOT_ALLOWED = 0,
  READ_ACCESS_ALLOWED = 1,
};

enum class WriteAccess {
  WRITE_ACCESS_NOT_ALLOWED = 0,
  WRITE_ACCESS_ALLOWED = 1,
};

class MemoryAccess {
public:
  void SetSegment(uint64_t segment) {
    segment_ = static_cast<uint8_t>(segment);
  }
  [[nodiscard]] uint8_t GetSegment() const { return segment_; }

  void SetPage(uint64_t page) {
    page_ = static_cast<uint8_t>(page);
  }
  [[nodiscard]] uint8_t GetPage() const { return page_; }

  void SetReadAccess(const std::string& access);
  [[nodiscard]] ReadAccess GetReadAccess() const { return read_access_; }

  void SetWriteAccess(const std::string& access);
  [[nodiscard]] WriteAccess GetWriteAccess() const { return write_access_; }

private:
  uint8_t segment_ = 0;
  uint8_t page_ = 0;
  ReadAccess read_access_ = ReadAccess::READ_ACCESS_NOT_ALLOWED;
  WriteAccess write_access_ = WriteAccess::WRITE_ACCESS_NOT_ALLOWED;
};


}  // namespace a2l::xcp
