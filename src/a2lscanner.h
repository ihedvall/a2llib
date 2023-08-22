/*
 * Copyright 2022 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
#pragma once

#include <fstream>
#include <string>
#include <memory>

#ifndef yyFlexLexerOnce

#undef yyFlexLexer
#define yyFlexLexer a2lFlexLexer
#include <FlexLexer.h>

#endif

#include "a2lparser.hpp"
#include <vector>
#include <map>
#include <sstream>

namespace a2l {


class A2lScanner : public a2lFlexLexer  {
 public:
  explicit A2lScanner(std::istream& in);
  int a2llex(A2lParser::value_type* yylval);

  void LastError(const std::string& error) { last_error_ = error; }
  [[nodiscard]] const std::string& LastError() const { return last_error_; }

 private:
  std::ostringstream utf8_stream_;
  A2lParser::semantic_type* yylval = nullptr;

  std::string last_error_;

  std::string ReadA2ML();
  std::string ReadIfData();
  std::string ReadIfDataSingleLine();
  std::string ReadIfDataMultiLine();
  void SkipUntil(const char end_char);
};

}  // namespace util::syslog
