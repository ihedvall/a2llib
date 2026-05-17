/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */
#include "a2lpropertygrid.h"

#include <a2l/a2lstructs.h>
#include <a2l/ccp/ccpdatablock.h>
#include <a2l/module.h>
#include <a2l/xcp/xcpdatablock.h>
#include <util/stringutil.h>
#include <wx/propgrid/props.h>

#include <array>
#include <map>
#include <ranges>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

#include "a2l/ifdatablock.h"
#include "windowid.h"

using namespace a2l;
using namespace util::string;

namespace {
 const std::map<uint16_t, std::string_view> kCcpCommandList = {
  {0x01, "0x01 CONNECT"},
  {0x1B, "0x1B GET_CCP_ VERSION"},
  {0x17, "0x17 EXCHANGE_ID"},
  {0x12, "0x12 GET_SEED"},
  {0x13, "0x13 UNLOCK"},
  {0x02, "0x02 SET_MTA"},
  {0x03, "0x03 DNLOAD"},
  {0x23, "0x23 DNLOAD_6"},
  {0x04, "0x04 UPLOAD"},
  {0x0F, "0x0F SHORT_UP"},
  {0x11, "0x11 SELECT_CAL_PAGE"},
  {0x14, "0x14 GET_DAQ_SIZE"},
  {0x15, "0x15 SET_DAQ_PTR"},
  {0x16, "0x16 WRITE_DAQ"},
  {0x06, "0x06 START_STOP"},
  {0x07, "0x07 DISCONNECT"},
  {0x0C, "0x0C SET_S_STATUS"},
  {0x0D, "0x0D GET_S_STATUS"},
  {0x0E, "0x0E BUILD_CHKSUM"},
  {0x10, "0x10 CLEAR_MEMORY"},
  {0x18, "0x18 PROGRAM"},
  {0x22, "0x22 PROGRAM_6"},
  {0x19, "0x19 MOVE"},
  {0x05, "0x05 TEST"},
  {0x09, "0x09 GET_ACTIVE_CAL_PAGE"},
  {0x08, "0x08 START_STOP_ALL"},
  {0x20, "0x20 DIAG_SERVICE"},
  {0x21, "0x21 ACTION_SERVICE"},
  };

  const std::map<uint16_t, std::string_view> kCcpScalingList = {
    {0, "1 \xC2\xB5s"},
    {1, "10 \xC2\xB5s"},
    {2, "100 \xC2\xB5s"},
    {3, "1 ms"},
    {4, "10 ms"},
    {5, "100 ms"},
    {6, "1 s"},
    {7, "10 s"},
    {8, "min"},
    {9, "hour"},
    {10, "day"},
    {100, "angle degree"},
    {101, "revolution"},
    {102, "cycle"},
    {103, "segment"},
    {998, "frame available"},
    {999, "new value"},
    {1000, "non-determistic"}
  };

  constexpr std::array<std::string_view, 5> kAddressGranularity = {
    "",
    "1",
    "2",
    "",
    "4",
  };

  constexpr std::array<std::string_view, 13> kResolutionList = {
    "1 ns",
    "10 ns",
    "100 ns",
    "1 \xC2\xB5s",
    "10 \xC2\xB5s",
    "100 \xC2\xB5s",
    "1 ms",
    "10 ms",
    "100 ms",
    "1 s",
    "1 ps",
    "10 ps",
    "100 ps",
  };
  constexpr std::array<std::string_view, 6> kHeaderLengthList = {
    "Byte",
    "Control Byte",
    "Fill Byte",
    "Word",
    "Control Word",
    "Fill Word"
  };
}

