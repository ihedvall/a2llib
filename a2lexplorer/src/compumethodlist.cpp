/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#include "compumethodlist.h"

#include <wx/wx.h>
#include <wx/splitter.h>

#include "a2lpropertygrid.h"
#include "a2l/module.h"
#include "a2l/compumethod.h"
#include "windowid.h"

using namespace a2l;
namespace a2lgui {

wxBEGIN_EVENT_TABLE(CompuMethodList, wxListView)
  EVT_LIST_ITEM_SELECTED(kIdCompuMethodListView, CompuMethodList::OnItemSelected)
wxEND_EVENT_TABLE()

CompuMethodList::CompuMethodList(wxWindow *parent)
: wxListView(parent, kIdCompuMethodListView, wxDefaultPosition, wxDefaultSize,
    wxLC_REPORT | wxLC_SINGLE_SEL | wxLC_VIRTUAL) {

  InsertColumn(0, "Name", wxLIST_FORMAT_LEFT, 300);
  InsertColumn(1, "Type",wxLIST_FORMAT_LEFT, 100);
  InsertColumn(2, "Unit",wxLIST_FORMAT_LEFT, 100);
}

void CompuMethodList::Redraw() {
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
    case TreeItemType::COMPU_METHOD_LIST: {
      if (auto* module = static_cast<Module*>(object); module != nullptr) {
        const auto& method_list = module->CompuMethods();
        SetItemCount(static_cast<long>(method_list.size()));
        if (selected >= 0 && selected < method_list.size()) {
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

wxString CompuMethodList::OnGetItemText(long item, long column) const {
  wxString text;
  A2lDocument* doc = GetDoc();
  if (doc == nullptr) {
    return text;
  }
  // ReSharper disable once CppDFAUnreachableCode
  const TreeItemType type = doc->SelectedType();
  void* object = doc->SelectedObject();
  if (type != TreeItemType::COMPU_METHOD_LIST || object == nullptr) {
    return text;
  }
  auto* module = static_cast<Module*>(object);
  if (module == nullptr) {
    return text;
  }
  const auto* method = module->GetCompuMethod(item);
  if (method == nullptr) {
    return text;
  }
  switch (column) {
    case 0:
      text = wxString::FromUTF8(method->Name());
      break;

    case 1:
      text = wxString::FromUTF8(ConversionTypeToString(method->Type()));
      break;

    case 2:
      text = wxString::FromUTF8(method->PhysUnit());
      break;

    default:
      break;
    }
  return text;
}

void CompuMethodList::OnItemSelected(wxListEvent &event) {
  const long index = event.GetIndex();
  A2lDocument* doc = GetDoc();
  if (doc == nullptr) {
    return;
  }
  doc->SetSelectedIndex(index);
  RedrawPropertyGrid();
}

void CompuMethodList::RedrawPropertyGrid() const {
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