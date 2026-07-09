/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#include "measurementview.h"
#include "windowid.h"

namespace a2lgui {
wxBEGIN_EVENT_TABLE(MeasurementView, wxPanel)
wxEND_EVENT_TABLE()

MeasurementView::MeasurementView(wxWindow* parent) : wxPanel(parent) {
  list_view_  = new MeasurementList(this);
  filter_view_ = new FilterListView(this, kIdMeasurementFilterView);

  auto* main_sizer = new wxBoxSizer(wxVERTICAL);
  main_sizer->Add(list_view_, 1 , wxALL | wxGROW,0);
  main_sizer->Add(filter_view_, 0, wxALL,2);
  SetSizerAndFit(main_sizer);
}

void MeasurementView::SetDoc(A2lDocument* doc) {
  document_ = doc;
  if (list_view_ != nullptr) {
    list_view_->SetDoc(doc);
  }
  if (filter_view_ != nullptr) {
    filter_view_->SetDoc(doc);
  }
}

void MeasurementView::Redraw() {
  if (list_view_ != nullptr) {
    list_view_->Redraw();
  }
  if (filter_view_ != nullptr) {
    filter_view_->Redraw();
  }
}

void MeasurementView::UpdateWindowUI(long flags) {
  wxPanel::UpdateWindowUI(flags);
  if (flags == wxUPDATE_UI_NONE && list_view_ != nullptr) {
    list_view_->Redraw();
  }
}

} // a2lgui