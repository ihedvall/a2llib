/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
#pragma once
#include <wx/imaglist.h>
#include <wx/listctrl.h>
#include <wx/panel.h>
#include <wx/splitter.h>
#include <wx/wx.h>

#include "selectionlistdocument.h"
#include "selectionlistpanel.h"
#include "objectlistpanel.h"

namespace a2l {
class SelectionListView;
class SelectionGrid;
class RasterListView;
class SelectionListFrame : public wxPanel {
 public:
  SelectionListFrame() = default;
  explicit SelectionListFrame(wxDocParentFrame *parent);
  void SetView(SelectionListView* view);
  void Redraw() const;

  [[nodiscard]] static SelectionListDocument* GetDocument();
  [[nodiscard]] SelectionGrid* GetGrid() const;
  [[nodiscard]] RasterListView* GetRasterList() const;
 private:
  SelectionListPanel* selection_list_panel_ = nullptr;
  ObjectListPanel* object_list_ = nullptr;
  wxSplitterWindow* splitter_ = nullptr;
  SelectionListView* view_ = nullptr;

  void OnCollapse(wxCommandEvent& event);
  void OnRasterCollapse(wxCommandEvent& event);
  wxDECLARE_DYNAMIC_CLASS(SelectionListFrame);
  wxDECLARE_EVENT_TABLE();

};
}




