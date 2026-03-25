/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#include "bloblist.h"

#include <wx/wx.h>
#include <wx/splitter.h>

#include "a2lpropertygrid.h"
#include "a2l/module.h"
#include "a2l/blob.h"
#include "windowid.h"

using namespace a2l;
namespace a2lgui {

wxBEGIN_EVENT_TABLE(BlobList, wxListView)
  EVT_LIST_ITEM_SELECTED(kIdBlobListView, BlobList::OnItemSelected)
wxEND_EVENT_TABLE()

BlobList::BlobList(wxWindow *parent)
: wxListView(parent, kIdBlobListView, wxDefaultPosition, wxDefaultSize,
    wxLC_REPORT | wxLC_SINGLE_SEL | wxLC_VIRTUAL) {

  InsertColumn(0, "Name", wxLIST_FORMAT_LEFT, 250);
  InsertColumn(1, "Address",wxLIST_FORMAT_LEFT, 200);
  InsertColumn(2, "Size",wxLIST_FORMAT_LEFT, 75);
}

void BlobList::Redraw() {
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
    case TreeItemType::BLOB_LIST: {
      if (auto* module = static_cast<Module*>(object); module != nullptr) {
        const auto& blob_list = module->Blobs();
        SetItemCount(static_cast<long>(blob_list.size()));
        if (selected >= 0 && selected < blob_list.size()) {
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

wxString BlobList::OnGetItemText(long item, long column) const {
  wxString text;
  A2lDocument* doc = GetDoc();
  if (doc == nullptr) {
    return text;
  }
  // ReSharper disable once CppDFAUnreachableCode
  const TreeItemType type = doc->SelectedType();
  void* object = doc->SelectedObject();
  if (type != TreeItemType::BLOB_LIST || object == nullptr) {
    return text;
  }
  auto* module = static_cast<Module*>(object);
  if (module == nullptr) {
    return text;
  }
  const Blob* blob = module->GetBlob(item);
  if (blob == nullptr) {
    return text;
  }
  switch (column) {
    case 0:
      text = wxString::FromUTF8(blob->Name());
      break;

    case 1:
      text = wxString::FromUTF8(A2lDocument::AddressToString(blob->Address()));
      break;

    case 2:
      text = wxString::FromUTF8(std::to_string(blob->Size()));
      break;

    default:
      break;
    }
  return text;
}

void BlobList::OnItemSelected(wxListEvent &event) {
  const long index = event.GetIndex();
  A2lDocument* doc = GetDoc();
  if (doc == nullptr) {
    return;
  }
  doc->SetSelectedIndex(index);
  RedrawPropertyGrid();
}

void BlobList::RedrawPropertyGrid() const {
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