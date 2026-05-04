/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>
#include <string>
#include <optional>

namespace a2l::ccp {

enum class ChecksumCalculation : uint8_t {
  ACTIVE_PAGE = 0,
  BIT_OR_WITH_OPT_PAGE = 1
};

class ChecksumParam {
public:
  void SetType(uint64_t type) {
    type_ = static_cast<uint16_t>(type);
  }
  [[nodiscard]] uint16_t GetType() const { return type_; }

  void SetMaxBlockLength(uint64_t max_block_length) {
    max_block_length_ = static_cast<uint32_t>(max_block_length);
  }
  [[nodiscard]] uint32_t GetMaxBlockLength() const { return max_block_length_; }

  void SetCalculation(const std::string& calculation);
  [[nodiscard]] const std::optional<ChecksumCalculation>& GetCalculation() const {
    return calculation_;
  }

private:
  uint16_t type_ = 0;
  uint32_t max_block_length_ = 0;
  std::optional<ChecksumCalculation> calculation_;;
};

}  // namespace a2l::ccp


