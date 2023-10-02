/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2ltreelist.h"
#include <sstream>
#include <a2l/a2mlblock.h>

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

A2lTreeList::A2lTreeList(wxWindow *parent, wxWindowID id, const wxPoint &pos,
                         const wxSize &size, long style, const wxString &name)
    : wxTreeListCtrl(parent, id, pos, size, style, name),
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

void A2lTreeList::RedrawA2ml(wxTreeListItem& root, Module& module) {
  const auto& a2ml = module.A2ml();
  if (a2ml.empty()) {
    return;
  }
  A2mlBlock a2ml_parser(a2ml);
  if (!a2ml_parser.IsOk() || a2ml_parser.BlockList().empty()) {
    return;
  }
  auto a2ml_item =
      AppendItem(root, wxString::FromUTF8("Meta-Language"), TREE_A2ML,
                 TREE_A2ML, new A2lTreeItemData(TreeItemType::MODULE, &module));
  for (const auto& block : a2ml_parser.BlockList()) {
    RedrawA2mlObject(a2ml_item, block, module);
  }
}

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

void A2lTreeList::RedrawModPar(wxTreeListItem& root, Module& module) {
  auto& par = module.ModPar();
  auto par_item = AppendItem(root, wxString::FromUTF8("Management Data"),
                         TREE_MOD_PAR, TREE_MOD_PAR,
                         new A2lTreeItemData(TreeItemType::MOD_PAR, &par));
  SetItemText(par_item, 1, wxString::FromUTF8(par.Comment));

  auto& cal_list = par.CalibrationMethodList;
  if (!cal_list.empty()) {
    auto cal_folder = AppendItem(
        par_item, wxString::FromUTF8("Calibration Methods"), TREE_FOLDER,
        TREE_FOLDER_OPEN, new A2lTreeItemData(TreeItemType::MOD_PAR, &par));
    for (auto& method : cal_list) {
      AppendItem(cal_folder, wxString::FromUTF8(method.Method), TREE_METHOD,
                 TREE_METHOD,
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
                 TREE_MEM_INFO, TREE_MEM_INFO,
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
                 TREE_MEM_PROP, TREE_MEM_PROP,
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
                                  TREE_NOTE, TREE_NOTE,
                           new A2lTreeItemData(TreeItemType::ANNOTATION,
                                               &note));
    SetItemText(item, 1, wxString::FromUTF8(note.Origin));
  }
}

void A2lTreeList::RedrawAxisPts(wxTreeListItem& root, Module& module) {
  auto& list = module.AxisPtss();
  if (list.empty()) {
    return;
  }
  auto folder = AppendItem(root,"Axis Point Distributions",
                                  TREE_FOLDER, TREE_FOLDER_OPEN,
                           new A2lTreeItemData(TreeItemType::MODULE, &module));
  for ( auto& [name, object] : list ) {
    auto item = AppendItem(folder,wxString::FromUTF8(name),
                                  TREE_AXIS, TREE_AXIS,
                new A2lTreeItemData(TreeItemType::AXIS_PTS, object.get()));
    SetItemText(item, 1, wxString::FromUTF8(object->Description()));
    RedrawAnnotation(item, object->Annotations());

  }
}

void A2lTreeList::RedrawBlob(wxTreeListItem& root,  a2l::Module& module) {
  auto& list = module.Blobs();
  if (list.empty()) {
    return;
  }
  auto folder = AppendItem(root,"Binary Blob Objects",
                                  TREE_FOLDER, TREE_FOLDER_OPEN,
                           new A2lTreeItemData(TreeItemType::MODULE, &module));
  for ( auto& [name, object] : list ) {
    auto item = AppendItem(folder,wxString::FromUTF8(name),
                                  TREE_BLOB, TREE_BLOB,
                      new A2lTreeItemData(TreeItemType::BLOB, object.get()));
    SetItemText(item, 1, wxString::FromUTF8(object->Description()));
    RedrawAnnotation(item, object->Annotations());
  }
}

void A2lTreeList::RedrawCharacteristic(wxTreeListItem& root, Module& module) {
  auto& list = module.Characteristics();
  if (list.empty()) {
    return;
  }
  auto folder = AppendItem(root,"Adjustable Objects",
                                  TREE_FOLDER, TREE_FOLDER_OPEN,
                           new A2lTreeItemData(TreeItemType::MODULE, &module));
  for ( auto& [name, object] : list ) {
    auto item = AppendItem(folder,wxString::FromUTF8(name),
                                  TREE_CHARACTERISTIC, TREE_CHARACTERISTIC,
            new A2lTreeItemData(TreeItemType::CHARACTERISTIC, object.get()));
    SetItemText(item, 1, wxString::FromUTF8(object->Description()));
    RedrawAnnotation(item, object->Annotations());
    RedrawAxisDescription(item, *object);
  }
}

void A2lTreeList::RedrawAxisDescription(wxTreeListItem& root,
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

void A2lTreeList::RedrawCompuMethod(wxTreeListItem& root, Module& module) {
  auto& list = module.CompuMethods();
  if (list.empty()) {
    return;
  }
  auto folder = AppendItem(root,"Conversion Methods",
                           TREE_FOLDER, TREE_FOLDER_OPEN,
                           new A2lTreeItemData(TreeItemType::MODULE, &module));
  for ( auto& [name, object] : list ) {
    auto item = AppendItem(folder,wxString::FromUTF8(name),
                           TREE_FUNCTION, TREE_FUNCTION,
                           new A2lTreeItemData(TreeItemType::COMPU_METHOD,
                                                 object.get()));
    SetItemText(item, 1, wxString::FromUTF8(object->Description()));
  }
}

void A2lTreeList::RedrawCompuTab(wxTreeListItem& root, Module& module) {
  std::map<std::string, TreeItemType> list;
  auto& list_tab = module.CompuTabs();
  auto& list_vtab = module.CompuVtabs();
  auto& list_range = module.CompuVtabRanges();

  for (const auto& [name1, tab1] : list_tab) {
    list.emplace(name1, TreeItemType::COMPU_TAB);
  }
  for (const auto& [name2, tab2] : list_vtab) {
    list.emplace(name2, TreeItemType::COMPU_VTAB);
  }
  for (const auto& [name3, tab3] : list_range) {
    list.emplace(name3, TreeItemType::COMPU_VTAB_RANGE);
  }
  if (list.empty()) {
    return;
  }
  auto folder = AppendItem(root,"Conversion Tables",
                           TREE_FOLDER, TREE_FOLDER_OPEN,
                           new A2lTreeItemData(TreeItemType::MODULE, &module));
  for ( auto& [name, type] : list ) {
    switch (type) {
      case TreeItemType::COMPU_TAB: {
        auto* tab = module.GetCompuTab(name);
        if (tab != nullptr) {
          auto item = AppendItem(folder,wxString::FromUTF8(name),
                                 TREE_TABLE, TREE_TABLE,
                                 new A2lTreeItemData(type, tab));
          SetItemText(item, 1, wxString::FromUTF8(tab->Description()));
        }
        break;
      }

      case TreeItemType::COMPU_VTAB: {
        auto* tab = module.GetCompuVtab(name);
        if (tab != nullptr) {
          auto item = AppendItem(folder,wxString::FromUTF8(name),
                                 TREE_TABLE, TREE_TABLE,
                                 new A2lTreeItemData(type, tab));
          SetItemText(item, 1, wxString::FromUTF8(tab->Description()));
        }
        break;
      }

      case TreeItemType::COMPU_VTAB_RANGE: {
        auto* tab = module.GetCompuVtabRange(name);
        if (tab != nullptr) {
          auto item = AppendItem(folder,wxString::FromUTF8(name),
                                 TREE_TABLE, TREE_TABLE,
                                 new A2lTreeItemData(type, tab));
          SetItemText(item, 1, wxString::FromUTF8(tab->Description()));
        }
        break;
      }

      default:
        break;
    }
  }
}

void A2lTreeList::RedrawFrame(wxTreeListItem& root, Module& module) {
  auto& list = module.Frames();
  if (list.empty()) {
    return;
  }
  auto folder = AppendItem(root,"Frames",
                           TREE_FOLDER, TREE_FOLDER_OPEN,
                           new A2lTreeItemData(TreeItemType::MODULE, &module));
  for ( auto& [name, object] : list ) {
    auto item = AppendItem(folder,wxString::FromUTF8(name),
                           TREE_FRAME, TREE_FRAME,
                           new A2lTreeItemData(TreeItemType::FRAME,
                                               object.get()));
    SetItemText(item, 1, wxString::FromUTF8(object->Description()));
  }
}

void A2lTreeList::RedrawFunction(wxTreeListItem& root, Module& module) {
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

void A2lTreeList::RedrawGroup(wxTreeListItem& root, Module& module) {
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

void A2lTreeList::RedrawInstance(wxTreeListItem& root, Module& module) {
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

void A2lTreeList::RedrawOverwrite(wxTreeListItem& root, Instance& instance) {
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

void A2lTreeList::RedrawMeasurement(wxTreeListItem& root, Module& module) {
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

void A2lTreeList::RedrawRecordLayout(wxTreeListItem& root, Module& module) {
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

void A2lTreeList::RedrawTransformer(wxTreeListItem& root, Module& module) {
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

void A2lTreeList::RedrawTypedef(wxTreeListItem& root, Module& module) {
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

void A2lTreeList::RedrawUnit(wxTreeListItem& root, Module& module) {
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
void A2lTreeList::RedrawVariantCoding(wxTreeListItem& root, Module& module) {
  auto& coding = module.VariantCoding();
  if (!coding.HasCoding()) {
    return;
  }
  auto var_cod = AppendItem(root,"Variant Coding",
                           TREE_VAR_CODING, TREE_VAR_CODING,
                           new A2lTreeItemData(TreeItemType::VARIANT_CODING,
                                               &coding));
  if (!coding.CharacteristicList.empty()) {
    auto char_folder = AppendItem(root,"Variant Characteristics",
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
    auto crit_folder = AppendItem(root,"Variant Criterions",
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