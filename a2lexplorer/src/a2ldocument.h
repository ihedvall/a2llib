/*
 * Copyright 2023 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
#pragma once
#include <wx/docview.h>
#include <wx/wx.h>

#include <a2l/a2lfile.h>
#include <a2l/module.h>

namespace a2lgui {

enum class TreeItemType {
  A2L_FILE,
  A2ML,
  ANNOTATION_LIST,
  ANNOTATION,
  AXIS_DESC,
  AXIS_PTS,
  AXIS_PTS_LIST,
  BLOB,
  BLOB_LIST,
  CAL_METHOD_LIST,
  CHARACTERISTIC,
  CHARACTERISTIC_LIST,
  COMPU_METHOD_LIST,
  COMPU_TAB_LIST,
  COMPU_TAB,
  COMPU_VTAB,
  COMPU_VTAB_RANGE,
  FRAME_LIST,
  FUNCTION_LIST,
  GROUP_LIST,
  INSTANCE,
  INSTANCE_LIST,
  MEM_LAYOUT_LIST,
  MEM_SEGMENT_LIST,
  MEASUREMENT,
  MEASUREMENT_LIST,
  MOD_COMMON,
  MOD_PAR,
  MODULE,
  OVERWRITE,
  PROJECT,
  RECORD_LAYOUT_LIST,
  STRUCTURE,
  TRANSFORMER_LIST,
  TYPEDEF_LIST,
  UNIT_LIST,
  USER_RIGHTS_LIST,
  VARIANT_CODING,
  VAR_CHARACTERISTIC,
  VAR_CRITERION,
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

  void SetSelectedIndex(long index) { selected_index_ = index; }
  [[nodiscard]] long SelectedIndex() const { return selected_index_; }

  static std::string AddressToString(uint64_t address);

private:
  a2l::A2lFile file_;
  TreeItemType selected_type_ = TreeItemType::UNKNOWN;
  void* selected_object_ = nullptr;
  long selected_index_ = -1;

  wxDECLARE_DYNAMIC_CLASS(A2lDocument);
  wxDECLARE_EVENT_TABLE();
};



} // end namespace a2lgui



