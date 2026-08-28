/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
#pragma once

#include <string>

#include <boost/asio.hpp>

#include <wx/wx.h>

namespace a2l {

class SelectionListEditor : public wxApp {
 public:
  bool OnInit() override;
  int OnExit() override;

  void OpenFile(const std::string& filename);
  Appearance GetAppearance() const { return appearance_; }
  void OnInitCmdLine(wxCmdLineParser& parser) override;
  bool OnCmdLineParsed(wxCmdLineParser& parser) override;
 private:
  boost::asio::io_context ctx_;
  std::string notepad_; ///< Path to notepad.exe if it exist
  Appearance appearance_ = Appearance::System;
  std::wstring label_file_;
  std::wstring a2l_file_;

  void OnOpenLogFile(wxCommandEvent& event);
  void OnUpdateOpenLogFile(wxUpdateUIEvent& event);

  wxDECLARE_EVENT_TABLE();
};
} // bus

wxDECLARE_APP(a2l::SelectionListEditor);
