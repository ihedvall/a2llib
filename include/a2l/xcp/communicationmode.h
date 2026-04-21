/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once
#include <cstdint>

namespace a2l::xcp {

class CommunicationMode {
public:
  void SlaveModeSupported(bool supported) { slave_mode_supported_ = supported; }
  [[nodiscard]] bool SlaveModeSupported() const { return slave_mode_supported_; }

  void MasterModeSupported(bool supported) { master_mode_supported_ = supported; }
  [[nodiscard]] bool MasterModeSupported() const { return master_mode_supported_; }

  void MaxBsPgm(uint8_t max_bs) { max_bs_pgm_ = max_bs; }
  [[nodiscard]] uint8_t MaxBsPgm() const { return max_bs_pgm_; }

  void MinStPgm(uint8_t min_st) { min_st_pgm_ = min_st; }
  [[nodiscard]] uint8_t MinStPgm() const { return min_st_pgm_; }

  void InterleavedSupported(bool supported) { interleaved_supported_ = supported; }

  void QueueSizePgm(uint8_t size) { queue_size_pgm_ = size; }
  [[nodiscard]] uint8_t QueueSizePgm() const { return queue_size_pgm_; }

private:
  bool slave_mode_supported_ = false;
  bool master_mode_supported_ = false;
  uint8_t max_bs_pgm_ = 0;
  uint8_t min_st_pgm_ = 0;
  bool interleaved_supported_ = false;
  uint8_t queue_size_pgm_ = 0;
};

}



