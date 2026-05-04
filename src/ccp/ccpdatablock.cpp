/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include <sstream>
#include <stdexcept>

#include "a2l/ccp/ccpdatablock.h"
#include "ccpdatascanner.h"

namespace a2l::ccp {

CcpDataBlock::CcpDataBlock( std::string if_data)
{
  try {
    if (if_data.empty()) {
      throw std::runtime_error("Nothing to parse");
    }
    std::istringstream temp(std::move(if_data));
    CcpDataScanner scanner(temp);
    CcpDataParser parser(scanner);
    parse_ = parser.parse() == 0;
    last_error_ = scanner.LastError();
    TransferData(scanner);

  } catch (const std::exception& err) {
    last_error_ = err.what();
    parse_ = false;
  }
}

void CcpDataBlock::TransferData(CcpDataScanner& scanner) {
 source_list_ = std::move(scanner.source_list_);
 raster_list_ = std::move(scanner.raster_list_);
 event_group_list_ = std::move(scanner.event_group_list_);
 seed_key_ = std::move(scanner.seed_key_);
 checksum_ = std::move(scanner.checksum_);
 tp_blob_ = std::move(scanner.tp_blob_);
 address_mapping_list_ = std::move(scanner.address_mapping_list_);
 dp_blob_ = std::move(scanner.dp_blob_);
 kp_blob_ = std::move(scanner.kp_blob_);
}

}  // namespace a2l::xcp