/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2l/a2lobject.h"
#include <sstream>
#include "a2lhelper.h"
namespace a2l {

void A2lObject::AddIfData(const std::string& input) {
  const auto protocol = A2lHelper::ParseIfDataProtocol(input);
  if (protocol.empty()) {
    return;
  }
  if_data_list_.emplace(protocol,input);
}

void A2lObject::AddAnnotation(const A2lAnnotation& annotation) {
  annotation_list_.emplace_back(annotation);
}

} // end namespace a2l

