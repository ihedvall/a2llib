/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#pragma once

#include <wx/imaglist.h>
#include <wx/treebase.h>
#include <wx/treectrl.h>

#include <string>

#include "a2l/a2lproject.h"
#include "a2l/amlmember.h"
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

class A2lTreeList : public wxTreeCtrl {
 public:
  explicit A2lTreeList(wxWindow* parent);
  void Redraw(a2l::A2lProject& project);
 private:
  wxImageList image_list_;

  void RedrawModule(const wxTreeItemId& root, a2l::Module& module);
  void RedrawA2ml(const wxTreeItemId& root, a2l::Module& module);
//  void RedrawA2mlObject(wxTreeListItem& root, const a2l::A2mlObject& object,
//                        a2l::Module& module);
  void RedrawModPar(wxTreeItemId& root, a2l::Module& module);
  void RedrawAnnotation(const wxTreeItemId& root, a2l::AnnotationList& list);
  void RedrawAxisPts(const wxTreeItemId& root, a2l::Module& module);
  void RedrawBlob(const wxTreeItemId& root, a2l::Module& module);
  void RedrawCharacteristic(const wxTreeItemId& root, a2l::Module& module);
  void RedrawAxisDescription(const wxTreeItemId& root, a2l::Characteristic& object);
  void RedrawCompuMethod(const wxTreeItemId& root,a2l::Module& module);
  void RedrawCompuTab(const wxTreeItemId& root,a2l::Module& module);
  void RedrawFrame(const wxTreeItemId& root,a2l::Module& module);
  void RedrawFunction(const wxTreeItemId& root,a2l::Module& module);
  void RedrawGroup(const wxTreeItemId& root,a2l::Module& module);
  void RedrawInstance(const wxTreeItemId& root,a2l::Module& module);
  void RedrawOverwrite(const wxTreeItemId& root,a2l::Instance& instance);
  void RedrawMeasurement(const wxTreeItemId& root,a2l::Module& module);
  void RedrawRecordLayout(const wxTreeItemId& root,a2l::Module& module);
  void RedrawTransformer(const wxTreeItemId& root,a2l::Module& module);
  void RedrawTypedef(const wxTreeItemId& root,a2l::Module& module);
  void RedrawUnit(const wxTreeItemId& root,a2l::Module& module);
  void RedrawUserRights(const wxTreeItemId& root,a2l::Module& module);
  void RedrawVariantCoding(const wxTreeItemId& root,a2l::Module& module);
};

}  // namespace a2lgui
