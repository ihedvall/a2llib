/*
* Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
#pragma once

#include <wx/panel.h>
#include <wx/notebook.h>

#include "selectionpage.h"
#include "selectionlistdocument.h"

namespace a2l {

class ObjectListPanel : public wxPanel {
public:
  ObjectListPanel(wxWindow* parent);
  void Redraw();
  static SelectionListDocument* GetDoc();

private:
  wxNotebook* notebook_ = nullptr;
  SelectionPage* measurement_list_ = nullptr;
  SelectionPage* characteristic_list_ = nullptr;
  SelectionPage* function_list_ = nullptr;
  SelectionPage* group_list_ = nullptr;

  void OnPageChanged(wxNotebookEvent& event);
  wxDECLARE_EVENT_TABLE();
};

}  // namespace a2l


