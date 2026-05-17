/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#include "ifdatalist.h"

#include <wx/wx.h>
#include <wx/splitter.h>

#include "a2lpropertygrid.h"
#include "a2l/module.h"

#include "windowid.h"

using namespace a2l;
namespace a2lgui {

wxBEGIN_EVENT_TABLE(IfDataList, wxListView)
  EVT_LIST_ITEM_SELECTED(kIfDataListView, IfDataList::OnItemSelected)
wxEND_EVENT_TABLE()

IfDataList::IfDataList(wxWindow *parent)
: wxListView(parent, kIfDataListView, wxDefaultPosition, wxDefaultSize,
    wxLC_REPORT | wxLC_SINGLE_SEL | wxLC_VIRTUAL) {

  InsertColumn(0, "Protocol", wxLIST_FORMAT_LEFT, 200);
  InsertColumn(1, "Version",wxLIST_FORMAT_LEFT, 100);
}

void IfDataList::Redraw() {
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
    case TreeItemType::IF_DATA_LIST: {
      if (auto* module = static_cast<Module*>(object); module != nullptr) {
        const auto& if_data_list = module->IfDatas();
        SetItemCount(static_cast<long>(if_data_list.size()));
        if (selected < 0 && !if_data_list.empty()) {
          selected = 0;
        }
        if (selected >= 0 && selected < if_data_list.size()) {
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

wxString IfDataList::OnGetItemText(long item, long column) const {
  wxString text;
  A2lDocument* doc = GetDoc();
  if (doc == nullptr) {
    return text;
  }
  // ReSharper disable once CppDFAUnreachableCode
  const TreeItemType type = doc->SelectedType();
  void* object = doc->SelectedObject();
  if (type != TreeItemType::IF_DATA_LIST || object == nullptr) {
    return text;
  }
  auto* module = static_cast<Module*>(object);
  if (module == nullptr) {
    return text;
  }

  const auto if_data = module->GetIfData(item);
  const std::string& protocol = if_data.first;
  std::string version = "Unknown";
  if (protocol == "XCPplus") {
    if (const xcp::XcpDataBlock* data_block = module->GetXcpPlusDataBlock();
      data_block != nullptr) {
      version = data_block->GetVersionAsString();
    }
  } else if (protocol == "XCP") {
    if (const xcp::XcpDataBlock* data_block = module->GetXcpDataBlock();
      data_block != nullptr) {
      version = data_block->GetVersionAsString();
    }
  } else if (protocol == "ASAP1B_CCP") {
    if (const ccp::CcpDataBlock* data_block = module->GetCcpDataBlock();
      data_block != nullptr) {
      if (const auto* tp_blob = data_block->GetTpBlob(); tp_blob != nullptr) {
        version = tp_blob->GetVersionAsString();
      }
    }
  }
  switch (column) {
    case 0:
      text = wxString::FromUTF8(if_data.first);
      break;

    case 1:
      text = wxString::FromUTF8(version);
      break;

    default:
      break;
    }
  return text;
}

void IfDataList::OnItemSelected(wxListEvent &event) {
  const long index = event.GetIndex();
  A2lDocument* doc = GetDoc();
  if (doc == nullptr) {
    return;
  }
  doc->SetSelectedIndex(index);
  RedrawPropertyGrid();
}

void IfDataList::RedrawPropertyGrid() const {
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