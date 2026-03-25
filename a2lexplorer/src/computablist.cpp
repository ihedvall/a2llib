/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#include "computablist.h"

#include <wx/wx.h>
#include <wx/splitter.h>

#include "a2lpropertygrid.h"
#include "a2l/module.h"
#include "a2l/computab.h"
#include "a2l/compuvtab.h"
#include "a2l/compuvtabrange.h"
#include "windowid.h"

using namespace a2l;
namespace a2lgui {

wxBEGIN_EVENT_TABLE(CompuTabList, wxListView)
  EVT_LIST_ITEM_SELECTED(kIdCompuTabListView, CompuTabList::OnItemSelected)
wxEND_EVENT_TABLE()

CompuTabList::CompuTabList(wxWindow *parent)
: wxListView(parent, kIdCompuTabListView, wxDefaultPosition, wxDefaultSize,
    wxLC_REPORT | wxLC_SINGLE_SEL | wxLC_VIRTUAL) {

  InsertColumn(0, "Name", wxLIST_FORMAT_LEFT, 300);
  InsertColumn(1, "Type",wxLIST_FORMAT_LEFT, 100);
  InsertColumn(2, "Description",wxLIST_FORMAT_LEFT, 200);
}

void CompuTabList::Redraw() {
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
    case TreeItemType::COMPU_TAB_LIST: {
      if (auto* module = static_cast<Module*>(object); module != nullptr) {
        const auto& tab_list = module->CompuTabs();
        const auto& vtab_list = module->CompuVtabs();
        const auto& vtab_range_list = module->CompuVtabRanges();
        const size_t count = tab_list.size() + vtab_list.size() + vtab_range_list.size();
        SetItemCount(static_cast<long>(count));
        if (selected >= 0 && selected < count) {
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

wxString CompuTabList::OnGetItemText(long item, long column) const {
  wxString text;
  A2lDocument* doc = GetDoc();
  if (doc == nullptr || item < 0) {
    return text;
  }
  // ReSharper disable once CppDFAUnreachableCode
  const TreeItemType type = doc->SelectedType();
  void* object = doc->SelectedObject();
  if (type != TreeItemType::COMPU_TAB_LIST || object == nullptr) {
    return text;
  }
  auto* module = static_cast<Module*>(object);
  if (module == nullptr) {
    return text;
  }

  const auto& tab_list = module->CompuTabs();
  if (item >= 0 && item < tab_list.size()) {
    if (const CompuTab* tab = module->GetCompuTab(item); tab != nullptr) {
      switch (column) {
        case 0:
          text = wxString::FromUTF8(tab->Name());
          break;

        case 1:
          text = wxString::FromUTF8(ConversionTypeToString(tab->Type()));
          break;

        case 2:
          text = wxString::FromUTF8(tab->Description());
          break;

        default:
          break;
      }

    }
    return text;
  }

  item -= tab_list.size();
  const auto& vtab_list = module->CompuVtabs();
  if (item >= 0 && item < vtab_list.size()) {
    if (const CompuVtab* tab = module->GetCompuVtab(item); tab != nullptr) {
      switch (column) {
        case 0:
          text = wxString::FromUTF8(tab->Name());
          break;

        case 1:
          text = wxString::FromUTF8(ConversionTypeToString(tab->Type()));
          break;

        case 2:
          text = wxString::FromUTF8(tab->Description());
          break;

        default:
          break;
      }

    }
    return text;
  }

  item -= vtab_list.size();
  const auto& vtab_range_list = module->CompuVtabRanges();
  if (item >= 0 && item < vtab_range_list.size()) {
    if (const CompuVtabRange* tab = module->GetCompuVtabRange(item); tab != nullptr) {
      switch (column) {
        case 0:
          text = wxString::FromUTF8(tab->Name());
          break;

        case 1:
          text = wxString::FromUTF8("");
          break;

        case 2:
          text = wxString::FromUTF8(tab->Description());
          break;

        default:
          break;
      }
    }
  }
  return text;
}

void CompuTabList::OnItemSelected(wxListEvent &event) {
  const long index = event.GetIndex();
  A2lDocument* doc = GetDoc();
  if (doc == nullptr) {
    return;
  }
  doc->SetSelectedIndex(index);
  RedrawPropertyGrid();
}

void CompuTabList::RedrawPropertyGrid() const {
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