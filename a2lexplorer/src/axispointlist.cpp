/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#include "axispointlist.h"

#include <wx/wx.h>
#include <wx/splitter.h>

#include "a2lpropertygrid.h"
#include "a2l/module.h"
#include "a2l/axispts.h"
#include "windowid.h"

using namespace a2l;
namespace a2lgui {

wxBEGIN_EVENT_TABLE(AxisPointList, wxListView)
  EVT_LIST_ITEM_SELECTED(kIdAxisPointListView,AxisPointList::OnItemSelected)
wxEND_EVENT_TABLE()

AxisPointList::AxisPointList(wxWindow *parent)
: wxListView(parent, kIdAxisPointListView, wxDefaultPosition, wxDefaultSize,
    wxLC_REPORT | wxLC_SINGLE_SEL | wxLC_VIRTUAL) {

  InsertColumn(0, "Name", wxLIST_FORMAT_LEFT, 300);
  InsertColumn(1, "Description",wxLIST_FORMAT_LEFT, 300);
}

void AxisPointList::Redraw() {
  A2lDocument* doc = GetDoc();
  if (doc == nullptr) {
    return;
  }
  long selected = GetFirstSelected();
  if (selected < 0) {
    selected = 0;
  }

  doc->SetSelectedIndex(selected);
  DeleteAllItems();
  const TreeItemType type = doc->SelectedType();
  void* object = doc->SelectedObject();
  if (object == nullptr) {
    return;
  }

  switch (type) {
    case TreeItemType::AXIS_PTS_LIST: {
      if (auto* module = static_cast<Module*>(object); module != nullptr) {
        const auto& axis_list = module->AxisPtss();
        SetItemCount(static_cast<long>(axis_list.size()));
        if (selected >= 0 && selected < axis_list.size()) {
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

wxString AxisPointList::OnGetItemText(long item, long column) const {
  wxString text;
  A2lDocument* doc = GetDoc();
  if (doc == nullptr) {
    return text;
  }
  // ReSharper disable once CppDFAUnreachableCode
  const TreeItemType type = doc->SelectedType();
  void* object = doc->SelectedObject();
  if (type != TreeItemType::AXIS_PTS_LIST || object == nullptr) {
    return text;
  }
  auto* module = static_cast<Module*>(object);
  if (module == nullptr) {
    return text;
  }
  const auto* axis_pts = module->GetAxisPts(item);
  if (axis_pts == nullptr) {
    return text;
  }
  switch (column) {
    case 0:
      text = wxString::FromUTF8(axis_pts->Name());
      break;

    case 1:
      text = wxString::FromUTF8(axis_pts->Description());
      break;

    default:
      break;
    }
  return text;
}

void AxisPointList::OnItemSelected(wxListEvent &event) {
  const long index = event.GetIndex();
  A2lDocument* doc = GetDoc();
  if (doc == nullptr) {
    return;
  }
  doc->SetSelectedIndex(index);
  RedrawPropertyGrid();
}

void AxisPointList::RedrawPropertyGrid() const {
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