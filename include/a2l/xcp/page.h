/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>
#include <optional>
#include <string>

namespace a2l::xcp {

enum class EcuAccessType : uint8_t {
  ECU_ACCESS_NOT_ALLOWED = 0,
  ECU_ACCESS_WITHOUT_XCP_ONLY = 1,
  ECU_ACCESS_WITH_XCP_ONLY = 2,
  ECU_ACCESS_DONT_CARE = 3,
};

enum class ReadAccessType : uint8_t {
  XCP_READ_ACCESS_NOT_ALLOWED = 0,
  XCP_READ_ACCESS_WITHOUT_ECU_ONLY = 1,
  XCP_READ_ACCESS_WITH_ECU_ONLY = 2,
  XCP_READ_ACCESS_DONT_CARE = 3,
};
enum class WriteAccessType : uint8_t {
  XCP_WRITE_ACCESS_NOT_ALLOWED = 0,
  XCP_WRITE_ACCESS_WITHOUT_ECU_ONLY = 1,
  XCP_WRITE_ACCESS_WITH_ECU_ONLY = 2,
  XCP_WRITE_ACCESS_DONT_CARE = 3,
};

class Page {
public:
  void SetNumber(uint8_t number) { number_ = number; }
  [[nodiscard]] uint8_t GetNumber() const { return number_; }

  void SetEcuAccessType(const std::string& type);
  [[nodiscard]] EcuAccessType GetEcuAccessType() const { return ecu_access_type_; }

  void SetReadAccessType(const std::string& type);
  [[nodiscard]] ReadAccessType GetReadAccessType() const { return read_access_type_; }

  void SetWriteAccessType(const std::string& type);
  [[nodiscard]] WriteAccessType GetWriteAccessType() const { return write_access_type_; }

  void SetInitSegment(uint64_t segment) {
    init_segment_ = static_cast<uint8_t>(segment);
  }
  [[nodiscard]] std::optional<uint8_t> GetInitSegment() const {
    return init_segment_;
  }

  void Reset();
private:
  uint8_t number_ = 0;
  EcuAccessType ecu_access_type_ = EcuAccessType::ECU_ACCESS_NOT_ALLOWED;
  ReadAccessType read_access_type_ =
      ReadAccessType::XCP_READ_ACCESS_NOT_ALLOWED;
  WriteAccessType write_access_type_ =
      WriteAccessType::XCP_WRITE_ACCESS_NOT_ALLOWED;
  std::optional<uint8_t> init_segment_;
};

}


