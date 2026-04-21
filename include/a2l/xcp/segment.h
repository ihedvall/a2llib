/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>
#include <optional>
#include <string>
#include <vector>

#include "a2l/xcp/page.h"

namespace a2l::xcp {

enum class XcpChecksumType : uint8_t {
  XCP_ADD_11  = 1,
  XCP_ADD_12  = 2,
  XCP_ADD_14  = 3,
  XCP_ADD_22  = 4,
  XCP_ADD_24  = 5,
  XCP_ADD_44  = 6,
  XCP_CRC_16  = 7,
  XCP_CRC_16_CITT  = 8,
  XCP_CRC_32  = 9,
  XCP_USER_DEFINED  = 10,
};

struct Checksum {
  XcpChecksumType type_ = XcpChecksumType::XCP_ADD_11;
  std::optional<uint32_t> max_block_size_;
  std::optional<std::string> external_function_;
  std::optional<uint16_t> mta_block_size_align_;
};

struct AddressMapping {
  uint32_t source_address_ = 0;
  uint32_t destination_address_ = 0;
  uint32_t length_ = 0;
};

using AddressMappingList = std::vector<AddressMapping>;
using PageList = std::vector<Page>;

class Segment {
public:
private:
  uint8_t number_ = 0;
  uint8_t number_of_pages_  = 0;
  uint8_t address_extension_ = 0;
  uint8_t compression_method_ = 0;
  uint8_t encryption_method_ = 0;
  std::optional<Checksum> checksum_;
  std::optional<uint8_t> default_page_number_;
  PageList page_list_;
  AddressMappingList address_mapping_list_;
  std::optional<uint32_t> pgm_verify;
};

}

