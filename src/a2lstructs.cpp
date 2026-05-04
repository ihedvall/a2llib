/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2l/a2lstructs.h"

namespace a2l {


const xcp::XcpDataBlock* A2lMemoryLayout::GetXcpPlusDataBlock() const {
  if (xcp_plus_data_block_.has_value() ) {
    return &xcp_plus_data_block_.value();
  }
  for (const auto& [protocol, if_data] : IfDataList ) {
    if (protocol != "XCPplus") {
      continue;
    }
    xcp::XcpDataBlock data_block(if_data);
    xcp_plus_data_block_ = std::move(data_block);
    break;
  }
  return xcp_plus_data_block_.has_value() ?
    &xcp_plus_data_block_.value() : nullptr;
}

const xcp::XcpDataBlock* A2lMemoryLayout::GetXcpDataBlock() const {
  if (xcp_data_block_.has_value() ) {
    return &xcp_data_block_.value();
  }
  for (const auto& [protocol, if_data] : IfDataList ) {
    if (protocol != "XCP") {
      continue;
    }
    xcp::XcpDataBlock data_block(if_data);
    xcp_data_block_ = std::move(data_block);
    break;
  }
  return xcp_data_block_.has_value() ?
    &xcp_data_block_.value() : nullptr;
}

const ccp::CcpDataBlock* A2lMemoryLayout::GetCcpDataBlock() const {
  if (ccp_data_block_.has_value() ) {
    return &ccp_data_block_.value();
  }
  for (const auto& [protocol, if_data] : IfDataList ) {
    if (protocol != "ASAP1B_CCP") {
      continue;
    }
    ccp::CcpDataBlock data_block(if_data);
    ccp_data_block_ = std::move(data_block);
    break;
  }
  return ccp_data_block_.has_value() ?
    &ccp_data_block_.value() : nullptr;
}

const xcp::XcpDataBlock* A2lMemorySegment::GetXcpPlusDataBlock() const {
  if (xcp_plus_data_block_.has_value() ) {
    return &xcp_plus_data_block_.value();
  }
  for (const auto& [protocol, if_data] : IfDataList ) {
    if (protocol != "XCPplus") {
      continue;
    }
    xcp::XcpDataBlock data_block(if_data);
    xcp_plus_data_block_ = std::move(data_block);
    break;
  }
  return xcp_plus_data_block_.has_value() ?
    &xcp_plus_data_block_.value() : nullptr;
}

const xcp::XcpDataBlock* A2lMemorySegment::GetXcpDataBlock() const {
  if (xcp_data_block_.has_value() ) {
    return &xcp_data_block_.value();
  }
  for (const auto& [protocol, if_data] : IfDataList ) {
    if (protocol != "XCP") {
      continue;
    }
    xcp::XcpDataBlock data_block(if_data);
    xcp_data_block_ = std::move(data_block);
    break;
  }
  return xcp_data_block_.has_value() ?
    &xcp_data_block_.value() : nullptr;
}

const ccp::CcpDataBlock* A2lMemorySegment::GetCcpDataBlock() const {
  if (ccp_data_block_.has_value() ) {
    return &ccp_data_block_.value();
  }
  for (const auto& [protocol, if_data] : IfDataList ) {
    if (protocol != "ASAP1B_CCP") {
      continue;
    }
    ccp::CcpDataBlock data_block(if_data);
    ccp_data_block_ = std::move(data_block);
    break;
  }
  return ccp_data_block_.has_value() ?
    &ccp_data_block_.value() : nullptr;
}

}
