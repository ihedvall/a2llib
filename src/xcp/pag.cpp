/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#include "a2l/xcp/pag.h"

namespace a2l::xcp {
void Pag::Reset() {
  max_segments_ = 0;
  freeze_supported_ = false;
}

}

