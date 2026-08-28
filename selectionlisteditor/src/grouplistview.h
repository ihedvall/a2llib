/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#pragma once

#include <wx/listctrl.h>

#include "a2l/module.h"

#include "filterlistview.h"

namespace a2l {

class SelectionListDocument;

class GroupListView : public wxListView {
public:
  explicit GroupListView(wxWindow* parent);

  [[nodiscard]] static SelectionListDocument* GetDoc();
  [[nodiscard]] static const Module* GetModule();

  void Redraw();
protected:
  [[nodiscard]] wxString OnGetItemText(long item, long column) const override;
private:
  FilterListView* filter_list_view_ = nullptr;
  void OnDoubleClick(wxListEvent& event);
  wxDECLARE_EVENT_TABLE();
};

} // a2l
