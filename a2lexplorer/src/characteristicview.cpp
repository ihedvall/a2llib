/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#include "characteristicview.h"
#include "windowid.h"

namespace a2lgui {
wxBEGIN_EVENT_TABLE(CharacteristicView, wxPanel)
wxEND_EVENT_TABLE()

CharacteristicView::CharacteristicView(wxWindow* parent) : wxPanel(parent) {
  list_view_  = new CharacteristicList(this);
  filter_view_ = new FilterListView(this, kIdCharacteristicFilterView);

  auto* main_sizer = new wxBoxSizer(wxVERTICAL);
  main_sizer->Add(list_view_, 1 , wxALL | wxGROW,0);
  main_sizer->Add(filter_view_, 0, wxALL,2);
  SetSizerAndFit(main_sizer);
}

void CharacteristicView::SetDoc(A2lDocument* doc) {
  document_ = doc;
  if (list_view_ != nullptr) {
    list_view_->SetDoc(doc);
  }
  if (filter_view_ != nullptr) {
    filter_view_->SetDoc(doc);
  }
}

void CharacteristicView::Redraw() {
  if (list_view_ != nullptr) {
    list_view_->Redraw();
  }
  if (filter_view_ != nullptr) {
    filter_view_->Redraw();
  }
}

void CharacteristicView::UpdateWindowUI(long flags) {
  wxPanel::UpdateWindowUI(flags);
  if (flags == wxUPDATE_UI_NONE && list_view_ != nullptr) {
     list_view_->Redraw();
  }
}

} // a2lgui