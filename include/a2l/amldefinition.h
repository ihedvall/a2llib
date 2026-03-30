/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#pragma once

#include "a2l/amlmember.h"

namespace a2l {

class AmlDefinition : public AmlMember {
 public:
  void Set(const AmlMember& member);
};

}  // namespace a2l

