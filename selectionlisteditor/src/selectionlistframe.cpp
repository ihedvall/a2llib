/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#include "selectionlistframe.h"

#include <filesystem>

#include "selectionlisteditor.h"
#include "selectionlistdocument.h"
#include "selectionlistpanel.h"
#include "mainframe.h"
#include "windowid.h"

namespace a2l {

wxIMPLEMENT_DYNAMIC_CLASS(SelectionListFrame,wxPanel)

wxBEGIN_EVENT_TABLE(SelectionListFrame, wxPanel)
EVT_BUTTON(kIdCollapseButton, SelectionListFrame::OnCollapse)
EVT_BUTTON(kIdRasterButton, SelectionListFrame::OnRasterCollapse)
wxEND_EVENT_TABLE()

SelectionListFrame::SelectionListFrame(wxDocParentFrame *parent)
    : wxPanel( parent ) {

  splitter_ = new wxSplitterWindow(this);
  splitter_->SetMinimumPaneSize(100);

  selection_list_panel_ = new SelectionListPanel(splitter_);
  object_list_ = new ObjectListPanel(splitter_);

  splitter_->SplitHorizontally(selection_list_panel_,
    object_list_, 400);

  auto* main_sizer = new wxBoxSizer(wxVERTICAL);
  main_sizer->Add(splitter_, 1 , wxALL | wxGROW,0);
  SetSizer(main_sizer);
  wxPanel::Layout();

  CallAfter([this]() -> void  {
    if (splitter_ != nullptr && splitter_->IsSplit()) {
      splitter_->SetSashPosition(300);
      splitter_->Layout();
    }
  });
}

void SelectionListFrame::Redraw() const {
  if (selection_list_panel_ == nullptr || object_list_ == nullptr) {
    return;
  }
  selection_list_panel_->Redraw();
  object_list_->Redraw();
}

SelectionListDocument *SelectionListFrame::GetDocument() {
  return MainFrame::GetDocument();
}

SelectionGrid* SelectionListFrame::GetGrid() const {
  if (selection_list_panel_ == nullptr) {
    return nullptr;
  }
  return selection_list_panel_->GetGrid();
}

RasterListView* SelectionListFrame::GetRasterList() const {
  if (selection_list_panel_ == nullptr) {
    return nullptr;
  }
  return selection_list_panel_->GetRasterList();
}

void SelectionListFrame::SetView(SelectionListView *view) {
  view_ = view;
}

void SelectionListFrame::OnCollapse(wxCommandEvent&) {
  if (object_list_ == nullptr || splitter_ == nullptr
      || selection_list_panel_ == nullptr) {
    return;
  }

  if (splitter_->IsSplit()) {
    splitter_->Unsplit(object_list_);
  } else {
    splitter_->SplitHorizontally(selection_list_panel_,
     object_list_);
  }

  Layout();

}

void SelectionListFrame::OnRasterCollapse(wxCommandEvent&) {
  if (selection_list_panel_ != nullptr) {
    selection_list_panel_->RasterCollapse();
  }
}

} // end namespace bus



