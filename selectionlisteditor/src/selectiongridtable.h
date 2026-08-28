/*
* Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <wx/grid.h>
#include <a2l/selectionlist.h>

namespace a2l {

class SelectionGridTable : public wxGridTableBase {
public:
  SelectionGridTable();
  int GetNumberRows() override;
  int GetNumberCols() override;

  wxString GetValue(int row, int col) override;
  void SetValue(int row, int col, const wxString& value) override;

  wxString GetRowLabelValue(int row) override;
  wxString GetColLabelValue(int col) override;

  void SetSelectionList(SelectionList* selection_list);
private:
  SelectionList* selection_list_ = nullptr;
};

}  // namespace a2l


