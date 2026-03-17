/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#pragma once

#include <wx/textctrl.h>

#include "a2ldocument.h"


namespace a2lgui {
class A2lTextControl : public wxTextCtrl {
  public:
    explicit A2lTextControl(wxWindow *parent);

    void SetDoc(A2lDocument* doc) { document_ = doc; };
    [[nodiscard]] A2lDocument* GetDoc() const { return document_; };
    void Redraw();

  private:
    A2lDocument* document_ = nullptr;
};
} // a2lgui

