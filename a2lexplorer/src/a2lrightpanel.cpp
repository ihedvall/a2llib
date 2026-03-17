/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#include "a2lrightpanel.h"
#include "windowid.h"


namespace a2lgui {

A2lRightPanel::A2lRightPanel(wxWindow *parent) : wxPanel(parent) {
  splitter_ = new wxSplitterWindow(this, kIdRightPanel, wxDefaultPosition, wxDefaultSize,
    wxSP_3D | wxCLIP_CHILDREN);
  property_view_ = new A2lPropertyGrid(splitter_);

  text_view_ = new A2lTextControl(splitter_);
  text_view_->Hide();

  axis_points_view_ = new AxisPointList(splitter_);
  axis_points_view_->Hide();

  cal_methods_view_ = new CalibrationMethodList(splitter_);
  cal_methods_view_->Hide();

  memory_layout_view_ = new MemoryLayoutList(splitter_);
  memory_layout_view_->Hide();

  memory_segment_view_ = new MemorySegmentList(splitter_);
  memory_segment_view_->Hide();

  blob_view_ = new BlobList(splitter_);
  blob_view_->Hide();

  characteristic_view_ = new CharacteristicList(splitter_);
  characteristic_view_->Hide();

  compu_method_view_ = new CompuMethodList(splitter_);
  compu_method_view_->Hide();

  compu_tab_view_ = new CompuTabList(splitter_);
  compu_tab_view_->Hide();

  frame_view_ = new FrameList(splitter_);
  frame_view_->Hide();

  splitter_->Initialize(property_view_);
  //splitter_->SplitVertically(text_view_, property_view_, -300);

  auto* main_sizer = new wxBoxSizer(wxVERTICAL);
  main_sizer->Add(splitter_, 1 , wxALL | wxGROW,0);
  SetSizerAndFit(main_sizer);

}

void A2lRightPanel::SetDoc(A2lDocument *doc) {
  document_ = doc;
  if (text_view_ != nullptr) {
    text_view_->SetDoc(doc);
  }
  if (property_view_ != nullptr) {
    property_view_->SetDoc(doc);
  }
  if (axis_points_view_ != nullptr) {
    axis_points_view_->SetDoc(doc);
  }
  if (cal_methods_view_ != nullptr) {
    cal_methods_view_->SetDoc(doc);
  }
  if (memory_layout_view_ != nullptr) {
    memory_layout_view_->SetDoc(doc);
  }
  if (memory_segment_view_ != nullptr) {
    memory_segment_view_->SetDoc(doc);
  }
  if (blob_view_ != nullptr) {
    blob_view_->SetDoc(doc);
  }
  if (characteristic_view_ != nullptr) {
    characteristic_view_->SetDoc(doc);
  }
  if (compu_method_view_ != nullptr) {
    compu_method_view_->SetDoc(doc);
  }
  if (compu_tab_view_ != nullptr) {
    compu_tab_view_->SetDoc(doc);
  }
  if (frame_view_ != nullptr) {
    frame_view_->SetDoc(doc);
  }
}

void A2lRightPanel::Redraw() {
  const auto* doc = GetDoc();
  if (doc == nullptr ||
    splitter_ == nullptr ||
    property_view_ == nullptr ||
    axis_points_view_ == nullptr ||
    text_view_ == nullptr ||
    cal_methods_view_ == nullptr ||
    memory_layout_view_ == nullptr ||
    memory_segment_view_ == nullptr ||
    blob_view_ == nullptr ||
    characteristic_view_ == nullptr ||
    compu_method_view_ == nullptr ||
    compu_tab_view_ == nullptr ||
    frame_view_ == nullptr) {
    return;
  }

  HideViews();

  wxWindow* left_window = splitter_->GetWindow1();

  // Get current tree item selected type.
  switch (doc->SelectedType()) {
     case TreeItemType::MEM_SEGMENT_LIST:
      ShowList(memory_segment_view_);
      break;

    case TreeItemType::MEM_LAYOUT_LIST:
      ShowList(memory_layout_view_);
      break;

    case TreeItemType::CAL_METHOD_LIST:
      ShowList(cal_methods_view_);
      break;

    case TreeItemType::AXIS_PTS_LIST:
      ShowList(axis_points_view_);
      break;

    case TreeItemType::BLOB_LIST:
      ShowList(blob_view_);
      break;

    case TreeItemType::CHARACTERISTIC_LIST:
      ShowList(characteristic_view_);
      break;

    case TreeItemType::COMPU_METHOD_LIST:
      ShowList(compu_method_view_);
      break;

    case TreeItemType::COMPU_TAB_LIST:
      ShowList(compu_tab_view_);
      break;

    case TreeItemType::FRAME_LIST:
      ShowList(compu_tab_view_);
      break;
    case TreeItemType::A2ML:
      // Show only text view on the left pane
      if (splitter_->IsSplit()) {
        splitter_->Unsplit();
      }
      if (left_window != nullptr && left_window != text_view_) {
        splitter_->ReplaceWindow(left_window, text_view_);
      }
      text_view_->Show();
      break;

    case TreeItemType::A2L_FILE:
    default:
      // Show only the property grid
      if (splitter_->IsSplit()) {
        splitter_->Unsplit();
      }
      if (left_window != nullptr && left_window != property_view_) {
        splitter_->ReplaceWindow(left_window, property_view_);
      }
      property_view_->Show();
      break;
  }
  RedrawViews();

}

void A2lRightPanel::HideViews() const {
  if (text_view_ != nullptr) {text_view_->Hide();}
  if (property_view_ != nullptr) {property_view_->Hide();}
  if (axis_points_view_ != nullptr) {axis_points_view_->Hide();}
  if (cal_methods_view_ != nullptr) {cal_methods_view_->Hide();}
  if (memory_layout_view_ != nullptr) {memory_layout_view_->Hide();}
  if (memory_segment_view_ != nullptr) {memory_segment_view_->Hide();}
  if (blob_view_ != nullptr) {blob_view_->Hide();}
  if (characteristic_view_ != nullptr) {characteristic_view_->Hide();}
  if (compu_method_view_ != nullptr) {compu_method_view_->Hide();}
  if (compu_tab_view_ != nullptr) {compu_tab_view_->Hide();}
  if (frame_view_ != nullptr) {frame_view_->Hide();}
}

void A2lRightPanel::ShowList(wxWindow *window) const {
  if (window == nullptr || splitter_ == nullptr || property_view_ == nullptr) {
    return;
  }
  wxWindow* left_window = splitter_->GetWindow1();
  wxWindow* right_window = splitter_->GetWindow2();

  if (!splitter_->IsSplit()) {
    splitter_->SplitVertically(window, property_view_, -400);
    window->Show();
    property_view_->Show();
    return;
  }
  if (left_window != nullptr && left_window != window) {
    splitter_->ReplaceWindow(left_window, window);
  }
  if (right_window != nullptr && right_window != property_view_) {
    splitter_->ReplaceWindow(right_window, property_view_);
  }
  window->Show();
  property_view_->Show();
}

void A2lRightPanel::RedrawViews() const {
  if (text_view_->IsShown()) {
    text_view_->Redraw();
  }
  if (property_view_->IsShown()) {
    property_view_->Redraw();
  }
  if (axis_points_view_->IsShown()) {
    axis_points_view_->Redraw();
  }
  if (cal_methods_view_->IsShown()) {
    cal_methods_view_->Redraw();
  }
  if (memory_layout_view_->IsShown()) {
    memory_layout_view_->Redraw();
  }
  if (memory_segment_view_->IsShown()) {
    memory_segment_view_->Redraw();
  }
  if (blob_view_->IsShown()) {
    blob_view_->Redraw();
  }
  if (characteristic_view_->IsShown()) {
    characteristic_view_->Redraw();
  }
  if (compu_method_view_->IsShown()) {
    compu_method_view_->Redraw();
  }
  if (compu_tab_view_->IsShown()) {
    compu_tab_view_->Redraw();
  }
  if (frame_view_->IsShown()) {
    frame_view_->Redraw();
  }
}

} // a2lgui