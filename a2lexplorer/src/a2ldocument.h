/*
 * Copyright 2023 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
#pragma once
#include <wx/docview.h>
#include <wx/wx.h>

#include <memory>

#include <a2l/a2lfile.h>

namespace a2lgui {

enum class TreeItemType {
  A2L_FILE,
  ANNOTATION_LIST,
  ANNOTATION,
  AXIS_DESC_LIST,
  AXIS_DESC,
  AXIS_PTS,
  BLOB_LIST,
  BLOB,
  PROJECT,
  MOD_COMMON,
  MOD_PAR,
  CAL_METHOD,
  MEM_LAYOUT,
  MEM_SEGMENT,
  MODULE,
  CHARACTERISTIC,
  UNKNOWN
};

class A2lDocument : public wxDocument {
 public:
  A2lDocument() = default;
  ~A2lDocument() override = default;

  bool OnOpenDocument(const wxString &filename) override;

  [[nodiscard]] a2l::A2lFile& GetFile() {
    return file_;
  }

  [[nodiscard]] a2l::A2lProject& GetProject() {
    return file_.Project();
  }

  void SetSelected(TreeItemType type, void* object) {
    selected_type_ = type;
    selected_object_ = object;
  }

  [[nodiscard]] TreeItemType SelectedType() const { return selected_type_; }
  [[nodiscard]] void* SelectedObject() const {
    return selected_object_;
  }

 private:
  a2l::A2lFile file_;
  TreeItemType selected_type_ = TreeItemType::UNKNOWN;
  void* selected_object_ = nullptr;

  wxDECLARE_DYNAMIC_CLASS(A2lDocument);
  wxDECLARE_EVENT_TABLE();
};



} // end namespace a2lgui



