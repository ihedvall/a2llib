/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2l/ccp/definedpages.h"

namespace a2l::ccp {

void DefinedPages::Reset() {
  number_ = 0;
  name_.clear();
  address_extension_ = 0;
  base_address_ = 0;
  length_ = 0;

  ram_ = false;
  rom_ = false;
  flash_ = false;
  eeprom_ = false;
  ram_init_by_ecu_ = false;
  ram_init_by_tool_ = false;
  auto_flash_back_ = false;
  flash_back_ = false;
  default_ = false;
}

}  // namespace a2l::ccp
