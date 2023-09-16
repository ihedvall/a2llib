/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2lpropertygrid.h"
#include <wx/propgrid/props.h>
#include <a2l/module.h>
using namespace a2l;


namespace {
void FixNameDesc(a2lgui::A2lPropertyGrid& grid,const A2lObject& object) {
  grid.Append(
      new wxStringProperty("Name", "name", wxString::FromUTF8(object.Name())));
  grid.Append(new wxLongStringProperty(
      "Description", "desc", wxString::FromUTF8(object.Description())));
}

template <typename T>
void FixPropertyMap(a2lgui::A2lPropertyGrid& grid,
                    const std::string_view& property_label,
                    const std::string_view& property_name,
                    const std::map<std::string,std::unique_ptr<T>>&
                        object_list) {
  if (!object_list.empty()) {
    wxArrayString list;
    for (const auto& [name, object] : object_list) {
      list.Add(wxString::FromUTF8(name));
    }
    grid.Append( new wxArrayStringProperty(property_label.data(),
           property_name.empty() ? wxPG_LABEL : wxString(property_name.data()),
                                          list));
  }
}

void FixStringMap(a2lgui::A2lPropertyGrid& grid,
                    const std::string_view& property_label,
                    const std::string_view& property_name,
                    const std::map<std::string,std::string>& string_list) {
  if (!string_list.empty()) {

    wxArrayString list;
    for (const auto& [name, text] : string_list) {
      list.Add(wxString::FromUTF8(name));
    }
    auto* root = grid.Append( new wxArrayStringProperty(property_label.data(),
           property_name.empty() ? wxPG_LABEL : wxString(property_name.data()),
           list));
    size_t count = 0;
    for (const auto& [name, value] : string_list) {
      std::ostringstream prop_name;
      prop_name << property_name << "_" << count;
      grid.AppendIn(root, new wxLongStringProperty(wxString::FromUTF8(name),
         prop_name.str(), wxString::FromUTF8(value)));
      ++count;
    }
  }
}

void FixUintList(a2lgui::A2lPropertyGrid& grid,
                  const std::string_view& property_label,
                  const std::string_view& property_name,
                  const std::vector<uint64_t>& uint_list) {
  if (!uint_list.empty()) {
    wxArrayString list;
    for (const auto value : uint_list) {
      list.Add(std::to_string(value));
    }
    grid.Append( new wxArrayStringProperty(property_label.data(),
           property_name.empty() ? wxPG_LABEL : wxString(property_name.data()),
                                          list));
  }
}

void FixIntList(a2lgui::A2lPropertyGrid& grid,
                 const std::string_view& property_label,
                 const std::string_view& property_name,
                 const std::vector<int64_t>& int_list) {
  if (!int_list.empty()) {
    wxArrayString list;
    for (const auto value : int_list) {
      list.Add(std::to_string(value));
    }
    grid.Append( new wxArrayStringProperty(property_label.data(),
           property_name.empty() ? wxPG_LABEL : wxString(property_name.data()),
                                          list));
  }
}

void FixStringList(a2lgui::A2lPropertyGrid& grid,
                const std::string_view& property_label,
                const std::string_view& property_name,
                const std::vector<std::string>& text_list) {
  if (!text_list.empty()) {
    wxArrayString list;
    for (const auto value : text_list) {
      list.Add(wxString::FromUTF8(value));
    }
    grid.Append( new wxArrayStringProperty(property_label.data(),
          property_name.empty() ? wxPG_LABEL : wxString(property_name.data()),
                                          list));
  }
}

template <typename T>
void FixEnumList(a2lgui::A2lPropertyGrid& grid,
                 const std::string_view& property_label,
                 const std::string_view& property_name,
                 const EnumStringList& enum_list,
                 T selected_enum) {
  if (selected_enum == T::UNKNOWN) {
    return;
  }
  wxPGChoices list;
  int count = 0;
  for (const auto& enum_name : enum_list) {
    list.Add(wxString::FromUTF8(enum_name.data()), count);
    ++count;
  }

  const int selected = static_cast<int>(selected_enum);
  grid.Append(new wxEnumProperty(property_label.data(),
           property_name.empty() ? wxPG_LABEL : wxString(property_name.data()),
                                 list, selected));
}

void FixString(a2lgui::A2lPropertyGrid& grid,
              const std::string_view& property_label,
              const std::string_view& property_name,
              const std::string& text) {
  if (!text.empty()) {
    grid.Append( new wxStringProperty(property_label.data(),
      property_name.empty() ? wxPG_LABEL : wxString(property_name.data()),
      wxString::FromUTF8(text)));
  }
}

void FixFloat(a2lgui::A2lPropertyGrid& grid,
             const std::string_view& property_label,
             const std::string_view& property_name,
             double value) {
  if (value != 0.0) {
    grid.Append( new wxFloatProperty(property_label.data(),
          property_name.empty() ? wxPG_LABEL : wxString(property_name.data()),
                                   value));
  }
}
void FixUint(a2lgui::A2lPropertyGrid& grid,
               const std::string_view& property_label,
               const std::string_view& property_name,
               uint64_t value) {
  if (value > 0) {
    grid.Append( new wxUIntProperty(property_label.data(),
       property_name.empty() ? wxPG_LABEL : wxString(property_name.data()),
       value));
  }
}

void FixInt(a2lgui::A2lPropertyGrid& grid,
             const std::string_view& property_label,
             const std::string_view& property_name,
             int64_t value) {
  if (value != 0) {
    grid.Append( new wxIntProperty(property_label.data(),
       property_name.empty() ? wxPG_LABEL : wxString(property_name.data()),
                                   value));
  }
}

void FixBool(a2lgui::A2lPropertyGrid& grid,
            const std::string_view& property_label,
            const std::string_view& property_name,
            bool value) {
  if (value) {
    grid.Append( new wxBoolProperty(property_label.data(),
          property_name.empty() ? wxPG_LABEL : wxString(property_name.data()),
                                  value));
  }
}

} // end namespace

