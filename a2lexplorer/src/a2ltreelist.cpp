/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2ltreelist.h"
#include <sstream>
using namespace a2l;

namespace {

#include "img/tree_list.xpm"

constexpr int TREE_FOLDER = 0;
constexpr int TREE_FOLDER_OPEN = 1;
constexpr int TREE_PROJECT = 2;
constexpr int TREE_MODULE = 3;
constexpr int TREE_A2ML = 4;
constexpr int TREE_AXIS = 5;
constexpr int TREE_BLOB = 6;
constexpr int TREE_CHARACTERISTIC = 7;
}
namespace a2lgui {

A2lTreeList::A2lTreeList(wxWindow *parent, wxWindowID id, const wxPoint &pos,
                         const wxSize &size, long style, const wxString &name)
    : wxTreeListCtrl(parent, id, pos, size, style, name),
      image_list_(16,16,false,25){
  AppendColumn("Name");
  AppendColumn("Description");

#ifdef _WIN32
  wxBitmap tree_list("TREE_LIST", wxBITMAP_TYPE_BMP_RESOURCE);
#else
  wxBitmap tree_list {wxICON(tree_list)};
#endif
  image_list_.Add(tree_list);
  wxTreeListCtrl::SetImageList(&image_list_);
}


void A2lTreeList::Redraw(A2lProject& project) {

  DeleteAllItems();
  auto root_item = GetRootItem();

  auto item = AppendItem(root_item,project.Name(), TREE_PROJECT, TREE_PROJECT,
                         new A2lTreeItemData(TreeItemType::A2L_FILE, &project));
  const auto& header = project.Header();

  SetItemText(item, 1, wxString::FromUTF8(project.Description()));

  const auto& module_list = project.Modules();
  for ( const auto& [name, module] : module_list ) {
    RedrawModule(item, *module);
  }
  Expand(item);
  /*
    auto selected_id = doc->GetSelectedBlockId();
    auto found = FindId(left_, left_->GetRootItem(), selected_id);
    if (found.IsOk()) {
      left_->SelectItem(found);
      left_->EnsureVisible(found);
    }
  */
}

void A2lTreeList::RedrawModule(wxTreeListItem& root, Module& module) {
  auto item = AppendItem(root, wxString::FromUTF8(module.Name()),
                         TREE_MODULE, TREE_MODULE,
                         new A2lTreeItemData(TreeItemType::MODULE, &module));
  SetItemText(item, 1, wxString::FromUTF8(module.Description()));

  RedrawModPar(item, module);
  RedrawAxisPts(item, module, module.AxisPtss());
  RedrawBlob(item, module.Blobs());
  RedrawCharacteristic(item, module.Characteristics());
  Expand(item);
}

void A2lTreeList::RedrawModPar(wxTreeListItem& root, Module& module) {
  auto& par = module.ModPar();
  auto par_item = AppendItem(root, wxString::FromUTF8("Management Data"),
                         TREE_A2ML, TREE_A2ML,
                         new A2lTreeItemData(TreeItemType::MOD_PAR, &par));
  SetItemText(par_item, 1, wxString::FromUTF8(par.Comment));

  auto& cal_list = par.CalibrationMethodList;
  if (!cal_list.empty()) {
    auto cal_folder = AppendItem(
        par_item, wxString::FromUTF8("Calibration Methods"), TREE_FOLDER,
        TREE_FOLDER_OPEN, new A2lTreeItemData(TreeItemType::MOD_PAR, &par));
    for (auto& method : cal_list) {
      AppendItem(cal_folder, wxString::FromUTF8(method.Method), TREE_A2ML,
                 TREE_A2ML,
                 new A2lTreeItemData(TreeItemType::CAL_METHOD, &method));
    }
  }

  auto& layout_list = par.MemoryLayoutList;
  if (!layout_list.empty()) {
    auto layout_folder =
        AppendItem(par_item, wxString::FromUTF8("Memory Layouts"),
                   TREE_FOLDER, TREE_FOLDER_OPEN,
                   new A2lTreeItemData(TreeItemType::MOD_PAR, &par));
    for (auto& layout : layout_list) {
        auto item = AppendItem(layout_folder,
                 PrgTypeToString(layout.Type).data(),
                 TREE_A2ML, TREE_A2ML,
                 new A2lTreeItemData(TreeItemType::MEM_LAYOUT, &layout));
        SetItemText(item, 1, std::to_string(layout.Address));
    }
  }

  auto& segment_list = par.MemorySegmentList;
  if (!segment_list.empty()) {
    auto segment_folder = AppendItem(par_item,
                                    wxString::FromUTF8("Memory Segments"),
                                    TREE_FOLDER, TREE_FOLDER_OPEN,
                                    new A2lTreeItemData(TreeItemType::MOD_PAR,
                                                        &par));
    for (auto& segment : segment_list) {

      auto item = AppendItem(segment_folder, wxString::FromUTF8(segment.Name),
                 TREE_A2ML, TREE_A2ML,
                 new A2lTreeItemData(TreeItemType::MEM_SEGMENT,
                                     &segment));
      SetItemText(item, 1, wxString::FromUTF8(segment.Description));
    }
  }
}

void A2lTreeList::RedrawAnnotation(wxTreeListItem& root, AnnotationList& list) {
  if (list.empty()) {
    return;
  }
  auto folder = AppendItem(root,"Notes", TREE_FOLDER, TREE_FOLDER_OPEN,
                           new A2lTreeItemData(TreeItemType::ANNOTATION_LIST,
                                               &list));
  for ( auto& note : list ) {
    auto item = AppendItem(folder,wxString::FromUTF8(note.Label),
                                  TREE_AXIS, TREE_AXIS,
                           new A2lTreeItemData(TreeItemType::ANNOTATION,
                                               &note));
    SetItemText(item, 1, wxString::FromUTF8(note.Origin));
  }
}

void A2lTreeList::RedrawAxisPts(wxTreeListItem& root, Module& parent,
                                AxisPtsList& list) {
  if (list.empty()) {
    return;
  }
  auto folder = AppendItem(root,"Axis Point Distributions",
                                  TREE_FOLDER, TREE_FOLDER_OPEN,
                           new A2lTreeItemData(TreeItemType::MODULE, &parent));
  for ( auto& [name, object] : list ) {
    auto item = AppendItem(folder,wxString::FromUTF8(name),
                                  TREE_AXIS, TREE_AXIS,
                new A2lTreeItemData(TreeItemType::AXIS_PTS, object.get()));
    SetItemText(item, 1, wxString::FromUTF8(object->Description()));
    RedrawAnnotation(item, object->Annotations());

  }
}

void A2lTreeList::RedrawBlob(wxTreeListItem& root,  BlobList& list) {
  if (list.empty()) {
    return;
  }
  auto folder = AppendItem(root,"Binary Blob Objects",
                                  TREE_FOLDER, TREE_FOLDER_OPEN);
  for ( auto& [name, object] : list ) {
    auto item = AppendItem(folder,wxString::FromUTF8(name),
                                  TREE_BLOB, TREE_BLOB);
    SetItemText(item, 1, wxString::FromUTF8(object->Description()));
    RedrawAnnotation(item, object->Annotations());

  }

}

void A2lTreeList::RedrawCharacteristic(wxTreeListItem& root,
                                      CharacteristicList& list) {
  if (list.empty()) {
    return;
  }
  auto folder = AppendItem(root,"Adjustable Objects",
                                  TREE_FOLDER, TREE_FOLDER_OPEN);
  for ( auto& [name, object] : list ) {
    auto item = AppendItem(folder,wxString::FromUTF8(name),
                                  TREE_CHARACTERISTIC, TREE_CHARACTERISTIC);
    SetItemText(item, 1, wxString::FromUTF8(object->Description()));
    RedrawAnnotation(item, object->Annotations());
    RedrawAxisDescription(item, object->AxisDescriptions());
  }
}

void A2lTreeList::RedrawAxisDescription(wxTreeListItem& root,
                                        a2l::AxisDescrList& list) {
  if (list.empty()) {
    return;
  }
  auto folder = AppendItem(root,"Axis Descriptions",
                           TREE_FOLDER, TREE_FOLDER_OPEN,
                 new A2lTreeItemData(TreeItemType::AXIS_DESC_LIST, &list));

  for ( auto& axis_desc : list ) {
    auto item = AppendItem(folder,
         wxString::FromUTF8(AxisTypeToString(axis_desc->AxisType()).data()),
         TREE_CHARACTERISTIC, TREE_CHARACTERISTIC,
         new A2lTreeItemData(TreeItemType::AXIS_DESC, axis_desc.get()));
    std::ostringstream temp;
    temp << axis_desc->InputQuantity() << "/" << axis_desc->Conversion();
    SetItemText(item, 1, wxString::FromUTF8(temp.str()));
    RedrawAnnotation(item, axis_desc->Annotations());
  }
}

}  // namespace a2lgui