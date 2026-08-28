/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <wx/grid.h>

#include "a2l/selectionlist.h"

namespace a2l {
class SelectionGridTable;
class SelectionListDocument;

class SelectionGrid : public wxGrid {
public:
  SelectionGrid(wxWindow* parent);
  static SelectionListDocument* GetDoc();
  void Redraw();
  void SetSelectionList(SelectionList* selection_list);

  void AddSelectionObject();
  void DeleteSelectionObject() const;
private:
  int current_rows_ = 0;
  SelectionGridTable* table_ = nullptr;
  void UpdateNofRows(int old_rows, int new_rows );
  void UpdateReadOnly();

  void OnRightClick(wxGridEvent& event);

  wxDECLARE_EVENT_TABLE();
};

}  // namespace a2l


