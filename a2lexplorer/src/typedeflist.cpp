/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#include "typedeflist.h"

#include <wx/wx.h>
#include <wx/splitter.h>

#include "a2lpropertygrid.h"
#include "a2l/module.h"
#include "a2l/a2lobject.h"

#include "windowid.h"

using namespace a2l;
namespace a2lgui {

wxBEGIN_EVENT_TABLE(TypedefList, wxListView)
  EVT_LIST_ITEM_SELECTED(kIdTypedefListView, TypedefList::OnItemSelected)
wxEND_EVENT_TABLE()

TypedefList::TypedefList(wxWindow *parent)
: wxListView(parent, kIdTypedefListView, wxDefaultPosition, wxDefaultSize,
    wxLC_REPORT | wxLC_SINGLE_SEL | wxLC_VIRTUAL) {

  InsertColumn(0, "Name", wxLIST_FORMAT_LEFT, 300);
  InsertColumn(1, "Type",wxLIST_FORMAT_LEFT, 200);
}

void TypedefList::Redraw() {
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
    case TreeItemType::TYPEDEF_LIST: {
      if (auto* module = static_cast<Module*>(object); module != nullptr) {
        const auto& typedef_list = module->GetTypedefList();
        SetItemCount(static_cast<long>(typedef_list.size()));
        if (selected >= 0 && selected < typedef_list.size()) {
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

wxString TypedefList::OnGetItemText(long item, long column) const {
  wxString text;
  A2lDocument* doc = GetDoc();
  if (doc == nullptr) {
    return text;
  }

  const TreeItemType type = doc->SelectedType();
  void* object = doc->SelectedObject();
  if (type != TreeItemType::TYPEDEF_LIST || object == nullptr) {
    return text;
  }
  auto* module = static_cast<Module*>(object);
  if (module == nullptr) {
    return text;
  }
  const FlatTypedefPair def = module->GetTypedef(item);
  if (def.second == nullptr) {
    return text;
  }
  switch (column) {
    case 0:
      text = wxString::FromUTF8(def.second->Name());
      break;

    case 1:
      text = wxString::FromUTF8(TypedefTypeToString(def.first));
      break;

    default:
      break;
  }
  return text;
}

void TypedefList::OnItemSelected(wxListEvent &event) {
  const long index = event.GetIndex();
  A2lDocument* doc = GetDoc();
  if (doc == nullptr) {
    return;
  }
  doc->SetSelectedIndex(index);
  RedrawPropertyGrid();
}

void TypedefList::RedrawPropertyGrid() const {
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