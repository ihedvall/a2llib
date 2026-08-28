/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#include "filterlistview.h"

#include <wx/valgen.h>

#include <ranges>
#include <set>
#include <string>
#include <vector>

#include <a2l/filterlist.h>

#include "mainframe.h"
#include "selectionpage.h"
#include "windowid.h"

using namespace a2l;

namespace a2l {

wxBEGIN_EVENT_TABLE(FilterListView, wxPanel)
  EVT_SEARCH(kIdNameFilter, FilterListView::OnNameChanged)
  EVT_SEARCH_CANCEL(kIdNameFilter, FilterListView::OnNameClear)
  EVT_TEXT(kIdNameFilter, FilterListView::OnNameChanged)
  EVT_CHOICE(kIdUnitFilter, FilterListView::OnUnitChanged)
  EVT_CHOICE(kIdInterfaceFilter, FilterListView::OnInterfaceChanged)
wxEND_EVENT_TABLE()

FilterListView::FilterListView(wxWindow* parent, wxWindowID filter_id)
  : wxPanel(parent, filter_id) {
  name_ctrl_ = new wxSearchCtrl(this, kIdNameFilter,
    name_filter_, wxDefaultPosition, wxDefaultSize,
    wxTE_PROCESS_ENTER | wxTE_LEFT);
  name_ctrl_->ShowSearchButton(true);
  name_ctrl_->ShowCancelButton(true);
  name_ctrl_->SetDescriptiveText("Filter name");
  name_ctrl_->SetMinSize(wxSize(150, -1));

  const bool show_unit = filter_id == kIdMeasurementListFilter ||
                         filter_id == kIdCharacteristicListFilter;
  if (show_unit) {
    const std::vector<wxString> unit_list = {""};
    unit_ctrl_ = new wxChoice(this, kIdUnitFilter,
      wxDefaultPosition, wxDefaultSize, unit_list, wxCB_SORT,
      wxGenericValidator(&unit_filter_));
  }

  interface_list_.emplace_back("");
  interface_ctrl_ = new wxChoice(this, kIdInterfaceFilter,
    wxDefaultPosition, wxDefaultSize, interface_list_, wxCB_SORT,
    wxGenericValidator(&interface_filter_));

  auto* main_sizer = new wxBoxSizer(wxHORIZONTAL);

  main_sizer->Add(new wxStaticText(this, wxID_ANY, "Name:"));
  main_sizer->AddSpacer(5);
  main_sizer->Add(name_ctrl_);
  main_sizer->AddSpacer(5);

  if (show_unit) {
    main_sizer->Add(new wxStaticText(this, wxID_ANY, "Unit:"));
    main_sizer->AddSpacer(5);
    main_sizer->Add(unit_ctrl_);
    main_sizer->AddSpacer(5);
  }
  main_sizer->Add(new wxStaticText(this, wxID_ANY, "Interface:"));
  main_sizer->AddSpacer(5);
  main_sizer->Add(interface_ctrl_);

  SetSizer(main_sizer);
}

SelectionListDocument* FilterListView::GetDoc() {
  return MainFrame::GetDocument();
}

Module* FilterListView::GetModule() {
  auto* doc = GetDoc();
  if (doc == nullptr) {
    return nullptr;
  }
  const A2lFile* a2l_file = doc->GetA2lFile();
  if (a2l_file == nullptr) {
    return nullptr;
  }
  const A2lProject& project = a2l_file->Project();
  for (const auto& module :
                project.Modules() | std::views::values) {
    if (module) {
      return module.get();
    }
  }

  return nullptr;
}

void FilterListView::Redraw() {
  UpdateList();
  Fit();
}

void FilterListView::UpdateList() {

  const wxWindowID list_id = GetId();
  auto* module = GetModule();
  if (module == nullptr) {
    return;
  }
  std::set<std::string> sorted_interface_list;
  std::set<std::string> sorted_unit_list;
  sorted_interface_list.insert("");
  sorted_unit_list.insert("");

  switch (list_id) {
    case kIdCharacteristicListFilter:
      for (const auto& characteristic :
              module->Characteristics() | std::views::values) {
        if (!characteristic) {
          continue;
        }
        std::string unit = module->GetUnitString(*characteristic);
        sorted_unit_list.insert(unit);
        for (const auto& interface_name :
             characteristic->IfDatas() | std::views::keys) {
          sorted_interface_list.insert(interface_name);
        }
      }
      break;

    case kIdMeasurementListFilter:
      for (const auto& measurement :
              module->Measurements() | std::views::values) {
        if (!measurement) {
          continue;
        }
        std::string unit = module->GetUnitString(*measurement);;
        sorted_unit_list.insert(unit);

        for (const auto& interface_name :
             measurement->IfDatas() | std::views::keys) {
          sorted_interface_list.insert(interface_name);
        }
      }
      break;

    case kIdFunctionListFilter:
      for (const auto& function :
              module->Functions() | std::views::values) {
        if (!function) {
          continue;
        }
        for (const auto& interface_name :
             function->IfDatas() | std::views::keys) {
          sorted_interface_list.insert(interface_name);
        }
      }
      break;

    case kIdGroupListFilter:
      for (const auto& group :
              module->Groups() | std::views::values) {
        if (!group) {
          continue;
        }
        for (const auto& interface_name :
             group->IfDatas() | std::views::keys) {
          sorted_interface_list.insert(interface_name);
        }
      }
      break;

    default:
      break;
  }

  if (interface_list_.size() != sorted_interface_list.size()) {
    interface_list_.clear();
    interface_list_.resize(sorted_interface_list.size());
    std::ranges::transform(sorted_interface_list, interface_list_.begin(),
                            [](const std::string& str) {
                              return wxString::FromUTF8(str);
                            });

    if (interface_ctrl_ != nullptr) {
      interface_ctrl_->Set(interface_list_);
      wxSize size = interface_ctrl_->GetBestSize();
      size.SetHeight(-1);
      interface_ctrl_->SetMinSize(size);
    }
  }

  if (unit_list_.size() != sorted_unit_list.size()) {
    unit_list_.clear();
    unit_list_.resize(sorted_unit_list.size());
    std::ranges::transform(sorted_unit_list, unit_list_.begin(),
                            [](const std::string& str)->wxString {
                              return wxString::FromUTF8(str);
                            });

    if (unit_ctrl_ != nullptr) {
      unit_ctrl_->Set(unit_list_);
      wxSize size = unit_ctrl_->GetBestSize();
      size.SetHeight(-1);
      unit_ctrl_->SetMinSize(size);
    }
  }

}

// ReSharper disable once CppParameterMayBeConstPtrOrRef
void FilterListView::OnNameChanged(wxCommandEvent& event) {
  if (name_ctrl_ != nullptr) {
    name_filter_ = event.GetString();
  }
  UpdateListView();
}

void FilterListView::OnNameClear(wxCommandEvent&) {
  if (name_ctrl_ != nullptr) {
    name_filter_.Clear();
  }
  UpdateListView();
}

// ReSharper disable once CppMemberFunctionMayBeConst
void FilterListView::OnUnitChanged(wxCommandEvent&) {
  if (unit_ctrl_ != nullptr) {
    unit_ctrl_->TransferDataFromWindow();
  }
  UpdateListView();
}

// ReSharper disable once CppMemberFunctionMayBeConst
void FilterListView::OnInterfaceChanged(wxCommandEvent&) {
  if (interface_ctrl_ != nullptr) {
    interface_ctrl_->TransferDataFromWindow();
  }
  UpdateListView();
}

void FilterListView::UpdateListView() const {
  auto* doc = GetDoc();
  if (doc == nullptr) {
    return;
  }
  Module* module = GetModule();
  if (module == nullptr) {
    return;
  }
  FilterList filter_list;
  filter_list.SetModule(module);
  filter_list.SetNameFilter(name_filter_.utf8_string());
  filter_list.SetUnitFilter(unit_filter_.utf8_string());
  filter_list.SetIfDataFilter(interface_filter_.utf8_string());

  switch (GetId()) {
    case kIdCharacteristicListFilter:
      module->SetCharacteristicFilter(filter_list);
      break;

    case kIdMeasurementListFilter:
      module->SetMeasurementFilter(filter_list);
      break;

    case kIdFunctionListFilter:
      module->SetFunctionFilter(filter_list);
      break;

    case kIdGroupListFilter:
      module->SetGroupFilter(filter_list);
      break;

    default:
      break;
  }

  if (auto* page = dynamic_cast<SelectionPage*>(GetParent());
      page != nullptr) {
    page->Redraw();
    page->Update();
  }

}

} // a2lgui