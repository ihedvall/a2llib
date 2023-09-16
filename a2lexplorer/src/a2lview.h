/*
 * Copyright 2023 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
#pragma once
#include <wx/docview.h>
#include "a2ldocument.h"

namespace a2lgui {
class A2lView : public wxView  {
 public:
  A2lView() = default;
  A2lDocument* GetDocument() const;

  bool OnCreate(wxDocument* doc, long flags) override;
  bool OnClose(bool del) override;

  void OnDraw(wxDC *dc) override;
  void OnUpdate(wxView *sender, wxObject *hint = nullptr) override;

 private:

  wxDECLARE_DYNAMIC_CLASS(A2lView);

};

}





