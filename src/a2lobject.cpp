/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2l/a2lobject.h"
#include <sstream>
namespace a2l {

void A2lObject::AddIfData(const std::string& input) {
  // Need to parse out the protocol, so it can be sorted.
  // The string look like "/begin{ws}IF_DATA{ws}Protocol{ws}
  constexpr std::string_view begin = "/begin";
  constexpr std::string_view if_data = "IF_DATA";
  size_t pos = 0;
  if (strncmp(input.data(), begin.data(), begin.size()) != 0) {
    return;
  }
  pos += begin.size();
  while (std::isspace(input[pos])) {
    ++pos;
  }
  if (strncmp(input.data() + pos, if_data.data(), if_data.size()) != 0) {
    return;
  }
  pos += if_data.size();
  while (std::isspace(input[pos])) {
    ++pos;
  }
  std::ostringstream protocol;
  while (input[pos] != '\0' && !std::isspace(input[pos])) {
    protocol << input[pos];
    ++pos;
  }
  if (protocol.str().empty()) {
    return;
  }
  if_data_list_.emplace(protocol.str(),input);
}

void A2lObject::AddAnnotation(const A2lAnnotation& annotation) {
  annotation_list_.emplace_back(annotation);
}

} // end namespace a2l

