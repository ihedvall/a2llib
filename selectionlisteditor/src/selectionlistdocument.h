/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
#pragma once
#include <memory>

#include <wx/docview.h>
#include <wx/wx.h>

#include "a2l/a2lfile.h"
#include "a2l/a2lselectionlist.h"

namespace a2l {

class MainFrame;

class SelectionGrid;
class SelectionListDocument : public wxDocument {
 public:
  SelectionListDocument() = default;

  A2lSelectionList& GetSelectionList() { return selection_list_; }
  [[nodiscard]] const A2lFile* GetA2lFile() const;

  [[nodiscard]] static MainFrame* GetMainFrame();
  [[nodiscard]] static SelectionGrid* GetSelectionGrid();
  bool OnNewDocument() override;
  bool OnCloseDocument() override;

  void AddSelectionObject(SelectionObject object);
  void DeleteSelectionObject(std::string name);

  void AttachA2lFile(const std::wstring& filename);
 protected:

  bool DoOpenDocument(const wxString& filename) override;
  bool DoSaveDocument(const wxString& filename) override;

private:
  A2lSelectionList selection_list_;
  std::unique_ptr<A2lFile> a2l_file_;
  void OnAttachA2l(wxCommandEvent& event);
  void OnAttachDbc(wxCommandEvent& event);
  wxDECLARE_DYNAMIC_CLASS(SelectionListDocument);
  wxDECLARE_EVENT_TABLE();
};



}



