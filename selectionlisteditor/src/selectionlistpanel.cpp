/*
* Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#include "selectionlistpanel.h"

#include <string>

#include <wx/sizer.h>

#include "selectionlistdocument.h"
#include "rasterlistview.h"
#include "mainframe.h"
#include "windowid.h"


namespace a2l {

SelectionListPanel::SelectionListPanel(wxWindow* parent)
: wxPanel(parent, kIdSelectionListPanel ) {

  wxPanel::SetMinSize({-1, 100});

  splitter_ = new wxSplitterWindow(this, kIdRasterSplitter);

  raster_grid_ = new SelectionGrid(splitter_);
  raster_list_ = new RasterListView(splitter_);
  //raster_list_->SetMaxSize({200, -1});

  file_label_ = new wxStaticText(this, wxID_ANY, "A2L File: None");

  collapse_button_ = new wxButton(this, kIdCollapseButton,
    "Hide/Show Available Objects");
  raster_button_ = new wxButton(this, kIdRasterButton,
    "Hide/Show Rasters");

  splitter_->SplitVertically(raster_grid_, raster_list_,
    -200);

  auto* raster_sizer = new wxBoxSizer(wxHORIZONTAL);
  raster_sizer->Add(splitter_, 1 , wxALL | wxGROW,0);

  auto* collapse_sizer = new wxBoxSizer(wxHORIZONTAL);
  collapse_sizer->Add(file_label_, 1,
    wxLEFT | wxRIGHT | wxEXPAND , 5  );

  collapse_sizer->Add(collapse_button_, 0,
    wxALIGN_CENTER_VERTICAL, 5 );
  collapse_sizer->AddStretchSpacer(1);
  collapse_sizer->Add(raster_button_, 0,
    wxALIGN_CENTER_VERTICAL, 5);

  auto* main_sizer = new wxBoxSizer(wxVERTICAL);
  main_sizer->Add(raster_sizer, 1, wxEXPAND , 0);
  main_sizer->Add(collapse_sizer, 0, wxALL | wxEXPAND, 2 );
  SetSizer(main_sizer);
  wxPanel::Layout();
  raster_grid_->Redraw();

  CallAfter([this]() -> void  {
  if (raster_grid_ != nullptr) {
    raster_grid_->Redraw();
    raster_grid_->Update();
  }

  if (splitter_ != nullptr && splitter_->IsSplit()) {
    splitter_->SetSashPosition(-200);
    splitter_->Layout();
  }
  });
}

SelectionListDocument* SelectionListPanel::GetDoc() {
  return MainFrame::GetDocument();
}

void SelectionListPanel::Redraw() {
  if (raster_grid_ == nullptr ||
      file_label_ == nullptr ||
      raster_list_ == nullptr ) {
    return;
  }
  raster_list_->Redraw();
  raster_list_->Update();


  auto* doc = GetDoc();
  if (doc == nullptr ) {
    raster_grid_->SetSelectionList(nullptr); // Will refresh the grid
  } else {
    SelectionList& list = doc->GetSelectionList();
    raster_grid_->SetSelectionList(&list);
  }
  raster_grid_->Update();

  const A2lFile* a2l_file = doc->GetA2lFile();
  if (a2l_file == nullptr ) {
    file_label_->SetLabel(L"A2L File: None");
  } else {
    file_label_->SetLabel(L"A2L File: " + a2l_file->NameW());
  }
  file_label_->Update();

  Layout();
}

void SelectionListPanel::RasterCollapse() {
  if (raster_list_ == nullptr || splitter_ == nullptr) {
    return;
  }

  if (splitter_->IsSplit()) {
    splitter_->Unsplit(raster_list_);
  } else {
    splitter_->SplitVertically(raster_grid_,raster_list_);
  }

  Layout();
}

} // a2l