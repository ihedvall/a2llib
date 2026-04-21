/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#ifndef yyFlexLexerOnce

#undef yyFlexLexer
#define yyFlexLexer xcpFlexLexer
#include "../FlexLexer.h"

#endif

#include "xcpdataparser.hpp"

namespace a2l::xcp {
class DataBlock;;

class XcpDataScanner : public xcpFlexLexer {
public:

  XcpDataScanner(std::istream& in);

  int xcplex(XcpDataParser::value_type* yylval);

  void LastError(std::string error) { last_error_ = std::move(error); }
  [[nodiscard]] std::string LastError() const { return last_error_; }

private:
  XcpDataParser::semantic_type* yylval = nullptr;
  std::string last_error_;

};

}


