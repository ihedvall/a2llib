/*
* Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#include "a2l/xcp/segment.h"

#include <array>
#include <string_view>

namespace a2l::xcp {

void Checksum::SetType(const std::string& checksum_type) {
  constexpr std::array<std::string_view, 9> kTypeList = {
    "XCP_ADD_11",
    "XCP_ADD_12",
    "XCP_ADD_14",
    "XCP_ADD_22",
    "XCP_ADD_24",
    "XCP_ADD_44",
    "XCP_CRC_16",
    "XCP_CRC_16_CITT",
    "XCP_CRC_32",
  };
  if (checksum_type == "XCP_USER_DEFINED") {
    type = ChecksumType::XCP_USER_DEFINED;
    return;
  }
  for (size_t index = 0; index < kTypeList.size(); ++index) {
    if (checksum_type == kTypeList[index]) {
      constexpr size_t kOffset = 1;
      type = static_cast<ChecksumType>(kOffset + index);
      break;
    }
  }
}

void Checksum::Reset() {
  type = ChecksumType::XCP_ADD_11;
  max_block_size.reset();
  external_function.clear();
  mta_block_size_align.reset();
}

void Segment::Reset() {
  number_ = 0;
  number_of_pages_ = 0;
  address_extension_ = 0;
  compression_method_= 0;
  encryption_method_ = 0;
  checksum_.reset();
  default_page_number_.reset();
  page_list_.clear();
  address_mapping_list_.clear();
  pgm_verify_.reset();
}

}  // namespace a2l::xcp