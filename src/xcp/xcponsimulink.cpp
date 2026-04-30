/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#include "a2l/xcp/xcponsimulink.h"

namespace a2l::xcp {
void XcpOnSimulink::Reset() {
  Protocol::Reset();
  model_name_.clear();
}
}  // namespace a2l::xcp