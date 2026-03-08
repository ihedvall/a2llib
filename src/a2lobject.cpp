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

} // end namespace a2l

