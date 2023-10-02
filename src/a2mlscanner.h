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
#define yyFlexLexer a2mlFlexLexer
#include <FlexLexer.h>

#endif

#include <map>
#include <memory>
#include <sstream>
#include <vector>
#include <stack>
#include "a2mlparser.hpp"
#include "a2l/a2mlobject.h"

namespace a2l {



class A2mlScanner : public a2mlFlexLexer {
 public:
  explicit A2mlScanner(std::istream& in);
  int a2mllex(A2mlParser::value_type* yylval);

  void LastError(const std::string& error) { last_error_ = error; }
  [[nodiscard]] const std::string& LastError() const { return last_error_; }

  void BlockList(const A2mlBlockList& list) { block_list_ = list; }
  [[nodiscard]] const A2mlBlockList& BlockList() const { return block_list_; }
 private:
  A2mlParser::semantic_type* yylval = nullptr;
  std::string last_error_;
  std::vector<A2mlObject> block_list_;

};

}  // namespace a2l
