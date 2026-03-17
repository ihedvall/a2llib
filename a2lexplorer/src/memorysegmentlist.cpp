/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#include "memorysegmentlist.h"

#include <sstream>

#include <wx/wx.h>
#include <wx/splitter.h>

#include "a2lpropertygrid.h"
#include "a2l/module.h"
#include "a2l/a2lstructs.h"
#include "windowid.h"

using namespace a2l;
namespace a2lgui {

wxBEGIN_EVENT_TABLE(MemorySegmentList, wxListView)
  EVT_LIST_ITEM_SELECTED(kIdMemorySegmentListView, MemorySegmentList::OnItemSelected)
wxEND_EVENT_TABLE()

MemorySegmentList::MemorySegmentList(wxWindow *parent)
: wxListView(parent, kIdMemorySegmentListView, wxDefaultPosition, wxDefaultSize,
    wxLC_REPORT | wxLC_SINGLE_SEL| wxLC_VIRTUAL) {

  InsertColumn(0, "Name", wxLIST_FORMAT_LEFT, 150);
  InsertColumn(2, "Segment/Memory Type",wxLIST_FORMAT_LEFT, 200);
  InsertColumn(3, "Interface",wxLIST_FORMAT_LEFT, 150);
}

void MemorySegmentList::Redraw() {
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
    case TreeItemType::MEM_SEGMENT_LIST: {
      if (auto* mod_par = static_cast<A2lModPar*>(object); mod_par != nullptr) {
        const auto& mem_list = mod_par->MemorySegmentList;
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

wxString MemorySegmentList::OnGetItemText(long item, long column) const {
  wxString text;
  A2lDocument* doc = GetDoc();
  if (doc == nullptr) {
    return text;
  }

  const TreeItemType type = doc->SelectedType();
  void* object = doc->SelectedObject();
  if (type != TreeItemType::MEM_SEGMENT_LIST || object == nullptr) {
    return text;
  }
  auto* mod_par = static_cast<A2lModPar*>(object);
  if (mod_par == nullptr) {
    return text;
  }
  const auto& mem_list = mod_par->MemorySegmentList;
  if (item < 0 || item >= mem_list.size()) {
    return text;
  }
  const auto& segment = mem_list[item];

  switch (column) {
    case 0:
      text = wxString::FromUTF8(segment.Name);
      break;

    case 1: {
      std::ostringstream types;
      types << SegmentTypeToString(segment.SegmentType) << "/" <<
        MemoryTypeToString(segment.MemoryType);
      text = wxString::FromUTF8(types.str());
      break;
    }

    case 2: {
      std::ostringstream interfaces;
      for ( const auto& [com, if_data] : segment.IfDataList) {
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

void MemorySegmentList::OnItemSelected(wxListEvent &event) {
  const long index = event.GetIndex();
  A2lDocument* doc = GetDoc();
  if (doc == nullptr) {
    return;
  }
  doc->SetSelectedIndex(index);
  RedrawPropertyGrid();
}

void MemorySegmentList::RedrawPropertyGrid() const {
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
