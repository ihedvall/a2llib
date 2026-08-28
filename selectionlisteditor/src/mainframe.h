/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
#pragma once

#include <wx/wx.h>
#include <wx/docview.h>
#include <wx/timer.h>

namespace a2l {

class SelectionListDocument;
class SelectionListFrame;
class SelectionGrid;
class RasterListView;
class MainFrame : public wxDocParentFrame {
 public:
  MainFrame(wxDocManager* doc_manager,
            const wxString& title,
            const wxPoint& start_pos,
            const wxSize& start_size,
            bool maximized);

  [[nodiscard]] SelectionListFrame* GetFrame() const;
  [[nodiscard]] SelectionGrid* GetGrid() const;
  [[nodiscard]] RasterListView* GetRasterList() const;
  [[nodiscard]] static SelectionListDocument* GetDocument();

 private:

  SelectionListFrame* selection_list_frame_ = nullptr;
  wxMenuBar* menu_bar_ = nullptr;
  wxStatusBar* status_bar_ = nullptr;
  wxTimer* timer_ = nullptr;

  void OnClose(wxCloseEvent& event);
  void OnAbout(wxCommandEvent& event);
  void OnAppearance(wxCommandEvent& event);

  void OnDropFiles(wxDropFilesEvent& event);

  void OnUpdateNoDocument(wxUpdateUIEvent& event);
  void OnTimer(wxTimerEvent& event);
  void OnAddSelectionObject(wxCommandEvent& event);
  void OnDeleteSelectionObject(wxCommandEvent& event);

  void OnRasterSelected(wxUpdateUIEvent& event);
  void OnAddRaster(wxCommandEvent& event);
  void OnEditRaster(wxCommandEvent& event);
  void OnDeleteRaster(wxCommandEvent& event);

  wxDECLARE_EVENT_TABLE();
};

} // end namespace bus

