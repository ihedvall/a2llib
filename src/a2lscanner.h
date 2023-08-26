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
#define yyFlexLexer a2lFlexLexer
#include <FlexLexer.h>

#endif

#include <map>
#include <memory>
#include <sstream>
#include <vector>

#include "a2l/axisdescr.h"
#include "a2l/axispts.h"
#include "a2l/module.h"
#include "a2lparser.hpp"

namespace a2l {


class A2lScanner : public a2lFlexLexer  {
 public:
  explicit A2lScanner(std::istream& in);
  int a2llex(A2lParser::value_type* yylval);

  void LastError(const std::string& error) { last_error_ = error; }
  [[nodiscard]] const std::string& LastError() const { return last_error_; }

  Module& CurrentModule();
  std::unique_ptr<Module>& ReleaseModule() { return module_; };

  AxisDescr& CurrentAxisDescr();
  std::unique_ptr<AxisDescr>& ReleaseAxisDescr() { return axis_descr_; };

  AxisPts& CurrentAxisPts();
  std::unique_ptr<AxisPts>& ReleaseAxisPts() { return axis_pts_; };

  Blob& CurrentBlob();
  std::unique_ptr<Blob>& ReleaseBlob() { return blob_; };

  Characteristic& CurrentCharacteristic();
  std::unique_ptr<Characteristic>& ReleaseCharacteristic() {
    return characteristic_;
  };
 private:
  std::ostringstream utf8_stream_;
  A2lParser::semantic_type* yylval = nullptr;

  std::string last_error_;

  std::string ReadA2ML();
  std::string ReadIfData();
  std::string ReadIfDataSingleLine();
  std::string ReadIfDataMultiLine();

  std::unique_ptr<Module> module_; ///< Current module
  std::unique_ptr<AxisDescr> axis_descr_; ///< Current axis descr
  std::unique_ptr<AxisPts> axis_pts_; ///< Current axis pts
  std::unique_ptr<Blob> blob_; ///< Current blob
  std::unique_ptr<Characteristic> characteristic_; ///< Current characteristic

  void SkipUntil(char end_char);
};

}  // namespace util::syslog
