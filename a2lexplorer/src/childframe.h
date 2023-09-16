/*
 * Copyright 2023 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
#pragma once
#include <wx/wx.h>
#include <wx/docmdi.h>
#include <wx/splitter.h>

#include <wx/listctrl.h>
#include <wx/imaglist.h>
#include <wx/stc/stc.h>
#include <wx/richtext/richtextctrl.h>

#include "a2ltreelist.h"
#include "a2lpropertygrid.h"
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
  A2lPropertyGrid* property_view_ = nullptr;
  wxStyledTextCtrl* file_view_ = nullptr;
  wxTextCtrl* text_view_ = nullptr;
  /*
  wxListView* history_view_ = nullptr;
  wxListView* measurement_view_ = nullptr;
  wxListView* event_view_ = nullptr;
  wxListView* attachment_view_ = nullptr;
  wxListView* hierarchy_view_ = nullptr;
*/
  wxSplitterWindow* splitter_ = nullptr;

  void OnTreeSelected(wxTreeListEvent& event);



  /*

  void RedrawListView();
  void RedrawHistoryView();
  void RedrawMeasurementView();
  void RedrawEventView();
  void RedrawAttachmentView();
  void RedrawHierarchyView();


  void OnTreeRightClick(wxTreeEvent& event);
  void OnListItemActivated(wxListEvent& event);
  */
  wxDECLARE_EVENT_TABLE();

};
}




