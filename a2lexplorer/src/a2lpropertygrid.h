/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#pragma once

#include <wx/propgrid/propgrid.h>
#include "a2ldocument.h"
namespace a2lgui {

class A2lPropertyGrid : public wxPropertyGrid {
 public:
  explicit A2lPropertyGrid( wxWindow *parent, wxWindowID id = wxID_ANY,
                 const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxDefaultSize,
                 long style = wxPG_DEFAULT_STYLE,
                 const wxString& name = wxASCII_STR(wxPropertyGridNameStr) );
  void SetDoc(A2lDocument* doc) { document_ = doc;  }
  void Redraw();
 private:
  A2lDocument* document_ = nullptr;

  void FixNameDesc(const a2l::A2lObject& object);

  template <typename T>
  void FixPropertyMap(const std::string_view& property_label,
                      const std::string_view& property_name,
                      const std::map<std::string,std::unique_ptr<T>>&
                          object_list);

  void FixStringMap(const std::string_view& property_label,
                    const std::string_view& property_name,
                    const std::map<std::string, std::string>& string_list);

  void FixFloatList(const std::string_view& property_label,
                    const std::string_view& property_name,
                    const std::vector<double>& float_list);

  void FixUintList(const std::string_view& property_label,
                   const std::string_view& property_name,
                   const std::vector<uint64_t>& uint_list);

  void FixIntList(const std::string_view& property_label,
                  const std::string_view& property_name,
                  const std::vector<int64_t>& int_list);

  void FixStringList(const std::string_view& property_label,
                     const std::string_view& property_name,
                     const std::vector<std::string>& text_list);

  template <typename T>
  void FixEnumList(const std::string_view& property_label,
                                    const std::string_view& property_name,
                                    const a2l::EnumStringList& enum_list,
                                    T selected_enum);

  template <typename T>
  void FixInEnumList(wxPGProperty* root,
                     const std::string_view& property_label,
                     const std::string_view& property_name,
                     const a2l::EnumStringList& enum_list,
                     T selected_enum);

  void FixString(const std::string_view& property_label,
                 const std::string_view& property_name,
                 const std::string& text);

  void FixFloat(const std::string_view& property_label,
                const std::string_view& property_name, double value);

  void FixUint(const std::string_view& property_label,
               const std::string_view& property_name, uint64_t value);

  void FixHex(const std::string_view& property_label,
              const std::string_view& property_name, uint64_t value);

  void FixInt(const std::string_view& property_label,
              const std::string_view& property_name, int64_t value);

  void FixBool(const std::string_view& property_label,
               const std::string_view& property_name, bool value);

  void FixAxisPts(const std::string_view& label, const a2l::A2lAxisPts& axis);
  void FixAxisRescale(const std::string_view& label,
                      const a2l::A2lAxisRescale& axis);
  void FixDistOp(const std::string_view& label, const a2l::A2lDistOp& dist);
  void FixFncValue(const std::string_view& label, const a2l::A2lFncValue& fnc);
  void FixExtendedLimits(const a2l::A2lExtendedLimits& limits);
  void FixMaxRefresh(const a2l::A2lMaxRefresh& refresh);
  void FixSymbolLink(const a2l::A2lSymbolLink& symbol);

  void Redraw(const a2l::A2lFile& file);
  void Redraw(const a2l::Module& module);
  void Redraw(const a2l::A2lModPar& par);
  void DrawCategory( const a2l::A2lModPar& par);
  void Redraw(const a2l::A2lAnnotation& note);
  void Redraw(const a2l::AnnotationList& list);
  void Redraw(const a2l::A2lCalibrationMethod& method);
  void Redraw(const a2l::A2lMemoryLayout& layout);
  void Redraw(const a2l::A2lMemorySegment& segment);
  void Redraw(const a2l::AxisDescr& axis);
  void Redraw(const a2l::AxisPts& axis);
  void Redraw(const a2l::Blob& blob);
  void Redraw(const a2l::Characteristic& object);
  void Redraw(const a2l::CompuMethod& method);
  void Redraw(const a2l::CompuTab& table);
  void Redraw(const a2l::CompuVtab& table);
  void Redraw(const a2l::CompuVtabRange& table);
  void Redraw(const a2l::Frame& frame);
  void Redraw(const a2l::Function& function);
  void Redraw(const a2l::Group& group);
  void Redraw(const a2l::Instance& instance);
  void Redraw(const a2l::Overwrite& object);
  void Redraw(const a2l::Measurement& meas);
  void Redraw(const a2l::RecordLayout& layout);
  void Redraw(const a2l::Transformer& transformer);
  void Redraw(const a2l::Structure& structure);
  void Redraw(const a2l::Unit& unit);
  void Redraw(const a2l::A2lVariantCoding& object);
  void Redraw(const a2l::A2lVarCharacteristic& object);
  void Redraw(const a2l::A2lVarCriterion& object);
};

template <typename T>
void A2lPropertyGrid::FixPropertyMap(const std::string_view& property_label,
                    const std::string_view& property_name,
                    const std::map<std::string,std::unique_ptr<T>>&
                        object_list) {
  if (!object_list.empty()) {
    wxArrayString list;
    for (const auto& [name, object] : object_list) {
      list.Add(wxString::FromUTF8(name));
    }
    Append( new wxArrayStringProperty(property_label.data(),
           property_name.empty() ? wxPG_LABEL : wxString(property_name.data()),
                                     list));
  }
}

template <typename T>
void A2lPropertyGrid::FixEnumList(const std::string_view& property_label,
                                  const std::string_view& property_name,
                                  const a2l::EnumStringList& enum_list,
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
  Append(new wxEnumProperty(property_label.data(),
          property_name.empty() ? wxPG_LABEL : wxString(property_name.data()),
                                 list, selected));
}

template <typename T>
void A2lPropertyGrid::FixInEnumList(wxPGProperty* root,
                                    const std::string_view& property_label,
                                    const std::string_view& property_name,
                                    const a2l::EnumStringList& enum_list,
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
  AppendIn(root, new wxEnumProperty(property_label.data(),
           property_name.empty() ? wxPG_LABEL : wxString(property_name.data()),
                            list, selected));
}

}  // namespace a2lgui
