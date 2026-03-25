/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#include "transformerlist.h"

#include <wx/wx.h>
#include <wx/splitter.h>

#include "a2lpropertygrid.h"
#include "a2l/module.h"
#include "a2l/transformer.h"
#include "windowid.h"

using namespace a2l;
namespace a2lgui {

wxBEGIN_EVENT_TABLE(TransformerList, wxListView)
  EVT_LIST_ITEM_SELECTED(kIdTransformerListView, TransformerList::OnItemSelected)
wxEND_EVENT_TABLE()

TransformerList::TransformerList(wxWindow *parent)
: wxListView(parent, kIdTransformerListView, wxDefaultPosition, wxDefaultSize,
    wxLC_REPORT | wxLC_SINGLE_SEL | wxLC_VIRTUAL) {

  InsertColumn(0, "Name", wxLIST_FORMAT_LEFT, 300);
  InsertColumn(1, "Trigger",wxLIST_FORMAT_LEFT, 150);
}

void TransformerList::Redraw() {
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
    case TreeItemType::TRANSFORMER_LIST: {
      if (auto* module = static_cast<Module*>(object); module != nullptr) {
        const auto& transformer_list = module->Transformers();
        SetItemCount(static_cast<long>(transformer_list.size()));
        if (selected >= 0 && selected < transformer_list.size()) {
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

wxString TransformerList::OnGetItemText(long item, long column) const {
  wxString text;
  A2lDocument* doc = GetDoc();
  if (doc == nullptr) {
    return text;
  }
  // ReSharper disable once CppDFAUnreachableCode
  const TreeItemType type = doc->SelectedType();
  void* object = doc->SelectedObject();
  if (type != TreeItemType::TRANSFORMER_LIST || object == nullptr) {
    return text;
  }
  auto* module = static_cast<Module*>(object);
  if (module == nullptr) {
    return text;
  }
  const Transformer* transformer = module->GetTransformer(item);
  if (transformer == nullptr) {
    return text;
  }
  switch (column) {
    case 0:
      text = wxString::FromUTF8(transformer->Name());
      break;

    case 1:
      text = wxString::FromUTF8(TriggerToString(transformer->Trigger()));
      break;

    default:
      break;
    }
  return text;
}

void TransformerList::OnItemSelected(wxListEvent &event) {
  const long index = event.GetIndex();
  A2lDocument* doc = GetDoc();
  if (doc == nullptr) {
    return;
  }
  doc->SetSelectedIndex(index);
  RedrawPropertyGrid();
}

void TransformerList::RedrawPropertyGrid() const {
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