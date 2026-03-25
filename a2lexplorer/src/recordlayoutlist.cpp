/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#include <wx/splitter.h>
#include <wx/wx.h>

#include "a2l/module.h"
#include "a2l/recordlayout.h"
#include "a2lpropertygrid.h"
#include "recordlayoutlist.h"
#include "windowid.h"

using namespace a2l;
namespace a2lgui {

wxBEGIN_EVENT_TABLE(RecordLayoutList, wxListView)
  EVT_LIST_ITEM_SELECTED(kIdRecordLayoutListView, RecordLayoutList::OnItemSelected)
wxEND_EVENT_TABLE()

RecordLayoutList::RecordLayoutList(wxWindow *parent)
: wxListView(parent, kIdRecordLayoutListView, wxDefaultPosition, wxDefaultSize,
    wxLC_REPORT | wxLC_SINGLE_SEL | wxLC_VIRTUAL) {

  InsertColumn(0, "Name", wxLIST_FORMAT_LEFT, 400);

}

void RecordLayoutList::Redraw() {
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
    case TreeItemType::RECORD_LAYOUT_LIST: {
      if (auto* module = static_cast<Module*>(object); module != nullptr) {
        const auto& layout_list = module->RecordLayouts();
        SetItemCount(static_cast<long>(layout_list.size()));
        if (selected >= 0 && selected < layout_list.size()) {
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

wxString RecordLayoutList::OnGetItemText(long item, long column) const {
  wxString text;
  A2lDocument* doc = GetDoc();
  if (doc == nullptr) {
    return text;
  }
  // ReSharper disable once CppDFAUnreachableCode
  const TreeItemType type = doc->SelectedType();
  void* object = doc->SelectedObject();
  if (type != TreeItemType::RECORD_LAYOUT_LIST || object == nullptr) {
    return text;
  }
  auto* module = static_cast<Module*>(object);
  if (module == nullptr) {
    return text;
  }
  const auto* layout = module->GetRecordLayout(item);
  if (layout == nullptr) {
    return text;
  }
  switch (column) {
    case 0:
      text = wxString::FromUTF8(layout->Name());
      break;

    default:
      break;
    }
  return text;
}

void RecordLayoutList::OnItemSelected(wxListEvent &event) {
  const long index = event.GetIndex();
  A2lDocument* doc = GetDoc();
  if (doc == nullptr) {
    return;
  }
  doc->SetSelectedIndex(index);
  RedrawPropertyGrid();
}

void RecordLayoutList::RedrawPropertyGrid() const {
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