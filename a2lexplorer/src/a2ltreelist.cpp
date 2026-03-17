/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2ltreelist.h"

#include <sstream>

#include <a2l/a2mlblock.h>

#include "windowid.h"

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
constexpr int TREE_MOD_PAR = 8;
constexpr int TREE_METHOD = 9;
constexpr int TREE_MEM_INFO = 10;
constexpr int TREE_MEM_PROP = 11;
constexpr int TREE_NOTE = 12;
constexpr int TREE_FUNCTION = 13;
constexpr int TREE_TABLE = 14;
constexpr int TREE_FRAME = 15;
constexpr int TREE_FUNCTION_INFO = 16;
constexpr int TREE_GROUP = 17;
constexpr int TREE_INSTANCE = 18;
constexpr int TREE_OVERWRITE = 19;
constexpr int TREE_MEAS = 20;
constexpr int TREE_TRANSFORMER = 21;
constexpr int TREE_STRUCTURE = 22;
constexpr int TREE_UNIT = 23;
constexpr int TREE_VAR_CODING = 24;
constexpr int TREE_VAR_CHAR = 25;
constexpr int TREE_VAR_PROP = 26;
constexpr int TREE_BLOCK = 27;
constexpr int TREE_UNION = 28;
constexpr int TREE_STRUCT = 29;
constexpr int TREE_TAGGED_STRUCT = 30;
constexpr int TREE_ENUM = 31;
constexpr int TREE_VARIABLE = 32;
}
namespace a2lgui {

A2lTreeList::A2lTreeList(wxWindow *parent )
    : wxTreeListCtrl(parent, kIdLeftTree),
      image_list_(16,16,false,33){
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

void A2lTreeList::RedrawModule(const wxTreeListItem& root, Module& module) {
  auto item = AppendItem(root, wxString::FromUTF8(module.Name()),
                         TREE_MODULE, TREE_MODULE,
                         new A2lTreeItemData(TreeItemType::MODULE, &module));
  SetItemText(item, 1, wxString::FromUTF8(module.Description()));

  RedrawA2ml(item, module);
  RedrawModPar(item, module);
  RedrawAxisPts(item, module);
  RedrawBlob(item, module);
  RedrawCharacteristic(item, module);
  RedrawCompuMethod(item, module);
  RedrawCompuTab(item, module);
  RedrawFrame(item, module);
  RedrawFunction(item, module);
  RedrawGroup(item, module);
  RedrawInstance(item, module);
  RedrawMeasurement(item, module);
  RedrawRecordLayout(item, module);
  RedrawTransformer(item, module);
  RedrawTypedef(item, module);
  RedrawUnit(item, module);
  RedrawVariantCoding(item, module);
  Expand(item);
}

void A2lTreeList::RedrawA2ml(const wxTreeListItem& root, Module& module) {
  const auto& a2ml = module.A2ml();
  if (a2ml.empty()) {
    return;
  }
  AppendItem(root, wxString::FromUTF8(" A2ML Meta-Language"), TREE_A2ML,
                 TREE_A2ML, new A2lTreeItemData(TreeItemType::A2ML, &module));
}
/*
void A2lTreeList::RedrawA2mlObject(wxTreeListItem& root,
                                   const a2l::A2mlObject& object,
                                   Module& module) {
  std::string name;
  if (!object.Ident().empty()) {
    name = object.Ident();
  } else if (!object.Tag().empty()) {
    name = object.Tag();
  }
  wxTreeListItem item;
  switch (object.Type()) {

    case A2mlTypeName::BLOCK: {
      item = AppendItem(root, wxString::FromUTF8(name),
                              TREE_BLOCK, TREE_BLOCK,
                              new A2lTreeItemData(TreeItemType::MODULE,
                                                       &module));
      SetItemText(item, 1, wxString::FromUTF8(object.TypeAsString().data()));
      break;
    }

    case A2mlTypeName::TAGGED_UNION: {
      item = AppendItem(root, wxString::FromUTF8(name),
                        TREE_UNION, TREE_UNION,
                        new A2lTreeItemData(TreeItemType::MODULE,
                                            &module));
      SetItemText(item, 1, wxString::FromUTF8(object.TypeAsString().data()));
      break;
    }

    case A2mlTypeName::TAGGED_STRUCT: {
      item = AppendItem(root, wxString::FromUTF8(name),
                        TREE_TAGGED_STRUCT, TREE_TAGGED_STRUCT,
                        new A2lTreeItemData(TreeItemType::MODULE,
                                            &module));
      SetItemText(item, 1, wxString::FromUTF8(object.TypeAsString().data()));
      break;
    }

    case A2mlTypeName::STRUCT: {
      item = AppendItem(root, wxString::FromUTF8(name),
                        TREE_STRUCT, TREE_STRUCT,
                        new A2lTreeItemData(TreeItemType::MODULE,
                                            &module));
      SetItemText(item, 1, wxString::FromUTF8(object.TypeAsString().data()));
      break;
    }

    case A2mlTypeName::ENUMERATE: {
      item = AppendItem(root, wxString::FromUTF8(name),
                        TREE_ENUM, TREE_ENUM,
                        new A2lTreeItemData(TreeItemType::MODULE,
                                            &module));
      SetItemText(item, 1, wxString::FromUTF8(object.TypeAsString().data()));
      break;
    }
    case A2mlTypeName::PREDEFINED: {
      item = AppendItem(root, wxString::FromUTF8(name),
                        TREE_VARIABLE, TREE_VARIABLE,
                        new A2lTreeItemData(TreeItemType::MODULE,
                                            &module));
      SetItemText(item, 1, wxString::FromUTF8(object.DataTypeAsString().data()));
      break;
    }

    default:
      break;
  }
  if (!item.IsOk()) {
    return;
  }
  for (const auto& member : object.MemberList()) {
    RedrawA2mlObject(item, member, module);
  }
}
*/
void A2lTreeList::RedrawModPar(wxTreeListItem& root, Module& module) {
  A2lModPar& par = module.ModPar();
  wxTreeListItem par_item = AppendItem(root, wxString::FromUTF8("Management Data"),
                         TREE_MOD_PAR, TREE_MOD_PAR,
                         new A2lTreeItemData(TreeItemType::MOD_PAR, &par));
  SetItemText(par_item, 1, wxString::FromUTF8(par.Comment));


  if (auto& cal_list = par.CalibrationMethodList; !cal_list.empty()) {
    std::ostringstream label;
    label << "Calibration Methods (" << cal_list.size() << ")";
    AppendItem( par_item,
      wxString::FromUTF8(label.str()), TREE_METHOD,
        TREE_METHOD, new A2lTreeItemData(TreeItemType::CAL_METHOD_LIST, &par));
  }


  if ( auto& layout_list = par.MemoryLayoutList; !layout_list.empty()) {
    std::ostringstream label;
    label << "Memory Layouts (" << layout_list.size() << ")";
    AppendItem(par_item, wxString::FromUTF8(label.str()),
                   TREE_MEM_INFO, TREE_MEM_INFO,
                   new A2lTreeItemData(TreeItemType::MEM_LAYOUT_LIST, &par));
  }


  if ( auto& segment_list = par.MemorySegmentList; !segment_list.empty()) {
    std::ostringstream label;
    label << "Memory Segments (" << segment_list.size() << ")";
    AppendItem(par_item,wxString::FromUTF8(label.str()),
             TREE_MEM_PROP, TREE_MEM_PROP,
                new A2lTreeItemData(TreeItemType::MEM_SEGMENT_LIST, &par));
  }
}

void A2lTreeList::RedrawAnnotation(const wxTreeListItem& root, AnnotationList& list) {
  if (list.empty()) {
    return;
  }
  auto folder = AppendItem(root,"Notes", TREE_FOLDER, TREE_FOLDER_OPEN,
                           new A2lTreeItemData(TreeItemType::ANNOTATION_LIST,
                                               &list));
  for ( auto& note : list ) {
    auto item = AppendItem(folder,wxString::FromUTF8(note.Label),
                                  TREE_NOTE, TREE_NOTE,
                           new A2lTreeItemData(TreeItemType::ANNOTATION,
                                               &note));
    SetItemText(item, 1, wxString::FromUTF8(note.Origin));
  }
}

void A2lTreeList::RedrawAxisPts(const wxTreeListItem& root, Module& module) {
  auto& list = module.AxisPtss();
  if (list.empty()) {
    return;
  }
  std::ostringstream label;
  label << "Axis Point Distributions (" << list.size() << ")";
  AppendItem(root,wxString::FromUTF8(label.str()),
                                  TREE_AXIS, TREE_AXIS,
                           new A2lTreeItemData(TreeItemType::AXIS_PTS_LIST, &module));
}

void A2lTreeList::RedrawBlob(const wxTreeListItem& root,  Module& module) {
  if (auto& list = module.Blobs(); !list.empty()) {
    std::ostringstream label;
    label << "Binary Large Objects (" << list.size() << ")";
    AppendItem(root,wxString::FromUTF8(label.str()),
               TREE_BLOB, TREE_BLOB,
               new A2lTreeItemData(TreeItemType::BLOB_LIST, &module));
  }
}

void A2lTreeList::RedrawCharacteristic(const wxTreeListItem& root, Module& module) {
  if (const auto& list = module.Characteristics(); !list.empty()) {
    std::ostringstream label;
    label << "Adjustable Objects (" << list.size() << ")";
    AppendItem(root,wxString::FromUTF8(label.str()),
               TREE_CHARACTERISTIC, TREE_CHARACTERISTIC,
                new A2lTreeItemData(TreeItemType::CHARACTERISTIC_LIST, &module));
  }
}

void A2lTreeList::RedrawAxisDescription(const wxTreeListItem& root,
                                        Characteristic& object) {
  auto& list = object.AxisDescriptions();
  if (list.empty()) {
    return;
  }
  auto folder = AppendItem(root,"Axis Descriptions",
                           TREE_FOLDER, TREE_FOLDER_OPEN,
                 new A2lTreeItemData(TreeItemType::CHARACTERISTIC, &object));

  for ( auto& axis_desc : list ) {
    auto item = AppendItem(folder,
         wxString::FromUTF8(AxisTypeToString(axis_desc->AxisType()).data()),
         TREE_AXIS, TREE_AXIS,
         new A2lTreeItemData(TreeItemType::AXIS_DESC, axis_desc.get()));
    std::ostringstream temp;
    temp << axis_desc->InputQuantity()
         << "/" << axis_desc->Conversion()
         << "/" << axis_desc->MaxAxisPoints();
    SetItemText(item, 1, wxString::FromUTF8(temp.str()));
    RedrawAnnotation(item, axis_desc->Annotations());
  }
}

void A2lTreeList::RedrawCompuMethod(const wxTreeListItem& root, Module& module) {
  if (auto& list = module.CompuMethods(); !list.empty()) {
    std::ostringstream label;
    label << "Conversion Methods (" << list.size() << ")";
    AppendItem(root,wxString::FromUTF8(label.str()),
      TREE_FUNCTION, TREE_FUNCTION,
         new A2lTreeItemData(TreeItemType::COMPU_METHOD_LIST, &module));
  }
}

void A2lTreeList::RedrawCompuTab(const wxTreeListItem& root, Module& module) {
  const auto& list_tab = module.CompuTabs();
  const auto& list_vtab = module.CompuVtabs();
  const auto& list_range = module.CompuVtabRanges();
  const size_t count = list_tab.size() + list_vtab.size() + list_range.size();
  if (count > 0) {
    std::ostringstream label;
    label << "Conversion Tables (" << count << ")";
    AppendItem(root,wxString::FromUTF8(label.str()),
      TREE_TABLE, TREE_TABLE,
         new A2lTreeItemData(TreeItemType::COMPU_TAB_LIST, &module));
  }
}

void A2lTreeList::RedrawFrame(const wxTreeListItem& root, Module& module) {
  if (auto& list = module.Frames(); !list.empty()) {
    std::ostringstream label;
    label << "Frames (" << list.size() << ")";
    AppendItem(root,wxString::FromUTF8(label.str()),
                           TREE_FRAME, TREE_FRAME,
                           new A2lTreeItemData(TreeItemType::FRAME_LIST, &module));
  }
}

void A2lTreeList::RedrawFunction(const wxTreeListItem& root, Module& module) {
  auto& list = module.Functions();
  if (list.empty()) {
    return;
  }
  auto folder = AppendItem(root,"Functions",
                           TREE_FOLDER, TREE_FOLDER_OPEN,
                           new A2lTreeItemData(TreeItemType::MODULE, &module));
  for ( auto& [name, object] : list ) {
    auto item = AppendItem(folder,wxString::FromUTF8(name),
                           TREE_FUNCTION_INFO, TREE_FUNCTION_INFO,
                           new A2lTreeItemData(TreeItemType::FUNCTION,
                                               object.get()));
    SetItemText(item, 1, wxString::FromUTF8(object->Description()));
    RedrawAnnotation(item,object->Annotations());
  }
}

void A2lTreeList::RedrawGroup(const wxTreeListItem& root, Module& module) {
  auto& list = module.Groups();
  if (list.empty()) {
    return;
  }
  auto folder = AppendItem(root,"Groups",
                           TREE_FOLDER, TREE_FOLDER_OPEN,
                           new A2lTreeItemData(TreeItemType::MODULE, &module));
  for ( auto& [name, object] : list ) {
    auto item = AppendItem(folder,wxString::FromUTF8(name),
                           TREE_GROUP, TREE_GROUP,
                           new A2lTreeItemData(TreeItemType::GROUP,
                                               object.get()));
    SetItemText(item, 1, wxString::FromUTF8(object->Description()));
    RedrawAnnotation(item,object->Annotations());
  }
}

void A2lTreeList::RedrawInstance(const wxTreeListItem& root, Module& module) {
  auto& list = module.Instances();
  if (list.empty()) {
    return;
  }
  auto folder = AppendItem(root,"Instances",
                           TREE_FOLDER, TREE_FOLDER_OPEN,
                           new A2lTreeItemData(TreeItemType::MODULE, &module));
  for ( auto& [name, object] : list ) {
    auto item = AppendItem(folder,wxString::FromUTF8(name),
                           TREE_INSTANCE, TREE_INSTANCE,
                           new A2lTreeItemData(TreeItemType::INSTANCE,
                                               object.get()));
    SetItemText(item, 1, wxString::FromUTF8(object->Description()));
    RedrawAnnotation(item,object->Annotations());
    RedrawOverwrite(item, *object);
  }
}

void A2lTreeList::RedrawOverwrite(const wxTreeListItem& root, Instance& instance) {
  auto& list = instance.Overwrites();
  if (list.empty()) {
    return;
  }
  auto folder = AppendItem(root,"OverWrites",
                           TREE_FOLDER, TREE_FOLDER_OPEN,
                           new A2lTreeItemData(TreeItemType::INSTANCE, &instance));
  for ( auto& object : list ) {
    auto item = AppendItem(folder,wxString::FromUTF8(object->Name()),
                           TREE_OVERWRITE, TREE_OVERWRITE,
                           new A2lTreeItemData(TreeItemType::OVERWRITE,
                                               object.get()));
    SetItemText(item, 1, std::to_string(object->AxisNo()));
  }
}

void A2lTreeList::RedrawMeasurement(const wxTreeListItem& root, Module& module) {
  auto& list = module.Measurements();
  if (list.empty()) {
    return;
  }
  auto folder = AppendItem(root,"Measurements",
                           TREE_FOLDER, TREE_FOLDER_OPEN,
                           new A2lTreeItemData(TreeItemType::MODULE, &module));
  for ( auto& [name, object] : list ) {
    auto item = AppendItem(folder,wxString::FromUTF8(name),
                           TREE_MEAS, TREE_MEAS,
                           new A2lTreeItemData(TreeItemType::MEASUREMENT,
                                               object.get()));
    SetItemText(item, 1, wxString::FromUTF8(object->Description()));
    RedrawAnnotation(item,object->Annotations());
  }
}

void A2lTreeList::RedrawRecordLayout(const wxTreeListItem& root, Module& module) {
  auto& list = module.RecordLayouts();
  if (list.empty()) {
    return;
  }
  auto folder = AppendItem(root,"Record Layouts",
                           TREE_FOLDER, TREE_FOLDER_OPEN,
                           new A2lTreeItemData(TreeItemType::MODULE, &module));
  for ( auto& [name, object] : list ) {
    auto item = AppendItem(folder,wxString::FromUTF8(name),
                           TREE_MEM_INFO, TREE_MEM_INFO,
                           new A2lTreeItemData(TreeItemType::RECORD_LAYOUT,
                                               object.get()));
    SetItemText(item, 1, wxString::FromUTF8(object->Description()));
  }
}

void A2lTreeList::RedrawTransformer(const wxTreeListItem& root, Module& module) {
  auto& list = module.Transformers();
  if (list.empty()) {
    return;
  }
  auto folder = AppendItem(root,"Transformers",
                           TREE_FOLDER, TREE_FOLDER_OPEN,
                           new A2lTreeItemData(TreeItemType::MODULE, &module));
  for ( auto& [name, object] : list ) {
    auto item = AppendItem(folder,wxString::FromUTF8(name),
                           TREE_TRANSFORMER, TREE_TRANSFORMER,
                           new A2lTreeItemData(TreeItemType::TRANSFORMER,
                                               object.get()));
    SetItemText(item, 1, wxString::FromUTF8(object->Version()));
  }
}

void A2lTreeList::RedrawTypedef(const wxTreeListItem& root, Module& module) {
  std::map<std::string, TreeItemType> list;
  auto& list_axis = module.TypedefAxiss();
  auto& list_blob = module.TypedefBlobs();
  auto& list_char = module.TypedefCharacteristics();
  auto& list_meas = module.TypedefMeasurements();
  auto& list_struct = module.TypedefStructures();

  for (const auto& [name1, tab1] : list_axis) {
    list.emplace(name1, TreeItemType::AXIS_PTS);
  }
  for (const auto& [name2, tab2] : list_blob) {
    list.emplace(name2, TreeItemType::BLOB);
  }
  for (const auto& [name3, tab3] : list_char) {
    list.emplace(name3, TreeItemType::CHARACTERISTIC);
  }
  for (const auto& [name4, tab4] : list_meas) {
    list.emplace(name4, TreeItemType::MEASUREMENT);
  }
  for (const auto& [name5, tab5] : list_struct) {
    list.emplace(name5, TreeItemType::STRUCTURE);
  }
  if (list.empty()) {
    return;
  }
  auto folder = AppendItem(root,"Typedefs",
                           TREE_FOLDER, TREE_FOLDER_OPEN,
                           new A2lTreeItemData(TreeItemType::MODULE, &module));
  for ( auto& [name, type] : list ) {
    switch (type) {
      case TreeItemType::AXIS_PTS: {
        auto* object = module.GetTypedefAxis(name);
        if (object != nullptr) {
          auto item = AppendItem(folder,wxString::FromUTF8(name),
                                 TREE_AXIS, TREE_AXIS,
                                 new A2lTreeItemData(type, object));
          SetItemText(item, 1, wxString::FromUTF8(object->Description()));
        }
        break;
      }

      case TreeItemType::BLOB: {
        auto* object = module.GetTypedefBlob(name);
        if (object != nullptr) {
          auto item = AppendItem(folder,wxString::FromUTF8(name),
                                 TREE_BLOB, TREE_BLOB,
                                 new A2lTreeItemData(type, object));
          SetItemText(item, 1, wxString::FromUTF8(object->Description()));
        }
        break;
      }

      case TreeItemType::CHARACTERISTIC: {
        auto* object = module.GetTypedefCharacteristic(name);
        if (object != nullptr) {
          auto item = AppendItem(folder,wxString::FromUTF8(name),
                                 TREE_CHARACTERISTIC, TREE_CHARACTERISTIC,
                                 new A2lTreeItemData(type, object));
          SetItemText(item, 1, wxString::FromUTF8(object->Description()));
        }
        break;
      }

      case TreeItemType::MEASUREMENT: {
        auto* object = module.GetTypedefMeasurement(name);
        if (object != nullptr) {
          auto item = AppendItem(folder,wxString::FromUTF8(name),
                                 TREE_MEAS, TREE_MEAS,
                                 new A2lTreeItemData(type, object));
          SetItemText(item, 1, wxString::FromUTF8(object->Description()));
        }
        break;
      }

      case TreeItemType::STRUCTURE: {
        auto* object = module.GetTypedefStructure(name);
        if (object != nullptr) {
          auto item = AppendItem(folder,wxString::FromUTF8(name),
                                 TREE_STRUCTURE, TREE_STRUCTURE,
                                 new A2lTreeItemData(type, object));
          SetItemText(item, 1, wxString::FromUTF8(object->Description()));
        }
        break;
      }

      default:
        break;
    }
  }

}

void A2lTreeList::RedrawUnit(const wxTreeListItem& root, Module& module) {
  auto& list = module.Units();
  if (list.empty()) {
    return;
  }
  auto folder = AppendItem(root,"Units",
                           TREE_FOLDER, TREE_FOLDER_OPEN,
                           new A2lTreeItemData(TreeItemType::MODULE, &module));
  for ( auto& [name, object] : list ) {
    auto item = AppendItem(folder,wxString::FromUTF8(name),
                           TREE_UNIT, TREE_UNIT,
                           new A2lTreeItemData(TreeItemType::UNIT,
                                               object.get()));
    SetItemText(item, 1, wxString::FromUTF8(object->Description()));
  }
}

void A2lTreeList::RedrawVariantCoding(const wxTreeListItem& root, Module& module) {
  auto& coding = module.VariantCoding();
  if (!coding.HasCoding()) {
    return;
  }
  auto var_cod = AppendItem(root,"Variant Coding",
                           TREE_VAR_CODING, TREE_VAR_CODING,
                           new A2lTreeItemData(TreeItemType::VARIANT_CODING,
                                               &coding));
  if (!coding.CharacteristicList.empty()) {
    auto char_folder = AppendItem(var_cod,"Variant Characteristics",
                              TREE_FOLDER, TREE_FOLDER_OPEN,
                              new A2lTreeItemData(TreeItemType::VARIANT_CODING,
                                                  &coding));
    for ( auto& [name, object] : coding.CharacteristicList) {
      AppendItem(char_folder,wxString::FromUTF8(name),
                 TREE_VAR_CHAR, TREE_VAR_CHAR,
                 new A2lTreeItemData(TreeItemType::VAR_CHARACTERISTIC,
                                     &object));
    }
  }

  if (!coding.CriterionList.empty()) {
    auto crit_folder = AppendItem(var_cod,"Variant Criterions",
                                  TREE_FOLDER, TREE_FOLDER_OPEN,
                              new A2lTreeItemData(TreeItemType::VARIANT_CODING,
                                                      &coding));
    for ( auto& [name, object] : coding.CriterionList) {
      auto item = AppendItem(crit_folder,wxString::FromUTF8(name),
                             TREE_VAR_PROP, TREE_VAR_PROP,
                             new A2lTreeItemData(TreeItemType::VAR_CRITERION,
                                                 &object));
      SetItemText(item, 1, wxString::FromUTF8(object.Description));
    }
  }

}

}  // namespace a2lgui