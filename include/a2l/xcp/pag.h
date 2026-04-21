/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>

namespace a2l::xcp {
class Pag {
public:
private:
  uint8_t max_segemnts_ = 0;
  bool freeze_supported_ = false;
};

}


