/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <wx/listctrl.h>
namespace a2l {
class SelectionListDocument;
class SelectionGrid;
class RasterListView : public wxListView {
public:
  explicit RasterListView(wxWindow* parent);
  void Redraw();
  static SelectionListDocument* GetDoc();
  static SelectionGrid* GetGrid();

  void RasterSelected(wxUpdateUIEvent& event) const;
  void AddRaster();
  void EditRaster();
  void DeleteRaster();

private:
  void OnItemChecked(wxListEvent& event);
  void OnItemUnchecked(wxListEvent& event);
  void OnItemRightClick(wxContextMenuEvent& event);
  wxDECLARE_EVENT_TABLE();
};

}  // namespace a2l


