/*
 * Copyright 2023 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#include "a2lscanner.h"
#include <queue>
namespace a2l {

A2lScanner::A2lScanner(std::istream& message)
    : a2lFlexLexer(&message), yylval(nullptr) {

}

std::string A2lScanner::ReadA2ML() {
  std::ostringstream a2ml_text;
  a2ml_text << yytext;

  std::string match;
  constexpr std::string_view end_a2ml = "/endA2ML";
  for (auto data = yyinput(); data != '\0'; data = yyinput()) {
    a2ml_text << static_cast<char>(data);
    if (std::isspace(data)) {
      continue;
    }
    match.push_back(static_cast<char>(data));
    if (match == end_a2ml) {
      break;
    }
    while (match.size() >= end_a2ml.size()) {
      match.erase(0,1);
    }
  }
  return a2ml_text.str();
}

std::string A2lScanner::ReadIfData() {
  std::ostringstream if_data_text;
  if_data_text << yytext;

  std::string match;
  constexpr std::string_view end_if_data = "/endIF_DATA";
  for (auto data = yyinput(); data != '\0'; data = yyinput()) {
    if_data_text << static_cast<char>(data);
    if (std::isspace(data)) {
      continue;
    }
    match.push_back(static_cast<char>(data));
    if (match == end_if_data) {
      break;
    }
    while (match.size() >= end_if_data.size()) {
      match.erase(0,1);
    }
  }
  return if_data_text.str();
}

std::string A2lScanner::ReadIfDataSingleLine() {
  std::ostringstream if_data_text;
  if_data_text << "/begin " << yytext;

  constexpr std::string_view end_if_data = "/endIF_DATA";
  for (auto data = yyinput();
       data != '\0' && data != '\n' && data != '\r';
       data = yyinput()) {
    if_data_text << static_cast<char>(data);
  }
  if_data_text << " " << end_if_data;
  return if_data_text.str();
}

std::string A2lScanner::ReadIfDataMultiLine() {
  std::ostringstream if_data_text;
  if_data_text << "/begin IF_DATA";

  constexpr std::string_view end_if_data = "/endIF_DATA";
  int state = 0; // The state becomes -1 at end of string
  for (auto data = yyinput(); data != '\0'; data = yyinput()) {
    switch (data) {
      case '{':
        ++state;
        break;
      case '}':
        --state;
        break;
      default:
        break;
    }
    if (state < 0) {
      break;
    }
    if_data_text << static_cast<char>(data);
  }
  if_data_text << " " << end_if_data;
  return if_data_text.str();
}

void A2lScanner::SkipUntil(char end_char) {
  for (auto data = yyinput();
       data != '\0' && data != end_char;
       data = yyinput()) {
  }
}

Module& A2lScanner::CurrentModule() {
  if (!module_) {
    module_ = std::make_unique<Module>();
  }
  return *module_;
}

AxisDescr& A2lScanner::CurrentAxisDescr() {
  if (!axis_descr_) {
    axis_descr_ = std::make_unique<AxisDescr>();
  }
  return *axis_descr_;
}

AxisPts& A2lScanner::CurrentAxisPts() {
  if (!axis_pts_) {
    axis_pts_ = std::make_unique<AxisPts>();
  }
  return *axis_pts_;
}

Blob& A2lScanner::CurrentBlob() {
  if (!blob_) {
    blob_ = std::make_unique<Blob>();
  }
  return *blob_;
}

Characteristic& A2lScanner::CurrentCharacteristic() {
  if (!characteristic_) {
    characteristic_ = std::make_unique<Characteristic>();
  }
  return *characteristic_;
}

CompuMethod& A2lScanner::CurrentCompuMethod() {
  if (!compu_method_) {
    compu_method_ = std::make_unique<CompuMethod>();
  }
  return *compu_method_;
}

CompuTab& A2lScanner::CurrentCompuTab() {
  if (!compu_tab_) {
    compu_tab_ = std::make_unique<CompuTab>();
  }
  return *compu_tab_;
}

CompuVtab& A2lScanner::CurrentCompuVtab() {
  if (!compu_vtab_) {
    compu_vtab_ = std::make_unique<CompuVtab>();
  }
  return *compu_vtab_;
}

CompuVtabRange& A2lScanner::CurrentCompuVtabRange() {
  if (!compu_vtab_range_) {
    compu_vtab_range_ = std::make_unique<CompuVtabRange>();
  }
  return *compu_vtab_range_;
}

Frame& A2lScanner::CurrentFrame() {
  if (!frame_) {
    frame_ = std::make_unique<Frame>();
  }
  return *frame_;
}

Function& A2lScanner::CurrentFunction() {
  if (!function_) {
    function_ = std::make_unique<Function>();
  }
  return *function_;
}

Group& A2lScanner::CurrentGroup() {
  if (!group_) {
    group_ = std::make_unique<Group>();
  }
  return *group_;
}

Instance& A2lScanner::CurrentInstance() {
  if (!instance_) {
    instance_ = std::make_unique<Instance>();
  }
  return *instance_;
}

Overwrite& A2lScanner::CurrentOverwrite() {
  if (!overwrite_) {
    overwrite_ = std::make_unique<Overwrite>();
  }
  return *overwrite_;
}

Measurement& A2lScanner::CurrentMeasurement() {
  if (!measurement_) {
    measurement_ = std::make_unique<Measurement>();
  }
  return *measurement_;
}

RecordLayout& A2lScanner::CurrentRecordLayout() {
  if (!record_layout_) {
    record_layout_ = std::make_unique<RecordLayout>();
  }
  return *record_layout_;
}

Transformer& A2lScanner::CurrentTransformer() {
  if (!transformer_) {
    transformer_ = std::make_unique<Transformer>();
  }
  return *transformer_;
}

AxisPts& A2lScanner::CurrentTypedefAxis() {
  if (!typedef_axis_) {
    typedef_axis_ = std::make_unique<AxisPts>();
  }
  return *typedef_axis_;
}

Blob& A2lScanner::CurrentTypedefBlob() {
  if (!typedef_blob_) {
    typedef_blob_ = std::make_unique<Blob>();
    typedef_blob_->AddressType(A2lAddressType::DIRECT);
  }
  return *typedef_blob_;
}

Characteristic& A2lScanner::CurrentTypedefCharacteristic() {
  if (!typedef_characteristic_) {
    typedef_characteristic_ = std::make_unique<Characteristic>();
  }
  return *typedef_characteristic_;
}

Measurement& A2lScanner::CurrentTypedefMeasurement() {
  if (!typedef_measurement_) {
    typedef_measurement_ = std::make_unique<Measurement>();
  }
  return *typedef_measurement_;
}

Structure& A2lScanner::CurrentTypedefStructure() {
  if (!typedef_structure_) {
    typedef_structure_ = std::make_unique<Structure>();
  }
  return *typedef_structure_;
}

A2lStructureComponent& A2lScanner::CurrentStructureComponent() {
  if (!structure_component_) {
    structure_component_ = std::make_unique<A2lStructureComponent>();
  }
  return *structure_component_;
}

Unit& A2lScanner::CurrentUnit() {
  if (!unit_) {
    unit_ = std::make_unique<Unit>();
  }
  return *unit_;
}

A2lUserRight& A2lScanner::CurrentUserRight() {
  if (!user_right_) {
    user_right_ = std::make_unique<A2lUserRight>();
  }
  return *user_right_;
}

}  // namespace a2l