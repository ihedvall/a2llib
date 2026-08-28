/*
* Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
// ReSharper disable CppMemberFunctionMayBeConst
#include "objectlistpanel.h"

#include <wx/sizer.h>

#include "mainframe.h"
#include "windowid.h"
namespace {
  constexpr int kIdPageMeasurement = 0;
  constexpr int kIdPageCharacteristic = 1;
  constexpr int kIdPageFunction = 2;
  constexpr int kIdPageGroup = 3;

  constexpr int kBmpMeasurementEnabled = 0;
  constexpr int kBmpMeasurementDisabled = 1;
  constexpr int kBmpCharacteristicEnabled = 2;
  constexpr int kBmpCharacteristicDisabled = 3;
  constexpr int kBmpFunctionEnabled = 4;
  constexpr int kBmpFunctionDisabled = 5;
  constexpr int kBmpGroupEnabled = 6;
  constexpr int kBmpGroupDisabled = 7;
}

namespace a2l {
wxBEGIN_EVENT_TABLE(ObjectListPanel, wxPanel)
EVT_NOTEBOOK_PAGE_CHANGED(kIdNotebook, ObjectListPanel::OnPageChanged)
wxEND_EVENT_TABLE()

ObjectListPanel::ObjectListPanel(wxWindow* parent)
  : wxPanel(parent, kIdObjectListPanel) {

  notebook_ = new wxNotebook(this, kIdNotebook, wxDefaultPosition,
    wxDefaultSize, wxNB_TOP);
  measurement_list_ = new SelectionPage(notebook_, kIdMeasurementListPage);
  characteristic_list_ = new SelectionPage(notebook_, kIdCharacteristicListPage);
  function_list_ = new SelectionPage(notebook_, kIdFunctionListPage);
  group_list_ = new SelectionPage(notebook_, kIdGroupListPage);

  auto* image_list = new wxImageList(24, 24, true);
  image_list->Add(wxBitmap("NOTEBOOK", wxBITMAP_TYPE_BMP_RESOURCE));
  notebook_->AssignImageList(image_list);

  notebook_->InsertPage(kIdPageMeasurement, measurement_list_,
    "Measurement", true, kBmpMeasurementEnabled);
  notebook_->InsertPage(kIdPageCharacteristic, characteristic_list_,
    "Characteristic", false, kBmpCharacteristicDisabled);
  notebook_->InsertPage(kIdPageFunction, function_list_,
    "Function", false, kBmpFunctionDisabled);
  notebook_->InsertPage(kIdPageGroup, group_list_,
    "Group", false, kBmpGroupDisabled);

  auto* main_sizer = new wxBoxSizer(wxVERTICAL);
  main_sizer->Add(notebook_, 1, wxEXPAND | wxALL, 2);

  SetSizerAndFit(main_sizer);

}

void ObjectListPanel::Redraw() {
  if (measurement_list_ != nullptr) {
    measurement_list_->Redraw();
  }
  if (characteristic_list_ != nullptr) {
    characteristic_list_->Redraw();
  }
  if (function_list_ != nullptr) {
    function_list_->Redraw();
  }
  if (group_list_ != nullptr) {
    group_list_->Redraw();
  }
}

SelectionListDocument* ObjectListPanel::GetDoc() {
  return MainFrame::GetDocument();
}


void ObjectListPanel::OnPageChanged(wxNotebookEvent& event) {
  int page = event.GetSelection();
  if (notebook_ == nullptr) {
    return;
  }
    // Supress constructor call-back funtions
  if (notebook_->GetPageCount() >= 4) {
    notebook_->SetPageImage(kIdPageMeasurement, kBmpMeasurementDisabled);
    notebook_->SetPageImage(kIdPageCharacteristic, kBmpCharacteristicDisabled);
    notebook_->SetPageImage(kIdPageFunction, kBmpFunctionDisabled);
    notebook_->SetPageImage(kIdPageGroup, kBmpGroupDisabled);
  }
  switch (page) {
    case kIdPageMeasurement:
      notebook_->SetPageImage(kIdPageMeasurement, kBmpMeasurementEnabled);
      if (measurement_list_ != nullptr) {
        measurement_list_->Redraw();
        measurement_list_->Update();
      }
      break;

    case kIdPageCharacteristic:
      notebook_->SetPageImage(kIdPageCharacteristic, kBmpCharacteristicEnabled);
      if (characteristic_list_ != nullptr) {
        characteristic_list_->Redraw();
        characteristic_list_->Update();
      }
      break;

    case kIdPageFunction:
      notebook_->SetPageImage(kIdPageFunction, kBmpFunctionEnabled);
      if (function_list_ != nullptr) {
        function_list_->Redraw();
        function_list_->Update();
      }
      break;

    case kIdPageGroup:
      notebook_->SetPageImage(kIdPageGroup, kBmpGroupEnabled);
      if (group_list_ != nullptr) {
        group_list_->Redraw();
        group_list_->Update();
      }
      break;

    default:
      event.Skip();
      break;
  }
}

} // a2l