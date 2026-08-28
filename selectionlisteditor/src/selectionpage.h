/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#pragma once

#include <wx/panel.h>
#include <wx/listctrl.h>
#include "filterlistview.h"
namespace a2l {

class SelectionPage : public wxPanel {
public:
  SelectionPage(wxWindow* parent, wxWindowID page_id);
  void Redraw() const;
private:
  int page_id_= 0; // Used to identify the type of page
  wxListView* list_view_ = nullptr;
  FilterListView* filter_view_ = nullptr;

};

}  // namespace a2l


