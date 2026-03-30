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
#define yyFlexLexer amlFlexLexer
#include <FlexLexer.h>

#endif

#include <map>
#include <memory>
#include <sstream>
#include <stack>
#include <vector>

#include "a2l/amlsection.h"

#include "amlparser.hpp"

namespace a2l {


class AmlScanner : public amlFlexLexer {
 public:
  explicit AmlScanner(std::istream& in);
  int amllex(AmlParser::value_type* yylval);

  void LastError(const std::string& error) { last_error_ = error; }
  [[nodiscard]] const std::string& LastError() const { return last_error_; }

  void DefinitionList(AmlDefinitionList list) {
    definition_list_ = std::move(list);
  }
  [[nodiscard]] const AmlDefinitionList& DefintionList() const {
    return definition_list_;
  }

 private:
  AmlParser::semantic_type* yylval = nullptr;
  std::string last_error_;
  AmlDefinitionList definition_list_;

};

}  // namespace a2l
