/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2l/selectionobject.h"

#include <array>
#include <string_view>

namespace {

constexpr std::array<std::string_view,5> kDisplayTypes {
  "",
  "Display",
  "DisplayOnly",
  "RecordOnly",
  "DoNotUse",
};

}

namespace a2l {

void SelectionObject::SetDisplayTypeAsString(const std::string& display_type) {
  // All examples from ETAS defines this type but specification defines
  // RecorderOnly.
  constexpr std::string_view patch_text = "RecorderOnly";
  if (display_type == patch_text) {
    display_type_ = ObjectDisplayType::RECORD_ONLY;
    return;
  }

  for (size_t index = 0; index < kDisplayTypes.size(); ++index) {
    if (display_type == kDisplayTypes[index]) {
      display_type_ = static_cast<ObjectDisplayType>(index);
      return;
    }
  }
  display_type_ = ObjectDisplayType::UNKNOWN;
}

const std::string_view& SelectionObject::GetDisplayTypeAsString() const {
  const auto index = static_cast<size_t>(GetDisplayType());
  return index < kDisplayTypes.size() ? kDisplayTypes[index] :
                                        kDisplayTypes.front();
}

} // a2l