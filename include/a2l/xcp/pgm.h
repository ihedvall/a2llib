/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>
#include <optional>
#include <string>
#include <vector>

#include "a2l/xcp/communicationmode.h"

namespace a2l::xcp {

enum class PgmType : uint8_t {
  PGM_MODE_ABSOLUTE = 1,
  PGM_MODE_FUNCTIONAL = 2,
  PGM_MODE_ABSOLUTE_AND_FUNCTIONAL = 3,
};

struct Sector {
  std::string name;
  uint8_t number = 0;
  uint32_t address = 0;
  uint32_t length = 0;
  uint8_t clear_sequence_number = 0;
  uint8_t program_sequence_number = 0;
  uint8_t program_method = 0;
};


using SectorList = std::vector<Sector>;

class Pgm {
public:
  void SetType(const std::string& type);
  [[nodiscard]] PgmType GetType() const { return type_; }

  void SetMaxSectors(uint64_t max_sectors) {
    max_sectors_ = static_cast<uint8_t>(max_sectors);
  }
  [[nodiscard]] uint8_t GetMaxSectors() const { return max_sectors_; }

  void SetMaxCtoPgm(uint64_t max_cto_pgm) {
    max_cto_pgm_ = static_cast<uint8_t>(max_cto_pgm);
  }
  [[nodiscard]] uint8_t GetMaxCtoPgm() const { return max_cto_pgm_; }

  void AddSector(Sector sector) {
    sector_list_.emplace_back(std::move(sector));
  }
  [[nodiscard]] const SectorList& GetSectorList() const { return sector_list_; }

  void SetCommunicationModeSupported(CommunicationMode communication_mode) {
    communication_mode_supported_ = std::move(communication_mode);
  }
  [[nodiscard]] const CommunicationMode* GetCommunicationModeSupported() const {
    return communication_mode_supported_.has_value() ?
      &communication_mode_supported_.value() : nullptr;
  }

  void Reset();
private:
  PgmType type_ = PgmType::PGM_MODE_ABSOLUTE;
  uint8_t max_sectors_ = 0;
  uint8_t max_cto_pgm_ = 0;
  SectorList sector_list_;
  std::optional<CommunicationMode> communication_mode_supported_;
};

}


