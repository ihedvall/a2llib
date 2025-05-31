/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */
#pragma once

#include <string>
#include <vector>
#include <cstdint>

namespace a2l {

struct IfDataItem {
  std::string Value;
  std::string BlockName;
  std::vector<IfDataItem> ItemList;
};


} // end namespace a2l