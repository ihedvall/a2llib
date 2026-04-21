/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2l/xcp/datablock.h"

#include <sstream>
#include <stdexcept>

#include "xcpdatascanner.h"

namespace a2l::xcp {

DataBlock::DataBlock( std::string if_data)
{
  try {
    if (if_data.empty()) {
      throw std::runtime_error("Nothing to parse");
    }
    std::istringstream temp(if_data);
    XcpDataScanner scanner(temp);
    XcpDataParser parser(scanner);
    parse_ = parser.parse() == 0;
    last_error_ = scanner.LastError();
  } catch (const std::exception& err) {
    last_error_ = err.what();
    parse_ = false;
  }
}
}