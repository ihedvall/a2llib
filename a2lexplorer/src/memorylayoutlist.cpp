/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#include "memorylayoutlist.h"

#include <sstream>

#include <wx/wx.h>
#include <wx/splitter.h>

#include "a2lpropertygrid.h"
#include "a2l/module.h"
#include "a2l/a2lstructs.h"
#include "windowid.h"

using namespace a2l;
namespace a2lgui {

wxBEGIN_EVENT_TABLE(MemoryLayoutList, wxListView)
  EVT_LIST_ITEM_SELECTED(kIdMemoryLayoutListView, MemoryLayoutList::OnItemSelected)
wxEND_EVENT_TABLE()

MemoryLayoutList::MemoryLayoutList(wxWindow *parent)
: wxListView(parent, kIdMemoryLayoutListView, wxDefaultPosition, wxDefaultSize,
    wxLC_REPORT | wxLC_SINGLE_SEL| wxLC_VIRTUAL) {

  InsertColumn(0, "Program Type", wxLIST_FORMAT_LEFT, 100);
  InsertColumn(1, "Interface",wxLIST_FORMAT_LEFT, 300);
}

void MemoryLayoutList::Redraw() {
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
    case TreeItemType::MEM_LAYOUT_LIST: {
      if (auto* mod_par = static_cast<A2lModPar*>(object); mod_par != nullptr) {
        const auto& mem_list = mod_par->MemoryLayoutList;
        SetItemCount(static_cast<long>(mem_list.size()));
        if (selected >= 0 && selected < mem_list.size()) {
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

wxString MemoryLayoutList::OnGetItemText(long item, long column) const {
  wxString text;
  A2lDocument* doc = GetDoc();
  if (doc == nullptr) {
    return text;
  }

  const TreeItemType type = doc->SelectedType();
  void* object = doc->SelectedObject();
  if (type != TreeItemType::MEM_LAYOUT_LIST || object == nullptr) {
    return text;
  }
  auto* mod_par = static_cast<A2lModPar*>(object);
  if (mod_par == nullptr) {
    return text;
  }
  const auto& mem_list = mod_par->MemoryLayoutList;
  if (item < 0 || item >= mem_list.size()) {
    return text;
  }
  const auto& layout = mem_list[item];

  switch (column) {
    case 0:
      text = wxString::FromUTF8(PrgTypeToString(layout.Type));
      break;

    case 1: {
      std::ostringstream interfaces;
      for ( const auto& [com, if_data] : layout.IfDataList) {
        interfaces << com << " ";
      }
      text = wxString::FromUTF8(interfaces.str());
      break;
    }

    default:
      break;
    }
  return text;
}

void MemoryLayoutList::OnItemSelected(wxListEvent &event) {
  const long index = event.GetIndex();
  A2lDocument* doc = GetDoc();
  if (doc == nullptr) {
    return;
  }
  doc->SetSelectedIndex(index);
  RedrawPropertyGrid();
}

void MemoryLayoutList::RedrawPropertyGrid() const {
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
