/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#include "calibrationmethodlist.h"

#include <wx/wx.h>
#include <wx/splitter.h>

#include "a2lpropertygrid.h"
#include "a2l/module.h"
#include "a2l/a2lstructs.h"
#include "windowid.h"

using namespace a2l;
namespace a2lgui {

wxBEGIN_EVENT_TABLE(CalibrationMethodList, wxListView)
  EVT_LIST_ITEM_SELECTED(kIdCalibrationMethodListView, CalibrationMethodList::OnItemSelected)
wxEND_EVENT_TABLE()

CalibrationMethodList::CalibrationMethodList(wxWindow *parent)
: wxListView(parent, kIdCalibrationMethodListView, wxDefaultPosition, wxDefaultSize,
    wxLC_REPORT | wxLC_SINGLE_SEL | wxLC_VIRTUAL) {

  InsertColumn(0, "Method", wxLIST_FORMAT_LEFT, 200);
  InsertColumn(1, "Version",wxLIST_FORMAT_LEFT, 75);
}

void CalibrationMethodList::Redraw() {
  A2lDocument* doc = GetDoc();
  if (doc == nullptr) {
    return;
  }
  long selected = GetFirstSelected();
  doc->SetSelectedIndex(selected);
  DeleteAllItems();
  const TreeItemType type = doc->SelectedType();
  void* object = doc->SelectedObject();
  if (object == nullptr) {
    return;
  }

  switch (type) {
    case TreeItemType::CAL_METHOD_LIST: {
      if (auto* mod_par = static_cast<A2lModPar*>(object); mod_par != nullptr) {
        const auto& cal_list = mod_par->CalibrationMethodList;
        SetItemCount(static_cast<long>(cal_list.size()));
        if (selected >= 0 && selected < cal_list.size()) {
          Select(selected);
          EnsureVisible(selected);
        }
      }
      break;
    }

    default:
      break;

  }
}

wxString CalibrationMethodList::OnGetItemText(long item, long column) const {
  wxString text;
  A2lDocument* doc = GetDoc();
  if (doc == nullptr) {
    return text;
  }

  const TreeItemType type = doc->SelectedType();
  void* object = doc->SelectedObject();
  if (type != TreeItemType::CAL_METHOD_LIST || object == nullptr) {
    return text;
  }
  auto* mod_par = static_cast<A2lModPar*>(object);
  if (mod_par == nullptr) {
    return text;
  }
  const auto& cal_list = mod_par->CalibrationMethodList;
  if (item < 0 || item >= cal_list.size()) {
    return text;
  }
  const auto& method = cal_list[item];

  switch (column) {
    case 0:
      text = wxString::FromUTF8(method.Method);
      break;

    case 1:
      text = wxString::FromUTF8(std::to_string(method.Version));
      break;

    default:
      break;
    }
  return text;
}

void CalibrationMethodList::OnItemSelected(wxListEvent &event) {
  const long index = event.GetIndex();
  A2lDocument* doc = GetDoc();
  if (doc == nullptr) {
    return;
  }
  doc->SetSelectedIndex(index);
  RedrawPropertyGrid();
}

void CalibrationMethodList::RedrawPropertyGrid() const {
  auto* splitter = dynamic_cast<wxSplitterWindow*>(GetParent());
  if (splitter == nullptr) {
    return;
  }
  auto* property_view = dynamic_cast<A2lPropertyGrid*>(splitter->GetWindow2());
  if (property_view == nullptr) {
    return;
  }
  property_view->Redraw();
}

} // a2lgui
