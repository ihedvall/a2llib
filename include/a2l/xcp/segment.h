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

enum class ChecksumType : uint8_t {
  XCP_ADD_11  = 1,
  XCP_ADD_12  = 2,
  XCP_ADD_14  = 3,
  XCP_ADD_22  = 4,
  XCP_ADD_24  = 5,
  XCP_ADD_44  = 6,
  XCP_CRC_16  = 7,
  XCP_CRC_16_CITT  = 8,
  XCP_CRC_32  = 9,
  XCP_USER_DEFINED  = 0xFF,
};

struct Checksum {
  ChecksumType type = ChecksumType::XCP_ADD_11;
  std::optional<uint32_t> max_block_size;
  std::string external_function;
  std::optional<uint16_t> mta_block_size_align;

  void SetType(const std::string& checksum_type);
  void Reset();
};

struct AddressMapping {
  uint32_t source_address = 0;
  uint32_t destination_address = 0;
  uint32_t length = 0;
};

using AddressMappingList = std::vector<AddressMapping>;
using PageList = std::vector<Page>;

class Segment {
public:
  void SetNumber(uint64_t number) {
    number_ = static_cast<uint8_t>(number);
  }
  [[nodiscard]] uint8_t GetNumber() const { return number_; }

  void SetNumberOfPages(uint64_t number_of_pages) {
    number_of_pages_ = static_cast<uint8_t>(number_of_pages);
  }
  [[nodiscard]] uint8_t GetNumberOfPages() const { return number_of_pages_; }

  void SetAddressExtension(uint64_t address_extension) {
    address_extension_ = static_cast<uint8_t>(address_extension);
  }
  [[nodiscard]] uint8_t GetAddressExtension() const { return address_extension_; }

  void SetCompressionMethod(uint64_t compression_method) {
    compression_method_ = static_cast<uint8_t>(compression_method);
  }
  [[nodiscard]] uint8_t GetCompressionMethod() const { return compression_method_; }

  void SetEncryptionMethod(uint64_t encryption_method) {
    encryption_method_ = static_cast<uint8_t>(encryption_method);
  }
  [[nodiscard]] uint8_t GetEncryptionMethod() const { return encryption_method_; }

  void SetChecksum(Checksum checksum) {
    checksum_ = std::move(checksum);
  }
  [[nodiscard]] const Checksum* GetChecksum() const {
    return checksum_.has_value() ? &checksum_.value() : nullptr;
  }

  void SetDefaultPageNumber(uint64_t default_page_number) {
    default_page_number_ = static_cast<uint8_t>(default_page_number);
  }
  [[nodiscard]] const std::optional<uint8_t>& GetDefaultPageNumber() const {
    return default_page_number_;
  }

  void AddPage(Page page) {
    page_list_.emplace_back(std::move(page));
  }
  [[nodiscard]] const PageList& GetPages() const {
    return page_list_;
  }

  void AddAddressMapping(AddressMapping address_mapping) {
    address_mapping_list_.emplace_back(std::move(address_mapping));
  }
  [[nodiscard]] const AddressMappingList& GetAddressMappings() const {
    return address_mapping_list_;
  }

  void SetPgmVerify(uint32_t pgm_verify) {
    pgm_verify_ = pgm_verify;
  }
  [[nodiscard]] const std::optional<uint32_t>& GetPgmVerify() const {
    return pgm_verify_;
  }

  void Reset();
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
  std::optional<uint32_t> pgm_verify_;
};

}

