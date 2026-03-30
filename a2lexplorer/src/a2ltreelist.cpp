/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2ltreelist.h"

#include <a2l/amlsection.h>

#include <sstream>

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
    : wxTreeCtrl(parent, kIdLeftTree),
      image_list_(16,16,false,33) {

#ifdef _WIN32
  wxBitmap tree_list("TREE_LIST", wxBITMAP_TYPE_BMP_RESOURCE);
#else
  wxBitmap tree_list {wxICON(tree_list)};
#endif
  image_list_.Add(tree_list);
  wxTreeCtrl::SetImageList(&image_list_);
}


void A2lTreeList::Redraw(A2lProject& project) {

  DeleteAllItems();
  auto root_item = GetRootItem();

  auto item = AppendItem(root_item,project.Name(), TREE_PROJECT, TREE_PROJECT,
                         new A2lTreeItemData(TreeItemType::A2L_FILE, &project));

  const auto& module_list = project.Modules();
  for ( const auto& [name, module] : module_list ) {
    RedrawModule(item, *module);
  }
  Expand(item);
}

void A2lTreeList::RedrawModule(const wxTreeItemId& root, Module& module) {
  auto item = AppendItem(root, wxString::FromUTF8(module.Name()),
                         TREE_MODULE, TREE_MODULE,
                         new A2lTreeItemData(TreeItemType::MODULE, &module));

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
  RedrawUserRights(item, module);
  RedrawVariantCoding(item, module);
  Expand(item);
}

