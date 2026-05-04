/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>
#include <vector>
namespace a2l::ccp {

class KpBlob {
public:
  void SetAddressExtension(uint64_t addr_ext) {
    address_extension_ = static_cast<uint16_t>(addr_ext);
  }
  [[nodiscard]] uint16_t GetAddressExtension() const {
    return address_extension_;
  }

  void SetBaseAddress(uint64_t base_addr) {
    base_address_ = static_cast<uint32_t>(base_addr);
  }
  [[nodiscard]] uint32_t GetBaseAddress() const { return base_address_; }

  void SetNofBytes(uint64_t nof_bytes) {
    nof_bytes_ = static_cast<uint32_t>(nof_bytes);
  }
  [[nodiscard]] uint32_t GetNofBytes() const { return nof_bytes_; }

  void SetRaster(std::vector<uint8_t> raster) { raster_ = std::move(raster); }
  [[nodiscard]] const std::vector<uint8_t>& GetRaster() const {
    return raster_;
  }

private:
  uint16_t address_extension_ = 0;
  uint32_t base_address_ = 0;
  uint32_t nof_bytes_ = 0;
  std::vector<uint8_t> raster_;
};

}  // namespace a2l


