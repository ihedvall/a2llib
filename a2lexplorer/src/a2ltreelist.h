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
#include "a2l/a2mlobject.h"

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
  explicit A2lTreeList(wxWindow* parent);
  void Redraw(a2l::A2lProject& project);
 private:
  wxImageList image_list_;

  void RedrawModule(const wxTreeListItem& root, a2l::Module& module);
  void RedrawA2ml(const wxTreeListItem& root, a2l::Module& module);
//  void RedrawA2mlObject(wxTreeListItem& root, const a2l::A2mlObject& object,
//                        a2l::Module& module);
  void RedrawModPar(wxTreeListItem& root, a2l::Module& module);
  void RedrawAnnotation(const wxTreeListItem& root, a2l::AnnotationList& list);
  void RedrawAxisPts(const wxTreeListItem& root, a2l::Module& module);
  void RedrawBlob(const wxTreeListItem& root, a2l::Module& module);
  void RedrawCharacteristic(const wxTreeListItem& root, a2l::Module& module);
  void RedrawAxisDescription(const wxTreeListItem& root, a2l::Characteristic& object);
  void RedrawCompuMethod(const wxTreeListItem& root,a2l::Module& module);
  void RedrawCompuTab(const wxTreeListItem& root,a2l::Module& module);
  void RedrawFrame(const wxTreeListItem& root,a2l::Module& module);
  void RedrawFunction(const wxTreeListItem& root,a2l::Module& module);
  void RedrawGroup(const wxTreeListItem& root,a2l::Module& module);
  void RedrawInstance(const wxTreeListItem& root,a2l::Module& module);
  void RedrawOverwrite(const wxTreeListItem& root,a2l::Instance& instance);
  void RedrawMeasurement(const wxTreeListItem& root,a2l::Module& module);
  void RedrawRecordLayout(const wxTreeListItem& root,a2l::Module& module);
  void RedrawTransformer(const wxTreeListItem& root,a2l::Module& module);
  void RedrawTypedef(const wxTreeListItem& root,a2l::Module& module);
  void RedrawUnit(const wxTreeListItem& root,a2l::Module& module);
  void RedrawVariantCoding(const wxTreeListItem& root,a2l::Module& module);
};

}  // namespace a2lgui
