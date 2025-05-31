/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */
#include <string_view>
#include <string>
#include <sstream>
#include <map>
#include <vector>


#include <wx/propgrid/props.h>
#include <util/stringutil.h>

#include "a2l/module.h"

#include "a2lpropertygrid.h"

using namespace a2l;
using namespace util::string;

namespace  a2lgui {
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
    for (const auto& [name, text] : string_list) {
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
                 const std::vector<double>& float_list) {
  if (!float_list.empty()) {
    wxArrayString list;
    for (const auto value : float_list) {
      list.Add(FormatDouble(value, 6));
    }
    Append( new wxArrayStringProperty(property_label.data(),
         property_name.empty() ? wxPG_LABEL : wxString(property_name.data()),
                                          list));
  }
}

void A2lPropertyGrid::FixUintList(const std::string_view& property_label,
                  const std::string_view& property_name,
                  const std::vector<uint64_t>& uint_list) {
  if (!uint_list.empty()) {
    wxArrayString list;
    for (const auto value : uint_list) {
      list.Add(std::to_string(value));
    }
    Append( new wxArrayStringProperty(property_label.data(),
           property_name.empty() ? wxPG_LABEL : wxString(property_name.data()),
                                          list));
  }
}

void A2lPropertyGrid::FixIntList( const std::string_view& property_label,
                 const std::string_view& property_name,
                 const std::vector<int64_t>& int_list) {
  if (!int_list.empty()) {
    wxArrayString list;
    for (const auto value : int_list) {
      list.Add(std::to_string(value));
    }
    Append( new wxArrayStringProperty(property_label.data(),
           property_name.empty() ? wxPG_LABEL : wxString(property_name.data()),
                                          list));
  }
}

void A2lPropertyGrid::FixStringList( const std::string_view& property_label,
                const std::string_view& property_name,
                const std::vector<std::string>& text_list) {
  if (!text_list.empty()) {
    wxArrayString list;
    for (const auto& value : text_list) {
      list.Add(wxString::FromUTF8(value));
    }
    const std::string_view prop_name = property_name.empty() ? property_label :
                                                             property_name;
    auto* item = Append( new wxArrayStringProperty(property_label.data(),
          prop_name.data(), list));
    if (text_list.size() > 1 && text_list.size() < 15) {
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
  if (value != 0.0) {
    Append( new wxFloatProperty(property_label.data(),
          property_name.empty() ? wxPG_LABEL : wxString(property_name.data()),
                                   value));
  }
}

void A2lPropertyGrid::FixUint(const std::string_view& property_label,
               const std::string_view& property_name,
               uint64_t value) {
  if (value > 0) {
    Append( new wxUIntProperty(property_label.data(),
       property_name.empty() ? wxPG_LABEL : wxString(property_name.data()),
       value));

  }
}

void A2lPropertyGrid::FixHex(const std::string_view& property_label,
             const std::string_view& property_name,
             uint64_t value) {
  if (value > 0) {
    const std::string_view prop_name = property_name.empty() ? property_label :
                            property_name;

    Append( new wxUIntProperty(property_label.data(),
           prop_name.data(),value));
    SetPropertyAttribute( prop_name.data(), wxPG_UINT_PREFIX, wxPG_PREFIX_0x );
    SetPropertyAttribute( prop_name.data(), wxPG_UINT_BASE, wxPG_BASE_HEX );
  }
}

void A2lPropertyGrid::FixInt(const std::string_view& property_label,
             const std::string_view& property_name,
             int64_t value) {
  if (value != 0) {
    Append( new wxIntProperty(property_label.data(),
       property_name.empty() ? wxPG_LABEL : wxString(property_name.data()),
                                   static_cast<long>(value)));
  }
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

A2lPropertyGrid::A2lPropertyGrid(wxWindow *parent, wxWindowID id,
                                 const wxPoint &pos, const wxSize &size,
                                 long style, const wxString &name)
    : wxPropertyGrid(parent, id, pos, size, style, name) {

}

void A2lPropertyGrid::Redraw() {
  Clear();
  if (document_ == nullptr) {
    return;
  }

  auto& file = document_->GetFile();
  auto type = document_->SelectedType();
  auto* object = document_->SelectedObject();

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
        auto* axis  = static_cast<a2l::AxisDescr*>(object);
        Redraw(*axis);
      }
      break;

    case TreeItemType::AXIS_PTS:
      if (object != nullptr ) {
        auto* axis  = static_cast<a2l::AxisPts*>(object);
        Redraw(*axis);
      }
      break;

    case TreeItemType::BLOB:
      if (object != nullptr ) {
        auto* blob  = static_cast<a2l::Blob*>(object);
        Redraw(*blob);
      }
      break;

    case TreeItemType::CAL_METHOD:
      if (object != nullptr ) {
        auto* method = static_cast<a2l::A2lCalibrationMethod*>(object);
        Redraw(*method);
      }
      break;

    case TreeItemType::CHARACTERISTIC:
      if (object != nullptr ) {
        auto* characteristic  = static_cast<a2l::Characteristic*>(object);
        Redraw(*characteristic);
      }
      break;

    case TreeItemType::COMPU_METHOD:
      if (object != nullptr ) {
        auto* method  = static_cast<a2l::CompuMethod*>(object);
        Redraw(*method);
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

    case TreeItemType::FRAME:
      if (object != nullptr ) {
        auto* frame  = static_cast<a2l::Frame*>(object);
        Redraw(*frame);
      }
      break;

    case TreeItemType::FUNCTION:
      if (object != nullptr ) {
        auto* function  = static_cast<a2l::Function*>(object);
        Redraw(*function);
      }
      break;

    case TreeItemType::GROUP:
      if (object != nullptr ) {
        auto* group  = static_cast<a2l::Group*>(object);
        Redraw(*group);
      }
      break;

    case TreeItemType::INSTANCE:
      if (object != nullptr ) {
        auto* instance = static_cast<a2l::Instance*>(object);
        Redraw(*instance);
      }
      break;

    case TreeItemType::MEM_SEGMENT:
      if (object != nullptr ) {
        auto* segment  = static_cast<a2l::A2lMemorySegment*>(object);
        Redraw(*segment);
      }
      break;

    case TreeItemType::MEM_LAYOUT:
      if (object != nullptr ) {
        auto* layout  = static_cast<a2l::A2lMemoryLayout*>(object);
        Redraw(*layout);
      }
      break;

    case TreeItemType::MEASUREMENT:
      if (object != nullptr ) {
        auto* measurement = static_cast<a2l::Measurement*>(object);
        Redraw(*measurement);
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

    case TreeItemType::RECORD_LAYOUT:
      if (object != nullptr ) {
        auto* layout = static_cast<a2l::RecordLayout*>(object);
        Redraw(*layout);
      }
      break;

    case TreeItemType::STRUCTURE:
      if (object != nullptr ) {
        auto* structure = static_cast<a2l::Structure*>(object);
        Redraw(*structure);
      }
      break;

    case TreeItemType::TRANSFORMER:
      if (object != nullptr ) {
        auto* transformer = static_cast<a2l::Transformer*>(object);
        Redraw(*transformer);
      }
      break;

    case TreeItemType::UNIT:
      if (object != nullptr ) {
        auto* unit = static_cast<a2l::Unit*>(object);
        Redraw(*unit);
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
      Redraw(file);
      break;

  }
  // SetPropertyReadOnly(GetRoot());
}

void A2lPropertyGrid::Redraw(const a2l::A2lFile& file) {
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

  const auto& a2ml = file.A2mlVersion();
  if (a2ml.VersionNo > 0) {
    Append( new wxPropertyCategory("A2ML Version") );
    Append( new wxUIntProperty("Version No", "a2mlversion", a2ml.VersionNo));
    Append( new wxUIntProperty("Upgrade No", "a2mlupgrade", a2ml.UpgradeNo));
  }

  const auto& project = file.Project();
  Append( new wxPropertyCategory("Project") );
  Append( new wxStringProperty("Name", "projname",
                              wxString::FromUTF8(project.Name())));
  Append( new wxLongStringProperty("Description", "projdesc",
                              wxString::FromUTF8(project.Description())));

  const auto& header = project.Header();
  Append( new wxLongStringProperty("Comments", "projcomment",
                                  wxString::FromUTF8(header.Comment)));
  Append( new wxStringProperty("Version", "projversion",
                                  wxString::FromUTF8(header.VersionNo)));
  Append( new wxStringProperty("Project", "projno",
                              wxString::FromUTF8(header.ProjectNo)));

  FixPropertyMap( "ECU", "modules", project.Modules());

}

void A2lPropertyGrid::Redraw(const a2l::Module& module) {
  Append(new wxPropertyCategory("ECU"));
  FixNameDesc(module);

  const auto& a2ml = module.A2ml();
  if (!a2ml.empty()) {
    Append(new wxLongStringProperty("Meta-Language", "a2ml",
                                    wxString::FromUTF8(a2ml)));
  }
  FixStringMap("Interface Data", "if_data", module.IfDatas());

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

  Append(new wxPropertyCategory("ECU Objects"));
  FixPropertyMap("Axis Points Distributions", "axis", module.AxisPtss());
  FixPropertyMap("Binary Large Objects", "blob", module.Blobs());
  FixPropertyMap("Adjustable Objects", "char", module.Characteristics());
  FixPropertyMap("Conversion Methods", "method", module.CompuMethods());
  FixPropertyMap("Conversion Tables", "table", module.CompuTabs());
  FixPropertyMap("Verbal Conversion Tables", "vtable",
                 module.CompuVtabs());
  FixPropertyMap("VTAB Ranges", "vtable_r", module.CompuVtabRanges());
  FixPropertyMap("Frames", "frame", module.Frames());
  FixPropertyMap("Function Descriptions", "function",
                 module.Functions());
  FixPropertyMap("Group Declarations", "group", module.Groups());
  FixPropertyMap("Instances", "instance", module.Instances());
  FixPropertyMap("Measurement Objects", "meas", module.Measurements());

  const auto& user_list = module.UserRights();
  if (!user_list.empty()) {
    for (const auto& [level, user_right] : user_list) {
      std::ostringstream cat_name;
      cat_name << level << "_cat";
      Append(new wxPropertyCategory("User Rights", cat_name.str()));

      std::ostringstream user_level;
      user_level << level << "_level";
      Append(new wxStringProperty("User Level", user_level.str(),
                                      wxString::FromUTF8(level)));

      std::ostringstream user_read;
      user_read << level << "_read";
      FixBool("Read-Only", user_read.str(), user_right->ReadOnly);

      if (!user_right->RefGroupList.empty()) {
        size_t group = 0;
        for (const auto& group_list : user_right->RefGroupList) {
          std::ostringstream user_group;
          user_group << level << "_group_" << group;
          FixStringList("Group References", user_group.str(), group_list);
          ++group;
        }
      }
    }
  }
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
  Append(new wxPropertyCategory("Frame"));
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

void A2lPropertyGrid::Redraw(const A2lVariantCoding& object) {
  Append(new wxPropertyCategory("Variant Coding"));
  {
    std::vector<std::string> list;
    for (const auto& [name, obj] : object.CharacteristicList) {
      list.emplace_back(name);
    }
    FixStringList("Variant Characteristics", "", list);
  }
  {
    std::vector<std::string> list;
    for (const auto& [name, obj] : object.CriterionList) {
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

}  // namespace a2lgui