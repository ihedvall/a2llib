/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#pragma once

#include <wx/propgrid/propgrid.h>

#include <string>
#include <vector>
#include <deque>
#include <map>
#include <memory>
#include <unordered_map>
#include <array>
#include <string_view>
#include <optional>
#include <sstream>
#include <iomanip>

#include "a2ldocument.h"
namespace a2lgui {

class A2lPropertyGrid : public wxPropertyGrid {
 public:
  explicit A2lPropertyGrid( wxWindow *parent );

  void SetDoc(A2lDocument* doc) { document_ = doc;  }
  [[nodiscard]] A2lDocument* GetDoc() const { return document_; }

  void Redraw();
 private:
  A2lDocument* document_ = nullptr;

  void FixNameDesc(const a2l::A2lObject& object);

  template <typename T>
  void FixPropertyMap(const std::string_view& property_label,
                      const std::string_view& property_name,
                      const std::map<std::string,std::unique_ptr<T>>&
                          object_list);

  template <typename T>
  void FixPropertyMap(const std::string_view& property_label,
                      const std::string_view& property_name,
                      const std::unordered_map<std::string,std::unique_ptr<T>>&
                          object_list);
  void FixStringMap(const std::string_view& property_label,
                    const std::string_view& property_name,
                    const std::map<std::string, std::string>& string_list);

  void FixStringMap(const std::string_view& property_label,
                    const std::string_view& property_name,
                    const std::unordered_map<std::string, std::string>& string_list);

  void FixFloatList(const std::string_view& property_label,
                    const std::string_view& property_name,
                    const std::deque<double>& float_list);

  void FixUintList(const std::string_view& property_label,
                   const std::string_view& property_name,
                   const std::deque<uint64_t>& uint_list);

  template <typename T>
  void FixHexList(const std::string_view& property_label,
                   const std::string_view& property_name,
                   const std::vector<T>& hex_list) {
    wxArrayString list;
    for (const auto value : hex_list) {
      std::ostringstream hex;
      hex << "0x" << std::uppercase << std::setfill('0')
        << std::setw(sizeof(T) * 2) << std::hex << value;
      list.Add(hex.str());
    }
    Append( new wxArrayStringProperty(property_label.data(),
           property_name.empty() ?
           wxPG_LABEL : wxString::FromUTF8(property_name.data()), list));
  }

  void FixIntList(const std::string_view& property_label,
                  const std::string_view& property_name,
                  const std::deque<int64_t>& int_list);

  void FixStringList(const std::string_view& property_label,
                     const std::string_view& property_name,
                     const std::vector<std::string>& text_list);

  void FixStringList(const std::string_view& property_label,
                     const std::string_view& property_name,
                     const std::deque<std::string>& text_list);

  template <typename T>
  void FixEnumList(const std::string_view& property_label,
                                    const std::string_view& property_name,
                                    const a2l::EnumStringList& enum_list,
                                    T selected_enum);
  template <typename T, size_t S>
  void FixEnumList(  const std::string_view& property_label,
                     const std::string_view& property_name,
                     const std::array<std::string_view, S>& enum_list,
                     T selected_enum);
  template <typename T, size_t S>
  void FixEnumList(  const std::string_view& property_label,
                     const std::string_view& property_name,
                     const std::array<std::string_view, S>& enum_list,
                     const std::optional<T> selected_enum) {
    if (selected_enum.has_value()) {
      FixEnumList(property_label, property_name, enum_list,
        selected_enum.value());
    }
  }

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

  template <typename T>
  void FixUint(const std::string_view& property_label,
               const std::string_view& property_name, T value) {
    Append( new wxUIntProperty(property_label.data(),
     property_name.empty() ? wxPG_LABEL : wxString(property_name.data()),
     value));
  }

  template <typename T>
  void FixUint(const std::string_view& property_label,
               const std::string_view& property_name,
               const std::optional<T>&  value) {
    if (value.has_value()) {
      FixUint(property_label, property_name,
        value.value());
    }
  }

  template <typename T>
  void FixHex(const std::string_view& property_label,
              const std::string_view& property_name,
              T value) {
    auto* property = new wxUIntProperty(property_label.data(),
         property_name.empty() ? wxPG_LABEL : wxString(property_name),
              value);
    property->SetAttribute(wxPG_UINT_PREFIX, wxPG_PREFIX_0x );
    property->SetAttribute(wxPG_UINT_BASE, wxPG_BASE_HEX );
    Append( property );
  }

  template <typename T>
  void FixHex(const std::string_view& property_label,
              const std::string_view& property_name,
              const std::optional<T>& value) {
    if (value.has_value()) {
      FixHex(property_label, property_name,
        static_cast<uint64_t>(value.value()));
    }
  }

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
  void Redraw(const a2l::A2lUserRights& user);
  void Redraw(const a2l::A2lVariantCoding& object);
  void Redraw(const a2l::A2lVarCharacteristic& object);
  void Redraw(const a2l::A2lVarCriterion& object);

  void RedrawXcpData(const std::string& protocol, const a2l::Module& module);
  void FixCommonParameters(const a2l::xcp::CommonParameters& common,
    const std::string& base);

