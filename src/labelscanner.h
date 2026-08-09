/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
#pragma once

#include <string>
#include <memory>
#include <vector>

#ifndef yyFlexLexerOnce

#undef yyFlexLexer
#define yyFlexLexer labelFlexLexer
#include <FlexLexer.h>

#endif

#include "labelparser.hpp"
#include "a2l/selectionlist.h"
namespace a2l {

enum class LabelState : int {
  Unknown = 0,
  Settings,
  Label,
  Ramcell,
  Group,
  Function,
};

class LabelScanner : public labelFlexLexer  {
 public:
  explicit LabelScanner(std::istream& in, SelectionList& selection_list);

  int labellex(LabelParser::value_type* yylval);

  void LastError(const std::string& error) { last_error_ = error; }
  [[nodiscard]] const std::string& LastError() const { return last_error_; }

  void SetLabelState(LabelState state) {
    label_state_ = state;
  }
  [[nodiscard]] LabelState GetLabelState() const { return label_state_; }

  void ParseLineText(const std::vector<std::string>& line_list) const;

 private:
  LabelParser::semantic_type* yylval = nullptr;

  std::string last_error_;
  SelectionList& selection_list_;
  LabelState label_state_ = LabelState::Unknown;

  void SetSettingsProperty(const std::vector<std::string>& property_list) const;
  void SetObjectProperty(const std::vector<std::string>& property_list) const;
  static void SetV10Property(SelectionObject& object,
      const std::vector<std::string>& property_list);
  void SetV11Property(SelectionObject& object,
      const std::vector<std::string>& property_list) const;
  void SetV12Property(SelectionObject& object,
      const std::vector<std::string>& property_list) const;
  void SetV13Property(SelectionObject& object,
      const std::vector<std::string>& property_list) const;
};

}  // namespace a2l