namespace  a2lgui {

A2lPropertyGrid::A2lPropertyGrid(wxWindow *parent)
    : wxPropertyGrid(parent, kIdPropertyView) {

}

void A2lPropertyGrid::FixNameDesc(const A2lObject& object) {
  Append( new wxStringProperty("Name", wxPG_LABEL,
                              wxString::FromUTF8(object.Name())));
  Append(new wxLongStringProperty("Description", wxPG_LABEL,
                              wxString::FromUTF8(object.Description())));
}

void A2lPropertyGrid::FixStringMap(const std::string_view& property_label,
                    const std::string_view& property_name,
                    const std::map<std::string,std::string>& string_list) {
  if (!string_list.empty()) {

    wxArrayString list;
    for (const auto& name : string_list | std::views::keys) {
      list.Add(wxString::FromUTF8(name));
    }
    const std::string_view prop_name = property_name.empty() ? property_label :
                                                  property_name;
    auto* item = Append( new wxArrayStringProperty(property_label.data(),
           prop_name.data(),
           list));
    size_t count = 0;
    for (const auto& [name, value] : string_list) {
      std::ostringstream item_prop_name;
      item_prop_name << prop_name << "_" << count;
      AppendIn(item, new wxLongStringProperty(wxString::FromUTF8(name),
         item_prop_name.str(), wxString::FromUTF8(value)));
      ++count;
    }
  }
}

void A2lPropertyGrid::FixStringMap(const std::string_view& property_label,
                    const std::string_view& property_name,
                    const std::unordered_map<std::string,std::string>& string_list) {
  if (!string_list.empty()) {

    wxArrayString list;
    for (const auto& name : string_list | std::views::keys) {
      list.Add(wxString::FromUTF8(name));
    }
    const std::string_view prop_name = property_name.empty() ? property_label :
                                                  property_name;
    auto* item = Append( new wxArrayStringProperty(property_label.data(),
           prop_name.data(),
           list));
    size_t count = 0;
    for (const auto& [name, value] : string_list) {
      std::ostringstream item_prop_name;
      item_prop_name << prop_name << "_" << count;
      AppendIn(item, new wxLongStringProperty(wxString::FromUTF8(name),
         item_prop_name.str(), wxString::FromUTF8(value)));
      ++count;
    }
  }
}

void A2lPropertyGrid::FixFloatList( const std::string_view& property_label,
                 const std::string_view& property_name,
                 const std::deque<double>& float_list) {
  if (!float_list.empty()) {
    wxArrayString list;
    for (const auto value : float_list) {
      list.Add(FormatDouble(value, 6));
    }
    Append( new wxArrayStringProperty(property_label.data(),
         property_name.empty() ? wxPG_LABEL : wxString::FromUTF8(property_name.data()),
                                          list));
  }
}

void A2lPropertyGrid::FixUintList(const std::string_view& property_label,
                  const std::string_view& property_name,
                  const std::deque<uint64_t>& uint_list) {
  if (uint_list.empty()) {
    return;
  }
  wxArrayString list;
  for (const auto value : uint_list) {
    list.Add(std::to_string(value));
  }
  Append( new wxArrayStringProperty(property_label.data(),
         property_name.empty() ? wxPG_LABEL : wxString::FromUTF8(property_name.data()),
                                        list));
}

void A2lPropertyGrid::FixIntList( const std::string_view& property_label,
                 const std::string_view& property_name,
                 const std::deque<int64_t>& int_list) {
  if (!int_list.empty()) {
    wxArrayString list;
    for (const auto value : int_list) {
      list.Add(std::to_string(value));
    }
    Append( new wxArrayStringProperty(property_label.data(),
           property_name.empty() ? wxPG_LABEL : wxString::FromUTF8(property_name.data()),
                                          list));
  }
}
void A2lPropertyGrid::FixStringList( const std::string_view& property_label,
                const std::string_view& property_name,
                const std::vector<std::string>& text_list) {
  if (text_list.empty()) {
    return;
  }
  wxArrayString list;
  for (const auto& value : text_list) {
    list.Add(wxString::FromUTF8(value));
  }
  const std::string_view prop_name = property_name.empty() ? property_label :
                                                           property_name;
  auto* item = Append( new wxArrayStringProperty(property_label.data(),
        prop_name.data(), list));
  if (text_list.size() > 1 && text_list.size() < 4) {
    size_t count = 0;
    for (const auto& text: text_list) {
      std::ostringstream item_prop_name;
      item_prop_name << prop_name << "_" << count;
      AppendIn(item, new wxLongStringProperty("", item_prop_name.str(),
                                              wxString::FromUTF8(text)));
      ++count;
    }
  }
}

void A2lPropertyGrid::FixStringList( const std::string_view& property_label,
                const std::string_view& property_name,
                const std::deque<std::string>& text_list) {
  if (text_list.empty()) {
    return;
  }
  wxArrayString list;
  for (const auto& value : text_list) {
    list.Add(wxString::FromUTF8(value));
  }
  const std::string_view prop_name = property_name.empty() ? property_label :
                                                           property_name;
  auto* item = Append( new wxArrayStringProperty(property_label.data(),
        prop_name.data(), list));
  if (text_list.size() > 1 && text_list.size() < 4) {
    size_t count = 0;
    for (const auto& text: text_list) {
      std::ostringstream item_prop_name;
      item_prop_name << prop_name << "_" << count;
      AppendIn(item, new wxLongStringProperty("", item_prop_name.str(),
                                              wxString::FromUTF8(text)));
      ++count;
    }
  }
}

void A2lPropertyGrid::FixString(const std::string_view& property_label,
              const std::string_view& property_name,
              const std::string& text) {
  if (!text.empty()) {
    Append( new wxStringProperty(property_label.data(),
      property_name.empty() ? wxPG_LABEL : wxString(property_name.data()),
      wxString::FromUTF8(text)));
  }
}

void A2lPropertyGrid::FixFloat(const std::string_view& property_label,
             const std::string_view& property_name,
             double value) {

  Append( new wxFloatProperty(property_label.data(),
    property_name.empty() ? wxPG_LABEL : wxString(property_name.data()),
         value));

}

void A2lPropertyGrid::FixInt(const std::string_view& property_label,
             const std::string_view& property_name,
             int64_t value) {
  Append( new wxIntProperty(property_label.data(),
  property_name.empty() ? wxPG_LABEL : wxString(property_name.data()),
                      static_cast<long>(value)));
}

void A2lPropertyGrid::FixBool(const std::string_view& property_label,
            const std::string_view& property_name,
            bool value) {
  if (value) {
    Append( new wxBoolProperty(property_label.data(),
          property_name.empty() ? wxPG_LABEL : wxString(property_name.data()),
                                  value));
  }
}

void A2lPropertyGrid::FixAxisPts(const std::string_view& label,
                                 const A2lAxisPts& axis) {
  if (axis.DataType == A2lDataType::UNKNOWN) {
    return;
  }

  auto *root = Append(new wxStringProperty(wxString::FromUTF8(label.data()),
                                         wxPG_LABEL, ""));

  {
    std::ostringstream temp;
    temp << label << " Position";
    AppendIn(root, new wxUIntProperty("Position", temp.str(),  axis.Position));
  }
  {
    std::ostringstream temp;
    temp << label << " Data Type";
    FixInEnumList(root, "Data Type", temp.str(), DataTypeToStringList(),
                  axis.DataType);
  }

  {
    std::ostringstream temp;
    temp << label << " Increment";
    FixInEnumList(root, "Increment", temp.str(), IndexOrderToStringList(),
                  axis.IndexOrder);
  }

  {
    std::ostringstream temp;
    temp << label << " Address Type";
    FixInEnumList(root, "Address Type", temp.str(), AddressTypeToStringList(),
                axis.AddressType);
  }
}

void A2lPropertyGrid::FixAxisRescale(const std::string_view& label,
                                 const A2lAxisRescale& axis) {
  if (axis.DataType == A2lDataType::UNKNOWN) {
    return;
  }
  auto *root = Append(new wxStringProperty(wxString::FromUTF8(label.data()),
                                           wxPG_LABEL, ""));
  {
    std::ostringstream temp;
    temp << label << " Position";
    AppendIn(root, new wxUIntProperty("Position", temp.str(), axis.Position));
  }

  {
    std::ostringstream temp;
    temp << label << " Data Type";
    FixInEnumList(root, "Data Type", temp.str(), DataTypeToStringList(),
                  axis.DataType);
  }
  {
    std::ostringstream temp;
    temp << label << " Rescale Pairs";
    AppendIn(root, new wxUIntProperty("Rescale Pairs",temp.str(),
                                      axis.MaxNoRescalePairs));
  }

  {
    std::ostringstream temp;
    temp << label << " Increment";
    FixInEnumList(root, "Increment", temp.str(), IndexOrderToStringList(),
                  axis.IndexOrder);
  }
  {
    std::ostringstream temp;
    temp << label << " Address Type";
    FixInEnumList(root, "Address Type", temp.str(), AddressTypeToStringList(),
                  axis.AddressType);
  }
}

void A2lPropertyGrid::FixDistOp(const std::string_view& label,
                                 const A2lDistOp& dist) {
  if (dist.DataType == A2lDataType::UNKNOWN) {
    return;
  }
  auto *root = Append(new wxStringProperty(wxString::FromUTF8(label.data()),
                                           wxPG_LABEL, ""));
  {
    std::ostringstream temp;
    temp << label << " Position";
    AppendIn(root, new wxUIntProperty("Position", temp.str(), dist.Position));
  }
  {
    std::ostringstream temp;
    temp << label << " Data Type";
    FixInEnumList(root, "Data Type", temp.str(), DataTypeToStringList(),
                  dist.DataType);
  }
}

void A2lPropertyGrid::FixFncValue(const std::string_view& label,
                                 const A2lFncValue& fnc) {
  if (fnc.DataType == A2lDataType::UNKNOWN) {
    return;
  }
  auto *root = Append(new wxStringProperty(wxString::FromUTF8(label.data()),
                                           wxPG_LABEL, ""));
  {
    std::ostringstream temp;
    temp << label << " Position";
    AppendIn(root, new wxUIntProperty("Position", temp.str(), fnc.Position));
  }

  {
    std::ostringstream temp;
    temp << label << " Data Type";
    FixInEnumList(root, "Data Type", temp.str(), DataTypeToStringList(),
                  fnc.DataType);
  }

  {
    std::ostringstream temp;
    temp << label << " Increment";
    FixInEnumList(root, "Increment", temp.str(), IndexModeToStringList(),
                  fnc.IndexMode);
  }

  {
    std::ostringstream temp;
    temp << label << " Address Type";
    FixInEnumList(root, "Address Type", temp.str(), AddressTypeToStringList(),
                  fnc.AddressType);
  }
}

void A2lPropertyGrid::FixExtendedLimits(const A2lExtendedLimits& limits) {
  if (limits.LowerLimits < limits.UpperLimits) {
    Append(new wxFloatProperty("Extended Lower Limit", wxPG_LABEL,
                                    limits.LowerLimits));
    Append(new wxFloatProperty("Extended Upper Limit", wxPG_LABEL,
                                    limits.UpperLimits));
  }
}

void A2lPropertyGrid::FixMaxRefresh( const A2lMaxRefresh& refresh) {
  if (refresh.ScalingUnit != 0 || refresh.Rate != 0) {
    Append(new wxUIntProperty("Refresh Scaling Unit", wxPG_LABEL,
                                   refresh.ScalingUnit));
    Append(new wxUIntProperty("Refresh Rate", wxPG_LABEL, refresh.Rate));
  }
}

void A2lPropertyGrid::FixSymbolLink(const A2lSymbolLink& symbol) {
  if (!symbol.SymbolName.empty()) {
    Append(new wxStringProperty("Symbol Name", wxPG_LABEL,
                                wxString::FromUTF8(symbol.SymbolName)));
    Append(new wxIntProperty("Symbol Offset", wxPG_LABEL,
                             static_cast<long>(symbol.Offset)));
  }
}


void A2lPropertyGrid::Redraw() {
  Clear();
  auto* doc = GetDoc();
  if (doc == nullptr) {
    return;
  }
  A2lFile& a2l_file = doc->GetFile();
  const TreeItemType type = doc->SelectedType();
  const long index = doc->SelectedIndex();
  void* object = doc->SelectedObject();
  if (object == nullptr) {
    Redraw(a2l_file);
    return;
  }

  switch (type) {
    case TreeItemType::ANNOTATION:
      if (object != nullptr ) {
        auto* note  = static_cast<a2l::A2lAnnotation*>(object);
        Redraw(*note);
      }
      break;

    case TreeItemType::ANNOTATION_LIST:
      if (object != nullptr ) {
        auto* notes  = static_cast<AnnotationList*>(object);
        Redraw(*notes);
      }
      break;

    case TreeItemType::AXIS_DESC:
      if (object != nullptr ) {
        auto* axis = static_cast<a2l::AxisDescr*>(object);
        Redraw(*axis);
      }
      break;

    case TreeItemType::AXIS_PTS_LIST:
        if (auto* module  = static_cast<Module*>(object); module != nullptr ) {
          if (const auto* axis_pts = module->GetAxisPts(index); axis_pts != nullptr) {
            Redraw(*axis_pts);
          } else {
            Redraw(*module);
          }
        }
        break;


    case TreeItemType::BLOB_LIST:
      if (auto* module  = static_cast<Module*>(object); module != nullptr ) {
        if (const auto* blob = module->GetBlob(index); blob != nullptr) {
          Redraw(*blob);
        } else {
          Redraw(*module);
        }
      }
      break;

    case TreeItemType::CHARACTERISTIC_LIST:
      if (auto* module  = static_cast<Module*>(object); module != nullptr ) {
        if (const auto* characteristic = module->GetCharacteristic(index); characteristic != nullptr) {
          Redraw(*characteristic);
        } else {
          Redraw(*module);
        }
      }
      break;

    case TreeItemType::CAL_METHOD_LIST:
        if (auto* mod_par = static_cast<A2lModPar*>(object); mod_par != nullptr) {
          const auto& cal_list = mod_par->CalibrationMethodList;
          if (index < 0 || index >= cal_list.size() ) {
            Redraw(*mod_par);
          } else {
            Redraw(cal_list[index]);
          }
        }
        break;

    case TreeItemType::CHARACTERISTIC:
      if (object != nullptr ) {
        auto* characteristic  = static_cast<a2l::Characteristic*>(object);
        Redraw(*characteristic);
      }
      break;

    case TreeItemType::COMPU_METHOD_LIST:
      if (auto* module  = static_cast<Module*>(object); module != nullptr ) {
        if (const auto* method = module->GetCompuMethod(index); method != nullptr) {
          Redraw(*method);
        } else {
          Redraw(*module);
        }
      }
      break;

    case TreeItemType::COMPU_TAB_LIST:
      if (auto* module  = static_cast<Module*>(object); module != nullptr ) {
        const auto& tab_list = module->CompuTabs();
        const auto& vtab_list = module->CompuVtabs();
        const auto& vtab_range_list = module->CompuVtabRanges();
        if (index >= 0 && index < tab_list.size() ) {
          if (const CompuTab* tab = module->GetCompuTab(index); tab != nullptr) {
            Redraw(*tab);
          } else {
            Redraw(*module);
          }
        } else if (static_cast<size_t>(index) >= tab_list.size() &&
                   static_cast<size_t>(index) < tab_list.size() + vtab_list.size() ) {
          if (const CompuVtab* tab =
            module->GetCompuVtab(index - static_cast<long>(tab_list.size()));
            tab != nullptr) {
            Redraw(*tab);
          } else {
            Redraw(*module);
          }
        } else if (static_cast<size_t>(index) >= tab_list.size() + vtab_list.size() &&
                   static_cast<size_t>(index) < tab_list.size() + vtab_list.size() + vtab_range_list.size() ) {
          if (const CompuVtabRange* tab = module->GetCompuVtabRange(
          index - static_cast<long>(tab_list.size())
               - static_cast<long>(vtab_list.size()));
            tab != nullptr) {
            Redraw(*tab);
          } else {
            Redraw(*module);
          }
        }
      }
      break;

    case TreeItemType::COMPU_TAB:
      if (object != nullptr ) {
        auto* table  = static_cast<a2l::CompuTab*>(object);
        Redraw(*table);
      }
      break;

    case TreeItemType::COMPU_VTAB:
      if (object != nullptr ) {
        auto* table  = static_cast<a2l::CompuVtab*>(object);
        Redraw(*table);
      }
      break;

    case TreeItemType::COMPU_VTAB_RANGE:
      if (object != nullptr ) {
        auto* table  = static_cast<a2l::CompuVtabRange*>(object);
        Redraw(*table);
      }
      break;

    case TreeItemType::FRAME_LIST:
      if (auto* module  = static_cast<Module*>(object); module != nullptr ) {
        if (const Frame* frame  = module->GetFrame(index); frame != nullptr) {
          Redraw(*frame);
        } else {
          Redraw(*module);
        }
      }
      break;

    case TreeItemType::FUNCTION_LIST:
      if (auto* module  = static_cast<Module*>(object); module != nullptr ) {
        if (const Function* function  = module->GetFunction(index);
            function != nullptr) {
          Redraw(*function);
        } else {
          Redraw(*module);
        }
      }
      break;

    case TreeItemType::GROUP_LIST:
      if (auto* module  = static_cast<Module*>(object); module != nullptr ) {
        if (const Group* group  = module->GetGroup(index); group != nullptr) {
          Redraw(*group);
        } else {
          Redraw(*module);
        }
      }
      break;

    case TreeItemType::INSTANCE_LIST:
      if (auto* module  = static_cast<Module*>(object); module != nullptr ) {
        if (const Instance* instance  = module->GetInstance(index); instance != nullptr) {
          Redraw(*instance);
        } else {
          Redraw(*module);
        }
      }
      break;

    case TreeItemType::IF_DATA_LIST:
      if (auto* module  = static_cast<Module*>(object); module != nullptr ) {
        const auto if_data  = module->GetIfData(index);
        if (if_data.first == "XCPplus" || if_data.first == "XCP" ) {
          RedrawXcpData(if_data.first, *module);
        } else if (if_data.first == "ASAP1B_CCP") {
          RedrawCcpData(*module);
        } else {
          RedrawIfData(if_data.first, if_data.second);
        }
      }
      break;
    case TreeItemType::MEM_SEGMENT_LIST:
      if (auto* mod_par = static_cast<A2lModPar*>(object); mod_par != nullptr) {
        const auto& mem_list = mod_par->MemorySegmentList;
        if (index < 0 || index >= mem_list.size() ) {
          Redraw(*mod_par);
        } else {
          Redraw(mem_list[index]);
        }
      }
      break;

    case TreeItemType::MEM_LAYOUT_LIST:
      if (auto* mod_par = static_cast<A2lModPar*>(object); mod_par != nullptr) {
        const auto& mem_list = mod_par->MemoryLayoutList;
        if (index < 0 || index >= mem_list.size() ) {
          Redraw(*mod_par);
        } else {
          Redraw(mem_list[index]);
        }
      }
      break;

    case TreeItemType::MEASUREMENT_LIST:
      if (auto* module  = static_cast<Module*>(object); module != nullptr ) {
        if (const Measurement* measurement = module->GetMeasurement(index);
          measurement != nullptr) {
          Redraw(*measurement);
        } else {
          Redraw(*module);
        }
      }
      break;

    case TreeItemType::MOD_PAR:
      if (object != nullptr ) {
        auto* par = static_cast<a2l::A2lModPar*>(object);
        Redraw(*par);
      }
      break;

    case TreeItemType::MODULE:
      if (object != nullptr ) {
        auto* module = static_cast<a2l::Module*>(object);
        Redraw(*module);
      }
      break;

    case TreeItemType::OVERWRITE:
      if (object != nullptr ) {
        auto* overwrite = static_cast<a2l::Overwrite*>(object);
        Redraw(*overwrite);
      }
      break;

    case TreeItemType::RECORD_LAYOUT_LIST:
      if (auto* module  = static_cast<Module*>(object); module != nullptr ) {
        if (const RecordLayout* layout = module->GetRecordLayout(index);
          layout != nullptr) {
            Redraw(*layout);
          } else {
            Redraw(*module);
          }
      }
      break;

    case TreeItemType::STRUCTURE:
      if (object != nullptr ) {
        auto* structure = static_cast<a2l::Structure*>(object);
        Redraw(*structure);
      }
      break;

    case TreeItemType::TRANSFORMER_LIST:
      if (auto* module  = static_cast<Module*>(object); module != nullptr ) {
        if (const Transformer* transformer = module->GetTransformer(index);
          transformer != nullptr) {
          Redraw(*transformer);
        } else {
          Redraw(*module);
        }
      }
      break;

    case TreeItemType::TYPEDEF_LIST:
      if (auto* module  = static_cast<Module*>(object); module != nullptr ) {
        const FlatTypedefPair def = module->GetTypedef(index);
        switch (def.first) {
          case A2lTypedefType::TYPEDEF_AXIS:
            if (auto* axis_pts = dynamic_cast<AxisPts*>(def.second);
              axis_pts != nullptr) {
              Redraw(*axis_pts);
            } else {
              Redraw(*module);
            }
            break;

          case A2lTypedefType::TYPEDEF_BLOB:
            if (auto* blob = dynamic_cast<Blob*>(def.second);
              blob != nullptr) {
              Redraw(*blob);
            } else {
              Redraw(*module);
            }
            break;

          case A2lTypedefType::TYPEDEF_CHARACTERISTIC:
            if (auto* characteristic = dynamic_cast<Characteristic*>(def.second);
              characteristic != nullptr) {
              Redraw(*characteristic);
            } else {
              Redraw(*module);
            }
            break;

          case A2lTypedefType::TYPEDEF_MEASUREMENT:
            if (auto* measurement = dynamic_cast<Measurement*>(def.second);
              measurement != nullptr) {
              Redraw(*measurement);
            } else {
              Redraw(*module);
            }
            break;

          case A2lTypedefType::TYPEDEF_STRUCTURE:
            if (auto* structure = dynamic_cast<Structure*>(def.second);
              structure != nullptr) {
              Redraw(*structure);
            } else {
              Redraw(*module);
            }
            break;

          default:
            Redraw(*module);
            break;
        }
      }
      break;

    case TreeItemType::UNIT_LIST:
      if (auto* module  = static_cast<Module*>(object); module != nullptr ) {
        if (const Unit* unit = module->GetUnit(index); unit != nullptr) {
          Redraw(*unit);
          } else {
            Redraw(*module);
          }
      }
      break;

    case TreeItemType::USER_RIGHTS_LIST:
      if (auto* module  = static_cast<Module*>(object); module != nullptr ) {
        if (const A2lUserRights* user = module->GetUserRights(index); user != nullptr) {
          Redraw(*user);
        } else {
          Redraw(*module);
        }
      }
      break;

    case TreeItemType::VARIANT_CODING:
      if (object != nullptr ) {
        auto* coding = static_cast<a2l::A2lVariantCoding*>(object);
        Redraw(*coding);
      }
      break;

    case TreeItemType::VAR_CHARACTERISTIC:
      if (object != nullptr ) {
        auto* characteristic = static_cast<a2l::A2lVarCharacteristic*>(object);
        Redraw(*characteristic);
      }
      break;

    case TreeItemType::VAR_CRITERION:
      if (object != nullptr ) {
        auto* criterion = static_cast<a2l::A2lVarCriterion*>(object);
        Redraw(*criterion);
      }
      break;

    case TreeItemType::A2L_FILE:
    case TreeItemType::PROJECT:
    default:
      Redraw(a2l_file);
      break;

  }
  // SetPropertyReadOnly(GetRoot());
}

void A2lPropertyGrid::Redraw(const A2lFile& file) {
  Append( new wxPropertyCategory("ASAP2 File") );
  Append( new wxStringProperty("Name", "name",
                            wxString::FromUTF8(file.Name())));
  Append( new wxFileProperty("File Name", "filename",
                            wxString::FromUTF8(file.Filename())));
  const auto& version = file.A2lVersion();
  if (version.VersionNo > 0) {
    Append( new wxPropertyCategory("ASAP2 Version") );
    Append( new wxUIntProperty("Version No", "a2lversion", version.VersionNo));
    Append( new wxUIntProperty("Upgrade No", "a2lupgrade", version.UpgradeNo));
  }

  const Asap2Version& a2ml = file.A2mlVersion();
  if (a2ml.VersionNo > 0) {
    Append( new wxPropertyCategory("A2ML Version") );
    Append( new wxUIntProperty("Version No", "a2mlversion", a2ml.VersionNo));
    Append( new wxUIntProperty("Upgrade No", "a2mlupgrade", a2ml.UpgradeNo));
  }

  const A2lProject& project = file.Project();
  Append( new wxPropertyCategory("Project") );
  Append( new wxStringProperty("Name", "projname",
                              wxString::FromUTF8(project.Name())));
  Append( new wxLongStringProperty("Description", "projdesc",
                              wxString::FromUTF8(project.Description())));

  const A2lHeader& header = project.Header();
  Append( new wxLongStringProperty("Comments", "projcomment",
                                  wxString::FromUTF8(header.Comment)));
  Append( new wxStringProperty("Version", "projversion",
                                  wxString::FromUTF8(header.VersionNo)));
  Append( new wxStringProperty("Project", "projno",
                              wxString::FromUTF8(header.ProjectNo)));

  FixPropertyMap( "ECU", "modules", project.Modules());
}

void A2lPropertyGrid::Redraw(const Module& module) {
  Append(new wxPropertyCategory("ECU"));
  FixNameDesc(module);

  const auto& a2ml = module.A2ml();
  if (!a2ml.empty()) {
    Append(new wxLongStringProperty("Meta-Language", "a2ml",
                                    wxString::FromUTF8(a2ml)));
  }
  FixStringMap("Interface Data", "if_data",
    module.IfDatas());

  Append(new wxPropertyCategory("ECU Specific Definitions"));
  const auto& common = module.ModCommon();
  Append(new wxLongStringProperty("Comment", "common_comment",
                                  wxString::FromUTF8(common.Comment)));

  FixUint("Alignment Int8", "", common.AlignmentByte);
  FixUint("Alignment Int16", "", common.AlignmentWord);
  FixUint("Alignment Int32", "", common.AlignmentLong);
  FixUint("Alignment Int64", "", common.AlignmentInt64);
  FixUint("Alignment Float16", "", common.AlignmentFloat16);
  FixUint("Alignment Float32", "", common.AlignmentFloat32);
  FixUint("Alignment Float64", "", common.AlignmentFloat64);
  FixEnumList("Byte Order", "byte_order", ByteOrderToStringList(),
              common.ByteOrder);
  FixUint("Data Size [bytes]", "data_size", common.DataSize);
  FixEnumList("Deposit Mode for Axis", "deposit", DepositToStringList(),
              common.Deposit);

  DrawCategory(module.ModPar());

  Append(new wxPropertyCategory("ECU Object Data"));
  Append(new wxUIntProperty("Axis Points", "axis",
    module.AxisPtss().size()));
  Append(new wxUIntProperty("Binary Large Objects", "blob",
    module.Blobs().size()));
  Append(new wxUIntProperty("Characteristics", "characteristic",
    module.Characteristics().size()));
  Append(new wxUIntProperty("Conversion Methods", "method",
    module.CompuMethods().size()));
  Append(new wxUIntProperty("Conversion Tables", "table",
    module.CompuTabs().size()));
  Append(new wxUIntProperty("Verbal Conversion Tables", "vtable",
    module.CompuVtabs().size()));
  Append(new wxUIntProperty("Verbal Range Tables", "vtable_r",
    module.CompuVtabRanges().size()));
  Append(new wxUIntProperty("Frames", "frame",
    module.Frames().size()));
  Append(new wxUIntProperty("Functions", "function",
    module.Functions().size()));
  Append(new wxUIntProperty("Groups", "group",
    module.Groups().size()));
  Append(new wxUIntProperty("Instances", "instance",
    module.Instances().size()));
  Append(new wxUIntProperty("Measurements", "measurements",
    module.Measurements().size()));
  Append(new wxUIntProperty("User Rights", "user_rights",
    module.UserRights().size()));
}

void A2lPropertyGrid::Redraw(const a2l::A2lModPar& par) {
  DrawCategory(par);
}

void A2lPropertyGrid::DrawCategory( const A2lModPar& par) {
  Append(new wxPropertyCategory("ECU Management Data"));
  Append(new wxLongStringProperty("Comment", "par_comment",
                                  wxString::FromUTF8(par.Comment)));
  FixUintList("Address of EEPROM Identifiers", "eepk",
              par.AddressEpkList);

  wxArrayString cal_method_list;
  for (const auto& cal_method : par.CalibrationMethodList) {
    cal_method_list.Add(cal_method.Method);
  }
  if (!cal_method_list.IsEmpty()) {
    Append(new wxArrayStringProperty("Access Methods", "access_method",
                                     cal_method_list));
  }
  FixString("CPU Type", "cpu_type", par.CpuType);
  FixString("Customer", "customer", par.Customer);
  FixString("Customer Number", "customer_no", par.CustomerNo);
  FixString("Control Unit", "control_unit", par.Ecu);
  Append(new wxIntProperty("Calibration Offset", "cal_offset",
                           static_cast<long>(par.EcuCalibrationOffset)));
  FixString("EPROM Identifier", "epk", par.Epk);
  FixUint("Number of Interfaces", "interface", par.NoOfInterfaces);
  if (!par.MemoryLayoutList.empty()) {
    wxArrayString enum_list;
    for (const auto& layout : par.MemoryLayoutList) {
      enum_list.Add(PrgTypeToString(layout.Type).data());
    }
    Append(new wxArrayStringProperty("Memory Segments", wxPG_LABEL, enum_list));
  }
  if (!par.MemorySegmentList.empty()) {
    wxArrayString name_list;
    for (const auto& seg : par.MemorySegmentList) {
      name_list.Add(wxString::FromUTF8(seg.Name));
    }
    Append(new wxArrayStringProperty("Memory Segments", "segments", name_list));
  }
  FixString("PhoneNo", "phone_no", par.PhoneNo);
  FixString("Supplier", "supplier", par.Supplier);
  FixString("User", "user", par.User);
  FixString("Version", "par_version", par.Version);
  FixStringMap("System Constants", "sys_const", par.SystemConstantList);
}

void A2lPropertyGrid::Redraw(const A2lCalibrationMethod& method) {
  Append(new wxPropertyCategory("Calibration Method"));
  Append( new wxStringProperty("Method", wxPG_LABEL,
                              wxString::FromUTF8(method.Method)));
  Append( new wxUIntProperty("Version", wxPG_LABEL, method.Version));
  if (!method.CalibrationHandleList.empty()) {
    wxArrayString list;
    for (const auto& object : method.CalibrationHandleList) {
      list.Add(wxString::FromUTF8(object.Comment));
    }
    auto item = Append(new wxArrayStringProperty("Calibration Handles",
                                                 wxPG_LABEL,list));
    size_t count = 0;
    for (const auto& handle : method.CalibrationHandleList) {
      wxArrayString handle_list;
      for (auto address : handle.HandleList) {
        handle_list.Add(std::to_string(address));
      }
      std::ostringstream prop_name;
      prop_name << "handle_" << count;
      AppendIn(item, new wxArrayStringProperty(
                         wxString::FromUTF8(handle.Comment),
                         prop_name.str(),handle_list));
      ++count;
    }
  }
}

void A2lPropertyGrid::Redraw(const A2lMemoryLayout& layout) {
  Append(new wxPropertyCategory("Memory Layout"));
  FixEnumList("Type","", PrgTypeToStringList(),layout.Type);
  FixHex("Address", "", layout.Address);
  FixIntList("Offset","", layout.OffsetList);
  FixStringMap("Interface Data","", layout.IfDataList);

}

void A2lPropertyGrid::Redraw(const A2lMemorySegment& segment) {
  Append(new wxPropertyCategory("Memory Segment"));
  Append( new wxStringProperty("Name", wxPG_LABEL,
                              wxString::FromUTF8(segment.Name)));
  Append( new wxStringProperty("Description", wxPG_LABEL,
                              wxString::FromUTF8(segment.Description)));
  FixEnumList("Segment Type","", SegmentTypeToStringList(),
              segment.SegmentType);
  FixEnumList("Memory Type","", MemoryTypeToStringList(),
              segment.MemoryType);
  FixEnumList("Memory Attribute","", MemoryAttributeToStringList(),
              segment.Attribute);
  FixHex("Address", "", segment.Address);
  FixIntList("Offset","", segment.OffsetList);
  FixStringMap("Interface Data","", segment.IfDataList);
}

void A2lPropertyGrid::Redraw(const AxisDescr& axis) {
  Append(new wxPropertyCategory("Axis Description"));
  FixEnumList("Type", "", AxisTypeToStringList(), axis.AxisType());
  Append( new wxStringProperty("Input Quantity", wxPG_LABEL,
                              wxString::FromUTF8(axis.InputQuantity())));
  Append( new wxStringProperty("Conversion", wxPG_LABEL,
                              wxString::FromUTF8(axis.Conversion())));
  Append( new wxUIntProperty("Axis Points", wxPG_LABEL,axis.MaxAxisPoints()));
  Append( new wxFloatProperty("Lower Limit", wxPG_LABEL, axis.LowerLimit()));
  Append( new wxFloatProperty("Upper Limit", wxPG_LABEL, axis.UpperLimit()));

  FixString("Axis Point Reference", "", axis.AxisPtsRef());
  FixEnumList( "Byte Order", "", ByteOrderToStringList(),
              axis.ByteOrder());
  FixString("Curve Axis Reference", "", axis.CurveAxisRef());
  FixEnumList("Deposit", "", DepositToStringList(), axis.Deposit());
  FixExtendedLimits(axis.ExtendedLimits());
  const auto& par = axis.FixAxisPar();
  if (par.Offset != 0.0 || par.Shift != 0.0 || par.NoAxisPoints > 0) {
    Append( new wxFloatProperty("Fixed Axis Offset", wxPG_LABEL,
                        par.Offset));
    Append( new wxFloatProperty("Fixed Axis Shift", wxPG_LABEL,
                               par.Shift));
    Append( new wxUIntProperty("Fixed Axis Points", wxPG_LABEL,
                               par.NoAxisPoints));
  }

  const auto& dist = axis.FixAxisParDist();
  if (dist.Offset != 0.0 || dist.Distance != 0.0 || dist.NoAxisPoints > 0) {
    Append( new wxFloatProperty("Fixed Axis Distance Offset", wxPG_LABEL,
                               dist.Offset));
    Append( new wxFloatProperty("Fixed Axis Distance", wxPG_LABEL,
                               dist.Distance));
    Append( new wxUIntProperty("Fixed Axis Distance Points", wxPG_LABEL,
                              dist.NoAxisPoints));
  }

  FixFloatList("Fixed Axis List", "", axis.FixAxisParList());
  FixString("Format", "", axis.Format());
  FixFloat("Max Gradient", "", axis.MaxGrad());
  FixEnumList("Monotony", "", MonotonyToStringList(), axis.Monotony());
  FixString("Physical Unit", "", axis.PhysUnit());
  FixBool("Read-Only", "", axis.ReadOnly());
  FixFloat("Step Size", "", axis.StepSize());
}

void A2lPropertyGrid::Redraw(const AxisPts& axis) {
  Append(new wxPropertyCategory("Axis Point Distribution"));
  FixNameDesc(axis);
  FixHex("Address", "", axis.Address());
  Append( new wxStringProperty("Input Quantity", wxPG_LABEL,
                              wxString::FromUTF8(axis.InputQuantity())));
  Append( new wxStringProperty("Record Reference", wxPG_LABEL,
                              wxString::FromUTF8(axis.RefRecord())));
  Append( new wxFloatProperty("Max Difference", wxPG_LABEL, axis.MaxDiff()));
  Append( new wxStringProperty("Conversion", wxPG_LABEL,
                              wxString::FromUTF8(axis.Conversion())));
  Append( new wxUIntProperty("Max axis Points", wxPG_LABEL,
                            axis.MaxAxisPoints()));
  Append( new wxFloatProperty("Lower Limit", wxPG_LABEL, axis.LowerLimit()));
  Append( new wxFloatProperty("Upper Limit", wxPG_LABEL, axis.UpperLimit()));

  FixEnumList("Byte Order", "", ByteOrderToStringList(),
              axis.ByteOrder());
  FixEnumList("Calibration Access", "", CalibrationAccessToStringList(),
              axis.CalibrationAccess());
  FixEnumList("Deposit", "", DepositToStringList(), axis.Deposit());
  FixString( "Display Identifier", "", axis.DisplayIdentifier());
  FixInt("ECU Address Extension", "", axis.EcuAddressExtension());
  FixExtendedLimits(axis.ExtendedLimits());
  FixString("Format", "", axis.Format());
  FixStringList("Functions", "", axis.FunctionList());
  FixBool( "Guard Rails", "", axis.GuardRails());
  FixStringMap( "Network Communication", "", axis.IfDatas());
  FixMaxRefresh(axis.MaxRefresh());
  FixString("Model Link", "", axis.ModelLink());
  FixEnumList("Monotony", "", MonotonyToStringList(), axis.Monotony());
  FixString("Physical Unit", "", axis.PhysUnit());
  FixBool("Read-Only", "", axis.ReadOnly());
  FixString("Memory Segment Reference", "", axis.RefMemorySegment());
  FixFloat("Step Size", "", axis.StepSize());
  FixSymbolLink(axis.SymbolLink());
}

void A2lPropertyGrid::Redraw(const Blob& blob) {
  Append(new wxPropertyCategory("Binary Large Object"));
  FixNameDesc(blob);
  FixHex("Address", "", blob.Address());
  Append( new wxUIntProperty("Size", wxPG_LABEL, blob.Size()));

  FixEnumList("Address Type", "", AddressTypeToStringList(),
              blob.AddressType());
  FixEnumList("Calibration Access", "", CalibrationAccessToStringList(),
              blob.CalibrationAccess());
  FixString("Display Identifier", "", blob.DisplayIdentifier());
  FixInt("ECU Address Extension", "", blob.EcuAddressExtension());
  FixStringMap( "Network Communication", "", blob.IfDatas());
  FixMaxRefresh(blob.MaxRefresh());
  FixString("Model Link", "", blob.ModelLink());
  FixSymbolLink(blob.SymbolLink());
}

void A2lPropertyGrid::Redraw(const Characteristic& object) {
  Append(new wxPropertyCategory("Characteristic"));
  FixNameDesc(object);
  FixEnumList("Type", "", CharacteristicTypeToStringList(), object.Type());
  FixHex("Address", "", object.Address());
  Append(new wxStringProperty("Reference to Data Record", wxPG_LABEL,
         wxString::FromUTF8(object.Deposit())));
  Append(new wxFloatProperty("Max Difference", wxPG_LABEL,
                              object.MaxDiff()));
  Append(new wxStringProperty("Conversion", wxPG_LABEL,
                              wxString::FromUTF8(object.Conversion())));
  Append(new wxFloatProperty("Lower Limit", wxPG_LABEL,
                             object.LowerLimit()));
  Append(new wxFloatProperty("Upper Limit", wxPG_LABEL,
                             object.UpperLimit()));


  FixHex("Bit Mask", "", object.BitMask());
  FixEnumList("Byte Order", "", ByteOrderToStringList(), object.ByteOrder());
  FixEnumList("CalibrationAccess", "", CalibrationAccessToStringList(),
              object.CalibrationAccess());
  FixString("Comparison Quantity", "", object.ComparisonQuantity());
  const auto& dep = object.DependentCharacteristic();
  if (!dep.Formula.empty() || !dep.CharacteristicList.empty()) {
    Append(new wxLongStringProperty("Dependent Formula", wxPG_LABEL,
                                wxString::FromUTF8(dep.Formula)));
    FixStringList("Dependent List", "", dep.CharacteristicList);
  }
  FixBool("Discrete", "", object.Discrete());
  FixString( "Display Identifier", "", object.DisplayIdentifier());
  FixInt("ECU Address Extension", "", object.EcuAddressExtension());
  if (object.Encoding() != A2lEncoding::ASCII) {
    FixEnumList("Encoding", "", EncodingToStringList(), object.Encoding());
  }
  FixExtendedLimits(object.ExtendedLimits());
  FixString( "Format", "", object.Format());
  FixStringList( "Function List", "", object.FunctionList());
  FixBool("Guard Rails", "", object.GuardRails());
  FixStringMap( "Network Communication", "", object.IfDatas());
  FixStringList( "Map List", "", object.MapList());
  FixUintList( "Matrix Dimension", "", object.MatrixDim());
  FixMaxRefresh(object.MaxRefresh());
  FixString( "Model Link", "", object.ModelLink());
  FixUint("Number of Bytes", "", object.Number());
  FixString("Physical Unit", "", object.PhysUnit());
  FixBool("Read-Only", "", object.ReadOnly());
  FixString("Memory Segment Reference", "", object.RefMemorySegment());
  FixFloat("Step Size", "", object.StepSize());
  FixSymbolLink(object.SymbolLink());
  const auto& virt = object.VirtualCharacteristic();
  if (!virt.Formula.empty() || !virt.CharacteristicList.empty()) {
    Append(new wxLongStringProperty(" Virtual Formula", wxPG_LABEL,
                                    wxString::FromUTF8(virt.Formula)));
    FixStringList("Virtual List", "", virt.CharacteristicList);
  }


}

void A2lPropertyGrid::Redraw(const AnnotationList& list) {
  Append(new wxPropertyCategory("Notes"));
  size_t count = 0;
  for (const auto& note : list) {
    std::ostringstream label;
    if (!note.Label.empty()) {
      label << note.Label;
    }
    if (!note.Origin.empty()) {
      if (!label.str().empty()) {
        label << "/";
      }
    }
    std::ostringstream name;
    name << "note_" << count;

    wxArrayString text_list;
    for (const auto& text : note.Text) {
      text_list.Add(wxString::FromUTF8(text));
    }
    Append(new wxArrayStringProperty(wxString::FromUTF8(label.str()),
              name.str(), text_list));
   ++count;
  }
}

void A2lPropertyGrid::Redraw(const A2lAnnotation& note) {
  Append(new wxPropertyCategory("Note"));
  FixString("Label", "", note.Label);
  FixString("Origin", "", note.Origin);
  FixStringList("Text", "", note.Text);
}

void A2lPropertyGrid::Redraw(const CompuMethod& method) {
  Append(new wxPropertyCategory("Conversion Method"));
  FixNameDesc(method);
  FixEnumList("Type", "", ConversionTypeToStringList(), method.Type());
  Append(new wxStringProperty("Format", wxPG_LABEL,
                              wxString::FromUTF8(method.Format())));
  Append(new wxStringProperty("Unit", wxPG_LABEL,
                              wxString::FromUTF8(method.PhysUnit())));

  FixFloatList("Float Coefficients", "" , method.Coeffs());
  FixFloatList("Linear Coefficients", "" , method.CoeffsLinear());
  FixString("Table Conversion Reference", "" , method.CompuTabRef());
  FixString("Formula", "" , method.Formula());
  FixString("Inverse Formula", "" , method.FormulaInv());
  FixString("Unit Reference", "" , method.RefUnit());
  FixString("Status Strings Reference", "" , method.StatusStringRef());
}

void A2lPropertyGrid::Redraw(const CompuTab& table) {
  Append(new wxPropertyCategory("Conversion Table"));
  FixNameDesc(table);
  FixEnumList("Type", "", ConversionTypeToStringList(), table.Type());
  auto item = Append(new wxUIntProperty("Value Pairs", wxPG_LABEL,
                                        table.Rows()));
  int count = 0;
  const auto& value_list = table.KeyValueList();
  for (const auto [key, value] : value_list) {
    auto name = FormatDouble(key, 6);
    std::ostringstream prop_name;
    prop_name << "key_" << count;
    AppendIn(item, new wxFloatProperty(name, prop_name.str(), value));
    ++count;
  }
  FixString("Default Value", "" , table.DefaultValue());
  FixFloat("Numeric Default Value", "" , table.DefaultValueNumeric());
}

void A2lPropertyGrid::Redraw(const CompuVtab& table) {
  Append(new wxPropertyCategory("Conversion String Table"));
  FixNameDesc(table);
  FixEnumList("Type", "", ConversionTypeToStringList(), table.Type());
  auto item = Append(new wxUIntProperty("Value Pairs", wxPG_LABEL,
                                        table.Rows()));
  int count = 0;
  const auto& value_list = table.KeyValueList();
  for (const auto& [key, value] : value_list) {
    auto name = FormatDouble(key, 6);
    std::ostringstream prop_name;
    prop_name << "key_" << count;
    AppendIn(item, new wxStringProperty(name, prop_name.str(),
                                        wxString::FromUTF8(value)));
    ++count;
  }
  FixString("Default Value", "" , table.DefaultValue());
}

void A2lPropertyGrid::Redraw(const CompuVtabRange& table) {
  Append(new wxPropertyCategory("Conversion String Table"));
  FixNameDesc(table);
  auto item = Append(new wxUIntProperty("Value Pairs", wxPG_LABEL,
                                        table.Rows()));
  int count = 0;
  const auto& value_list = table.KeyValueList();
  for (const auto& [key, value] : value_list) {
    std::ostringstream range;
    range << FormatDouble(key.first, 6) << ".." << FormatDouble(key.second, 6);

    std::ostringstream prop_name;
    prop_name << "key_" << count;
    AppendIn(item, new wxStringProperty(range.str(), prop_name.str(),
                                        wxString::FromUTF8(value)));
    ++count;
  }
  FixString("Default Value", "" , table.DefaultValue());
}

void A2lPropertyGrid::Redraw(const Frame& frame) {
  Append(new wxPropertyCategory("Frame"));
  FixNameDesc(frame);
  Append(new wxUIntProperty("Scaling Unit", wxPG_LABEL, frame.ScalingUnit()));
  Append(new wxUIntProperty("Rate", wxPG_LABEL, frame.Rate()));
  FixStringList("Measurement Objects", "", frame.FrameMeasurement());
  FixStringMap("Network Communication", "", frame.IfDatas());
}

void A2lPropertyGrid::Redraw(const Function& function) {
  Append(new wxPropertyCategory("Function"));
  FixNameDesc(function);
  FixString("Component Type", "", function.ComponentType());
  FixString("Prototype", "", function.PrototypeOf());
  FixStringList("Default Characteristics", "",
                function.DefaultCharacteristics());
  FixString("Version", "", function.Version());
  FixStringMap("Network Communication", "", function.IfDatas());
  FixStringList("Input Measurements", "", function.InMeasurements());
  FixStringList("Local Measurements", "", function.LocMeasurements());
  FixStringList("Output Measurements", "", function.OutMeasurements());
  FixStringList("Characteristic References", "", function.RefCharacteristics());
  FixStringList("Sub-Functions", "", function.SubFunctions());
}

void A2lPropertyGrid::Redraw(const Group& group) {
  Append(new wxPropertyCategory("Group"));
  FixNameDesc(group);
  FixStringList("Function References", "", group.FunctionList());
  FixStringMap("Network Communication", "", group.IfDatas());
  FixStringList("Characteristic References", "", group.RefCharacteristics());
  FixStringList("Measurement References", "", group.RefMeasurements());
  FixBool("Root Group", "", group.Root());
  FixStringList("Sub-Groups", "", group.SubGroups());
}

void A2lPropertyGrid::Redraw(const Instance& instance) {
  Append(new wxPropertyCategory("Instance"));
  FixNameDesc(instance);
  Append(new wxStringProperty("Type", wxPG_LABEL,
                              wxString::FromUTF8(instance.RefTypeDef())));
  FixHex("Address", "", instance.Address());
  FixEnumList("Address Type", "", AddressTypeToStringList(),
              instance.AddressType());
  FixEnumList("Calibration Access", "", CalibrationAccessToStringList(),
              instance.CalibrationAccess());
  FixString("Display Identifier", "", instance.DisplayIdentifier());
  FixInt("ECU Address Extension", "", instance.EcuAddressExtension());
  FixStringMap("Network Communication", "", instance.IfDatas());
  FixEnumList("Layout", "", LayoutToStringList(),
              instance.Layout());
  FixUintList("Matrix Dimension", "", instance.MatrixDim());
  FixMaxRefresh(instance.MaxRefresh());
  FixString("Model Link", "", instance.ModelLink());
  FixBool("Read and Write", "", instance.ReadWrite());
  FixSymbolLink(instance.SymbolLink());
}

void A2lPropertyGrid::Redraw(const Overwrite& object) {
  Append(new wxPropertyCategory("Overwrite"));
  Append(new wxStringProperty("Name", wxPG_LABEL,
                              wxString::FromUTF8(object.Name())));
  Append(new wxUIntProperty("Axis", wxPG_LABEL,object.AxisNo()));
  FixString("Conversion", "", object.Conversion());
  FixExtendedLimits(object.ExtendedLimits());
  FixString("Format", "", object.Format());
  FixString("Input Quantity", "", object.InputQuantity());
  if (object.LowerLimit() < object.UpperLimit()) {
    Append(new wxFloatProperty("Lower Limit", wxPG_LABEL,object.LowerLimit()));
    Append(new wxFloatProperty("Upper Limit", wxPG_LABEL,object.UpperLimit()));
  }
  FixEnumList("Monotony", "", MonotonyToStringList(), object.Monotony());
  FixString("Physical Unit", "", object.PhysUnit());
}

void A2lPropertyGrid::Redraw(const Measurement& meas) {
  Append(new wxPropertyCategory("Measurement"));
  FixNameDesc(meas);
  FixEnumList("Data Type", "", DataTypeToStringList(), meas.DataType());
  Append(new wxStringProperty("Conversion", wxPG_LABEL,
                              wxString::FromUTF8(meas.Conversion())));
  Append(new wxUIntProperty("Resolution", wxPG_LABEL, meas.Resolution()));
  Append(new wxFloatProperty("Accuracy", wxPG_LABEL, meas.Accuracy()));
  Append(new wxFloatProperty("Lower Limit", wxPG_LABEL, meas.LowerLimit()));
  Append(new wxFloatProperty("Upper Limit", wxPG_LABEL, meas.UpperLimit()));

  FixEnumList("Address Type", "", AddressTypeToStringList(), meas.AddressType());
  FixUint("Array Size", "", meas.ArraySize());
  FixHex("Bit Mask", "", meas.BitMask());

  const auto& operation = meas.BitOperation();
  FixUint("Left Shift", "", operation.LeftShift);
  FixUint("Right Shift", "", operation.RightShift);
  FixBool("Extended Sign", "", operation.SignExtended);

  FixEnumList("Byte Order", "", ByteOrderToStringList(), meas.ByteOrder());
  FixBool("Discrete", "", meas.Discrete());
  FixString( "Display Identifier", "", meas.DisplayIdentifier());
  FixHex("ECU Address", "", meas.EcuAddress());
  FixInt("ECU Address Extension", "", meas.EcuAddressExtension());
  FixHex("Error Mask", "", meas.ErrorMask());
  FixString( "Format", "", meas.Format());
  FixStringList( "Function List", "", meas.FunctionList());
  FixStringMap( "Network Communication", "", meas.IfDatas());
  FixEnumList("Layout", "", LayoutToStringList(), meas.Layout());
  FixUintList( "Matrix Dimension", "", meas.MatrixDim());
  FixMaxRefresh(meas.MaxRefresh());
  FixString( "Model Link", "", meas.ModelLink());
  FixString("Physical Unit", "", meas.PhysUnit());
  FixBool("Read and Write", "", meas.ReadWrite());
  FixString("Memory Segment Reference", "", meas.RefMemorySegment());
  FixSymbolLink(meas.SymbolLink());
  FixStringList("Virtual Measurements", "", meas.Virtuals());

}
void A2lPropertyGrid::Redraw(const RecordLayout& layout) {
  Append(new wxPropertyCategory("Record Layout"));
  Append(new wxStringProperty("Name", wxPG_LABEL,
                              wxString::FromUTF8(layout.Name())));

  FixUint("Alignment Int8", "", layout.AlignmentByte());
  FixUint("Alignment Int16", "", layout.AlignmentWord());
  FixUint("Alignment Int32", "", layout.AlignmentLong());
  FixUint("Alignment Int64", "", layout.AlignmentInt64());
  FixUint("Alignment Float16", "", layout.AlignmentFloat16());
  FixUint("Alignment Float32", "", layout.AlignmentFloat32());
  FixUint("Alignment Float64", "", layout.AlignmentFloat64());

  FixAxisPts("X Axis Point", layout.AxisPtsX());
  FixAxisPts("Y Axis Point", layout.AxisPtsY());
  FixAxisPts("Z Axis Point", layout.AxisPtsZ());
  FixAxisPts("4 Axis Point", layout.AxisPts4());
  FixAxisPts("5 Axis Point", layout.AxisPts5());

  FixAxisRescale("X Axis Rescale", layout.AxisRescaleX());

  FixDistOp("X Distance", layout.DistOpX());
  FixDistOp("Y Distance", layout.DistOpY());
  FixDistOp("Z Distance", layout.DistOpZ());
  FixDistOp("4 Distance", layout.DistOp4());
  FixDistOp("5 Distance", layout.DistOp5());

  FixUint("X Axis Fixed Points", "", layout.FixNoAxisPtsX());
  FixUint("Y Axis Fixed Points", "", layout.FixNoAxisPtsY());
  FixUint("Z Axis Fixed Points", "", layout.FixNoAxisPtsZ());
  FixUint("4 Axis Fixed Points", "", layout.FixNoAxisPts4());
  FixUint("5 Axis Fixed Points", "", layout.FixNoAxisPts5());

  FixFncValue("Function Value", layout.FncValues());
  const auto& ident = layout.Identification();
  if ( ident.DataType != A2lDataType::UNKNOWN ) {
    Append(new wxUIntProperty("Identification Position", wxPG_LABEL,
                              ident.Position));
    FixEnumList("Identification Data Type", "", DataTypeToStringList(),
                ident.DataType);
  }

  FixDistOp("X No Axis Points", layout.NoAxisPtsX());
  FixDistOp("Y No Axis Points", layout.NoAxisPtsY());
  FixDistOp("Z No Axis Points", layout.NoAxisPtsX());
  FixDistOp("4 No Axis Points", layout.NoAxisPts4());
  FixDistOp("5 No Axis Points", layout.NoAxisPts5());

  FixDistOp("X No Rescale", layout.NoRescaleX());

  FixDistOp("X Offset", layout.OffsetX());
  FixDistOp("Y Offset", layout.OffsetY());
  FixDistOp("Z Offset", layout.OffsetZ());
  FixDistOp("4 Offset", layout.Offset4());
  FixDistOp("5 Offset", layout.Offset5());

  const auto& reserved_list = layout.ReservedList();
  size_t reserved_count = 1;
  for (const auto& reserved : reserved_list) {
    std::ostringstream res_name;
    res_name << "Reserved " << reserved_count;
    FixDistOp(res_name.str(), reserved);
    ++reserved_count;
  }

  FixDistOp("W RIP Address", layout.RipAddrW());
  FixDistOp("X RIP Address", layout.RipAddrX());
  FixDistOp("Y RIP Address", layout.RipAddrY());
  FixDistOp("Z RIP Address", layout.RipAddrZ());
  FixDistOp("4 RIP Address", layout.RipAddr4());
  FixDistOp("5 RIP Address", layout.RipAddr5());

  FixDistOp("X Shift Operand", layout.ShiftOpX());
  FixDistOp("Y Shift Operand", layout.ShiftOpY());
  FixDistOp("Z Shift Operand", layout.ShiftOpZ());
  FixDistOp("4 Shift Operand", layout.ShiftOp4());
  FixDistOp("5 Shift Operand", layout.ShiftOp5());

  FixDistOp("X Source Address", layout.SrcAddrX());
  FixDistOp("Y Source Address", layout.SrcAddrY());
  FixDistOp("Z Source Address", layout.SrcAddrZ());
  FixDistOp("4 Source Address", layout.SrcAddr4());
  FixDistOp("5 Source Address", layout.SrcAddr5());

  FixBool("Static Address Offset", "", layout.StaticAddressOffsets());
  FixBool("Static Record Layout", "", layout.StaticRecordLayout());

}

void A2lPropertyGrid::Redraw(const Transformer& transformer) {
  Append(new wxPropertyCategory("Transformer"));
  Append(new wxStringProperty("Name", wxPG_LABEL,
                              wxString::FromUTF8(transformer.Name())));
  Append(new wxStringProperty("Version", wxPG_LABEL,
                              wxString::FromUTF8(transformer.Version())));
  Append(new wxStringProperty("32-bit Executable", wxPG_LABEL,
                              wxString::FromUTF8(transformer.Executable32())));
  Append(new wxStringProperty("64-bit Executable", wxPG_LABEL,
                              wxString::FromUTF8(transformer.Executable64())));
  Append(new wxUIntProperty("Timeout", wxPG_LABEL,transformer.Timeout()));
  FixEnumList("Trigger", "", TriggerToStringList(), transformer.Trigger());
  Append(new wxStringProperty("Inverse Transformer", wxPG_LABEL,
                  wxString::FromUTF8(transformer.InverseTransformer())));
  FixStringList("Input Objects", "", transformer.TransformerInObjects());
  FixStringList("Output Objects", "", transformer.TransformerOutObjects());
}

void A2lPropertyGrid::Redraw(const Structure& structure) {
  Append(new wxPropertyCategory("Structure"));
  FixNameDesc(structure);
  Append(new wxUIntProperty("Size", wxPG_LABEL,structure.Size()));
  FixEnumList("Address Type", "", AddressTypeToStringList(),
              structure.AddressType());
  FixBool("Consistent Exchange", "", structure.ConsistentExchange());
  FixString("Symbol Type Link", "", structure.SymbolTypeLink());

  const auto& list = structure.StructureComponents();
  size_t count = 1;
  for (const auto& [name, component] : list) {
    std::ostringstream cat_text;
    cat_text << "Component " << count;
    Append(new wxPropertyCategory(cat_text.str()));

    std::ostringstream prop_name;
    prop_name << name << "_name";
    Append(new wxStringProperty("Name", prop_name.str(),
                                wxString::FromUTF8(component->Name)));

    std::ostringstream prop_typedef;
    prop_typedef << name << "_typedef";
    Append(new wxStringProperty("Typedef", prop_typedef.str(),
                                wxString::FromUTF8(component->Typedef)));

    std::ostringstream prop_offset;
    prop_offset << name << "_offset";
    Append(new wxUIntProperty("Offset", prop_offset.str(),
                                component->AddressOffset));

    std::ostringstream prop_type;
    prop_type << name << "_type";
    FixEnumList("Address Type", prop_type.str(), AddressTypeToStringList(),
                component->AddressType);

    std::ostringstream prop_layout;
    prop_layout << name << "_layout";
    FixEnumList("Layout", prop_layout.str(), LayoutToStringList(),
                component->Layout);

    std::ostringstream prop_matrix;
    prop_matrix << name << "_matrix";
    FixUintList("Matrix Dimension", prop_matrix.str(), component->MatrixDim);

    std::ostringstream prop_link;
    prop_link << name << "_link";
    FixString("Symbol Type Link", prop_link.str(), structure.SymbolTypeLink());

    ++count;
  }
}

void A2lPropertyGrid::Redraw(const Unit& unit) {
  Append(new wxPropertyCategory("Unit"));
  FixNameDesc(unit);
  Append(new wxStringProperty("Display Identifier", wxPG_LABEL,
                              wxString::FromUTF8(unit.DisplayIdentifier())));
  FixEnumList("Type", "", UnitTypeToStringList(), unit.Type());

  FixString("Unit Reference", "", unit.RefUnit());
  const auto& exp = unit.SiExponents();
  if (exp.HasExponent()) {
    Append(new wxIntProperty("Length SI Exponent", wxPG_LABEL,
                             static_cast<long>(exp.Length)));
    Append(new wxIntProperty("Mass SI Exponent", wxPG_LABEL,
                             static_cast<long>(exp.Mass)));
    Append(new wxIntProperty("Time SI Exponent", wxPG_LABEL,
                             static_cast<long>(exp.Time)));
    Append(new wxIntProperty("Current SI Exponent", wxPG_LABEL,
                             static_cast<long>(exp.ElectricCurrent)));
    Append(new wxIntProperty("Temperature SI Exponent", wxPG_LABEL,
                             static_cast<long>(exp.Temperature)));
    Append(new wxIntProperty("Amount SI Exponent", wxPG_LABEL,
                             static_cast<long>(exp.AmountOfSubstance)));
    Append(new wxIntProperty("Luminous SI Exponent", wxPG_LABEL,
                             static_cast<long>(exp.LuminousIntensity)));
  }
  FixFloat("Gradient", "", unit.Gradient());
  FixFloat("Offset", "", unit.Offset());
}

void A2lPropertyGrid::Redraw(const A2lUserRights& user) {
  Append(new wxPropertyCategory("User Rights"));

  Append(new wxStringProperty("", wxPG_LABEL,
                              wxString::FromUTF8(user.UserLevelId)));
  FixBool("Read Only", "", user.ReadOnly);
  for (const auto& group : user.RefGroupList) {
     FixStringList("Reference Group", "", group);
  }

}

void A2lPropertyGrid::Redraw(const A2lVariantCoding& object) {
  Append(new wxPropertyCategory("Variant Coding"));
  {
    std::vector<std::string> list;
    for (const auto& name : object.CharacteristicList | std::views::keys) {
      list.emplace_back(name);
    }
    FixStringList("Variant Characteristics", "", list);
  }
  {
    std::vector<std::string> list;
    for (const auto& name : object.CriterionList | std::views::keys) {
      list.emplace_back(name);
    }
    FixStringList("Variant Criterion", "", list);
  }
  size_t count = 0;
  for (const auto& comb_list : object.ForbiddenCombList) {
    std::ostringstream list_name;
    list_name << "comb_list_" << count;
    FixStringMap("Forbidden Combinations", list_name.str(), comb_list);
    ++count;
  }
  FixString("Naming", "", object.Naming);
  FixString("Separator", "", object.Separator);
}

void A2lPropertyGrid::Redraw(const A2lVarCharacteristic& object) {
  Append(new wxPropertyCategory("Variant Characteristic"));
  Append(new wxStringProperty("Name", wxPG_LABEL,
                              wxString::FromUTF8(object.Name)));
  FixStringList("Criterion Names", "", object.CriterionNameList);
  FixUintList("Variant Address", "", object.AddressList);
}

void A2lPropertyGrid::Redraw(const A2lVarCriterion& object) {
  Append(new wxPropertyCategory("Variant Criterion"));
  Append(new wxStringProperty("Name", wxPG_LABEL,
                              wxString::FromUTF8(object.Name)));
  Append(new wxStringProperty("Description", wxPG_LABEL,
                              wxString::FromUTF8(object.Description)));
  FixStringList("Values", "", object.ValueList);
  FixString("Measurement", "", object.Measurement);
  FixString("Characteristic", "", object.SelectionCharacteristic);
}

void A2lPropertyGrid::RedrawXcpData(const std::string& protocol,
                                    const Module& module) {
  const xcp::XcpDataBlock* data = nullptr;
  if (protocol == "XCPplus") {
    data = module.GetXcpPlusDataBlock();
  } else if (protocol == "XCP") {
    data = module.GetXcpDataBlock();
  }
  if (data == nullptr) {
    Redraw(module);
    return;
  }

  const xcp::CommonParameters& common = data->GetCommonParameters();
  FixCommonParameters(common, "common_");
  FixXcpOnCan(data->GetXcpOnCans());
  FixXcpOnSxi(data->GetXcpOnSxis());
  FixXcpOnTcpIp(data->GetXcpOnTcpIps());
  FixXcpOnUdpIp(data->GetXcpOnUdpIps());
  FixXcpOnUsb(data->GetXcpOnUsbs());
  FixXcpOnFlx(data->GetXcpOnFlxs());
}
void A2lPropertyGrid::FixCommonParameters(const xcp::CommonParameters& common,
  const std::string& base) {
  if (const xcp::ProtocolLayer* layer = common.GetProtocolLayer();
    layer != nullptr ) {
    FixProtocolLayer(*layer, base);
  }

  if (const xcp::Daq* daq = common.GetDaq();
      daq != nullptr ) {
    FixDaq(*daq, base);
  }

  if (const xcp::DaqEvent* daq_event = common.GetDaqEvent();
      daq_event != nullptr ) {
    FixDaqEvent(*daq_event);
  }

  if (const xcp::Pag* pag = common.GetPag();
      pag != nullptr ) {
    Append(new wxPropertyCategory("Page Switching",
      base + "page_switching"));
    FixUint("Max Segments",
      base + "pag_switching_max_segments", pag->GetMaxSegments());
    FixBool("Freeze Supported",
      base + "pag_switching_freeze", pag->GetFreezeSupported());
  }

  if (const xcp::Pgm* pgm = common.GetPgm(); pgm != nullptr ) {
    FixPgm(*pgm, base);
  }

  if (const xcp::Segment* segment = common.GetSegment(); segment != nullptr ) {
    FixSegment(*segment);
  }

  if (const auto* correlation = common.GetTimeCorrelation();
      correlation != nullptr ) {
    FixTimeCorrelation(*correlation, base);
  }
}

void A2lPropertyGrid::FixProtocolLayer(const xcp::ProtocolLayer& layer,
  const std::string& base) {
  Append(new wxPropertyCategory("Protocol Layer",base + "layer"));
  FixString("Version",
    base + "layer_version",
    layer.GetVersionAsString());
  FixUint("T1 [ms]", base + "layer_t1",
    layer.GetTimer(xcp::ProtocolTimer::T1));
  FixUint("T2 [ms]", base + "layer_t2",
    layer.GetTimer(xcp::ProtocolTimer::T2));
  FixUint("T3 [ms]", base + "layer_t3",
    layer.GetTimer(xcp::ProtocolTimer::T3));
  FixUint("T4 [ms]", base + "layer_t4",
    layer.GetTimer(xcp::ProtocolTimer::T4));
  FixUint("T5 [ms]", base + "layer_t5",
    layer.GetTimer(xcp::ProtocolTimer::T5));
  FixUint("T6 [ms]", base + "layer_t6",
    layer.GetTimer(xcp::ProtocolTimer::T6));
  FixUint("T7 [ms]", base + "layer_t7",
    layer.GetTimer(xcp::ProtocolTimer::T7));

  FixUint("Max Command Transfer Object [byte]",
    base +"layer_max_cto", layer.GetMaxCto());
  FixUint("Max Data Transfer Object [byte]",
    base + "layer_max_dto",
    layer.GetMaxDto());

  constexpr std::array<std::string_view, 2> kByteOrder = {
    "Little Endian",
    "Big Endian"
  };
  FixEnumList("Byte Order",
    base + "layer_byte_order", kByteOrder,
    layer.GetByteOrder());

  FixEnumList("Address Granularity [byte]",
    base + "layer_granularity",
    kAddressGranularity, layer.GetAddressGranularity());

  if (const auto& optional = layer.GetOptionalCommands();
      !optional.empty() ) {
    std::vector<std::string> list;
    for (const auto& command : optional) {
      const std::string_view cmd = xcp::CommandToString(command);
      list.emplace_back(cmd.empty() ?
        std::to_string(static_cast<int>(command)) : std::string(cmd));
    }
    FixStringList("Optional Commands",
      base + "layer_optional_commands", list);
  }

  if (const auto& level1 = layer.GetOptionalCommandsLevel1();
    !level1.empty() ) {
    std::vector<std::string> list;
    for (const auto& command : level1) {
      const std::string_view cmd = xcp::CommandLevel1ToString(command);
      list.emplace_back(cmd.empty() ?
        std::to_string(static_cast<int>(command)) : std::string(cmd));
    }
    FixStringList("Optional Level1 Commands",
      base + "layer_level1_commands", list);
  }

  if (const auto* mode = layer.GetCommunicationMode(); mode != nullptr) {
    FixCommunicationMode(*mode, base +"layer");
  }

  if (const std::string& seed_key = layer.GetSeedAndKeyFunction();
      !seed_key.empty()) {
    FixString("Seed and Key Function",
      base + "layer_seed_key", seed_key);
  }
  if (const auto& max_dto = layer.GetMaxDtoStim();
      max_dto.has_value() ) {
    FixUint("Max DTO for STIM [bytes]",
      base +"layer_max_dto_stim",
      max_dto.value());
  }

  FixEcuState(layer.GetEcuStates(), base);
}

void A2lPropertyGrid::FixCommunicationMode(
    const a2l::xcp::CommunicationMode& mode,
    const std::string& base_name) {
    if (const bool slave = mode.GetSlaveModeSupported(); slave) {
     FixBool("Slave Mode Supported", base_name + "mode_slave",
      mode.GetSlaveModeSupported());
    }
    if (const bool master = mode.GetMasterModeSupported(); master) {
       FixBool("Master Mode Supported", base_name + "mode_master",
      mode.GetMasterModeSupported());
       FixUint("Max Block Size", base_name + "mode_max_bs",
         mode.GetMaxBs());
       FixUint("Min Time Interval", base_name + "mode_min_st",
         mode.GetMinSt());
    }
    if (const bool interleaved = mode.GetInterleavedSupported(); interleaved) {
       FixBool("Interleaved Supported", base_name + "mode_interleaved",
      mode.GetMasterModeSupported());
       FixUint("Queue Size", base_name + "mode_queue_size",
         mode.GetMaxBs());
    }
}
void A2lPropertyGrid::FixEcuState( const std::vector<xcp::EcuState>& state_list,
  const std::string& base) {
  for (size_t index = 0; index < state_list.size(); ++index) {
    const auto& state = state_list[index];
    const std::string ecu_base = base + "layer_ecu_state"
      += std::to_string(index);
    Append(new wxPropertyCategory("ECU State", ecu_base));
    FixUint("Number", ecu_base + "_number",
      state.GetNumber() );
    FixString("Name",ecu_base + "_name",
      state.GetName());
    FixBool("ECU Swithed to Default Page",
        ecu_base + "_default_page",
        state.GetEcuSwithedToDefaultPage());

    constexpr std::array<std::string_view, 3> kDaqList = {
          "Not Active",
          "Active",
          "Getter Only"
        };
    FixEnumList("CAL/PAG Resource",ecu_base + "_cal_pag",
        kDaqList, state.GetCalPagResource());

    constexpr std::array<std::string_view, 2> kActiveList = {
      "Not Active",
      "Active",
    };
    FixEnumList("DAQ Resource",
      ecu_base + "_daq",
        kActiveList, state.GetDaqResource());
    FixEnumList("PGM Resource",
      ecu_base + "_pgm",
        kActiveList, state.GetPgmResource());
    FixEnumList("STIM Resource",
      ecu_base + "_stim",
        kActiveList, state.GetStimResource());
    const auto& memory_list = state.GetMemoryAccessList();
    for (size_t idx = 0; idx < memory_list.size(); ++idx ) {
      const auto& memory = memory_list[idx];
      const std::string memory_base = ecu_base + "_memory"
        += std::to_string(idx);
      Append(new wxPropertyCategory("Memory Access",memory_base));
      FixUint("Segment Number",memory_base + "_segment",
        memory.GetSegment());
      FixUint("Page Number",memory_base + "_page",
        memory.GetPage());
      constexpr std::array<std::string_view, 2> kAllowedList = {
        "Not Allowed",
        "Allowed"
      };
      FixEnumList("Read Access",memory_base + "_read",
        kAllowedList, memory.GetReadAccess());
      FixEnumList("Write Access",memory_base + "_write",
        kAllowedList, memory.GetWriteAccess());
    }
  }
}

void A2lPropertyGrid::FixDaq(const xcp::Daq& daq, const std::string& base) {
  Append(new wxPropertyCategory("Data Acquisition", base + "daq"));
  constexpr std::array<std::string_view, 2> kTypeList = {
    "Static",
    "Dynamic"
  };
  FixEnumList("Type", base + "daq_type", kTypeList,
    daq.GetType());
  FixUint("Max DAQ Lists", base + "daq_max_daq",
    daq.GetMaxDaq());
  FixUint("Max Event Channels", base + "daq_max_event",
    daq.GetMaxEvent());
  FixUint("Min DAQ Lists", base + "daq_min_daq",
    daq.GetMinDaq());

  constexpr std::array<std::string_view, 6> kOptList = {
    "Default",
    "ODT Type 16",
    "ODT Type 32",
    "ODT Type 64",
    "ODT Type Alignment"
    "Max Entry Size"
  };
  FixEnumList("Optimisation Type",
    base + "daq_opt", kOptList,
    daq.GetOptimisationType());

  constexpr std::array<std::string_view, 4> kExtensionList = {
    "Free",
    "ODT",
    "",
    "DAQ",
  };
  FixEnumList("Address Extension", base + "daq_extension",
    kExtensionList,daq.GetOptimisationType());

  constexpr std::array<std::string_view, 4> kFieldTypeList = {
    "Absolute",
    "Relative Byte",
    "Relative Word",
    "Relative Word Aligned"
  };
  FixEnumList("Identification Field Type",
    base + "daq_field_type",
    kFieldTypeList, daq.GetIdentificationFieldType());

  FixUint("DAQ ODT Entry Size [byte]",
    base + "daq_gran_daq",
    static_cast<uint8_t>(daq.GetGranularityOdtEntrySizeDaq()) );

  FixUint("Max ODT Entry Size [byte]",
    base + "daq_max_odt_entry",
    daq.GetMaxOdtEntrySize());

  constexpr std::array<std::string_view, 3> kOverloadList = {
    "No Indication",
    "Packet ID",
    "Event"
  };
  FixEnumList("Overload Indication",
    base + "daq_overload",
    kOverloadList, daq.GetOverloadIndicator());

  if (const auto& daq_alt = daq.GetDaqAlternatingSupported();
      daq_alt.has_value() ) {
    FixUint("Display Event Channel",
      base + "daq_display_event_channel", daq_alt.value());
  }
  FixBool("Prescaler Supported", base + "daq_prescaler",
    daq.GetPrescalerSupported());
  FixBool("Resume Supported", base + "daq_resume",
    daq.GetResumeSupported());
  FixBool("Store DAQ Supported", base + "daq_store_daq",
    daq.GetStoreDaqSupported());
  FixBool("DTO CTR Field Supported", base + "daq_field",
    daq.GetDtoCtrSupported());
  FixBool("Optimisation Type ODT Strict Mode",
    base + "daq_strict",
    daq.GetOptimisationTypeOdtStrict());

  if (const auto* daq_stim = daq.GetStim(); daq_stim != nullptr) {
     FixUint("STIM ODT Entry Size [byte]",
      base + "daq_stim_entry",
      static_cast<uint8_t>(daq_stim->stim_size));
    FixUint("Max STIM ODT Entry Size",
      base + "daq_stim_max_entry", daq_stim->max_odt_entry_size);
    FixBool("Bit STIM Supported", base + "daq_stim_bit",
      daq_stim->bit_stim_supported);
    if (const auto& min_st_stim = daq_stim->min_st_stim;
        min_st_stim.has_value() ) {
      FixUint("Min STIM [100 \xC2\xB5s]",
        base + "daq_stim_min_stim", min_st_stim.value());
    }
  }

  if (const auto* timestamp = daq.GetTimestamp(); timestamp != nullptr) {
    FixUint("Timestamp Ticks",
      base + "daq_timestamp_ticks",timestamp->GetTicks());
    FixUint("Timestamp Size [byte]",
      base + "daq_timestamp_size",
    static_cast<uint8_t>(timestamp->GetSize()));

    constexpr std::array<std::string_view, 13> kResolutionList = {
      "1 ns",
      "10 ns"
      "100 ns",
      "1 \xC2\xB5s",
      "10 \xC2\xB5s",
      "100 \xC2\xB5s",
      "1 ms",
      "10 ms",
      "100 ms",
      "1 s",
      "1 ps",
      "10 ps",
      "100 ps"
    };
    FixEnumList("Resolution",
      base + "daq_timestamp_resolution",
      kResolutionList, timestamp->GetResolution());
    FixBool("Fixed", base + "daq_timestamp_fixed",
      timestamp->GetFixed());
  }
  FixBool("Packet ID Off Supported", base + "daq_pid_off",
    daq.GetPidOffSupported());
  if (const auto& total = daq.GetMaxDaqTotal();
      total.has_value()) {
    FixUint("Max DAQ Total", base + "daq_max_daq_total",
      total.value());
  }
  if (const auto& total = daq.GetMaxOdtTotal();
      total.has_value()) {
    FixUint("Max ODT Total", "daq_max_odt_total",
      total.value());
  }
  if (const auto& total = daq.GetMaxOdtDaqTotal();
      total.has_value()) {
    FixUint("Max ODT DAQ Total",
      base + "daq_max_odt_daq_total", total.value());
  }
  if (const auto& total = daq.GetMaxOdtStimTotal();
      total.has_value()) {
    FixUint("Max ODT STIM Total",
      base + "daq_max_odt_stim_total", total.value());
  }
  if (const auto& total = daq.GetMaxDtoEntriesTotal();
      total.has_value()) {
    FixUint("Max DTO Entries Total",
      base + "daq_max_dto_entries_total", total.value());
  }
  if (const auto& total = daq.GetMaxDtoEntriesDaqTotal();
      total.has_value()) {
    FixUint("Max DTO Entries DAQ Total",
      base + "daq_max_dto_entries_daq_total", total.value());
  }
  if (const auto& total = daq.GetMaxDtoEntriesStimTotal();
      total.has_value()) {
    FixUint("Max DTO Entries STIM Total",
      base + "daq_max_dto_entries_stim_total", total.value());
  }
  if (const auto& total = daq.GetCpuLoadMaxTotal();
      total.has_value()) {
    FixFloat("Max CPU Load Total",
      base + "daq_max_cpu_load_total", total.value());
  }
  if (const auto& total = daq.GetCoreLoadMaxTotal();
      total.has_value()) {
    FixFloat("Max Core Load Total",
      base + "daq_max_core_load_total", total.value());
  }

  const auto& core_list = daq.GetCoreLoadMaxList();
  for (size_t index = 0; index < core_list.size(); ++index) {
    const auto& core = core_list[index];
    const std::string core_index = std::to_string(index);
    Append(new wxPropertyCategory("Max Core Load",
      base + "daq_max_core_load" += core_index));
    FixUint("Core Number",
      base + "daq_max_core_load_core" += core_index, core.number);
    FixFloat("Max Core Load",
      base + "daq_max_core_load" += core_index, core.max);
  }

  if (const auto* consumption = daq.GetDaqMemoryConsumption();
      consumption != nullptr) {
    Append(new wxPropertyCategory("DAQ Memory Consumption",
      base + "daq_mem_consuption"));
    FixUint("Limit [element]",
      base + "daq_mem_consumption_limit", consumption->limit );
    FixUint("DAQ Size/List [element]",
      base + "daq_mem_consumption_daq_size", consumption->daq_size );
    FixUint("ODT Entry Size [element]",
      base + "daq_mem_consumption_odt_size", consumption->odt_size );
    FixUint("ODT DAQ Buffer Size",
      base + "daq_mem_consumption_odt_daq_buffer",
      consumption->odt_daq_buffer_element_size );
    FixUint("ODT STIM Buffer Size",
      base + "daq_mem_consumption_odt_stim_buffer",
      consumption->odt_stim_buffer_element_size );
    if (const auto& dto_stim = consumption->dto_stim_size;
        dto_stim.has_value()) {
      FixUint("ODT DAQ Buffer Reserve [%]",
        base + "daq_mem_consumption_odt_daq_reserve",
        dto_stim.value().odt_daq_buffer );
      FixUint("ODT STIM Buffer Reserve [%]",
        base + "daq_mem_consumption_odt_stim_reserve",
        dto_stim.value().odt_stim_buffer );
    }

  }
  FixDaqList(daq.GetDaqList(), base);
  FixEventList(daq.GetEventList(),base);
}

void A2lPropertyGrid::FixTimeCorrelation(
    const xcp::TimeCorrelation& correlation,
    const std::string& base) {
  Append(new wxPropertyCategory("Time Correlation",
  base + "time_correlation"));
  constexpr std::array<std::string_view, 2> kRelateList = {
    "XCP Slave Clock",
    "ECU Clock"
  };
  FixEnumList("DAQ Timestamps Relation",
    base + "time_correlation_relation",
    kRelateList, correlation.GetTimestampsRelateTo());
  const auto& clock_list = correlation.GetClocks();
  for (size_t index = 0; index < clock_list.size(); ++index) {
    const auto& clock = clock_list[index];
    const std::string clock_index = std::to_string(index);
    const std::string clock_base = base + "time_correlation_clock" + clock_index;

    Append(new wxPropertyCategory("Clock",clock_base));
    FixString("UUID",
      clock_base  + "_uuid",
      clock.GetUuid());

    constexpr std::array<std::string_view, 4> kTypeList = {
      "XCP Slave Clock",
      "ECU Clock",
      "XCP Slave Grandmaster Clock",
      "ECU Grandmaster Clock"
    };
    FixEnumList("Type", clock_base + "_type",
      kTypeList, clock.GetType());

    constexpr std::array<std::string_view, 3> kReadabilityList = {
      "Randomly",
      "Limited",
      "Not Readable"
    };
    FixEnumList("Readability",
      clock_base + "_readability",
      kReadabilityList, clock.GetReadability());

    constexpr std::array<std::string_view, 4> kSyncList = {
      "Synchronization Unsupported",
      "Synchronization Only",
      "Syntonization Only",
      "Synchronize All"
    };
    FixEnumList("Synchronization",
      clock_base + "_sync",
      kSyncList, clock.GetSynchronization());

    FixUint("Clock Quality",clock_base + "_quality",
      clock.GetClockQuality());

    if (const auto* timestamp = clock.GetCharacteristic(); timestamp != nullptr) {
      FixUint("Timestamp Ticks",
        clock_base + "_timestamp_ticks",
        timestamp->GetTicks());
      FixEnumList("Timestamp Resolution",
        clock_base + "_timestamp_resolution",
        kResolutionList, timestamp->GetResolution());
      FixUint("Timestamp Size [bytes]",
        clock_base + "_timestamp_size",
        static_cast<uint8_t>(timestamp->GetSize()));
    }
    FixUint("Timestamp Wrap-Around",
      clock_base + "_wrap_around",
      clock.GetMaxTimestampValueBeforeWrapAround());

    constexpr std::array<std::string_view, 3> kEpochList = {
      "Atomic Time (TAI)",
      "UTC",
      "Arbitary"
    };
    FixEnumList("Epoch",
      clock_base + "_epoch",
        kEpochList, clock.GetEpoch());
  }

}

void A2lPropertyGrid::FixDaqList(const std::vector<xcp::DaqList>& daq_list,
  const std::string& base) {
  for (size_t index = 0; index < daq_list.size(); ++index) {
    const auto& list = daq_list[index];
    const std::string list_index = std::to_string(index);
    Append(new wxPropertyCategory("Data Acquisition List",
      base + "daq_list" + list_index));
    FixUint("Number",
      base + "daq_list_number" + list_index,
      list.GetNumber() );

    if (const auto& type = list.GetType(); type.has_value()) {
      constexpr std::array<std::string_view, 4> kTypeList = {
        "",
        "DAQ",
        "STIM"
        "DAQ & STIM"
      };
      FixEnumList("Type",
        base + "daq_list_type" + list_index,
           kTypeList,type.value());
    }
    if (const auto& max_odt = list.GetMaxOdt(); max_odt.has_value()) {
      FixUint("Max ODT",
        base + "daq_list_max_odt" + list_index, max_odt.value());
    }
    if (const auto& max_odt_entries = list.GetMaxOdtEntries();
        max_odt_entries.has_value()) {
      FixUint("Max ODT Entries",
        base + "daq_list_max_odt_entries" + list_index,
        max_odt_entries.value());
    }
    if (const auto& first_pid = list.GetFirstPid();
        first_pid.has_value()) {
      FixHex("First Packet ID",
        base +"daq_list_first_pid" + list_index, first_pid.value());
    }
    if (const auto& event_fixed = list.GetEventFixed();
        event_fixed.has_value()) {
      FixUint("Event",
        base + "daq_list_event" + list_index,
        event_fixed.value());
    }
    FixBool("DAQ Packed Mode",
      base + "daq_list_packed" + list_index,
      list.GetDaqPackedModeSupported());
    const auto& odt_list = list.GetPredefinedList();
    for (size_t idx = 0; idx < odt_list.size(); ++idx) {
      const auto& odt = odt_list[idx];
      const std::string odt_index = std::to_string(idx);
      Append(new wxPropertyCategory("Predefined ODT",
        base + "daq_list_odt" + list_index + "_odt" + odt_index));
      FixUint("ODT Number",
        base + "daq_list" + list_index + "_odt" + odt_index,
        odt.number);

      for ( size_t ixx = 0; ixx < odt.odt_entry_list.size(); ++ixx) {
        const auto& entry = odt.odt_entry_list[ixx];
        const std::string entry_index = std::to_string(ixx);
        Append(new wxPropertyCategory("ODT Entry",
          base + "daq_list" + list_index + "_odt" +
          odt_index + "_entry" + entry_index ));

        FixUint("Number",
          base + "daq_list" + list_index + "_odt" +
          odt_index + "_entry_no" + entry_index,
          entry.number);

        FixHex("Address",
          base + "daq_list" + list_index + "_odt" +
          odt_index + "_entry_address" + entry_index,
          entry.address);

        FixUint("Address Extension",
          base + "daq_list" + list_index + "_odt" +
          odt_index + "_entry_extension" + entry_index,
          entry.address_extension);

        FixUint("Size [element]",
          base + "daq_list" + list_index + "_odt" +
          odt_index + "_entry_size" + entry_index,
          entry.size);

        FixUint("Bit Offset",
          base + "daq_list" + list_index + "_odt" +
          odt_index + "_entry_offset" + entry_index,
          entry.bit_offset);
      }
    }
  }
}

void A2lPropertyGrid::FixEventList(const std::vector<xcp::Event>& event_list,
  const std::string& base) {
  for (size_t index = 0; index < event_list.size(); ++index) {
    const auto& event = event_list[index];
    const std::string event_index = std::to_string(index);
    Append(new wxPropertyCategory("Event Channel",
      base + "event" + event_index));
    FixString("Name", base + "event_name" + event_index,
      event.GetName());
    FixString("Display Name", base + "event_display" + event_index,
      event.GetName());
    FixUint("Number",
      base + "event_number" + event_index,
      event.GetNumber());

    constexpr std::array<std::string_view, 4> kTypeList = {
      "",
      "DAQ",
      "STIM",
      "DAQ & STIM"
    };
    FixEnumList("Type", base + "event_type" + event_index,
      kTypeList,event.GetType());
    FixUint("Max DAQ Lists",
      base + "event_max_daq_list" + event_index, event.GetMaxDaqList());
    FixUint("Cycle",
      base + "event_cycle" + event_index, event.GetTimeCycle());
    FixUint("Unit",
      base + "event_unit" + event_index, event.GetTimeUnit());
    FixUint("Priority",
      base + "event_priority" + event_index, event.GetPriority());
    if (const auto& bypass = event.GetComplementaryBypassNumber();
        bypass.has_value()) {
      FixUint("Bypass Event Channel",
        base + "event_bypass" + event_index,
        bypass.value());
    }
    if (const auto& consistency = event.GetConsistency();
        consistency.has_value()) {
      constexpr std::array<std::string_view, 4> kConsistencyList = {
        "DAQ",
        "Event",
        "ODT",
        "None"
      };
      FixEnumList("Consistency",
        base + "event_consistency" + event_index,
        kConsistencyList, consistency.value());
    }
    FixBool("Event Counter Present",
      base + "event_counter",
      event.GetEventCounterPresent());
    if (const auto& related = event.GetRelatedNumber();
        related.has_value()) {
      FixUint("Related Event Channel",
        base + "event_related" + event_index,
        related.value());
    }
    FixBool("Related Event Channel Fixed",
      base + "event_related_fixed",event.GetRelatedNumberFixed());
    if (const auto& daq_mode = event.GetDtoCtrDaqMode();
        daq_mode.has_value()) {
      constexpr std::array<std::string_view, 2> kModeList = {
        "Insert Counter",
        "Insert STIM Counter Copy"
      };
      FixEnumList("DTO CTR DAQ Mode",
        base + "event_daq_mode" + event_index,
        kModeList, daq_mode.value());
    }
    FixBool("DTO CTR DAQ Mode Fixed",
      base + "event_daq_mode_fixed",event.GetDtoCtrDaqModeFixed());
    if (const auto& stim_mode = event.GetDtoCtrStimMode();
        stim_mode.has_value()) {
      constexpr std::array<std::string_view, 2> kModeList = {
        "Do not Check Counter",
        "Check Counter"
      };
      FixEnumList("DTO CTR STIM Mode",
        base + "event_stim_mode" + event_index,
        kModeList, stim_mode.value());
    }
    FixBool("DTO CTR STIM Mode Fixed",
      base + "event_stim_mode_fixed",event.GetDtoCtrStimModeFixed());
    FixBool("STIM DTO CTR Copy Present",
  base + "event_stim_copy",event.GetStimDtoCtrCopyPresent());
    if (const auto* packed = event.GetDaqPackedMode(); packed != nullptr) {
      constexpr std::array<std::string_view, 3> kGroupList = {
        "",
        "Element Grouped",
        "Event"
      };
      FixEnumList("DAQ Packed Mode",
        base + "event_daq_packed_mode" + event_index,
        kGroupList, packed->group);
      constexpr std::array<std::string_view, 2> kStsList = {
        "STS Last",
        "STS First"
      };
      FixEnumList("DAQ Packed Timestamp Mode",
        base + "event_daq_packed_timestamp" + event_index,
        kStsList, packed->timestamp_mode);
      constexpr std::array<std::string_view, 2> kUsageList = {
        "Optional",
        "Mandatory"
      };
      FixEnumList("DAQ Packed Usage",
        base + "event_daq_packed_usage" + event_index,
        kUsageList, packed->usage);
      FixUint("DAQ Packed Sample Count",
        base + "event_daq_packed_sample_count" + event_index,
        packed->sample_count);
      if (const auto& valid_list = packed->alt_sample_count;
         !valid_list.empty()) {
        std::deque<uint64_t> list(valid_list.cbegin(),
                                   valid_list.cend());
        FixUintList("DAQ Packed Valid Sample Counts",
          base + "event_daq_packed_valid_count" + event_index,
          list);
      }
    }
    if (const auto* min_cycle = event.GetMinCycleTime();
        min_cycle != nullptr) {
      FixUint("Min Time Cycle",
        base + "event_min_time_cycle" + event_index,
        min_cycle->time_cycle);
      FixUint("Min Time Unit",
        base + "event_min_time_unit" + event_index,
        min_cycle->time_unit);
    }
    if (const auto* reserve = event.GetBufferReserveEvent();
        reserve != nullptr) {
      FixUint("Buffer Reserver DAQ Size",
        base + "event_reserve_daq" + event_index,
        reserve->odt_daq_buffer_element_reserve);
      FixUint("Buffer Reserver STIM Size",
        base + "event_reserve_stim" + event_index,
        reserve->odt_stim_buffer_element_reserve);
    }

    if (const auto& cpu_load = event.GetCpuLoadMax();
        cpu_load.has_value()) {
      FixUint("Max CPU Load [%]",
        base + "event_cpu_load_max" + event_index,
        cpu_load.value());
    }

    if (const auto* consumption = event.GetCpuLoadConsumptionDaq();
        consumption != nullptr ) {
      Append(new wxPropertyCategory("CPU Load Consumption DAQ",
        base + "cpu_load_daq" + event_index));
      FixFloat("DAQ Factor [%]",
        base + "cpu_load_daq_daq_factor" + event_index,
        consumption->daq_factor);
      FixFloat("ODT Factor [%]",
        base + "cpu_load_daq_odt_factor" + event_index,
        consumption->odt_factor);
      FixFloat("ODT Entry Factor [%]",
        base + "cpu_load_daq_odt_entry_factor" + event_index,
        consumption->odt_entry_factor);
      if (const auto& core_load = consumption->core_load_ep;
          core_load.has_value()) {
        FixUint("Core Number",
          base + "cpu_load_daq_odt_core_number" + event_index,
        core_load.value().number);
        FixFloat("Core Max Load [%]",
          base + "cpu_load_daq_odt_core_load" + event_index,
          core_load.value().max);
      }
      for ( size_t idx = 0; idx < consumption->odt_entry_size_factors.size(); ++idx) {
        const auto& factor = consumption->odt_entry_size_factors[idx];
        std::string size_index = std::to_string(idx);
        Append(new wxPropertyCategory("ODT Entry Size Factor",
          base + "cpu_load_daq_entry" + event_index + "_size" + size_index));
        FixUint("Size",
          base + "cpu_load_daq_odt_entry" + event_index +
          "_size_size" + size_index,
          factor.factor);
        FixFloat("Factor [%]",
          base + "cpu_load_daq_odt_entry" + event_index +
          "_size_factor" + size_index,
          factor.factor);
      }
    }

    if (const auto* consumption = event.GetCpuLoadConsumptionStim();
        consumption != nullptr ) {
      Append(new wxPropertyCategory("CPU Load Consumption STIM",
        "cpu_load_stim" + event_index));
      FixFloat("DAQ Factor [%]",
        base + "cpu_load_stim_daq_factor" + event_index,
        consumption->daq_factor);
      FixFloat("ODT Factor [%]",
        base + "cpu_load_stim_odt_factor" + event_index,
        consumption->odt_factor);
      FixFloat("ODT Entry Factor [%]",
        base + "cpu_load_stim_odt_entry_factor" + event_index,
        consumption->odt_entry_factor);
      if (const auto& core_load = consumption->core_load_ep;
          core_load.has_value()) {
        FixUint("Core Number",
          base + "cpu_load_stim_odt_core_number" + event_index,
        core_load.value().number);
        FixFloat("Core Max Load [%]",
          base + "cpu_load_stim_odt_core_load" + event_index,
          core_load.value().max);
          }
      for ( size_t idx = 0; idx < consumption->odt_entry_size_factors.size(); ++idx) {
        const auto& factor = consumption->odt_entry_size_factors[idx];
        std::string size_index = std::to_string(idx);
        Append(new wxPropertyCategory("ODT Entry Size Factor",
          base + "cpu_load_stim_entry" + event_index + "_size" + size_index));
        FixUint("Size",
          base + "cpu_load_stim_odt_entry" + event_index +
          "_size_size" + size_index,
          factor.factor);
        FixFloat("Factor [%]",
          base + "cpu_load_stim_odt_entry" + event_index +
          "_size_factor" + size_index,
          factor.factor);
      }
    }

    if (const auto& consumption = event.GetCpuLoadConsumptionQueue();
        consumption != nullptr ) {
      Append(new wxPropertyCategory("CPU Load Consumption Queue",
        base + "cpu_load_queue" + event_index));
      FixFloat("ODT Factor [%]",
        base + "cpu_load_queue_odt_factor" + event_index,
        consumption->odt_factor);
      FixFloat("ODT Element Load",
        base + "cpu_load_queue_odt_element_load" + event_index,
        consumption->odt_element_load);
      if (const auto& core_load = consumption->core_load_ep;
          core_load.has_value()) {
        FixUint("Core Number",
          base + "cpu_load_queue_odt_core_number" + event_index,
        core_load.value().number);
        FixFloat("Core Max Load [%]",
          base + "cpu_load_queue_odt_core_load" + event_index,
          core_load.value().max);
      }
    }

    if (const auto& consumption = event.GetCpuLoadConsumptionQueue();
    consumption != nullptr ) {
      Append(new wxPropertyCategory("CPU Load Consumption Queue STIM",
        base + "cpu_load_queue_stim" + event_index));
      FixFloat("ODT Factor [%]",
        base + "cpu_load_queue_stim_odt_factor" + event_index,
        consumption->odt_factor);
      FixFloat("ODT Element Load",
        base + "cpu_load_queue_stim_odt_element_load" + event_index,
        consumption->odt_element_load);
      if (const auto& core_load = consumption->core_load_ep;
          core_load.has_value()) {
        FixUint("Core Number",
          base + "cpu_load_queue_stim_odt_core_number" + event_index,
        core_load.value().number);
        FixFloat("Core Max Load [%]",
          base + "cpu_load_queue_stim_odt_core_load" + event_index,
          core_load.value().max);
      }
    }

  }
}

void A2lPropertyGrid::FixDaqEvent(const xcp::DaqEvent& event) {
  Append(new wxPropertyCategory("Data Acquisition Event",
    "daq_event"));
  if (const auto& fixed_list = event.GetFixedEventList();
      !fixed_list.empty()) {
    std::deque<uint64_t> list(fixed_list.cbegin(),
                               fixed_list.cend());
    FixUintList("Fixed Events", "daq_event_fixed_list",
      list);
  }
  if (const auto& avail_list = event.GetAvailableEventList();
      !avail_list.empty()) {
    std::deque<uint64_t> list(avail_list.cbegin(),
                               avail_list.cend());
    FixUintList("Available Events",
      "daq_event_avail_list", list);
  }
  if (const auto& default_list = event.GetDefaultEventList();
      !default_list.empty()) {
    std::deque<uint64_t> list(default_list.cbegin(),
                               default_list.cend());
    FixUintList("Default Events",
      "daq_event_default_list", list);
  }
  if (const auto& consistency_list = event.GetConsistencyEventList();
      !consistency_list.empty()) {
    std::deque<uint64_t> list(consistency_list.cbegin(),
                               consistency_list.cend());
    FixUintList("Consistency Events",
      "daq_event_consistency_list", list);
  }

}

void A2lPropertyGrid::FixPgm(const xcp::Pgm& pgm, const std::string& base) {
  Append(new wxPropertyCategory("Flash Programming",
    base + "pgm"));
  constexpr std::array<std::string_view, 4> kTypeList = {
    "",
    "Absolute",
    "Functional",
    "Absolute & Functional"
  };
  FixEnumList("Type", base + "pgm_type", kTypeList,
    pgm.GetType());
  FixUint("Max Sectors", base + "pgm_max_sectors",
    pgm.GetMaxSectors());
  FixUint("Max CTO PGM", base + "pgm_max_cto_pgm",
    pgm.GetMaxCtoPgm());
  if (const auto* mode = pgm.GetCommunicationModeSupported(); mode != nullptr) {
    FixCommunicationMode(*mode, base + "pgm_mode");
  }
  const auto& sector_list = pgm.GetSectorList();
  for (size_t index = 0; index < sector_list.size(); ++index) {
    const auto& sector = sector_list[index];
    std::string sector_index = std::to_string(index);
    Append(new wxPropertyCategory("Sector",
      base + "pgm_sector" + sector_index));
    FixString("Name",
      base + "pgm_sector_name" + sector_index,
      sector.name);
    FixUint("Number",
      base + "pgm_sector_number" + sector_index,
      sector.number);
    FixHex("Address",
      base + "pgm_sector_address" + sector_index,
      sector.address);
    FixUint("Length",
      base + "pgm_sector_length" + sector_index,
      sector.length);
    FixUint("Clear Sequence Number",
      base + "pgm_sector_clear_sequence_number" + sector_index,
      sector.clear_sequence_number);
    FixUint("Program Sequence Number",
      base + "pgm_sector_program_sequence_number" + sector_index,
      sector.program_sequence_number);
    FixUint("Program Method",
      base + "pgm_sector_program_method" + sector_index,
      sector.program_method);
  }
}

void A2lPropertyGrid::FixSegment(const xcp::Segment& segment) {
  Append(new wxPropertyCategory("Segment","segment"));
  FixUint("Number", "segment_number",
    segment.GetNumber());
  FixUint("Number of Pages", "segment_number_of_pages",
    segment.GetNumberOfPages());
  FixUint("Address Extension", "segment_extension",
    segment.GetAddressExtension());
  FixUint("Compression Method", "segment_compression",
    segment.GetCompressionMethod());
  FixUint("Encryption Method", "segment_encryption",
    segment.GetEncryptionMethod());
  if (const auto* checksum = segment.GetChecksum();
      checksum != nullptr) {
    FixUint("Checksum Type", "segment_checksum_type",
      static_cast<uint16_t>(checksum->type));
    if (const auto& max = checksum->max_block_size; max.has_value()) {
      FixUint("Checksum Max Block Size", "segment_checksum_max_block_size",
        max.value());
    }
    if (const std::string& function = checksum->external_function;
        !function.empty()) {
      FixString("Checksum External Function", "segment_checksum_external_function",
        function);
    }
    if (const auto& mta = checksum->mta_block_size_align; mta.has_value()) {
      FixUint("Checksum MTA Block Size Align", "segment_checksum_mta_block_size_align",
        mta.value());
    }
  }
  FixUint("Default Page Number", "segment_default",
      segment.GetDefaultPageNumber());
  FixUint("PGM Verify", "segment_verify",
      segment.GetPgmVerify());

  FixPage(segment.GetPages());
  const auto& map_list = segment.GetAddressMappings();
  for (size_t index = 0; index < map_list.size(); ++index) {
    const auto& map = map_list[index];
    const std::string map_index = std::to_string(index);
    Append(new wxPropertyCategory("Address Mapping",
      "segment_map" + map_index));
    FixHex("Source Address",
      "segment_map_source_address" + map_index,
      map.source_address);
    FixHex("Destination Address",
      "segment_map_destination_address" + map_index,
      map.destination_address);
    FixUint("Length",
      "segment_map_length" + map_index, map.length);
  }
}

void A2lPropertyGrid::FixPage(const std::vector<xcp::Page>& page_list) {
  for (size_t index = 0; index < page_list.size(); ++index) {
    const auto& page = page_list[index];
    std::string page_index = std::to_string(index);
    Append(new wxPropertyCategory("Page",
      "segment_page" + page_index));
    FixUint("Number",
      "segment_page_number" + page_index, page.GetNumber());
    constexpr std::array<std::string_view, 4> kAccessList = {
      "Not Allowed",
      "Without XCP Only",
      "With XCP Only",
      "Don't Care"
    };
    FixEnumList("ECU Access Type",
      "segemnt_page_ecu_access" + page_index, kAccessList,
      page.GetEcuAccessType());
    FixEnumList("XCP Read Access Type",
      "segment_page_xcp_read_access" + page_index, kAccessList,
      page.GetReadAccessType());
    FixEnumList("XCP Write Access Type",
      "segment_page_xcp_write_access" + page_index, kAccessList,
      page.GetWriteAccessType());
    FixUint("Init Segment",
        "segment_page_init_segment" + page_index, page.GetInitSegment());
  }

}
void A2lPropertyGrid::FixXcpOnCan( const std::vector<xcp::XcpOnCan>& xcp_on_can_list) {
  for (size_t index = 0; index < xcp_on_can_list.size(); ++index) {
    const auto& can = xcp_on_can_list[index];
    const std::string base = "xcp_on_can" + std::to_string(index);
    Append(new wxPropertyCategory("XCP On CAN", base));
    FixString("XCP on CAN Version",
      base + "_version",can.GetVersionAsString());
    FixHex("Broadcast ID",
        base + "broadcast_id", can.GetCanIdBroadcast());
    FixHex("Master ID",
        base + "_master_id", can.GetCanIdMaster());
    FixBool("Master ID Incremental",
      base + "_master_id_incremental",
      can.GetCanIdMasterIncremental());
    FixHex("Slave ID",
        base + "_slave_id", can.GetCanIdSlave());
    FixHex("Get DAQ Clock Multicast ID",
        base + "_multicast_id",
        can.GetCanIdGetDaqClockMulticast());
    FixUint("Baudrate [Hz]",
        base + "_baudrate", can.GetBaudrate());
    FixUint("Sample Point [%]",
        base + "_sample_point", can.GetSamplePoint());
    constexpr std::array<std::string_view, 4> kRateList = {
      "",
      "1 sample/bit"
      "",
      "3 samples/bit"
    };
    FixEnumList("Sample Rate",base + "_sample_rate",
      kRateList,can.GetSampleRate());
    FixUint("Bit Time Logic Cycles [slots per bit time]",
        base + "_btl_cycles", can.GetBtlCycles());
    FixUint("Sync Jump Width",
        base + "_sjw", can.GetSjw());
    constexpr std::array<std::string_view, 3> kEdgeList = {
      "",
      "Falling Edge Only",
      "Falling & Rising Edge",
    };
    FixEnumList("Sync Edge", base + "_sync_edge",
      kEdgeList,   can.GetSyncEdge());
    FixBool("Max DLC Required",
      base + "_max_dlc_required",can.GetMaxDlcRequired());
    FixUint("Max Bus Load [%]", base + "_max_bus_load",
      can.GetMaxBusLoad());
    FixBool("Measurement Split Allowed",
      base + "_measurement_split_allowed",can.GetMeasurementSplitAllowed());
    if (const auto* can_fd = can.GetCanFd(); can_fd != nullptr) {
      const std::string fd_base = base + "_can_fd";
      Append(new wxPropertyCategory("CAN FD", fd_base));
      FixUint("Max DLC", fd_base + "_max_dlc",
        can_fd->max_dlc);
      FixUint("Baudrate [Hz]", fd_base + "_baudrate",
        can_fd->baudrate);
      FixUint("Sample Point [%]", fd_base + "_sample_point",
        can_fd->sample_point);
      FixUint("Bit Time Logic [slots/bit time]",
        fd_base + "_btl_cycles", can_fd->btl_cycles);
      FixUint("Sync Jump Width", fd_base + "_sjw",
        can_fd->sjw);
      FixEnumList("Sync Edge", fd_base + "_sync_edge",
        kEdgeList,   can_fd->sync_edge);
      FixBool("Max DLC Required", fd_base + "_max_dlc_required",
        can_fd->max_dlc_required);
      FixUint("Secondary Sample Point [%]",
        fd_base + "_secondary_sample_point",
        can_fd->secondary_sample_point);
      constexpr std::array<std::string_view, 2> kDelayList = {
        "Off",
        "On"
      };
      FixEnumList("Transciever Delay Compensation",
        fd_base + "_delay_compensation",
       kDelayList, can_fd->transceiver_delay_compensation);
    }

    const auto& cmd_list = can.GetSubCmdList();
    std::deque<std::string> list;
    for (size_t idx = 0; idx < cmd_list.size(); ++idx) {
      constexpr size_t kOffset = 0xFA;
      const size_t cmd = static_cast<size_t>(cmd_list[idx]) - kOffset;
      constexpr std::array<std::string_view, 6> kCmdList = {
        "GET_DAQ_CLOCK_MULTICAST", // 0xFA
        "",
        "",
        "SET_DAQ_ID", // 0xFD
        "GET_DAQ_ID",
        "GET_SLAVE_ID",
      };
      if (cmd < kCmdList.size()) {
        list.emplace_back(std::string(kCmdList[cmd]));
      }
    }
    FixStringList("Optional Commands",
      base + "_optional_commands", list);

    FixString("Transport Layer Instance",
      base + "_transport_layer_instance",
      can.GetTransportLayerInstance());

    const auto& daq_list = can.GetCanIdDaqList();
    for (size_t idx = 0; idx < daq_list.size(); ++idx) {
      const auto& daq = daq_list[idx];
      const std::string daq_base = base + "_daq_list"
        += std::to_string(idx);
      Append(new wxPropertyCategory(
        "DAQ List " + std::to_string(daq.number),
        daq_base));
      FixUint("DAQ List Number",
        daq_base + "_number", daq.number);
      FixBool("Variable CAN ID",
        daq_base + "_variable", daq.variable);
      FixHex("Fixed CAN ID",
        daq_base + "_fixed", daq.fixed);
    }

    const auto& event_list = can.GetCanIdEventList();
    for (size_t idx = 0; idx < event_list.size(); ++idx) {
      const auto& event = event_list[idx];
      const std::string event_base = base + "_event"
      += std::to_string(idx);
      Append(new wxPropertyCategory("Event " + std::to_string(event.number),
        event_base));
      FixUint("Number",
        event_base + "_number", event.number);
      FixHexList("Fixed CAN ID",
        event_base + "_fixed", event.fixed_list);
    }

    FixCommonParameters(can.GetOverrulingParameters(),
      base + "_");

  }
}
void A2lPropertyGrid::FixXcpOnSxi(
    const std::vector<xcp::XcpOnSxi>& xcp_on_sxi_list) {
  for (size_t index = 0; index < xcp_on_sxi_list.size(); ++index) {
    const auto& sxi = xcp_on_sxi_list[index];
    const std::string sxi_index = std::to_string(index);
    const std::string base = "xcp_on_sxi" + sxi_index;

    Append(new wxPropertyCategory("XCP On SxI", base));
    FixString("Version",
      base + "_version",sxi.GetVersionAsString());
    FixUint("Baudrate [Hz]", base + "_baudrate",
      sxi.GetBaudrate());

    if (const auto* asynch = sxi.GetAsynchFullDuplexMode(); asynch != nullptr) {
      constexpr std::array<std::string_view, 3> kParityList = {
        "None",
        "Odd",
        "Even"
      };
      FixEnumList("Parity", base + "_parity",
        kParityList, asynch->parity);
      FixUint("Stop Bits", base + "_stop_bits",
        static_cast<uint8_t>(asynch->stop_bit));
      if (const auto& framing = asynch->framing;
        framing.has_value()) {
        FixUint("Framing SYNC", base + "_framing_sync",
          framing.value().sync);
        FixUint("Framing ESC", base + "_framing_esc",
          framing.value().esc);
      }
    }
    FixBool("Synch Full Duplex Mode Byte",
      base + "_duplex_byte",
      sxi.GetSynchFullDuplexModeByte());
    FixBool("Synch Full Duplex Mode Word",
      base + "_duplex_word",
      sxi.GetSynchFullDuplexModeWord());
    FixBool("Synch Full Duplex Mode DWord",
      base + "_duplex_dword",
      sxi.GetSynchFullDuplexModeDword());
    FixBool("Synch Master Slave Mode Byte",
      base + "_ms_byte",
      sxi.GetSynchMasterSlaveModeByte());
    FixBool("Synch Master Slave Mode Word",
      base + "_ms_word",
      sxi.GetSynchMasterSlaveModeWord());
    FixBool("Synch Master Slave Mode DWord",
      base + "_ms_dword",
      sxi.GetSynchMasterSlaveModeDword());


    FixEnumList("Header Length",base + "_header_length",
      kHeaderLengthList, sxi.GetHeaderLength());
    constexpr std::array<std::string_view, 3> kChecksumList = {
      "None",
      "Byte",
      "Word"
    };
    FixEnumList("Checksum", base + "_checksum",
      kChecksumList, sxi.GetChecksum());


    FixString("Transport Layer Instance",
        base + "_transport_layer_instance",
        sxi.GetTransportLayerInstance());
    FixCommonParameters(sxi.GetOverrulingParameters(), base + "_");
  }
}

void A2lPropertyGrid::FixXcpOnTcpIp(
  const std::vector<xcp::XcpOnTcpIp>& xcp_on_tcp_list) {
  for (size_t index = 0; index < xcp_on_tcp_list.size(); ++index) {
    const auto& tcp = xcp_on_tcp_list[index];
    const std::string tcp_index = std::to_string(index);
    const std::string base = "xcp_on_tcp" + tcp_index;

    Append(new wxPropertyCategory("XCP On TCP/IP", base));
    FixString("Version",
      base + "_version",tcp.GetVersionAsString());
    FixUint("Port", base + "_port",
      tcp.GetPort());
    FixString("Host Name", base + "_host_name",
      tcp.GetHostName());
    FixString("Address", base + "_address",
      tcp.GetAddress());
    FixString("IPV6", base + "_ipv6",
      tcp.GetIpv6());
    FixUint("Max Bus Load [%]", base + "_max_bus_load",
      tcp.GetMaxBusLoad());
    FixUint("Max Bir Rate [Mbit]", base + "_max_bit_rate",
      tcp.GetMaxBitRate());
    constexpr std::array<std::string_view, 3> kAlignmentList = {
      "8 bits",
      "16 bits",
      "32 bits"
    };
    FixEnumList("Packet Alignment", base + "_packet_alignment",
      kAlignmentList, tcp.GetPacketAlignment());

    const auto& cmd_list = tcp.GetSubCmds();
    std::deque<std::string> list;
    for (size_t idx = 0; idx < cmd_list.size(); ++idx) {
      constexpr size_t kOffset = 0xFA;
      const size_t cmd = static_cast<size_t>(cmd_list[idx]) - kOffset;
      constexpr std::array<std::string_view, 6> kCmdList = {
        "GET_DAQ_CLOCK_MULTICAST", // 0xFA
        "",
        "SET_SLAVE_IP_ADDRESS", // 0xFC
        "GET_SLAVE_ID_EXTENDED",
        "",
        "GET_SLAVE_ID",
      };
      if (cmd < kCmdList.size()) {
        list.emplace_back(std::string(kCmdList[cmd]));
      }
    }
    FixStringList("Optional Commands",
      base + "_optional_commands", list);
    FixString("Transport Layer Instance",
      base + "_transport_layer_instance",
      tcp.GetTransportLayerInstance());

    FixCommonParameters(tcp.GetOverrulingParameters(), base + "_");
  }
}
void A2lPropertyGrid::FixXcpOnUdpIp(
  const std::vector<xcp::XcpOnUdpIp>& xcp_on_udp_list) {
  for (size_t index = 0; index < xcp_on_udp_list.size(); ++index) {
    const auto& udp = xcp_on_udp_list[index];
    const std::string udp_index = std::to_string(index);
    const std::string base = "xcp_on_udp" + udp_index;

    Append(new wxPropertyCategory("XCP On UDP/IP", base));
    FixString("Version",
      base + "_version",udp.GetVersionAsString());
    FixUint("Port", base + "_port",
      udp.GetPort());
    FixString("Host Name", base + "_host_name",
      udp.GetHostName());
    FixString("Address", base + "_address",
      udp.GetAddress());
    FixString("IPV6", base + "_ipv6",
      udp.GetIpv6());
    FixUint("Max Bus Load [%]", base + "_max_bus_load",
      udp.GetMaxBusLoad());
    FixUint("Max Bir Rate [Mbit]", base + "_max_bit_rate",
      udp.GetMaxBitRate());
    constexpr std::array<std::string_view, 3> kAlignmentList = {
      "8 bits",
      "16 bits",
      "32 bits"
    };
    FixEnumList("Packet Alignment", base + "_packet_alignment",
      kAlignmentList, udp.GetPacketAlignment());

    const auto& cmd_list = udp.GetSubCmds();
    std::deque<std::string> list;
    for (size_t idx = 0; idx < cmd_list.size(); ++idx) {
      constexpr size_t kOffset = 0xFA;
      const size_t cmd = static_cast<size_t>(cmd_list[idx]) - kOffset;
      constexpr std::array<std::string_view, 6> kCmdList = {
        "GET_DAQ_CLOCK_MULTICAST", // 0xFA
        "",
        "SET_SLAVE_IP_ADDRESS", // 0xFC
        "GET_SLAVE_ID_EXTENDED",
        "",
        "GET_SLAVE_ID",
      };
      if (cmd < kCmdList.size()) {
        list.emplace_back(std::string(kCmdList[cmd]));
      }
    }
    FixStringList("Optional Commands",
      base + "_optional_commands", list);
    FixString("Transport Layer Instance",
      base + "_transport_layer_instance",
      udp.GetTransportLayerInstance());

    FixCommonParameters(udp.GetOverrulingParameters(), base + "_");
  }
}

void A2lPropertyGrid::FixXcpOnUsb(
    const std::vector<xcp::XcpOnUsb>& xcp_on_usb_list) {
  for (size_t index = 0; index < xcp_on_usb_list.size(); ++index) {
    const auto& usb = xcp_on_usb_list[index];
    const std::string usb_index = std::to_string(index);
    const std::string base = "xcp_on_usb" + usb_index;

    Append(new wxPropertyCategory("XCP On USB", base));
    FixString("Version",
      base + "_version",usb.GetVersionAsString());
    FixUint("Vendor ID", base + "_vendor_id",
      usb.GetVendorId());
    FixUint("Product ID", base + "_product_id",
      usb.GetProductId());
    FixUint("Number of Interface", base + "_nof_interface",
      usb.GetNumberOfInterfaces());
    FixEnumList("Header Length", base + "_header_length",
      kHeaderLengthList, usb.GetHeaderLength());


    const auto& cmd_list = usb.GetSubCmds();
    std::deque<std::string> list;
    for (size_t idx = 0; idx < cmd_list.size(); ++idx) {
      constexpr size_t kOffset = 0xFE;
      const size_t cmd = static_cast<size_t>(cmd_list[idx]) - kOffset;
      constexpr std::array<std::string_view, 2> kCmdList = {
        "SET_DAQ_EP", // 0xFE
        "GET_DAQ_EP",
      };
      if (cmd < kCmdList.size()) {
        list.emplace_back(std::string(kCmdList[cmd]));
      }
    }
    FixStringList("Optional Commands",
      base + "_optional_commands", list);
    FixString("Transport Layer Instance",
      base + "_transport_layer_instance",
      usb.GetTransportLayerInstance());

    FixUint("Alternating Setting Number",
      base + "_alternating_setting_number",
      usb.GetAlternateSettingNo());
    FixString("Interface Description",
      base + "_interface_description",
      usb.GetInterfaceStringDescriptor());


    if (const auto* ep_stim = usb.GetOutEpCmdStim();
        ep_stim != nullptr) {
      const std::string ep_base = base + "_out_ep_cmd_stim";
      Append(new wxPropertyCategory("Out-EP for CMD & STIM",
        ep_base));
      FixEpParameters(*ep_stim, ep_base);
    }
    const auto& out_ep_list = usb.GetOutEpOnlyStim();
    for (size_t idx = 0; idx < out_ep_list.size(); ++idx) {
      const std::string ep_base = base + "_out_ep_only_stim"
        += std::to_string(idx);
      Append(new wxPropertyCategory("Out-EP only STIM",
        ep_base));
      FixEpParameters(out_ep_list[idx], ep_base);
    }

    if (const auto* ep_daq = usb.GetInEpReserrDaqEvserv();
        ep_daq != nullptr) {
      const std::string ep_base = base + "in_ep_daq";
      Append(new wxPropertyCategory("In-EP for DAQ & EV/SERV",
        ep_base));
      FixEpParameters(*ep_daq, ep_base);
    }
    const auto& in_ep_list = usb.GetInEpOnlyDaq();
    for (size_t idx = 0; idx < in_ep_list.size(); ++idx) {
      const std::string ep_base = base + "_in_ep_only_daq"
        += std::to_string(idx);
      Append(new wxPropertyCategory("In-EP only DAQ",
        ep_base));
      FixEpParameters(in_ep_list[idx], ep_base);
    }
    if (const auto* ep_ev_serv = usb.GetInEpOnlyEvserv();
        ep_ev_serv != nullptr) {
      const std::string ep_base = base + "in_ep_evserv";
      Append(new wxPropertyCategory("In-EP for EV/SERV",
        ep_base));
      FixEpParameters(*ep_ev_serv, ep_base);
    }
    const auto& endpoint_list = usb.GetDaqListUsbEndpoint();
    for (size_t idx = 0; idx < endpoint_list.size(); ++idx) {
      const auto& endpoint = endpoint_list[idx];
      const std::string ep_base = base + "_daq_endpoint"
      += std::to_string(idx);

      Append(new wxPropertyCategory("USB Endpoint",ep_base));
      FixUint("DAQ List", ep_base + "_daq_list",
        endpoint.number);
      FixUint("Fixed In", ep_base + "_fixed_in",
        endpoint.fixed_in);
      FixUint("Fixed Out", ep_base + "_fixed_out",
        endpoint.fixed_out);
    }
    FixCommonParameters(usb.GetOverrulingParameters(), base + "_");
  }
}

void A2lPropertyGrid::FixEpParameters(const xcp::EpParameters& ep_params,
                                      const std::string& base) {
  FixUint("Endpoint Number", base + "_endpoint",
    ep_params.GetEndpointNumber());
  constexpr std::array<std::string_view, 4> kTransferType = {
    "",
    "",
    "Bulk",
    "Interrupt"
  };
  FixEnumList("Transfer Type", base + "_transfer_type",
    kTransferType, ep_params.GetTransferType());

  FixUint("Max Packet Size", base + "_max_packet_size",
    ep_params.GetMaxPacketSize());
  FixUint("Interval", base + "_interval",
    ep_params.GetInterval());
  constexpr std::array<std::string_view, 3> kPackingList = {
    "Single",
    "Multiple",
    "Streaming"
  };
  FixEnumList("Message Packing", base + "_packing",
    kPackingList, ep_params.GetMessagePacking());
  constexpr std::array<std::string_view, 4> kAlignmentList = {
    "8 bits",
    "16 bits",
    "32 bits",
    "64 bits"
  };
  FixEnumList("Message Alignment", base + "_alignment",
    kAlignmentList, ep_params.GetUsbAlignment());
  FixUint("Recommended Host Buffer Size",
    base + "_recommended_host_buffer_size",
    ep_params.GetRecommendedHostBufsize());
}
void A2lPropertyGrid::FixXcpOnFlx(
    const std::vector<xcp::XcpOnFlx>& xcp_on_flx_list) {
  for (size_t index = 0; index < xcp_on_flx_list.size(); ++index) {
    const auto& flx = xcp_on_flx_list[index];
    const std::string base = "xcp_on_flx" + std::to_string(index);

    Append(new wxPropertyCategory("XCP On FlexRay", base));
    FixString("Version",
      base + "_version",flx.GetVersionAsString());
    FixUint("T1 [ms]", base + "_t1",
      flx.GetT1Flx());
    FixString("FIBEX File", base + "_fibex_file",
      flx.GetFibexFile());
    FixString("Cluster ID", base + "_cluster_id",
      flx.GetClusterId());
    FixUint("NAX", base + "_nax", flx.GetNax());
    constexpr std::array<std::string_view, 9> kNaxList = {
      "None",
      "Fill",
      "CTR",
      "Fill 3",
      "CTR Fill 2",
      "LEN",
      "CTR LEN",
      "FILL 2 LEN",
      "CTR FILL LEN"
    };
    FixEnumList("Header NAX", base + "_header_nax",
      kNaxList, flx.GetHeaderNax());
    constexpr std::array<std::string_view, 3> kAlignmentList = {
      "8 Bits",
      "16 Bits",
      "32 Bits"
    };
    FixEnumList("Packet Alignment", base + "_packet_alignment",
      kAlignmentList, flx.GetPacketAlignment());


    const auto& cmd_list = flx.GetSubCmds();
    std::deque<std::string> list;
    for (size_t idx = 0; idx < cmd_list.size(); ++idx) {
      constexpr size_t kOffset = 0xFA;
      const size_t cmd = static_cast<size_t>(cmd_list[idx]) - kOffset;
      constexpr std::array<std::string_view, 6> kCmdList = {
        "GET_DAQ_CLOCK_MULTICAST", // 0xFA
        "SET_DAQ_FLX_BUF",
        "GET_DAQ_FLX_BUF",
        "FLX_DEACTIVATE",
        "FLX_ACTIVATE",
        "SET_DAQ_FLX_BUF",
      };
      if (cmd < kCmdList.size()) {
        list.emplace_back(std::string(kCmdList[cmd]));
      }
    }
    FixStringList("Optional Commands",
      base + "_optional_commands", list);

    FixString("Transport Layer Instance",
      base + "_transport_layer_instance",
      flx.GetTransportLayerInstance());
    if (const auto* cmd = flx.GetCmdBuffer(); cmd != nullptr) {
      const std::string cmd_base = base + "_initial_cmd_buffer";
      Append(new wxPropertyCategory("Initial CMD Buffer",
        cmd_base));
      FixFlxBuffer(*cmd, cmd_base);
    }
    if (const auto* res_err = flx.GetResErrBuffer();
        res_err != nullptr) {
      const std::string res_err_base = base + "_initial_res_err_buffer";
      Append(new wxPropertyCategory("Initial RES_ERR Buffer",
        res_err_base));
      FixFlxBuffer(*res_err, res_err_base);
    }
    const auto& pool_list = flx.GetPoolBuffers();
    for (size_t idx = 0; idx < pool_list.size(); ++idx) {
      const auto& pool = pool_list[idx];
      const std::string pool_base = base + "_pool_buffer"
               += std::to_string(idx);
      Append(new wxPropertyCategory("Pool Buffer",
        pool_base));
      FixFlxBuffer(pool, pool_base);
    }
    FixCommonParameters(flx.GetOverrulingParameters(), base + "_");
  }

}

void A2lPropertyGrid::FixFlxBuffer(const xcp::FlxBuffer& buffer,
                                   const std::string& base) {
  FixUint("Number", base + "_number",
    buffer.GetBufferNo());
  if (const auto* max_len = buffer.GetMaxFlxLenBuffer();
      max_len != nullptr) {
    FixUint("Max Length Fixed", base + "_max_length_fixed",
      max_len->fixed);
    FixUint("Max Length Variable", base + "_max_length_variable",
      max_len->variable);
  }
  if (const auto* slot_id = buffer.GetFlxSlotId();
      slot_id != nullptr) {
    FixUint("Slot ID Fixed", base + "_slot_id_fixed",
      slot_id->fixed);
    FixUint("Slot ID Variable Inital Value",
      base + "_slot_id_variable", slot_id->initial_value);
  }
  if (const auto* offset = buffer.GetFlxSlotId();
      offset != nullptr) {
    FixUint("Offset Fixed", base + "_offset_fixed",
      offset->fixed);
    FixUint("Offset Variable Inital Value",
      base + "_offset_variable", offset->initial_value);
  }
  if (const auto* cycle = buffer.GetCycleRepetition();
      cycle != nullptr) {
    FixUint("Cycle Repetition Fixed", base + "_cycle_fixed",
      cycle->fixed);
    FixUint("Cycle Repetition Variable Inital Value",
      base + "_cycle_variable", cycle->initial_value);
  }

  if (const auto* channel = buffer.GetChannel();
      channel != nullptr) {
    constexpr std::array<std::string_view, 2> kChannelList = {
          "A",
          "B"
    };
    FixEnumList("Channel Fixed",
      base + "_channel_fixed",
      kChannelList, channel->fixed_channel);
    FixEnumList("Channel Variable Inital Value",
      base + "_channel_variable",
      kChannelList, channel->initial_value);
  }
  constexpr std::array<std::string_view, 4> kAssignmentList = {
    "Not Allowed",
    "Fixed",
    "Variable Initialized",
    "Variable"
  };
  FixEnumList("XCP Packet CMD",
    base + "_assignment_cmd", kAssignmentList,
    buffer.GetCmd());
  FixEnumList("XCP Packet RES_ERR",
    base + "_assignment_res_err", kAssignmentList,
    buffer.GetResErr());
  FixEnumList("XCP Packet EV_SERV",
    base + "_assignment_ev_serv", kAssignmentList,
    buffer.GetEvServ());
  FixEnumList("XCP Packet DAQ",
    base + "_assignment_daq", kAssignmentList,
    buffer.GetDaq());
  FixEnumList("XCP Packet STIM",
    base + "_assignment_stim", kAssignmentList,
    buffer.GetStim());
  FixEnumList("XCP Packet Multicast",
    base + "_assignment_multicast", kAssignmentList,
    buffer.GetMulticast());
}

void A2lPropertyGrid::RedrawCcpData(const Module& module) {
  const ccp::CcpDataBlock* data = module.GetCcpDataBlock();
  if (data == nullptr) {
    Redraw(module);
    return;
  }

  const ccp::TpBlob* tp_blob = data->GetTpBlob();
  if (tp_blob != nullptr) {
    FixTpBlob(*tp_blob);
  }
  FixSource(data->GetSourceList());
  FixRaster(data->GetRasterList());
  FixEventGroup(data->GetEventGroupList());

  if (const auto& seed_key = data->GetSeedKey()) {
    Append(new wxPropertyCategory("Seed Key Files", "seed_key"));
    FixString("Calibration Priviledge",
      "seed_key_cal", seed_key->GetCalDll());
    FixString("Data Aquisition Priviledge",
      "seed_key_daq", seed_key->GetDaqDll());
    FixString("Programming Priviledge",
      "seed_key_pgm", seed_key->GetPgmDll());
  }

  if (const std::string& checksum = data->GetChecksum();
      !checksum.empty()) {
    Append(new wxPropertyCategory("Checksum", "checksum"));
    FixString("Checksum File",
      "checksum_file", checksum);
  }

  const auto& mapping_list = data->GetAddressMappingList();
  for (size_t map = 0; map < mapping_list.size(); ++map) {
    const auto& mapping = mapping_list[map];
    const std::string map_index = std::to_string(map);
    Append(new wxPropertyCategory("Address Mapping",
      "address_mapping" + map_index));
    FixHex("From", "mapping_from" + map_index,
      mapping.GetFromAddress());
    FixHex("To", "mapping_to" + map_index,
      mapping.GetToAddress());
    FixUint("Length", "mapping_length" + map_index,
      mapping.GetLength());
  }

  if (const ccp::DpBlob* dp_blob = data->GetDpBlob();
      dp_blob != nullptr) {
    Append(new wxPropertyCategory("DP BLOB", "dp_blob"));
    FixHex("Address Extension",
      "dp_blob_extension", dp_blob->GetAddressExtension());
    FixHex("Base Address",
      "dp_blob_base", dp_blob->GetBaseAddress());
    FixUint("Number of Bytes",
      "dp_blob_length", dp_blob->GetNofBytes());
  }

  if (const ccp::KpBlob* kp_blob = data->GetKpBlob();
      kp_blob != nullptr) {
    Append(new wxPropertyCategory("KP BLOB", "kp_blob"));
    FixHex("Address Extension",
      "kp_blob_extension", kp_blob->GetAddressExtension());
    FixHex("Base Address",
      "kp_blob_base", kp_blob->GetBaseAddress());
    FixUint("Number of Bytes",
      "kp_blob_length", kp_blob->GetNofBytes());
    if (const auto& raster_list = kp_blob->GetRaster();
        !raster_list.empty()) {
      std::deque<uint64_t> temp_list;
      for (const uint8_t raster : raster_list) {
        temp_list.push_back(raster);
      }
      FixUintList("Event Channels",
        "kp_blob_raster", temp_list);
    }
  }
}

void A2lPropertyGrid::FixTpBlob(const a2l::ccp::TpBlob& tp_blob) {
  Append(new wxPropertyCategory("TP Blob"));
  FixString("Version", "tp_version",
    tp_blob.GetVersionAsString());

  FixString("Blob Version", "blob_version",
       tp_blob.GetBlobVersionAsString());

  FixHex("Transmit Message ID", "transmit_id",
    tp_blob.GetTransmitMessageId() );
  FixHex("Receive Message ID", "receive_id",
    tp_blob.GetReceiveMessageId() );

  FixHex("Station Address", "address",
    tp_blob.GetAddress() );

  const uint16_t byte_order = tp_blob.GetByteOrder();
  if (byte_order == 1) {
    FixString("Byte Order", "byte_order",
      "1: Big Endian");
  } else if (byte_order == 2) {
    FixString("Byte Order", "byte_order",
      "2: Little Endian");
  }

  if ( const auto& baudrate = tp_blob.GetBaudrate();
       baudrate.has_value()) {
    FixUint("Baudrate [kHz]", "baudrate",
      baudrate.value() / 1000);
  }

  if ( const auto& sample_point = tp_blob.GetSamplePoint();
       sample_point.has_value()) {
    FixUint("Sample Point [%]", "sample_point",
      sample_point.value());
  }

  if (const auto& sample_rate = tp_blob.GetSampleRate();
      sample_rate.has_value()) {
    FixUint("Sample Rate [Samples/Bit]", "sample_rate",
      sample_rate.value());
  }

  if ( const auto& btl_cycles = tp_blob.GetBtlCycles();
       btl_cycles.has_value()) {
    FixUint("Bit Timing Cycles", "btl_cycles",
      btl_cycles.value());
  }

  if (const auto& sjw = tp_blob.GetSjw();
      sjw.has_value()) {
    FixUint("Synchronization Jump Width", "sjw",
      sjw.value());
  }

  if (const auto& sync_edge = tp_blob.GetSyncEdge();
      sync_edge.has_value()) {
    constexpr std::array<std::string_view,2> kEnumList = {
      "Single",
      "Dual"
    };
    FixEnumList("Synchronisation", "sync_edge",
      kEnumList, sync_edge.value());
  }

  if (const auto& daq_mode = tp_blob.GetDaqMode();
      daq_mode.has_value()) {
    constexpr std::array<std::string_view,2> kEnumList = {
      "Alternating",
      "Burst"
    };
    FixEnumList("Data Acquisition Mode", "daq_mode",
      kEnumList, daq_mode.value());
  }

  FixBool("Bytes Only", "bytes_only",
    tp_blob.GetBytesOnly());
  FixBool("Resume Supported", "resume_supported",
    tp_blob.GetResumeSupported());
  FixBool("Store Supported", "store_supported",
    tp_blob.GetStoreSupported());


  if (const auto& consistency = tp_blob.GetConsistency();
      consistency.has_value()) {
    constexpr std::array<std::string_view,2> kEnumList = {"DAQ", "ODT"};
    FixEnumList("Consistency", "consistency",
      kEnumList, consistency.value());
  }

  if (const auto& address_extension = tp_blob.GetAddressExtension();
      address_extension.has_value()) {
    constexpr std::array<std::string_view,2> kEnumList = {"DAQ", "ODT"};
    FixEnumList("Address Extension", "address_extension",
      kEnumList, address_extension.value());
  }

  if ( const auto& optional_list = tp_blob.GetOptionalCmds();
       !optional_list.empty()) {
    std::deque<std::string> list;
    for (uint16_t cmd : optional_list) {
      const auto itr = kCcpCommandList.find(cmd);
      if (itr != kCcpCommandList.cend()) {
        std::string cmd_name(itr->second);
        list.emplace_back(cmd_name);
      } else {
        list.emplace_back(std::to_string(cmd));
      }
    }
    FixStringList("Optional Commands", "optional_cmds",
      list);
       }
  if (const auto* can_param = tp_blob.GetCanParam();
      can_param != nullptr) {
    Append(new wxPropertyCategory("CAN Parameters"));
    Append(new wxIntProperty("Frequency", wxPG_LABEL,
        can_param->GetFrequency() ));
    FixHex("Bit Timing Register 0", "btr0",
      can_param->GetBtr0());
    FixHex("Bit Timing Register 1", "btr1",
      can_param->GetBtr1());
  }

  if ( const auto* checksum_param = tp_blob.GetChecksumParam();
       checksum_param != nullptr) {
    Append(new wxPropertyCategory("Checksum Parameters"));
    FixUint("Type", "checksum_type",
      checksum_param->GetType());
    FixUint("Max Block Length", "max_block_length",
      checksum_param->GetMaxBlockLength());
    if (const auto& calculation = checksum_param->GetCalculation();
        calculation.has_value()) {
      constexpr std::array<std::string_view,2> kEnumList = {
        "Active Page",
        "Bit or With Optional Page"
      };
      FixEnumList("Calculation", "checksum_calculation",
        kEnumList, calculation.value());
    }
  }

  const auto& defined_pages_list = tp_blob.GetDefinedPages();
  for (size_t index = 0; index < defined_pages_list.size(); ++index) {
    const auto& page = defined_pages_list[index];

    const std::string page_index = std::to_string(index);
    Append(new wxPropertyCategory("Defined Pages", "defined_pages" + page_index));
    FixUint("Logical Number", "page_number" + page_index,
      page.GetNumber());
    FixString("Name", "page_name" + page_index,
      page.GetName());
    FixHex("Address Extension", "page_extension" + page_index,
      page.GetAddressExtension());
    FixHex("Base Address", "page_base" + page_index,
      page.GetBaseAddress());
    FixBool("RAM", "page_ram" + page_index,
      page.GetRam());
    FixBool("ROM", "page_rom" + page_index,
      page.GetRom());
    FixBool("FLASH", "page_flash" + page_index,
      page.GetFlash());
    FixBool("EEPROM", "page_eeprom" + page_index,
      page.GetEeprom());
    FixBool("RAM Init by ECU", "page_ecu" + page_index,
      page.GetRamInitByEcu());
    FixBool("RAM Init by Tool", "page_tool" + page_index,
      page.GetRamInitByEcu());
    FixBool("Automatic Flashed Back", "page_auto" + page_index,
      page.GetAutoFlashBack());
    FixBool("Flashed Back", "page_back" + page_index,
      page.GetFlashBack());
    FixBool("Default", "page_default" + page_index,
      page.GetDefault());
  }
}

void A2lPropertyGrid::FixSource( const std::vector<ccp::Source>& source_list) {
  for (size_t index = 0; index < source_list.size(); ++index) {
    const auto& source = source_list[index];
    const std::string source_index = std::to_string(index);
    Append(new wxPropertyCategory("DAQ List Description",
      "source" + source_index ));
    FixString("Name", "source_name" + source_index,
      source.GetName());
    const uint16_t scale = source.GetScalingUnit();

    if (const auto itr = kCcpScalingList.find(scale);
        itr != kCcpScalingList.cend()) {
      FixString("Scaling Unit",
        "source_scale" + source_index,std::string(itr->second));
    } else {
      FixUint("Scaling Unit",
        "source_scale" + source_index, scale);
    }

    FixInt("Rate",
        "source_rate" + source_index, source.GetRate());

    if ( const std::string& display = source.GetDisplayIdentifier();
         !display.empty()) {
      FixString("Display Identifier",
        "source_display" + source_index, display);
    }

    if (const auto* qp_blob = source.GetQpBlob();
        qp_blob != nullptr) {
      FixUint("DAQ List Number",
        "daq_list" + source_index,
        qp_blob->GetNumber());
      if (const auto& length = qp_blob->GetLength();
        length.has_value()) {
        FixUint("Length",
          "qp_blob_length" + source_index,
          length.value());
      }
      FixBool("CAN ID Variable",
        "qp_blob_variable" + source_index,
        qp_blob->GetCanIdVariable());

      if (const auto& fixed = qp_blob->GetCanIdFixed();
          fixed.has_value()) {
        FixHex("CAN ID Fixed",
          "qp_blob_fixed" + source_index,
          fixed.value());
      }

      FixBool("Reduction Allowed",
  "qp_blob_reduction" + source_index,
  qp_blob->GetReductionAllowed());
      if (const auto& first_pid = qp_blob->GetFirstPid();
          first_pid.has_value()) {
        FixUint("First PID",
          "qp_blob_first_pid" + source_index,
          first_pid.value());
      }
      if (const auto& raster_list = qp_blob->GetRasterList();
          !raster_list.empty()) {
        std::deque<uint64_t> temp_list;
        for (const uint8_t raster : raster_list) {
          temp_list.push_back(raster);
        }
        FixUintList("Supported Event Channels",
          "qp_blob_raster" + source_index, temp_list);
      }
      if (const auto& exclusive_list = qp_blob->GetExclusiveList();
          !exclusive_list.empty()) {
        std::deque<int64_t> temp_list;
        for (const auto excluded : exclusive_list) {
          temp_list.push_back(excluded);
        }
        FixIntList("Excluded DAQ Lists",
          "qp_blob_excluded" + source_index, temp_list);
      }
    }

  }
}

void A2lPropertyGrid::FixRaster( const std::vector<ccp::Raster>& raster_list) {
  for (size_t index = 0; index < raster_list.size(); ++index) {
    const auto& raster = raster_list[index];
    const std::string raster_index = std::to_string(index);
    Append(new wxPropertyCategory("ECU Sampling Rate", "raster" + raster_index ));
    FixString("Event Channel Name", "raster_name" + raster_index,
      raster.GetName());
    FixString("Display Name", "raster_display" + raster_index,
      raster.GetShortName());
    FixUint("Event Channel Number",
      "raster_number" + raster_index, raster.GetNumber());

    const int16_t period = raster.GetPeriod();
    if (const auto itr = kCcpScalingList.find(static_cast<size_t>(period));
        itr != kCcpScalingList.cend()) {
      FixString("Period",
        "raster_period" + raster_index,std::string(itr->second));
    } else {
      FixInt("Period",
        "raster_period" + raster_index, period);
    }

    FixInt("Sampling Rate",
        "raster_rate" + raster_index, raster.GetSampleRate());


    if (const auto& exclusive_list = raster.GetExclusiveList();
        !exclusive_list.empty()) {
      std::deque<int64_t> temp_list;
      for (const auto excluded : exclusive_list) {
        temp_list.push_back(excluded);
      }
      FixIntList("Excluded Event Channels",
        "raster_excluded" + raster_index, temp_list);
    }
  }
}

void A2lPropertyGrid::FixEventGroup( const std::vector<ccp::EventGroup>& group_list) {
  for (size_t index = 0; index < group_list.size(); ++index) {
    const auto& group = group_list[index];
    const std::string group_index = std::to_string(index);
    Append(new wxPropertyCategory("Event Group", "group" + group_index ));
    FixString("Event Group Name",
      "group_name" + group_index, group.GetName());
    FixString("Display Name",
      "group_display" + group_index,group.GetShortName());

    if (const auto& event_list = group.GetRasterList();
        !event_list.empty()) {
      std::deque<int64_t> temp_list;
      for (const auto event : event_list) {
        temp_list.push_back(event);
      }
      FixIntList("Event Channels",
        "group_event" + group_index, temp_list);
    }
  }
}

void A2lPropertyGrid::RedrawIfData(const std::string& protocol,
                                   const std::string& if_data) {
  IfDataBlock block(if_data);
  const std::string& base = "if_data";
  const auto& item_list = block.ItemList();
  if (!block.IsOk() || item_list.empty()) {
    Append(new wxPropertyCategory(protocol, base));
    return;
  }

  for (size_t index = 0; index < item_list.size(); ++index) {
    const auto& item = item_list[index];
    const std::string item_base = base + "_item"
        += std::to_string(index);
    std::ostringstream name;
    name << item.BlockName();
    if (const std::string& value = item.Value(); !value.empty()) {
      name << "/" << item.Value();
    }
    Append(new wxPropertyCategory(name.str(), item_base));
    const auto& value_list = item.ItemList();
    for (size_t value_index = 0; value_index < value_list.size(); ++value_index) {
      const auto& value = value_list[value_index];
      const std::string value_base = item_base + "_value"
        += std::to_string(value_index);
      std::ostringstream value_name;
      value_name << "Value[" << value_index << "}";

      std::ostringstream value_txt;
      if (const std::string& blk = value.BlockName(); !blk.empty()) {
        value_txt << blk;
        value_txt << "/";
      }
      value_txt << value.Value();
      FixString(value_name.str(), value_base,
        value_txt.str());
      
    }
  }

}

}  // namespace a2lgui