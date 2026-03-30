/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#include "a2l/amldefinition.h"

namespace a2l {

void AmlDefinition::Set(const AmlMember& member) {
  auto* this_member = dynamic_cast<AmlMember*> (this);
  if (this_member != nullptr && this_member != &member) {
      *this_member = member;
  }
}

}  // namespace a2l