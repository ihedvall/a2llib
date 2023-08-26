/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#pragma once

#include <map>
#include <memory>
#include <string>

#include "a2l/a2lobject.h"
#include "a2l/a2lstructs.h"
#include "a2l/module.h"

namespace a2l {
using ModuleList = std::map<std::string, std::unique_ptr<Module>>;

class A2lProject : public A2lObject {
 public:
  [[nodiscard]] A2lHeader& Header() { return header_;}
  [[nodiscard]] const A2lHeader& Header() const { return header_;}

  void AddModule(std::unique_ptr<Module>& module );
  [[nodiscard]] const ModuleList& Modules() const { return module_list_; }
 private:
  A2lHeader header_;
  ModuleList module_list_;
};

}  // namespace a2l
