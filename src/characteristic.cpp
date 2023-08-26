/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2l/characteristic.h"

namespace a2l {
void Characteristic::AddAxisDescr(std::unique_ptr<AxisDescr>& axis_descr) {
  axis_descr_list_.emplace_back( std::move(axis_descr));
}
} // end namespace a2l
