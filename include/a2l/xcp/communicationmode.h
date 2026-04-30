/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once
#include <cstdint>

namespace a2l::xcp {

class CommunicationMode {
public:
  void SetSlaveModeSupported() { slave_mode_supported_ = true; }
  [[nodiscard]] bool GetSlaveModeSupported() const { return slave_mode_supported_; }

  void SetMasterModeSupported() { master_mode_supported_ = true; }
  [[nodiscard]] bool GetMasterModeSupported() const { return master_mode_supported_; }

  void SetMaxBsPgm(uint64_t max_bs) {
    max_bs_pgm_ = static_cast<uint8_t>(max_bs);
  }
  [[nodiscard]] uint8_t GetMaxBsPgm() const { return max_bs_pgm_; }

  void SetMinStPgm(uint64_t min_st) {
    min_st_pgm_ = static_cast<uint8_t>(min_st);
  }
  [[nodiscard]] uint8_t GetMinStPgm() const { return min_st_pgm_; }

  void SetInterleavedSupported() { interleaved_supported_ = true; }
  [[nodiscard]] bool GetInterleavedSupported() const { return interleaved_supported_; }

  void SetQueueSize(uint64_t size) {
    queue_size_ = static_cast<uint8_t>(size);
  }
  [[nodiscard]] uint8_t GetQueueSize() const { return queue_size_; }

  void Reset();
private:
  bool slave_mode_supported_ = false;
  bool master_mode_supported_ = false;
  uint8_t max_bs_pgm_ = 0;
  uint8_t min_st_pgm_ = 0;
  bool interleaved_supported_ = false;
  uint8_t queue_size_ = 0;
};

}



