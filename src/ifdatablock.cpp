/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2l/ifdatablock.h"
#include <sstream>
#include "ifdatascanner.h"
#include "ifdataparser.hpp"

namespace a2l {

IfDataBlock::IfDataBlock(const std::string& ifdata) {
  try {
    if (ifdata.empty()) {
      throw std::runtime_error("Nothing to parse");
    }
    std::istringstream temp(ifdata);
    IfDataScanner scanner(temp);
    IfDataParser parser(scanner);
    parse_ = parser.parse() == 0;
    last_error_ = scanner.LastError();
    protocol_ = scanner.Protocol();
    item_list_ = scanner.ItemList();
  } catch (const std::exception& err) {
    last_error_ = err.what();
    parse_ = false;
  }
}

std::string IfDataBlock::AsString() const {
  std::ostringstream temp;
  temp << Protocol() << std::endl;

  for (const auto& item : item_list_) {
    if (item.BlockName.empty() && item.ItemList.empty()) {
      temp << "\t" << item.Value << std::endl;
    } else {
      temp << AsString(1,item);
    }
  }
  temp << std::endl;
  return temp.str();
}

std::string IfDataBlock::AsString(size_t tab_level, // NOLINT
                                  const IfDataItem& block_item) const {
  std::ostringstream temp;
  for (size_t level1 = 0; level1 < tab_level; ++level1 ) {
    temp << "\t";
  }
  temp << block_item.BlockName << std::endl;

  for (const auto& item : block_item.ItemList) {
    if (item.BlockName.empty() && item.ItemList.empty()) {
      for (size_t level1 = 0; level1 < tab_level; ++level1 ) {
        temp << "\t";
      }
      temp << "\t" << item.Value << std::endl;
    } else {
      temp << AsString(tab_level + 1,item);
    }
  }
  temp << std::endl;
  return temp.str();

}

}  // namespace a2l