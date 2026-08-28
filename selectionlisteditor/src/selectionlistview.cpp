/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
#include "selectionlistview.h"

#include <wx/docview.h>

#include <filesystem>
#include <sstream>

#include "a2l/a2llogstream.h"

#include "mainframe.h"
#include "selectionlistdocument.h"
#include "selectionlistframe.h"
#include "selectionlisteditor.h"

using namespace std::filesystem;

namespace a2l {

wxIMPLEMENT_DYNAMIC_CLASS(SelectionListView,wxView)

wxBEGIN_EVENT_TABLE(SelectionListView, wxView)

wxEND_EVENT_TABLE()

SelectionListDocument *SelectionListView::GetDoc() const {
  return dynamic_cast<SelectionListDocument*>(wxView::GetDocument());
}

SelectionList *SelectionListView::GetSelectionList() const {
  if (auto* doc = GetDoc(); doc != nullptr) {
    return &doc->GetSelectionList();
  }
  return nullptr;
}

SelectionListFrame* SelectionListView::GetSelectionListFrame() {
  if (auto* parent = GetMainFrame(); parent != nullptr ) {
    return parent->GetFrame();
  }
  return nullptr;
}

MainFrame* SelectionListView::GetMainFrame() {
  const auto& app = wxGetApp();
  return dynamic_cast<MainFrame*>(app.GetTopWindow());
}

void SelectionListView::OnDraw(wxDC* dc) {

}

bool SelectionListView::OnCreate(wxDocument *doc, long flags) {
  if (!wxView::OnCreate( doc,flags)) {
    return false;
  }

  if (auto* frame = GetSelectionListFrame(); frame != nullptr) {
    frame->SetView(this);
  }
  UpdateTitle();
  return true;
}

bool SelectionListView::OnClose(bool del) {
  if (!wxView::OnClose(del)) {
    return false;
  }
  Activate(false);

  auto& app = wxGetApp();
  if (auto* parent = dynamic_cast<MainFrame*>(app.GetTopWindow());
      parent != nullptr ) {
    if (auto* frame = parent->GetFrame(); frame != nullptr) {
      frame->ClearBackground();
      frame->SetView(nullptr);
    }
    parent->SetTitle(app.GetAppDisplayName());
  }
  SetFrame(nullptr);
  return true;
}

void SelectionListView::OnUpdate(wxView* sender, wxObject* hint) {
  wxView::OnUpdate(sender, hint);
  UpdateTitle();
  if (auto* frame = GetSelectionListFrame(); frame != nullptr) {
    frame->Redraw();
    frame->Update();
  }
}

void SelectionListView::OnUpdateSelectionListExist(wxUpdateUIEvent& event) {
  if (const auto* selection_list = GetSelectionList(); selection_list != nullptr) {
    event.Enable(true);
  } else {
    event.Enable(false);
  }
}

void SelectionListView::UpdateTitle() const {
  const auto& app = wxGetApp();
  std::wostringstream title;
  title << app.GetAppDisplayName();
  if (const auto* doc = GetDoc(); doc != nullptr) {
    wxString name = doc->GetFilename();
    std::wstring short_name;
    try {
      const path fullname(name.ToStdWstring());
      const path filename = fullname.filename();
      short_name = filename.wstring();
    } catch (const std::exception& err) {
      A2L_ERROR() << "Filename error. Error: " << err.what();
      short_name.clear();
    }
    if (short_name.empty()) {
      title << " - " << "No Name";
    } else {
      title << " - " << short_name;
    }
  }
  if (auto* main_frame = GetMainFrame(); main_frame != nullptr) {
    const wxString old_title = main_frame->GetTitle();
    if (!old_title.IsSameAs(title.str()) ) {
      main_frame->SetTitle(title.str());
    }
  }
}


}  // namespace bus