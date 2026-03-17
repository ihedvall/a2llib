/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#include "A2lTextControl.h"

#include <a2l/module.h>
#include "windowid.h"
#include "a2ldocument.h"

using namespace a2l;

namespace a2lgui {
A2lTextControl::A2lTextControl(wxWindow *parent)
: wxTextCtrl(parent, kIdTextView, wxEmptyString, wxDefaultPosition, wxDefaultSize,
    wxTE_MULTILINE | wxTE_READONLY | wxTE_RICH2 | wxHSCROLL) {

}

void A2lTextControl::Redraw() {
  Clear();
  const auto* doc = GetDoc();
  if (doc == nullptr) {
    return;
  }

  const TreeItemType type = doc->SelectedType();
  void* object = doc->SelectedObject();
  if (object == nullptr) {
    return;
  }

  switch (type) {
    case TreeItemType::A2ML: {
      if (auto* module = static_cast<Module*>(object); module != nullptr) {
        std::string a2ml = module->A2ml();
        AppendText(wxString::FromUTF8(a2ml));
        ShowPosition(0);
      }
      break;
    }

    default:
      break;

  }

}
} // a2lgui