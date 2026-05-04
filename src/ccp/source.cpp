/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2l/ccp/source.h"

namespace a2l::ccp {

void Source::Reset() {
  name_.clear();
  scaling_unit_ = 0;
  rate_ = 0;
  display_identifier_.clear();
  qp_blob_.reset();
}

} // a2l::ccp