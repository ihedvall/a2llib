/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include <fstream>
#include <string>
#include <memory>

#ifndef yyFlexLexerOnce

#undef yyFlexLexer
#define yyFlexLexer ifdataFlexLexer
#include <FlexLexer.h>

#endif

#include <map>
#include <memory>
#include <sstream>
#include <vector>
#include <stack>
#include "ifdataparser.hpp"
#include "a2l/ifdataitem.h"

namespace a2l {

class IfDataScanner : public ifdataFlexLexer {
 public:
  explicit IfDataScanner(std::istream& in);
  int ifdatalex(IfDataParser::value_type* yylval);

  void LastError(const std::string& error) { last_error_ = error; }
  [[nodiscard]] const std::string& LastError() const { return last_error_; }

  void Protocol(const std::string& protocol) { protocol_ = protocol; }
  [[nodiscard]] const std::string& Protocol() const { return protocol_; }

  void ItemList(const std::vector<IfDataItem>& list) { item_list_ = list; }
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
