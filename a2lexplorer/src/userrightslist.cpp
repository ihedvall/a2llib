/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#include "userrightslist.h"

#include <wx/wx.h>
#include <wx/splitter.h>

#include "a2lpropertygrid.h"
#include "a2l/module.h"
#include "a2l/a2lstructs.h"
#include "windowid.h"

using namespace a2l;
namespace a2lgui {

wxBEGIN_EVENT_TABLE(UserRightsList, wxListView)
  EVT_LIST_ITEM_SELECTED(kIdUserRightsListView, UserRightsList::OnItemSelected)
wxEND_EVENT_TABLE()

UserRightsList::UserRightsList(wxWindow *parent)
: wxListView(parent, kIdUserRightsListView, wxDefaultPosition, wxDefaultSize,
    wxLC_REPORT | wxLC_SINGLE_SEL | wxLC_VIRTUAL) {

  InsertColumn(0, "User Level ID", wxLIST_FORMAT_LEFT, 300);
}

void UserRightsList::Redraw() {
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
    case TreeItemType::USER_RIGHTS_LIST: {
      if (auto* module = static_cast<Module*>(object); module != nullptr) {
        const auto& user_list = module->UserRights();
        SetItemCount(static_cast<long>(user_list.size()));
        if (selected >= 0 && selected < user_list.size()) {
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

wxString UserRightsList::OnGetItemText(long item, long column) const {
  wxString text;
  A2lDocument* doc = GetDoc();
  if (doc == nullptr) {
    return text;
  }
  // ReSharper disable once CppDFAUnreachableCode
  const TreeItemType type = doc->SelectedType();
  void* object = doc->SelectedObject();
  if (type != TreeItemType::USER_RIGHTS_LIST || object == nullptr) {
    return text;
  }
  auto* module = static_cast<Module*>(object);
  if (module == nullptr) {
    return text;
  }
  const A2lUserRights* user = module->GetUserRights(item);
  if (user == nullptr) {
    return text;
  }
  switch (column) {
    case 0:
      text = wxString::FromUTF8(user->UserLevelId);
      break;

    default:
      break;
    }
  return text;
}

void UserRightsList::OnItemSelected(wxListEvent &event) {
  const long index = event.GetIndex();
  A2lDocument* doc = GetDoc();
  if (doc == nullptr) {
    return;
  }
  doc->SetSelectedIndex(index);
  RedrawPropertyGrid();
}

void UserRightsList::RedrawPropertyGrid() const {
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