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

}  // namespace a2l