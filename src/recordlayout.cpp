/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2l/recordlayout.h"

namespace a2l {

void RecordLayout::AddReserved(const A2lDistOp& reserved) {
  reserved_list_.emplace_back(reserved);
}

} // end namespace a2l
