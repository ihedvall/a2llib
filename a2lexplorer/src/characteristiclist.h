/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#pragma once

#include <wx/listctrl.h>

#include "a2ldocument.h"
namespace a2lgui {

class CharacteristicList : public wxListView {
  public:
    explicit CharacteristicList(wxWindow* parent);

    void SetDoc(A2lDocument* doc) { document_ = doc; };
    [[nodiscard]] A2lDocument* GetDoc() const { return document_; };

    void Redraw();

  protected:
    [[nodiscard]] wxString OnGetItemText(long	item, long column)	const override;
    void OnItemSelected(wxListEvent& event);

  private:
    A2lDocument* document_ = nullptr;
    void RedrawPropertyGrid() const;
    wxDECLARE_EVENT_TABLE();
};

} // a2lgui