namespace a2lgui {

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
    case TreeItemType::AXIS_PTS:
      if (object != nullptr ) {
        auto* axis  = static_cast<a2l::AxisPts*>(object);
        Redraw(*axis);
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

    case TreeItemType::CAL_METHOD:
      if (object != nullptr ) {
        auto* method = static_cast<a2l::A2lCalibrationMethod*>(object);
        Redraw(*method);
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

  FixPropertyMap(*this, "ECU", "modules", project.Modules());

}

void A2lPropertyGrid::Redraw(const a2l::Module& module) {
  Append(new wxPropertyCategory("ECU"));
  FixNameDesc(*this, module);

  const auto& a2ml = module.A2ml();
  if (!a2ml.empty()) {
    Append(new wxLongStringProperty("Meta-Language", "a2ml",
                                    wxString::FromUTF8(a2ml)));
  }

  Append(new wxPropertyCategory("ECU Specific Definitions"));
  const auto& common = module.ModCommon();
  Append(new wxLongStringProperty("Comment", "common_comment",
                                  wxString::FromUTF8(common.Comment)));

  FixUint(*this, "Alignment Int8", "int8", common.AlignmentByte);
  FixUint(*this,"Alignment Int16", "int16", common.AlignmentWord);
  FixUint(*this,"Alignment Int32", "int32", common.AlignmentLong);
  FixUint(*this,"Alignment Int64", "int64", common.AlignmentInt64);
  FixUint(*this,"Alignment Float16", "float16", common.AlignmentFloat16);
  FixUint(*this,"Alignment Float32", "float32", common.AlignmentFloat32);
  FixUint(*this,"Alignment Float64", "float64", common.AlignmentFloat64);
  FixEnumList(*this, "Byte Order", "byte_order", ByteOrderToStringList(),
              common.ByteOrder);
  FixUint(*this,"Data Size [bytes]", "data_size", common.DataSize);
  FixEnumList(*this, "Deposit Mode for Axis", "deposit", DepositToStringList(),
              common.Deposit);

  DrawCategory(module.ModPar());


  Append(new wxPropertyCategory("ECU Objets"));
  FixPropertyMap(*this, "Axis Points Distributions", "axis", module.AxisPtss());
  FixPropertyMap(*this, "Binary Large Objects", "blob", module.Blobs());
  FixPropertyMap(*this, "Adjustable Objects", "char", module.Characteristics());
  FixPropertyMap(*this, "Conversion Methods", "method", module.CompuMethods());
  FixPropertyMap(*this, "Conversion Tables", "table", module.CompuTabs());
  FixPropertyMap(*this, "Verbal Conversion Tables", "vtable",
                 module.CompuVtabs());
  FixPropertyMap(*this, "VTAB Ranges", "vtable_r", module.CompuVtabRanges());
  FixPropertyMap(*this, "Frames", "frame", module.Frames());
  FixPropertyMap(*this, "Function Descriptions", "function",
                 module.Functions());
  FixPropertyMap(*this, "Group Declarations", "group", module.Groups());
  FixStringMap(*this, "Interface Data", "if_data", module.IfDatas());
  FixPropertyMap(*this, "Instances", "instance", module.Instances());
  FixPropertyMap(*this, "Measurement Objects", "meas", module.Measurements());
}

void A2lPropertyGrid::Redraw(const a2l::A2lModPar& par) {
  DrawCategory(par);
}

void A2lPropertyGrid::DrawCategory( const A2lModPar& par) {
  Append(new wxPropertyCategory("ECU Management Data"));
  Append(new wxLongStringProperty("Comment", "par_comment",
                                  wxString::FromUTF8(par.Comment)));
  FixUintList(*this, "Address of EEPROM Identifiers", "eepk",
              par.AddressEpkList);

  wxArrayString cal_method_list;
  for (const auto& cal_method : par.CalibrationMethodList) {
    cal_method_list.Add(cal_method.Method);
  }
  if (!cal_method_list.IsEmpty()) {
    Append(new wxArrayStringProperty("Access Methods", "access_method",
                                     cal_method_list));
  }
  FixString(*this, "CPU Type", "cpu_type", par.CpuType);
  FixString(*this, "Customer", "customer", par.Customer);
  FixString(*this, "Customer Number", "customer_no", par.CustomerNo);
  FixString(*this, "Control Unit", "control_unit", par.Ecu);
  Append(new wxIntProperty("Calibration Offset", "cal_offset",
                           static_cast<long>(par.EcuCalibrationOffset)));
  FixString(*this, "EPROM Identifier", "epk", par.Epk);
  FixUint(*this, "Number of Interfaces", "interface", par.NoOfInterfaces);
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
  FixString(*this, "PhoneNo", "phone_no", par.PhoneNo);
  FixString(*this, "Supplier", "supplier", par.Supplier);
  FixString(*this, "User", "user", par.User);
  FixString(*this, "Version", "par_version", par.Version);
  FixStringMap(*this, "System Constants", "sys_const", par.SystemConstantList);
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
  FixEnumList(*this, "Type","", PrgTypeToStringList(),layout.Type);
  Append( new wxUIntProperty("Address", wxPG_LABEL, layout.Address));
  FixIntList(*this, "Offset","", layout.OffsetList);
  FixStringMap(*this, "Interface Data","", layout.IfDataList);

}

void A2lPropertyGrid::Redraw(const A2lMemorySegment& segment) {
  Append(new wxPropertyCategory("Memory Segment"));
  Append( new wxStringProperty("Name", wxPG_LABEL,
                              wxString::FromUTF8(segment.Name)));
  Append( new wxStringProperty("Description", wxPG_LABEL,
                              wxString::FromUTF8(segment.Description)));
  FixEnumList(*this, "Segment Type","", SegmentTypeToStringList(),
              segment.SegmentType);
  FixEnumList(*this, "Memory Type","", MemoryTypeToStringList(),
              segment.MemoryType);
  FixEnumList(*this, "Memory Attribute","", MemoryAttributeToStringList(),
              segment.Attribute);
  Append( new wxUIntProperty("Address", wxPG_LABEL, segment.Address));
  FixIntList(*this, "Offset","", segment.OffsetList);
  FixStringMap(*this, "Interface Data","", segment.IfDataList);

}

void A2lPropertyGrid::Redraw(const AxisPts& axis) {
  Append(new wxPropertyCategory("Axis Point Distribution"));
  FixNameDesc(*this, axis);
  Append( new wxUIntProperty("Address", wxPG_LABEL, axis.Address()));
  Append( new wxStringProperty("Input Quantity", wxPG_LABEL,
                              wxString::FromUTF8(axis.InputQuantity())));
  Append( new wxStringProperty("Reference Record", wxPG_LABEL,
                              wxString::FromUTF8(axis.RefRecord())));
  Append( new wxFloatProperty("Max Difference", wxPG_LABEL, axis.MaxDiff()));
  Append( new wxStringProperty("Conversion", wxPG_LABEL,
                              wxString::FromUTF8(axis.Conversion())));
  Append( new wxUIntProperty("Max axis Points", wxPG_LABEL,
                            axis.MaxAxisPoints()));
  Append( new wxFloatProperty("Lower Limit", wxPG_LABEL, axis.LowerLimit()));
  Append( new wxFloatProperty("Upper Limit", wxPG_LABEL, axis.UpperLimit()));

  FixEnumList(*this, "Byte Order", "", ByteOrderToStringList(),
              axis.ByteOrder());
  FixEnumList(*this, "Calibration Access", "", CalibrationAccessToStringList(),
              axis.CalibrationAccess());
  FixEnumList(*this, "Deposit", "", DepositToStringList(), axis.Deposit());
  FixString(*this, "Display Identifier", "", axis.DisplayIdentifier());
  FixInt(*this, "ECU Address Extension", "", axis.EcuAddressExtension());
  const auto& ex_limits = axis.ExtendedLimits();
  if (ex_limits.LowerLimits < ex_limits.UpperLimits) {
    Append( new wxFloatProperty("Extended Lower Limit", wxPG_LABEL,
                               ex_limits.LowerLimits));
    Append( new wxFloatProperty("Extended Upper Limit", wxPG_LABEL,
                               ex_limits.UpperLimits));
  }
  FixString(*this, "Format", "", axis.Format());
  FixStringList(*this, "Functions", "", axis.FunctionList());
  FixBool(*this, "Guard Rails", "", axis.GuardRails());
  FixStringMap(*this, "Network Communication", "", axis.IfDatas());
  const auto& refresh = axis.MaxRefresh();
  if (refresh.ScalingUnit != 0 || refresh.Rate != 0) {
    Append( new wxUIntProperty("Scaling Unit", wxPG_LABEL,
                               refresh.ScalingUnit));
    Append( new wxUIntProperty("Rate", wxPG_LABEL,
                               refresh.Rate));
  }
  FixString(*this, "Model Link", "", axis.ModelLink());
  FixEnumList(*this, "Monotony", "", MonotonyToStringList(), axis.Monotony());
  FixString(*this, "Physical Unit", "", axis.PhysUnit());
  FixBool(*this, "Read-Only", "", axis.ReadOnly());
  FixString(*this, "Reference Memory Segment", "", axis.RefMemorySegment());
  FixFloat(*this, "Step Size", "", axis.StepSize());
  const auto& symbol = axis.SymbolLink();
  if (!symbol.SymbolName.empty()) {
    Append( new wxStringProperty("Symbol Name", wxPG_LABEL,
                              wxString::FromUTF8(symbol.SymbolName)));
    Append( new wxIntProperty("Symbol Offset", wxPG_LABEL,
                              static_cast<long>(symbol.Offset)));
  }

}

}  // namespace a2lgui