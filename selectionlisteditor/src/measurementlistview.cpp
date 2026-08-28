/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#include "measurementlistview.h"

#include <wx/wx.h>

#include <ranges>

#include "a2l/measurement.h"
#include "a2l/module.h"
#include "mainframe.h"
#include "selectionlistdocument.h"
#include "selectionlisteditor.h"
#include "windowid.h"

namespace a2l {

wxBEGIN_EVENT_TABLE(MeasurementListView, wxListView)
EVT_LIST_ITEM_ACTIVATED(kIdMeasurementList, MeasurementListView::OnDoubleClick)
wxEND_EVENT_TABLE()

MeasurementListView::MeasurementListView(wxWindow *parent)
: wxListView(parent, kIdMeasurementList, wxDefaultPosition, wxDefaultSize,
    wxLC_REPORT | wxLC_SINGLE_SEL | wxLC_VIRTUAL) {

  InsertColumn(0, "Name", wxLIST_FORMAT_LEFT, 300);
  InsertColumn(1, "Unit",wxLIST_FORMAT_LEFT, 75);
  InsertColumn(2, "Limit",wxLIST_FORMAT_LEFT, 75);
  InsertColumn(3, "Interface",wxLIST_FORMAT_LEFT, 200);
  InsertColumn(4, "Description",wxLIST_FORMAT_LEFT, 300);
}

void MeasurementListView::Redraw() {
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
  const auto& flat_list = module->GetFlatMeasurementList();
  const size_t item_count = flat_list.size();
  SetItemCount(static_cast<long>(item_count));

  for ( const std::string& selname : selected_list) {
    if (long find = module->GetFlatMeasurement(selname);
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

wxString MeasurementListView::OnGetItemText(long item, long column) const {
  wxString text;
  const Module* module = GetModule();
  if (module == nullptr || item < 0) {
    return text;
  }
  const Measurement* measurement = module->GetFlatMeasurement(item);
  if (measurement == nullptr) {
    return text;
  }
  switch (column) {
    case 0: // Name
      text = wxString::FromUTF8(measurement->Name());
      break;

    case 1:  // Unit
      text = wxString::FromUTF8(module->GetUnitString(*measurement));
      break;

    case 2: // Limit
      if (measurement->HaveLimit()) {
        std::ostringstream temp;
        temp << measurement->LowerLimit() << "/" << measurement->UpperLimit();
        text = wxString::FromUTF8(temp.str());
      }
      break;

    case 3:  // IF DATA PROTOCOLS
      text = wxString::FromUTF8(measurement->IfDatasAsString());
      break;

    case 4:  // Description
      text = wxString::FromUTF8(measurement->Description());
      break;

    default:
      break;
  }
  return text;
}

// ReSharper disable once CppParameterMayBeConstPtrOrRef
// ReSharper disable once CppMemberFunctionMayBeStatic
void MeasurementListView::OnDoubleClick(wxListEvent& event) {
  auto* module = GetModule();
  if (module == nullptr) {
    return;
  }
  const long row = event.GetIndex();
  if (row < 0) {
    return;
  }
  Measurement* measurement = module->GetFlatMeasurement(row);
  if (measurement == nullptr) {
    return;
  }
  // Add the selected characteristic to the label file
  SelectionObject object;
  object.SetDevice(module->Name());
  object.SetUserObject(measurement);
  object.SetObjectType(ObjectType::RAMCELL);
  object.SetName(measurement->Name());
  object.SetDescription(measurement->Description());

  std::string unit = module->GetUnitString(*measurement);
  object.SetUnit(unit);
  object.SetLowerLimit(measurement->LowerLimit());
  object.SetUpperLimit(measurement->UpperLimit());
  if (auto* doc = GetDoc(); doc != nullptr) {
    doc->AddSelectionObject(std::move(object));
  }

}

SelectionListDocument* MeasurementListView::GetDoc() {
  return MainFrame::GetDocument();
}

const Module* MeasurementListView::GetModule() {
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