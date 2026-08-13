/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2l/a2lobject.h"

#include <algorithm>
#include <sstream>
//#include <uchardet.h>

#include "a2l/a2lhelper.h"
namespace {
/*
std::string DetectEncoding(const std::string& text) {
  uchardet_t detector = uchardet_new();
  if (detector == nullptr) {
    return "unknown";
  }

  const int handle_result =
      uchardet_handle_data(detector, text.c_str(), text.size());

  if (handle_result != 0) {
    uchardet_delete(detector);
    return "unknown";
  }

  uchardet_data_end(detector);

  size_t size = uchardet_get_n_candidates(detector);
  const char* charset = uchardet_get_encoding(detector, size);

  std::string result =
      charset != nullptr && *charset != '\0'
          ? charset
          : "unknown";

  uchardet_delete(detector);
  return result;
}
*/
}
namespace a2l {

void A2lObject::AddIfData(std::string input) {
  std::string protocol = A2lHelper::ParseIfDataProtocol(input);
  if (protocol.empty()) {
    return;
  }
  if_data_list_.emplace(std::move(protocol),std::move(input));
}

std::pair<std::string, std::string> A2lObject::GetIfData(long index) const {
  std::pair<std::string, std::string> if_data;
  if (index < 0 || index >= if_data_list_.size()) {
    return if_data;
  }
  auto itr = if_data_list_.cbegin();
  std::advance(itr, index);
  if_data = *itr;
  return if_data;
}

const std::string& A2lObject::Description() const {
  return description_;
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

void A2lObject::ConvertAllStrings(const std::string& encoding) {
  if (encoding.empty()) {
    return;
  }
  A2lHelper::MakeValidUtf8(description_, encoding);
  A2lHelper::MakeValidUtf8(phys_unit_, encoding);
  // Symbol link name is questionable if they need conversion

  for (A2lAnnotation& annotation: annotation_list_) {
    A2lHelper::MakeValidUtf8(annotation.Label, encoding);
    A2lHelper::MakeValidUtf8(annotation.Origin, encoding);
    for ( std::string& text : annotation.Text) {
      A2lHelper::MakeValidUtf8(text, encoding);
    }
  }

  // TODO: Convert the communication data blocks.
}

} // end namespace a2l

