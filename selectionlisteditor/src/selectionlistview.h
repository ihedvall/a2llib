/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
#pragma once
#include <wx/docview.h>

namespace a2l {

class SelectionList;
class SelectionListFrame;
class MainFrame;
class SelectionListDocument;
class SelectionListView : public wxView  {
public:
  SelectionListView() = default;
  [[nodiscard]] SelectionListDocument* GetDoc() const;
  [[nodiscard]] SelectionList* GetSelectionList() const;
  [[nodiscard]] static SelectionListFrame* GetSelectionListFrame();
  [[nodiscard]] static MainFrame* GetMainFrame();

  bool OnCreate(wxDocument* doc, long flags) override;
  bool OnClose(bool del) override;

  void OnDraw(wxDC *dc) override;
  void OnUpdate(wxView *sender, wxObject *hint) override;

  void OnUpdateSelectionListExist(wxUpdateUIEvent& event);


private:
  void UpdateTitle() const;
  wxDECLARE_DYNAMIC_CLASS(SelectionListView);
  wxDECLARE_EVENT_TABLE();
};

}  // namespace a2l
