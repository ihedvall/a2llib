/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

// ReSharper disable CppMemberFunctionMayBeStatic
// ReSharper disable CppParameterMayBeConstPtrOrRef
#include "rasterlistview.h"

#include <boost/algorithm/string.hpp>
#include "a2l/a2llogstream.h"

#include "mainframe.h"
#include "selectionlistdocument.h"
#include "selectionlisteditor.h"
#include "selectiongrid.h"

#include "windowid.h"

using namespace a2l::ccp;
using namespace boost::algorithm;

namespace a2l {
wxBEGIN_EVENT_TABLE(RasterListView, wxListView)
EVT_LIST_ITEM_CHECKED(kIdRasterList, RasterListView::OnItemChecked)
EVT_LIST_ITEM_UNCHECKED(kIdRasterList, RasterListView::OnItemUnchecked)
EVT_CONTEXT_MENU(RasterListView::OnItemRightClick)
wxEND_EVENT_TABLE()

RasterListView::RasterListView(wxWindow* parent)
: wxListView(parent, kIdRasterList,wxDefaultPosition, wxDefaultSize,
  wxLC_REPORT | wxLC_SINGLE_SEL ) {
  InsertColumn(0, "Use", wxLIST_FORMAT_LEFT, 40);
  InsertColumn(1, "Raster",wxLIST_FORMAT_LEFT, 150);
  wxListView::EnableCheckBoxes(true);
}

void RasterListView::Redraw() {
  std::set<std::string> selected_list;
  for (long selected = GetFirstSelected(); selected >= 0;
          selected = GetNextSelected(selected)) {
    wxString sel = GetItemText(selected, 1);
    if (!sel.empty()) {
      selected_list.emplace(sel.utf8_string());
    }
  }
  DeleteAllItems();
  auto* doc = GetDoc();
  if (doc == nullptr) {
    return;
  }
  SelectionList& selection_list = doc->GetSelectionList();
  const auto& raster_list = selection_list.GetRasters();
  long line = 0;
  for (const auto& raster : raster_list) {
    const bool used = raster.IsActive();
    const wxString display_name = wxString::FromUTF8(raster.GetShortName());
    const bool selected = selected_list.contains(raster.GetShortName());

    const long index = InsertItem(line, wxEmptyString);
    SetItem(index, 1, display_name);
    CheckItem(index, used);
    Select(index, selected);
    ++line;
  }
}

SelectionListDocument* RasterListView::GetDoc() {
  return MainFrame::GetDocument();
}

SelectionGrid* RasterListView::GetGrid() {
  if (MainFrame* main_frame = SelectionListDocument::GetMainFrame();
      main_frame != nullptr) {
    return main_frame->GetGrid();
  }
  return nullptr;
}

void RasterListView::RasterSelected(wxUpdateUIEvent& event) const {
  const int count = GetSelectedItemCount();
  event.Enable(count == 1);
}

void RasterListView::AddRaster() {
  auto* doc = GetDoc();
  if (doc == nullptr) {
    return;
  }
  wxTextEntryDialog dialog(this, "Enter new raster name",
    "Raster Dialog");
  wxTextValidator validator(wxFILTER_ASCII);
  validator.SetCharExcludes(" ");
  dialog.SetTextValidator(validator);
  dialog.ShowModal();
  const int result = dialog.ShowModal();
  if (result != wxID_OK) {
    return;
  }
  std::string short_name = dialog.GetValue().utf8_string();
  trim(short_name);
  if (short_name.empty()) {
    wxMessageBox("Raster name cannot be empty", "Error",
      wxID_OK | wxICON_ERROR);
    return;
  }
  Raster raster_obj;
  raster_obj.SetActive(false);
  raster_obj.SetName(short_name);
  raster_obj.SetShortName(short_name);

  SelectionList& selection_list = doc->GetSelectionList();
  selection_list.AddRaster(raster_obj);

  Redraw();
  Update();

  // No need to update the grid as we added inactive raster.
}

void RasterListView::EditRaster() {
  auto* doc = GetDoc();
  if (doc == nullptr) {
    return;
  }
  std::vector<long> selected_items;
  for (long selected = GetFirstSelected(); selected >= 0;
            selected = GetNextSelected(selected)) {
    selected_items.push_back(selected);
  }
  if (selected_items.size() != 1) {
    A2L_ERROR() << "Too many items selected";
    return;
  }
  const auto selected_index = static_cast<size_t>(selected_items[0]);
  SelectionList& selection_list = doc->GetSelectionList();
  Raster* raster_obj = selection_list.GetRaster(selected_index);
  if (raster_obj == nullptr) {
    A2L_ERROR() << "Raster not found";
    return;
  }
  wxString old_name = wxString::FromUTF8(raster_obj->GetShortName());
  wxTextEntryDialog dialog(this, "Rename raster name",
    "Raster Dialog", old_name);
  wxTextValidator validator(wxFILTER_ASCII);
  validator.SetCharExcludes(" ");
  dialog.SetTextValidator(validator);
  dialog.ShowModal();
  const int result = dialog.ShowModal();
  if (result != wxID_OK) {
    return;
  }
  std::string short_name = dialog.GetValue().utf8_string();
  trim(short_name);
  if (short_name.empty()) {
    wxMessageBox("Raster name cannot be empty", "Error",
      wxID_OK | wxICON_ERROR);
    return;
  }
  raster_obj->SetShortName(short_name);
  Redraw();
  Update();

  if (SelectionGrid* grid = GetGrid(); grid != nullptr) {
    grid->Redraw();
    grid->Update();
  }
}

void RasterListView::DeleteRaster() {
  auto* doc = GetDoc();
  if (doc == nullptr) {
    return;
  }

  SelectionList& selection_list = doc->GetSelectionList();
  std::vector<wxString> delete_list;
  for (long selected = GetFirstSelected(); selected >= 0;
            selected = GetNextSelected(selected)) {
    const auto selected_index = static_cast<size_t>(selected);
    Raster* raster_obj = selection_list.GetRaster(selected_index);
    if (raster_obj == nullptr) {
      A2L_ERROR() << "Raster not found";
      continue;
    }
    const wxString name = wxString::FromUTF8(raster_obj->GetShortName());
    delete_list.push_back(name);
  }

  if (delete_list.empty()) {
    A2L_ERROR() << "No items selected";
    return;
  }

  std::wostringstream ask;
  ask << L"Do you want to delete the following rasters?" << std::endl;
  for (const wxString& name : delete_list) {
    ask << name.ToStdWstring() << std::endl;
  }

  const int result = wxMessageBox(ask.str(), "Raster Delete Dialog",
    wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
  if (result != wxYES) {
    return;
  }

  for (const wxString& name : delete_list) {
    selection_list.DeleteRaster(name.utf8_string());
  }
  Redraw();
  Update();

  if (SelectionGrid* grid = GetGrid(); grid != nullptr) {
    grid->Redraw();
    grid->Update();
  }
}

void RasterListView::OnItemChecked(wxListEvent& event) {
  const long index = event.GetIndex();
  auto* doc = GetDoc();
  if (doc == nullptr) {
    return;
  }
  SelectionList& selection_list = doc->GetSelectionList();
  Raster* raster = selection_list.GetRaster(index);
  if (raster == nullptr) {
    return;
  }
  raster->SetActive(true);
  // Need to redraw the raster grid
  if (SelectionGrid* grid = GetGrid(); grid != nullptr) {
    grid->Redraw();
    grid->Update();
  }
}

void RasterListView::OnItemUnchecked(wxListEvent& event) {
  const long index = event.GetIndex();
  auto* doc = GetDoc();
  if (doc == nullptr) {
    return;
  }
  SelectionList& selection_list = doc->GetSelectionList();
  Raster* raster = selection_list.GetRaster(index);
  if (raster == nullptr) {
    return;
  }
  raster->SetActive(false);
  // Need to redraw the raster grid
  if (SelectionGrid* grid = GetGrid(); grid != nullptr) {
    grid->Redraw();
    grid->Update();
  }
}

void RasterListView::OnItemRightClick(wxContextMenuEvent& event) {
  wxMenu menu;
  menu.Append(kIdRastersAdd, wxGetStockLabel(wxID_ADD),
    "Adds a new raster object");
  menu.Append(kIdRastersEdit, wxGetStockLabel(wxID_EDIT),
    "Modify an existing raster object");
  menu.Append(kIdRastersDelete, wxGetStockLabel(wxID_DELETE),
    "Delete an existing raster object");

  wxPoint point = ScreenToClient(event.GetPosition());
  if (point == wxDefaultPosition) {
    point = ScreenToClient(wxGetMousePosition());
  }

  if (const bool shown = PopupMenu(&menu, point);
      !shown) {
    A2L_ERROR() << "Failed to show context menu";
  }

}

} // a2l