void A2lTreeList::RedrawA2ml(const wxTreeItemId& root, Module& module) {
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
void A2lTreeList::RedrawModPar(wxTreeItemId& root, Module& module) {
  A2lModPar& par = module.ModPar();
  auto par_item = AppendItem(root, wxString::FromUTF8("Management Data"),
                         TREE_MOD_PAR, TREE_MOD_PAR,
                         new A2lTreeItemData(TreeItemType::MOD_PAR, &par));

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

void A2lTreeList::RedrawAnnotation(const wxTreeItemId& root, AnnotationList& list) {
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
  }
}

void A2lTreeList::RedrawAxisPts(const wxTreeItemId& root, Module& module) {
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

void A2lTreeList::RedrawBlob(const wxTreeItemId& root,  Module& module) {
  if (auto& list = module.Blobs(); !list.empty()) {
    std::ostringstream label;
    label << "Binary Large Objects (" << list.size() << ")";
    AppendItem(root,wxString::FromUTF8(label.str()),
               TREE_BLOB, TREE_BLOB,
               new A2lTreeItemData(TreeItemType::BLOB_LIST, &module));
  }
}

void A2lTreeList::RedrawCharacteristic(const wxTreeItemId& root, Module& module) {
  if (const auto& list = module.Characteristics(); !list.empty()) {
    std::ostringstream label;
    label << "Characteristics (" << list.size() << ")";
    AppendItem(root,wxString::FromUTF8(label.str()),
               TREE_CHARACTERISTIC, TREE_CHARACTERISTIC,
                new A2lTreeItemData(TreeItemType::CHARACTERISTIC_LIST, &module));
  }
}

void A2lTreeList::RedrawAxisDescription(const wxTreeItemId& root,
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

    RedrawAnnotation(item, axis_desc->Annotations());
  }
}

void A2lTreeList::RedrawCompuMethod(const wxTreeItemId& root, Module& module) {
  if (auto& list = module.CompuMethods(); !list.empty()) {
    std::ostringstream label;
    label << "Conversion Methods (" << list.size() << ")";
    AppendItem(root,wxString::FromUTF8(label.str()),
      TREE_FUNCTION, TREE_FUNCTION,
         new A2lTreeItemData(TreeItemType::COMPU_METHOD_LIST, &module));
  }
}

void A2lTreeList::RedrawCompuTab(const wxTreeItemId& root, Module& module) {
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

void A2lTreeList::RedrawFrame(const wxTreeItemId& root, Module& module) {
  if (auto& list = module.Frames(); !list.empty()) {
    std::ostringstream label;
    label << "Frames (" << list.size() << ")";
    AppendItem(root,wxString::FromUTF8(label.str()),
                           TREE_FRAME, TREE_FRAME,
                           new A2lTreeItemData(TreeItemType::FRAME_LIST, &module));
  }
}

void A2lTreeList::RedrawFunction(const wxTreeItemId& root, Module& module) {
  if (const auto& list = module.Functions(); !list.empty()) {
    std::ostringstream label;
    label << "Functions (" << list.size() << ")";
    AppendItem(root,wxString::FromUTF8(label.str()),
    TREE_FUNCTION_INFO, TREE_FUNCTION_INFO,
            new A2lTreeItemData(TreeItemType::FUNCTION_LIST, &module));
  }
}

void A2lTreeList::RedrawGroup(const wxTreeItemId& root, Module& module) {
  if (const GroupList& list = module.Groups(); !list.empty()) {
    std::ostringstream label;
    label << "Groups (" << list.size() << ")";
    AppendItem(root,wxString::FromUTF8(label.str()),
                           TREE_GROUP, TREE_GROUP,
                           new A2lTreeItemData(TreeItemType::GROUP_LIST, &module));
  }

}

void A2lTreeList::RedrawInstance(const wxTreeItemId& root, Module& module) {
  if (const auto& list = module.Instances(); !list.empty()) {
    std::ostringstream label;
    label << "Instances (" << list.size() << ")";
    AppendItem(root,wxString::FromUTF8(label.str()),
                           TREE_INSTANCE, TREE_INSTANCE,
                           new A2lTreeItemData(TreeItemType::INSTANCE_LIST, &module));
  }
}

void A2lTreeList::RedrawOverwrite(const wxTreeItemId& root, Instance& instance) {
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
  }
}

void A2lTreeList::RedrawMeasurement(const wxTreeItemId& root, Module& module) {
  if (const auto& list = module.Measurements(); !list.empty()) {
    std::ostringstream label;
    label << "Measurements (" << list.size() << ")";
    AppendItem(root,wxString::FromUTF8(label.str()),
               TREE_MEAS, TREE_MEAS,
               new A2lTreeItemData(TreeItemType::MEASUREMENT_LIST, &module));
  }
}

void A2lTreeList::RedrawRecordLayout(const wxTreeItemId& root, Module& module) {
  if (const auto& list = module.RecordLayouts();! list.empty()) {
    std::ostringstream label;
    label << "Record Layouts (" << list.size() << ")";
    AppendItem(root,wxString::FromUTF8(label.str()),
               TREE_MEM_INFO, TREE_MEM_INFO,
               new A2lTreeItemData(TreeItemType::RECORD_LAYOUT_LIST, &module));
  }
}

void A2lTreeList::RedrawTransformer(const wxTreeItemId& root, Module& module) {
  if (const auto& list = module.Transformers(); !list.empty()) {
    std::ostringstream label;
    label << "Transformers (" << list.size() << ")";
    AppendItem(root,wxString::FromUTF8(label.str()),
               TREE_TRANSFORMER, TREE_TRANSFORMER,
               new A2lTreeItemData(TreeItemType::TRANSFORMER_LIST, &module));
  }
}

void A2lTreeList::RedrawTypedef(const wxTreeItemId& root, Module& module) {
  if (const auto& list = module.GetTypedefList();
      !list.empty()) {
    std::ostringstream label;
    label << "Typedefs (" << list.size() << ")";
    AppendItem(root,wxString::FromUTF8(label.str()),
               TREE_OVERWRITE, TREE_OVERWRITE,
               new A2lTreeItemData(TreeItemType::TYPEDEF_LIST, &module));
  }
}

void A2lTreeList::RedrawUnit(const wxTreeItemId& root, Module& module) {
  if (const auto& list = module.Units(); !list.empty()) {
    std::ostringstream label;
    label << "Units (" << list.size() << ")";
    AppendItem(root,wxString::FromUTF8(label.str()),
               TREE_UNIT, TREE_UNIT,
               new A2lTreeItemData(TreeItemType::UNIT_LIST, &module));
  }
}

void A2lTreeList::RedrawUserRights(const wxTreeItemId& root, Module& module) {
  if (const auto& list = module.UserRights(); !list.empty()) {
    std::ostringstream label;
    label << "User Rights (" << list.size() << ")";
    AppendItem(root,wxString::FromUTF8(label.str()),
               TREE_UNIT, TREE_UNIT,
               new A2lTreeItemData(TreeItemType::USER_RIGHTS_LIST, &module));
  }
}

void A2lTreeList::RedrawVariantCoding(const wxTreeItemId& root, Module& module) {
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
    }
  }

}

}  // namespace a2lgui