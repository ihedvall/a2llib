/*
 * Copyright 2023 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
#pragma once
#include <string>
#include <wx/wx.h>

#if !wxUSE_DOC_VIEW_ARCHITECTURE
#error You must set wxUSE_DOC_VIEW_ARCHITECTURE to 1 in setup.h!
#endif

namespace a2lgui {

class A2lExplorer : public wxApp {
 public:

  bool OnInit() override;
  int OnExit() override;

  void OpenFile(const std::string& filename) const;

 private:
  std::string notepad_; ///< Path to notepad.exe if it exist

  void OnOpenLogFile(wxCommandEvent& event);
  void OnUpdateOpenLogFile(wxUpdateUIEvent& event);
  wxDECLARE_EVENT_TABLE();
};
} // namespace

wxDECLARE_APP(a2lgui::A2lExplorer);
