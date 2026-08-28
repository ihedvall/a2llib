/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#pragma once

#include <vector>

#include <wx/string.h>
#include <wx/panel.h>
#include <wx/srchctrl.h>
#include <wx/choice.h>

#include <a2l/module.h>
#include "selectionlistdocument.h"

namespace a2l {


class FilterListView : public wxPanel {
public:
  explicit FilterListView(wxWindow* parent, wxWindowID filter_id);
  [[nodiscard]] static SelectionListDocument* GetDoc() ;
  [[nodiscard]] static Module* GetModule();
  void Redraw();

 private:

  wxSearchCtrl* name_ctrl_ = nullptr;
  wxChoice* unit_ctrl_ = nullptr;
  wxChoice* interface_ctrl_ = nullptr;

  std::vector<wxString> unit_list_;
  std::vector<wxString> interface_list_;

  wxString name_filter_;
  wxString unit_filter_;
  wxString interface_filter_;

  void UpdateList();
  void OnNameChanged(wxCommandEvent& event);
  void OnNameClear(wxCommandEvent& event);
  void OnUnitChanged(wxCommandEvent& event);
  void OnInterfaceChanged(wxCommandEvent& event);
  void UpdateListView() const;

  wxDECLARE_EVENT_TABLE();
};


}  // namespace a2l

