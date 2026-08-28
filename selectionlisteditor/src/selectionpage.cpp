/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#include "selectionpage.h"

#include "a2l/a2llogstream.h"
#include "characteristiclistview.h"
#include "filterlistview.h"
#include "measurementlistview.h"
#include "functionlistview.h"
#include "grouplistview.h"
#include "windowid.h"

namespace a2l {
SelectionPage::SelectionPage(wxWindow* parent, wxWindowID page_id)
: wxPanel(parent, page_id),
  page_id_(page_id) {

  switch (page_id) {

    case kIdMeasurementListPage:
      list_view_ = new MeasurementListView(this);
      filter_view_ = new FilterListView(this, kIdMeasurementListFilter);
      break;

    case kIdCharacteristicListPage:
      list_view_ = new CharacteristicListView(this);
      filter_view_ = new FilterListView(this, kIdCharacteristicListFilter);
      break;

    case kIdFunctionListPage:
      list_view_ = new FunctionListView(this);
      filter_view_ = new FilterListView(this, kIdFunctionListFilter);
      break;

    case kIdGroupListPage:
      list_view_ = new GroupListView(this);
      filter_view_ = new FilterListView(this, kIdGroupListFilter);
      break;

    default:
      A2L_ERROR() << "Invalid page id";
      break;;

  }
  if (list_view_ == nullptr || filter_view_ == nullptr) {
    A2L_ERROR() << "Failed to create list view";
    return;
  }
  auto* main_sizer = new wxBoxSizer(wxVERTICAL);
  main_sizer->Add(list_view_, 1, wxEXPAND | wxLEFT | wxBOTTOM, 0);
  main_sizer->Add(filter_view_, 0,  wxEXPAND |wxALL, 2);
  SetSizerAndFit(main_sizer);
}

void SelectionPage::Redraw() const {
  switch (page_id_) {
    case kIdMeasurementListPage:
      if (auto* view = dynamic_cast<MeasurementListView*>(list_view_);
          view != nullptr) {
        view->Redraw();
      }
      break;

    case kIdCharacteristicListPage:
      if (auto* view = dynamic_cast<CharacteristicListView*>(list_view_);
          view != nullptr) {
        view->Redraw();
      }
      break;

    case kIdFunctionListPage:
      if (auto* view = dynamic_cast<FunctionListView*>(list_view_);
          view != nullptr) {
        view->Redraw();
      }
      break;

    case kIdGroupListPage:
      if (auto* view = dynamic_cast<GroupListView*>(list_view_);
          view != nullptr) {
        view->Redraw();
      }
      break;

    default:
      break;
  }
  if (filter_view_ != nullptr) {
    filter_view_->Redraw();
  }
}

} // a2l