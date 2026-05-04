/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>
#include <optional>
#include <vector>

namespace a2l::ccp {

class QpBlob {
public:
  void SetNumber(uint64_t number) {
    number_ = static_cast<uint16_t>(number);
  }
  [[nodiscard]] uint16_t GetNumber() const { return number_; }

  void SetLength(uint64_t length) {
    length_ = static_cast<uint16_t>(length);
  }
  [[nodiscard]] std::optional<uint16_t> GetLength() const { return length_; }

  void SetCanIdVariable() { can_id_variable_ = true;}
  [[nodiscard]] bool GetCanIdVariable() const { return can_id_variable_; }

  void SetCanIdFixed(uint64_t can_id_fixed) {
    can_id_fixed_ = static_cast<uint32_t>(can_id_fixed);
  }
  [[nodiscard]] std::optional<uint32_t> GetCanIdFixed() const {
    return can_id_fixed_;
  }

  void AddRaster(uint8_t raster) {
    raster_list_.push_back(raster);
  }
  [[nodiscard]] const std::vector<uint8_t>& GetRasterList() const {
    return raster_list_;
  }

  void AddExclusive(int64_t exclusive) {
    exclusive_list_.push_back(static_cast<int16_t>(exclusive));
  }
  [[nodiscard]] const std::vector<int16_t>& GetExclusiveList() const {
    return exclusive_list_;
  }

  void SetReductionAllowed() { reduction_allowed_ = true; }
  [[nodiscard]] bool GetReductionAllowed() const { return reduction_allowed_; }

  void SetFirstPid(uint64_t first_pid) {
    first_pid_ = static_cast<uint8_t>(first_pid);
  }
  [[nodiscard]] std::optional<uint8_t> GetFirstPid() const {
    return first_pid_;
  }

  void Reset();

private:
  uint16_t number_ = 0;
  std::optional<uint16_t> length_;
  bool can_id_variable_ = false;
  std::optional<uint32_t> can_id_fixed_;
  std::vector<uint8_t> raster_list_;
  std::vector<int16_t> exclusive_list_;
  bool reduction_allowed_ = false;
  std::optional<uint8_t> first_pid_;
};

}  // namespace a2l::ccp


