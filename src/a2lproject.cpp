/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2l/a2lproject.h"

#include <ranges>

namespace a2l {

void A2lProject::AddModule(std::unique_ptr<Module>& module) {
  if (module) {
    module_list_.emplace(module->Name(), std::move(module));
  }
}
void A2lProject::ConvertAllStrings(const std::string& encoding) {
  A2lObject::ConvertAllStrings(encoding);
  for (auto& module : module_list_ | std::views::values) {
    if (module) {
      module->ConvertAllStrings(encoding);
    }
  }
}

}  // namespace a2l