  void FixProtocolLayer(const a2l::xcp::ProtocolLayer& layer,
                        const std::string& base);
  void FixCommunicationMode(const a2l::xcp::CommunicationMode& mode,
                            const std::string& base_name);
  void FixEcuState(const std::vector<a2l::xcp::EcuState>& state_list,
    const std::string& base);
  void FixDaq(const a2l::xcp::Daq& daq, const std::string& base);
  void FixTimeCorrelation(const a2l::xcp::TimeCorrelation& correlation,
    const std::string& base);
  void FixDaqList(const std::vector<a2l::xcp::DaqList>& daq_list,
    const std::string& base);
  void FixEventList(const std::vector<a2l::xcp::Event>& event_list,
    const std::string& base);
  void FixDaqEvent(const a2l::xcp::DaqEvent& event);
  void FixPgm(const a2l::xcp::Pgm& pgm, const std::string& base);
  void FixSegment(const a2l::xcp::Segment& segment);
  void FixPage(const std::vector<a2l::xcp::Page>& page_list);
  void FixXcpOnCan(const std::vector<a2l::xcp::XcpOnCan>& xcp_on_can_list);
  void FixXcpOnSxi(const std::vector<a2l::xcp::XcpOnSxi>& xcp_on_sxi_list);
  void FixXcpOnTcpIp(const std::vector<a2l::xcp::XcpOnTcpIp>& xcp_on_tcp_list);
  void FixXcpOnUdpIp(const std::vector<a2l::xcp::XcpOnUdpIp>& xcp_on_udp_list);
  void FixXcpOnUsb(const std::vector<a2l::xcp::XcpOnUsb>& xcp_on_usb_list);
  void FixEpParameters(const a2l::xcp::EpParameters& ep_params,
                       const std::string& base);
  void FixXcpOnFlx(const std::vector<a2l::xcp::XcpOnFlx>& xcp_on_flx_list);
  void FixFlxBuffer(const a2l::xcp::FlxBuffer& buffer,
                       const std::string& base);

  void RedrawCcpData(const a2l::Module& module);
  void FixTpBlob(const a2l::ccp::TpBlob& tp_blob);
  void FixSource(const std::vector<a2l::ccp::Source>& source_list);
  void FixRaster(const std::vector<a2l::ccp::Raster>& raster_list);
  void FixEventGroup(const std::vector<a2l::ccp::EventGroup>& group_list);

  void RedrawIfData(const std::string& protocol, const std::string& if_data);
};

template <typename T>
void A2lPropertyGrid::FixPropertyMap(const std::string_view& property_label,
                    const std::string_view& property_name,
                    const std::map<std::string,std::unique_ptr<T>>&
                        object_list) {
  if (!object_list.empty()) {
    wxArrayString list;
    list.Alloc(object_list.size());
    for (const auto& [name, object] : object_list) {
      list.Add(wxString::FromUTF8(name));
    }
    Append( new wxArrayStringProperty(property_label.data(),
           property_name.empty() ? wxPG_LABEL : wxString::FromUTF8(property_name.data()),
                                     list));
  }
}

template <typename T>
void A2lPropertyGrid::FixPropertyMap(const std::string_view& property_label,
                    const std::string_view& property_name,
                    const std::unordered_map<std::string,std::unique_ptr<T>>&
                        object_list) {
  if (!object_list.empty()) {
    wxArrayString list;
    list.Alloc(object_list.size());
    for (const auto& [name, object] : object_list) {
      list.Add(wxString::FromUTF8(name));
    }
    Append( new wxArrayStringProperty(property_label.data(),
           property_name.empty() ? wxPG_LABEL : wxString::FromUTF8(property_name.data()),
                                     list));
  }
}

template <typename T>
void A2lPropertyGrid::FixEnumList(const std::string_view& property_label,
                                  const std::string_view& property_name,
                                  const a2l::EnumStringList& enum_list,
                                  T selected_enum) {
  if (const auto sel = static_cast<size_t>(selected_enum);
      sel < enum_list.size()) {
    if ( const std::string_view& enum_name = enum_list[sel];
         enum_name.empty()) {
      return;
    }
  } else {
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
          property_name.empty() ? wxPG_LABEL : wxString::FromUTF8(property_name.data()),
                                 list, selected));
}

template <typename T, size_t S>
void A2lPropertyGrid::FixEnumList(const std::string_view& property_label,
                                  const std::string_view& property_name,
                                  const std::array<std::string_view, S>& enum_list,
                                  T selected_enum) {
  if (const auto sel = static_cast<size_t>(selected_enum);
      sel < enum_list.size()) {
    if ( const std::string_view& enum_name = enum_list[sel];
         enum_name.empty()) {
      return;
    }
  } else {
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
          property_name.empty() ? wxPG_LABEL : wxString::FromUTF8(property_name.data()),
                                 list, selected));
}

template <typename T>
void A2lPropertyGrid::FixInEnumList(wxPGProperty* root,
                                    const std::string_view& property_label,
                                    const std::string_view& property_name,
                                    const a2l::EnumStringList& enum_list,
                                    T selected_enum) {
  if (const auto sel = static_cast<size_t>(selected_enum);
      sel < enum_list.size()) {
    if (const std::string_view& enum_name = enum_list[sel];
        enum_name.empty()) {
      return;
    }
  } else {
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
           property_name.empty() ? wxPG_LABEL : wxString::FromUTF8(property_name.data()),
                            list, selected));
}

}  // namespace a2lgui
