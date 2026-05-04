/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2l/ccp/qpblob.h"

namespace a2l::ccp {
void QpBlob::Reset() {
  number_ = 0;
  length_.reset();
  can_id_variable_ = false;
  can_id_fixed_.reset();
  raster_list_.clear();
  exclusive_list_.clear();
  reduction_allowed_ = false;
  first_pid_.reset();
}
} // a2l::ccp