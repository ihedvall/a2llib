/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2l/a2mlblock.h"
#include <sstream>
#include "a2mlscanner.h"
#include "a2mlparser.hpp"

namespace a2l {

A2mlBlock::A2mlBlock(const std::string& a2ml) {
  try {
    if (a2ml.empty()) {
      throw std::runtime_error("Nothing to parse");
    }
    std::istringstream temp(a2ml);
    A2mlScanner scanner(temp);
    A2mlParser parser(scanner);
    parse_ = parser.parse() == 0;
    last_error_ = scanner.LastError();
    block_list_ = scanner.BlockList();
  } catch (const std::exception& err) {
    last_error_ = err.what();
    parse_ = false;
  }
}

}  // namespace a2l