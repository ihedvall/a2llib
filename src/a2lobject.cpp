/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2l/a2lobject.h"
#include <sstream>
#include <algorithm>
#include "a2lhelper.h"
namespace a2l {

void A2lObject::AddIfData(std::string input) {
  std::string protocol = A2lHelper::ParseIfDataProtocol(input);
  if (protocol.empty()) {
    return;
  }
  if_data_list_.emplace(std::move(protocol),std::move(input));
}

void A2lObject::AddAnnotation(A2lAnnotation annotation) {
  annotation_list_.emplace_back(std::move(annotation));
}

bool A2lObject::HaveIfData(const std::string_view& protocol) const {
  return std::any_of(if_data_list_.cbegin(), if_data_list_.cend(),
                     [&] (const auto& itr) {
                       return itr.first == protocol;
                     });
}

const xcp::XcpDataBlock* A2lObject::GetXcpPlusDataBlock() const {
  if (xcp_plus_data_block_) {
    return xcp_plus_data_block_.get();
  }
  for (const auto& [protocol, if_data] : if_data_list_) {
    if (protocol != "XCPplus") {
      continue;
    }
    xcp_plus_data_block_ = std::make_unique<xcp::XcpDataBlock>(if_data);
    return xcp_plus_data_block_.get();
  }
  return nullptr;
}

const xcp::XcpDataBlock* A2lObject::GetXcpDataBlock() const {
  if (xcp_data_block_) {
    return xcp_data_block_.get();
  }
  for (const auto& [protocol, if_data] : if_data_list_) {
    if (protocol != "XCP") {
      continue;
    }
    xcp_data_block_ = std::make_unique<xcp::XcpDataBlock>(if_data);
    return xcp_data_block_.get();
  }
  return nullptr;
}

const ccp::CcpDataBlock* A2lObject::GetCcpDataBlock() const {
  if (ccp_data_block_) {
    return ccp_data_block_.get();
  }
  for (const auto& [protocol, if_data] : if_data_list_) {
    if (protocol != "ASAP1B_CCP") {
      continue;
    }
    ccp_data_block_ = std::make_unique<ccp::CcpDataBlock>(if_data);
    return ccp_data_block_.get();
  }
  return nullptr;
}

} // end namespace a2l

