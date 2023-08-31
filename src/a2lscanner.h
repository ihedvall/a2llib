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

  CompuMethod& CurrentCompuMethod();
  std::unique_ptr<CompuMethod>& ReleaseCompuMethod() {
    return compu_method_;
  };

  CompuTab& CurrentCompuTab();
  std::unique_ptr<CompuTab>& ReleaseCompuTab() {
    return compu_tab_;
  };

  CompuVtab& CurrentCompuVtab();
  std::unique_ptr<CompuVtab>& ReleaseCompuVtab() {
    return compu_vtab_;
  };

  CompuVtabRange& CurrentCompuVtabRange();
  std::unique_ptr<CompuVtabRange>& ReleaseCompuVtabRange() {
    return compu_vtab_range_;
  };

  Frame& CurrentFrame();
  std::unique_ptr<Frame>& ReleaseFrame() {
    return frame_;
  };

  Function& CurrentFunction();
  std::unique_ptr<Function>& ReleaseFunction() {
    return function_;
  };

  Group& CurrentGroup();
  std::unique_ptr<Group>& ReleaseGroup() {
    return group_;
  };

  Instance& CurrentInstance();
  std::unique_ptr<Instance>& ReleaseInstance() {
    return instance_;
  };

  Overwrite& CurrentOverwrite();
  std::unique_ptr<Overwrite>& ReleaseOverwrite() {
    return overwrite_;
  };

  Measurement& CurrentMeasurement();
  std::unique_ptr<Measurement>& ReleaseMeasurement() {
    return measurement_;
  };

  A2lBitOperation& CurrentBitOperation() { return bit_operation_; };
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
  std::unique_ptr<CompuMethod> compu_method_; ///< Current Compu Method
  std::unique_ptr<CompuTab> compu_tab_; ///< Current COMPU TAB
  std::unique_ptr<CompuVtab> compu_vtab_; ///< Current COMPU VTAB
  std::unique_ptr<CompuVtabRange> compu_vtab_range_; ///< Current VTAB Range
  std::unique_ptr<Frame> frame_; ///< Current Frame
  std::unique_ptr<Function> function_; ///< Current Function
  std::unique_ptr<Group> group_;
  std::unique_ptr<Instance> instance_;
  std::unique_ptr<Overwrite> overwrite_;
  std::unique_ptr<Measurement> measurement_;
  A2lBitOperation bit_operation_ = {};
  void SkipUntil(char end_char);
};

}  // namespace util::syslog
