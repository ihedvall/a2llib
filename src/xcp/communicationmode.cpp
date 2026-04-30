/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#include "a2l/xcp/communicationmode.h"

namespace a2l::xcp {
void CommunicationMode::Reset() {
  slave_mode_supported_ = false;
  master_mode_supported_ = false;
  max_bs_pgm_ = 0;
  min_st_pgm_ = 0;
  interleaved_supported_ = false;
  queue_size_ = 0;
}

}  // namespace a2l::xcp