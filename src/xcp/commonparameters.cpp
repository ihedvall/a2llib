/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#include "a2l/xcp/commonparameters.h"

namespace a2l::xcp {

void CommonParameters::Reset() {
  protocol_layer_.reset();
  time_correlation_.reset();;
  segment_.reset();
  daq_.reset();
  pag_.reset();
  pgm_.reset();
  daq_event_.reset();
}

}