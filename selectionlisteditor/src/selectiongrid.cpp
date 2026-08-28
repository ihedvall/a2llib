/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
// ReSharper disable CppParameterMayBeConstPtrOrRef
#include "selectiongrid.h"

#include "a2l/a2llogstream.h"

#include "mainframe.h"
#include "selectiongridtable.h"
#include "selectionlistframe.h"
#include "windowid.h"

namespace a2l {

wxBEGIN_EVENT_TABLE(SelectionGrid, wxGrid)
EVT_GRID_CMD_CELL_RIGHT_CLICK(kIdSelectionGrid, SelectionGrid::OnRightClick)
wxEND_EVENT_TABLE()

SelectionGrid::SelectionGrid(wxWindow* parent)
  : wxGrid(parent, kIdSelectionGrid) {

  table_ = new SelectionGridTable;
  SetTable(table_, true);
  wxGrid::SetMinSize({-1, 200});
  UseNativeColHeader(true);
  HideRowLabels();
  EnableGridLines(false);
  SetCellHighlightPenWidth(0);
  SetCellHighlightROPenWidth(0);
  SetSelectionBackground(GetDefaultCellBackgroundColour());
  SetSelectionForeground(GetDefaultCellTextColour());
  SetSelectionMode(wxGrid::wxGridSelectRows);
  wxGridCellBoolEditor::UseStringValues("1", "0");
  {
    // NAME
    auto* attr = new wxGridCellAttr;
    attr->SetAlignment(wxALIGN_LEFT, wxALIGN_CENTER);
    attr->SetReadOnly(true);
    SetColAttr(0, attr);
  }
  {
    // TYPE
    auto* attr = new wxGridCellAttr;
    attr->SetAlignment(wxALIGN_LEFT, wxALIGN_CENTER);
    attr->SetReadOnly(true);
    SetColAttr(1, attr);
  }
  for (int col = 2; col <= 6 ; ++col) { // RASTER
    auto* attr = new wxGridCellAttr;
    attr->SetRenderer(new wxGridCellBoolRenderer);
    attr->SetEditor(new wxGridCellBoolEditor);
    attr->SetAlignment(wxALIGN_CENTER, wxALIGN_CENTER);
    SetColAttr(col, attr);
  }
  {
    wxArrayString choices;
    choices.Add("");
    choices.Add("Display");
    choices.Add("Display Only");
    choices.Add("Record Only");
    choices.Add("Do Not Use");
    auto* attr = new wxGridCellAttr;
    attr->SetEditor(new wxGridCellChoiceEditor(choices));
    attr->SetAlignment(wxALIGN_LEFT, wxALIGN_CENTER);
    SetColAttr(7, attr);
  }
  for (int col = 8; col < 10; ++col) { // COMMENT, DEVICE
    auto* attr = new wxGridCellAttr;
    attr->SetAlignment(wxALIGN_LEFT, wxALIGN_CENTER);
    SetColAttr(8, attr);
  }
  for (int col = 10; col < 14; ++col) { // UNIT and beyond
    // Components from the attached A2L file
    auto* attr = new wxGridCellAttr;
    attr->SetAlignment(wxALIGN_LEFT, wxALIGN_CENTER);
    attr->SetReadOnly(true);
    SetColAttr(col, attr);
  }
}

SelectionListDocument* SelectionGrid::GetDoc() {
  return MainFrame::GetDocument();
}

void SelectionGrid::Redraw() {
  BeginBatch();
  int columns = GetNumberCols();
  for (int col = 0; col < columns; ++col) {
    const wxString label = GetColLabelValue(col);
    const bool show = IsColShown(col);
    if (label.IsEmpty() && show) {
      HideCol(col);
    } else if (!label.IsEmpty() && !show) {
      ShowCol(col);
    }
  }

  ClearGrid();
  const int new_rows = table_->GetNumberRows();
  UpdateNofRows(current_rows_, new_rows);
  current_rows_ = new_rows;

  AutoSizeColumns();
  EndBatch();
}

void SelectionGrid::SetSelectionList(SelectionList* selection_list) {
  if (table_ == nullptr) {
    return;
  }
  table_->SetSelectionList(selection_list);
  Redraw();
  ForceRefresh();
}

void SelectionGrid::UpdateNofRows(int old_rows, int new_rows) {
  if (new_rows > old_rows) {
    wxGridTableMessage msg(
      table_,
      wxGRIDTABLE_NOTIFY_ROWS_APPENDED,
      new_rows - old_rows
    );
    ProcessTableMessage(msg);
  } else if (new_rows < old_rows) {
    wxGridTableMessage msg(
      table_,
      wxGRIDTABLE_NOTIFY_ROWS_DELETED,
      new_rows,
      old_rows - new_rows
    );
    ProcessTableMessage(msg);
  }
}

void SelectionGrid::UpdateReadOnly() {
  for (int row = 0; row < GetNumberRows(); ++row) {
    SetReadOnly(row, 0, true);
  }
}


void SelectionGrid::OnRightClick(wxGridEvent& event) {
  const int row = event.GetRow();
  ClearSelection();
  SelectRow(row);
  auto* doc = GetDoc();
  if (doc == nullptr) {
    return;
  }
  const SelectionList& selection_list = doc->GetSelectionList();
  const SelectionObject* object = selection_list.GetObject(
    static_cast<size_t>(row));
  if (object == nullptr) {
    return;
  }

  wxMenu menu;
  menu.Append(kIdSelectionObjectAdd,
    wxGetStockLabel(wxID_ADD), wxGetStockHelpString(wxID_ADD));
  menu.Append(kIdSelectionObjectDelete, wxGetStockLabel(wxID_DELETE));
  PopupMenu(&menu);

}

void SelectionGrid::AddSelectionObject() {
  auto* doc = GetDoc();
  if (doc == nullptr) {
    return;
  }
  SelectionList& selection_list = doc->GetSelectionList();

  wxTextEntryDialog dialog(this, "Enter the new object name");
  wxTextValidator validator(wxFILTER_ASCII);
  validator.SetCharExcludes(" ");
  dialog.SetTextValidator(validator);
  const int result = dialog.ShowModal();
  if (result != wxID_OK) {
    return;
  }
  SelectionObject object;
  object.SetName(dialog.GetValue().utf8_string());
  // Copy the remaining object from any selected object
  const wxArrayInt selected_list = GetSelectedRows();
  for (const int selected_row : selected_list ) {
    const SelectionObject* ref_object = selection_list.GetObject(
      static_cast<size_t>(selected_row));
    if (ref_object == nullptr) {
      continue;
    }
    object.SetObjectType(ref_object->GetObjectType());
    for (const std::string& raster : ref_object->GetRasterList()) {
      object.AddRaster(raster);
    }
    object.SetDisplayType(ref_object->GetDisplayType());


    break;
  }
  doc->AddSelectionObject(object);
}

void SelectionGrid::DeleteSelectionObject() const {
  auto* doc = GetDoc();
  if (doc == nullptr) {
    return;
  }

  const wxArrayInt selected_list = GetSelectedRows();
  if (selected_list.empty()) {
    A2L_ERROR() << "No object(s) selected";
    return;
  }

  std::set<std::string> deleted_list;
  SelectionList& selection_list = doc->GetSelectionList();
  std::ostringstream message;
  message << "Do you want to delete the following objects?" << std::endl;
  for (const int selected_row : selected_list ) {
    const SelectionObject* ref_object = selection_list.GetObject(
      static_cast<size_t>(selected_row));
    if (ref_object == nullptr) {
      continue;
    }
    deleted_list.insert(ref_object->GetName());
    message << ref_object->GetName() << std::endl;
  }

  const int ask = wxMessageBox(message.str(), "Delete Selection Object",
    wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);;
  if (ask != wxYES) {
    return;
  }
  for (const std::string& name : deleted_list) {
    doc->DeleteSelectionObject(name);
  }
}

} // a2l