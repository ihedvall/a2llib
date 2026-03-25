/*
 * Copyright 2023 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
#pragma once
#include <wx/wx.h>
#include <wx/docmdi.h>
#include <wx/splitter.h>

#include "a2ltreelist.h"
#include "a2lrightpanel.h"
#include "a2ldocument.h"

namespace a2lgui {

class ChildFrame : public wxDocMDIChildFrame {
 public:
  ChildFrame(wxDocument *doc,
            wxView *view,
            wxMDIParentFrame *parent,
            wxWindowID id,
            const wxString& title);
  ChildFrame() = default;

  void Update() override;
 protected:
  [[nodiscard]] A2lDocument* GetDoc();

 private:
  A2lTreeList* left_ = nullptr;
  A2lRightPanel* right_ = nullptr;
  wxSplitterWindow* splitter_ = nullptr;

  void OnTreeSelected(wxTreeEvent& event);
  wxDECLARE_EVENT_TABLE();

};
}




