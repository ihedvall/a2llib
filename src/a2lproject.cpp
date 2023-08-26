/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2l/a2lproject.h"

namespace a2l {

void A2lProject::AddModule(std::unique_ptr<Module>& module) {
  module_list_.emplace(module->Name(), std::move(module));
}

}  // namespace a2l