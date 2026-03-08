/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include <string>
#include <memory>

#ifndef yyFlexLexerOnce

#undef yyFlexLexer
#define yyFlexLexer ifdataFlexLexer
#include <FlexLexer.h>

#endif

#include <vector>

#include "ifdataparser.hpp"

#include "a2l/ifdataitem.h"

namespace a2l {

class IfDataScanner : public ifdataFlexLexer {
 public:
  explicit IfDataScanner(std::istream& in);
  int ifdatalex(IfDataParser::value_type* yylval);

  void LastError(std::string error) { last_error_ = std::move(error); }
  [[nodiscard]] const std::string& LastError() const { return last_error_; }

  void Protocol(std::string protocol) { protocol_ = std::move(protocol); }
  [[nodiscard]] const std::string& Protocol() const { return protocol_; }

  void ItemList(std::vector<IfDataItem> list) { item_list_ = std::move(list); }
  [[nodiscard]] const std::vector<IfDataItem>& ItemList() const {
    return item_list_;
  }
 private:
  IfDataParser::semantic_type* yylval = nullptr;
  std::string last_error_;

  std::string protocol_;
  std::vector<IfDataItem> item_list_;


};

}  // namespace a2l
