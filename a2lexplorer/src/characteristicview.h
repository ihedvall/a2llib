/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#pragma once

#include <wx/panel.h>

#include "a2ldocument.h"
#include "characteristiclist.h"
#include "filterlistview.h"
namespace a2lgui {

class CharacteristicView : public wxPanel {
 public:
  explicit CharacteristicView(wxWindow* parent);
  void SetDoc(A2lDocument* doc);
  [[nodiscard]] A2lDocument* GetDoc() const { return document_; }

  void Redraw();

  void UpdateWindowUI(long flags) override;
private:
  A2lDocument* document_ = nullptr;
  CharacteristicList* list_view_ = nullptr;
  FilterListView* filter_view_ = nullptr;
  wxDECLARE_EVENT_TABLE();
};

}  // namespace a2lgui


