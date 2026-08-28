/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
#pragma once

#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/splitter.h>

#include "rasterlistview.h"
#include "selectiongrid.h"

namespace a2l {

class SelectionListDocument;
class SelectionListPanel : public wxPanel {
public:
  SelectionListPanel(wxWindow* parent);
  static SelectionListDocument* GetDoc();
  [[nodiscard]] SelectionGrid* GetGrid() const { return raster_grid_; }
  [[nodiscard]] RasterListView* GetRasterList() const { return raster_list_; }
  void Redraw();
  void RasterCollapse();

  private:
  wxSplitterWindow* splitter_ = nullptr;
  SelectionGrid* raster_grid_ = nullptr;
  RasterListView* raster_list_ = nullptr;
  wxStaticText* file_label_ = nullptr;
  wxButton* collapse_button_ = nullptr;
  wxButton* raster_button_ = nullptr;
};

}  // namespace a2l


