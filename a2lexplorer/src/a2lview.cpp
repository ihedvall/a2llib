/*
 * Copyright 2023 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
#include <wx/docmdi.h>
#include "a2lview.h"
#include "a2lexplorer.h"
#include "childframe.h"

namespace a2lgui {

wxIMPLEMENT_DYNAMIC_CLASS(A2lView,wxView) //NOLINT

A2lDocument *A2lView::GetDocument() const {
  return wxDynamicCast(wxView::GetDocument(),A2lDocument );
}

void A2lView::OnDraw(wxDC*) {
}

bool A2lView::OnCreate(wxDocument *doc, long flags) {
  if (!wxView::OnCreate( doc,flags)) {
    return false;
  }

  auto & app = wxGetApp();
  auto* parent = wxDynamicCast(app.GetTopWindow(),wxMDIParentFrame);
  wxFrame* sub_frame = new ChildFrame(doc, this, parent,wxID_ANY,"A2L File");
  sub_frame->Show();
  return true;
}

bool A2lView::OnClose(bool del) {
  return wxView::OnClose(del);
}

void A2lView::OnUpdate(wxView *sender, wxObject *hint) {
  wxView::OnUpdate(sender, hint);
  auto* frame = GetFrame();
  if (frame != nullptr) {
    frame->Update();
  }

}

}