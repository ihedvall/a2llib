/*
 * Copyright 2023 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
#include <sstream>
#include <filesystem>

#include <wx/sizer.h>
#include <wx/bitmap.h>

#include <util/timestamp.h>

#include "childframe.h"
#include "a2ldocument.h"
#include "windowid.h"

using namespace a2l;

namespace a2lgui {

wxBEGIN_EVENT_TABLE(ChildFrame, wxDocMDIChildFrame)
  EVT_TREE_SEL_CHANGED(kIdLeftTree,ChildFrame::OnTreeSelected)
wxEND_EVENT_TABLE()

ChildFrame::ChildFrame(wxDocument *doc, wxView *view,
                     wxMDIParentFrame *parent,  wxWindowID id,
                     const wxString& title)
    : wxDocMDIChildFrame(doc, view, parent, id, title, wxDefaultPosition, wxDefaultSize,
                         wxDEFAULT_FRAME_STYLE, wxASCII_STR(wxFrameNameStr)) {
#ifdef _WIN32
  wxIcon sub("SUB_ICON", wxBITMAP_TYPE_ICO_RESOURCE);
#else
  wxIcon sub {wxICON(sub)};
#endif
  SetIcon(sub);
  auto* main_panel = new wxPanel(this);
  splitter_ = new wxSplitterWindow(main_panel, wxID_ANY,
    wxDefaultPosition, wxDefaultSize, wxSP_3D | wxCLIP_CHILDREN);
  splitter_->SetMinimumPaneSize(250);
  left_ = new A2lTreeList(splitter_);
  right_ = new A2lRightPanel(splitter_);
  splitter_->SplitVertically(left_, right_, 250);

  auto* main_sizer = new wxBoxSizer(wxVERTICAL);
  main_sizer->Add(splitter_, 1 , wxALL | wxGROW,0);
  main_panel->SetSizerAndFit(main_sizer);
}

void ChildFrame::Update() {
  if (auto* doc = GetDoc();doc != nullptr) {
    auto& project = doc->GetProject();
    if (left_ != nullptr) {
      left_->Redraw(project);
    }
    if (right_ != nullptr) {
      right_->SetDoc(doc);
      right_->Redraw();
    }
  }
}

A2lDocument *ChildFrame::GetDoc() {
  return wxDynamicCast(GetDocument(),A2lDocument ); // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
}

void ChildFrame::OnTreeSelected(wxTreeEvent& event) {
  auto* doc = GetDoc();
  if (doc == nullptr || left_ == nullptr || right_ == nullptr) {
    return;
  }
  const wxTreeItemId item = event.GetItem();
  const auto* data = left_->GetItemData(item);

  if (!item.IsOk() || data == nullptr) {
    doc->SetSelected(TreeItemType::UNKNOWN, nullptr);
  } else {
    const auto* temp = dynamic_cast<const A2lTreeItemData*>(data);
    if (temp == nullptr) {
      doc->SetSelected(TreeItemType::UNKNOWN, nullptr);
    } else {
      doc->SetSelected(temp->Type(), temp->Object());
    }
  }
  right_->Redraw();
}

}



