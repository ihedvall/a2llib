/*
 * Copyright 2023 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
#pragma once

#include <fstream>
#include <string>
#include <memory>
#include <utility>
#include <vector>
#include <sstream>

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
#include "a2l/a2lfile.h"

namespace a2l {

class A2lFile;

class A2lScanner : public a2lFlexLexer  {
 public:

  struct FileItem{
    std::istringstream utf8_stream; ///< The file input converted to UTF8
    yy_buffer_state *buffer_state = nullptr; ///< Needed when switching state
    std::string file; ///< Filename including path.

    explicit FileItem(std::string filename) :
        file(std::move(filename)) {
    }
  };

  explicit A2lScanner(std::istringstream& in);

  int a2llex(A2lParser::value_type* yylval);

  void InputFile( std::string filename);
  [[nodiscard]] std::string InputFile() const;

  void Parent(A2lFile* parent);

  static void ReadAndConvertFile(const std::string& filename, std::istringstream& utf8_stream );

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

  RecordLayout& CurrentRecordLayout();
  std::unique_ptr<RecordLayout>& ReleaseRecordLayout() {
    return record_layout_;
  };

  Transformer& CurrentTransformer();
  std::unique_ptr<Transformer>& ReleaseTransformer() {
    return transformer_;
  };

  AxisPts& CurrentTypedefAxis();
  std::unique_ptr<AxisPts>& ReleaseTypedefAxis() {
    return typedef_axis_;
  };

  Blob& CurrentTypedefBlob();
  std::unique_ptr<Blob>& ReleaseTypedefBlob() {
    return typedef_blob_;
  };

  Characteristic& CurrentTypedefCharacteristic();
  std::unique_ptr<Characteristic>& ReleaseTypedefCharacteristic() {
    return typedef_characteristic_;
  };

  Measurement& CurrentTypedefMeasurement();
  std::unique_ptr<Measurement>& ReleaseTypedefMeasurement() {
    return typedef_measurement_;
  };

  Structure& CurrentTypedefStructure();
  std::unique_ptr<Structure>& ReleaseTypedefStructure() {
    return typedef_structure_;
  };

  A2lStructureComponent& CurrentStructureComponent();
  std::unique_ptr<A2lStructureComponent>& ReleaseStructureComponent() {
    return structure_component_;
  };

  Unit& CurrentUnit();
  std::unique_ptr<Unit>& ReleaseUnit() {
    return unit_;
  };

  A2lUserRight& CurrentUserRight();
  std::unique_ptr<A2lUserRight>& ReleaseUserRight() {
    return user_right_;
  };

  A2lVarCriterion& VarCriterion() { return var_criterion_; };

  [[nodiscard]] bool IsA2lFile() const { return found_; }

 private:

  std::vector<FileItem> file_stack_; ///< The file stack is main purpose is for include files handling
  A2lParser::semantic_type* yylval = nullptr;
  A2lFile* parent_ = nullptr; ///< Parent is needed if I must merge an A2L file.
  std::string last_error_;
  bool found_ = false; ///< Indicate that the  PROJECT tag has been found in the file.

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
  std::unique_ptr<RecordLayout> record_layout_;
  std::unique_ptr<Transformer> transformer_;
  std::unique_ptr<AxisPts> typedef_axis_;
  std::unique_ptr<Blob> typedef_blob_;
  std::unique_ptr<Characteristic> typedef_characteristic_;
  std::unique_ptr<Measurement> typedef_measurement_;
  std::unique_ptr<Structure> typedef_structure_;
  std::unique_ptr<A2lStructureComponent> structure_component_;
  std::unique_ptr<Unit> unit_;
  std::unique_ptr<A2lUserRight> user_right_;
  A2lVarCriterion var_criterion_ = {};
  void SkipUntil(char end_char);
  void FixIncludeFile();
};

}  // namespace a2l
