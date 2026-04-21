/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>
#include <string>
#include <vector>


namespace a2l::xcp {

enum class XcpPgmType : uint8_t {
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
private:
  XcpPgmType type_ = XcpPgmType::PGM_MODE_ABSOLUTE;
  uint8_t max_sectors_ = 0;
  uint8_t max_cto_pgm_ = 0;
  SectorList sector_list_;
};

}


