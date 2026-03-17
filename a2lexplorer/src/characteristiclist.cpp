/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#include "characteristiclist.h"

#include <wx/wx.h>
#include <wx/splitter.h>

#include "a2lpropertygrid.h"
#include "a2l/module.h"
#include "a2l/characteristic.h"
#include "windowid.h"

using namespace a2l;
namespace a2lgui {

wxBEGIN_EVENT_TABLE(CharacteristicList, wxListView)
  EVT_LIST_ITEM_SELECTED(kIdCharacteristicListView, CharacteristicList::OnItemSelected)
wxEND_EVENT_TABLE()

CharacteristicList::CharacteristicList(wxWindow *parent)
: wxListView(parent, kIdCharacteristicListView, wxDefaultPosition, wxDefaultSize,
    wxLC_REPORT | wxLC_SINGLE_SEL | wxLC_VIRTUAL) {

  InsertColumn(0, "Name", wxLIST_FORMAT_LEFT, 400);
  InsertColumn(1, "Type",wxLIST_FORMAT_LEFT, 100);
}

void CharacteristicList::Redraw() {
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
    case TreeItemType::CHARACTERISTIC_LIST: {
      if (auto* module = static_cast<Module*>(object); module != nullptr) {
        const auto& characteristic_list = module->Characteristics();
        SetItemCount(static_cast<long>(characteristic_list.size()));
        if (selected >= 0 && selected < characteristic_list.size()) {
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

wxString CharacteristicList::OnGetItemText(long item, long column) const {
  wxString text;
  A2lDocument* doc = GetDoc();
  if (doc == nullptr) {
    return text;
  }
  // ReSharper disable once CppDFAUnreachableCode
  const TreeItemType type = doc->SelectedType();
  void* object = doc->SelectedObject();
  if (type != TreeItemType::CHARACTERISTIC_LIST || object == nullptr) {
    return text;
  }
  auto* module = static_cast<Module*>(object);
  if (module == nullptr) {
    return text;
  }
  const auto* characteristic = module->GetCharacteristic(item);
  if (characteristic == nullptr) {
    return text;
  }
  switch (column) {
    case 0:
      text = wxString::FromUTF8(characteristic->Name());
      break;

    case 1:
      text = wxString::FromUTF8(CharacteristicTypeToString(characteristic->Type() ));
      break;

    default:
      break;
    }
  return text;
}

void CharacteristicList::OnItemSelected(wxListEvent &event) {
  const long index = event.GetIndex();
  A2lDocument* doc = GetDoc();
  if (doc == nullptr) {
    return;
  }
  doc->SetSelectedIndex(index);
  RedrawPropertyGrid();
}

void CharacteristicList::RedrawPropertyGrid() const {
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