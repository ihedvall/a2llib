/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#include "functionlistview.h"

#include <wx/wx.h>

#include <ranges>

#include "a2l/function.h"
#include "a2l/module.h"
#include "mainframe.h"
#include "selectionlistdocument.h"
#include "selectionlisteditor.h"
#include "windowid.h"

namespace a2l {

wxBEGIN_EVENT_TABLE(FunctionListView, wxListView)
EVT_LIST_ITEM_ACTIVATED(kIdFunctionList, FunctionListView::OnDoubleClick)
wxEND_EVENT_TABLE()

FunctionListView::FunctionListView(wxWindow *parent)
: wxListView(parent, kIdFunctionList, wxDefaultPosition, wxDefaultSize,
    wxLC_REPORT | wxLC_SINGLE_SEL | wxLC_VIRTUAL) {

  InsertColumn(0, "Name", wxLIST_FORMAT_LEFT, 300);
  InsertColumn(1, "Interface",wxLIST_FORMAT_LEFT, 200);
  InsertColumn(2, "Description",wxLIST_FORMAT_LEFT, 300);
}

void FunctionListView::Redraw() {
    // Save the selected items so they still is selected after redraw
  std::set<std::string> selected_list;
  for (long selected = GetFirstSelected(); selected >= 0;
            selected = GetNextSelected(selected)) {
    wxString sel = GetItemText(selected, 0);
    if (!sel.empty()) {
      selected_list.emplace(sel.utf8_string());
    }
  }

  DeleteAllItems();

  const Module* module = GetModule();
  if (module == nullptr) {
    return;
  }
  const auto& flat_list = module->GetFlatFunctionList();
  const size_t item_count = flat_list.size();
  SetItemCount(static_cast<long>(item_count));

  for ( const std::string& selname : selected_list) {
    if (long find = module->GetFlatFunction(selname);
        find >= 0) {
     Select(find);
     EnsureVisible(find);
    }
  }
  if (item_count > 0) {
    RefreshItems(0, static_cast<long>(item_count) - 1);
  } else {
    Refresh();
  }

}

wxString FunctionListView::OnGetItemText(long item, long column) const {
  wxString text;
  const Module* module = GetModule();
  if (module == nullptr || item < 0) {
    return text;
  }
  const Function* function = module->GetFlatFunction(item);
  if (function == nullptr) {
    return text;
  }
  switch (column) {
    case 0: // Name
      text = wxString::FromUTF8(function->Name());
      break;

    case 1:  // IF DATA PROTOCOLS
      text = wxString::FromUTF8(function->IfDatasAsString());
      break;

    case 2:  // Description
      text = wxString::FromUTF8(function->Description());
      break;

    default:
      break;
  }
  return text;
}

// ReSharper disable once CppParameterMayBeConstPtrOrRef
// ReSharper disable once CppMemberFunctionMayBeStatic
void FunctionListView::OnDoubleClick(wxListEvent& event) {
  auto* module = GetModule();
  if (module == nullptr) {
    return;
  }
  const long row = event.GetIndex();
  if (row < 0) {
    return;
  }
  Function* function = module->GetFlatFunction(row);
  if (function == nullptr) {
    return;
  }
  // Add the selected characteristic to the label file
  SelectionObject object;
  object.SetDevice(module->Name());
  object.SetUserObject(function);
  object.SetObjectType(ObjectType::FUNCTION);
  object.SetName(function->Name());
  object.SetDescription(function->Description());
  if (auto* doc = GetDoc(); doc != nullptr) {
    doc->AddSelectionObject(std::move(object));
  }
}

SelectionListDocument* FunctionListView::GetDoc() {
  return MainFrame::GetDocument();
}

const Module* FunctionListView::GetModule() {
  auto* doc = GetDoc();
  if (doc == nullptr) {
    return nullptr;
  }
  auto* a2l_file = doc->GetA2lFile();
  if (a2l_file == nullptr) {
    return nullptr;
  }
  const A2lProject& project = a2l_file->Project();
  for ( const auto& module : project.Modules() | std::views::values ) {
    if (!module) {
      continue;
    }
    return module.get();
  }
  return nullptr;
}


} // a2l