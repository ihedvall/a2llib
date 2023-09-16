/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#pragma once

#include <wx/treelist.h>

#include <string>

#include <wx/imaglist.h>
#include <wx/treebase.h>
#include "a2l/a2lproject.h"
#include "a2ldocument.h"
namespace a2lgui {


class A2lTreeItemData final : public wxTreeItemData {
 public:
  A2lTreeItemData(TreeItemType type, void* object)
    : type_(type),
      object_(object) {

  }
  [[nodiscard]] TreeItemType Type() const { return type_; }
  [[nodiscard]] void* Object() const { return object_; }

 private:
  TreeItemType type_ = TreeItemType::UNKNOWN;
  void* object_ = nullptr;
};

class A2lTreeList : public wxTreeListCtrl {
 public:
  A2lTreeList(wxWindow* parent,
                 wxWindowID id,
                 const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxDefaultSize,
                 long style = wxTL_DEFAULT_STYLE,
                 const wxString& name = wxASCII_STR(wxTreeListCtrlNameStr));
  void Redraw(a2l::A2lProject& project);
 private:
  wxImageList image_list_;

  void RedrawModule(wxTreeListItem& root, a2l::Module& module);
  void RedrawModPar(wxTreeListItem& root, a2l::Module& module);
  void RedrawAnnotation(wxTreeListItem& root, a2l::AnnotationList& a2ml);
  void RedrawAxisPts(wxTreeListItem& root, a2l::Module& parent,
                                           a2l::AxisPtsList& list);
  void RedrawBlob(wxTreeListItem& root, a2l::BlobList& list);
  void RedrawCharacteristic(wxTreeListItem& root,
                            a2l::CharacteristicList& list);
  void RedrawAxisDescription(wxTreeListItem& root,
                            a2l::AxisDescrList& list);
};

}  // namespace a2lgui
