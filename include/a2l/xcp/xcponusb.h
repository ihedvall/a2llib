/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include <optional>

#include "a2l/xcp/protocol.h"
#include "a2l/xcp/epparameters.h"

namespace a2l::xcp {

enum class HeaderLength : uint8_t {
  HEADER_LEN_BYTE = 0,
  HEADER_LEN_CTR_BYTE = 1,
  HEADER_LEN_FILL_BYTE = 2,
  HEADER_LEN_WORD = 3,
  HEADER_LEN_CTR_WORD = 4,
  HEADER_LEN_FILL_WORD = 5
};

enum class UsbSubCmd : uint8_t {
  GET_DAQ_EP = 0xFF,
  SET_DAQ_EP = 0xFE
};

struct DaqListUsbEndpoint {
  uint16_t number = 0;
  std::optional<uint8_t> fixed_in;
  std::optional<uint8_t> fixed_out;
  void Reset() {
    number = 0;
    fixed_in.reset();
    fixed_out.reset();
  }
};

using UsbSubCmdList = std::vector<UsbSubCmd>;

class XcpOnUsb : public Protocol {
public:
  XcpOnUsb() = default;
  ~XcpOnUsb() override = default;

  void SetVersion(uint64_t version) { version_ = static_cast<uint16_t>(version); }
  [[nodiscard]] uint16_t GetVersion() const { return version_; }
  [[nodiscard]] std::string GetVersionAsString() const;

  void SetVendorId(uint64_t vendor_id) {
    vendor_id_ = static_cast<uint16_t>(vendor_id);
  }
  [[nodiscard]] uint16_t GetVendorId() const { return vendor_id_; }

  void SetProductId(uint64_t product_id) {
    product_id_ = static_cast<uint16_t>(product_id);
  }
  [[nodiscard]] uint16_t GetProductId() const { return product_id_; }

  void SetNumberOfInterfaces(uint64_t number_of_interfaces) {
    number_of_interfaces_ = static_cast<uint8_t>(number_of_interfaces);
  }
  [[nodiscard]] uint8_t GetNumberOfInterfaces() const {
    return number_of_interfaces_;
  }

  void SetHeaderLength(const std::string& header_length);
  [[nodiscard]] HeaderLength GetHeaderLength() const { return header_length_; }

  void SetOutEpCmdStim() {
    out_ep_cmd_stim_ = std::move(ep_parameters_);
    ep_parameters_.Reset();
  }
  [[nodiscard]] const EpParameters* GetOutEpCmdStim() const {
    return out_ep_cmd_stim_.has_value() ? &out_ep_cmd_stim_.value() : nullptr;
  }

  void SetInEpReserrDaqEvserv() {
    in_ep_reserr_daq_evserv_ = std::move(ep_parameters_);
    ep_parameters_.Reset();
  }
  [[nodiscard]] const EpParameters* GetInEpReserrDaqEvserv() const {
    return in_ep_reserr_daq_evserv_.has_value() ?
      &in_ep_reserr_daq_evserv_.value() : nullptr;
  }

  void SetAlternateSettingNo(uint64_t alternate_setting_no) {
    alternate_setting_no_ = static_cast<uint8_t>(alternate_setting_no);
  }
  [[nodiscard]] const std::optional<uint8_t>&  GetAlternateSettingNo() const {
    return alternate_setting_no_;
  }

  void SetInterfaceStringDescriptor(std::string interface_string_descriptor) {
    interface_string_descriptor_ = std::move(interface_string_descriptor);
  }
  [[nodiscard]] const std::optional<std::string>& GetInterfaceStringDescriptor() const {
    return interface_string_descriptor_;
  }

  void AddOutEpOnlyStim() {
    out_ep_only_stim_list_.emplace_back(std::move(ep_parameters_));
    ep_parameters_.Reset();
  }
  [[nodiscard]] const std::vector<EpParameters>& GetOutEpOnlyStim() const {
    return out_ep_only_stim_list_;
  }

  void AddInEpOnlyDaq() {
    in_ep_only_daq_list_.emplace_back(std::move(ep_parameters_));
    ep_parameters_.Reset();
  }
  [[nodiscard]] const std::vector<EpParameters>& GetInEpOnlyDaq() const {
    return in_ep_only_daq_list_;
  }

  void SetInEpOnlyEvserv() {
    in_ep_only_evserv_ = std::move(ep_parameters_);
    ep_parameters_.Reset();
  }
  [[nodiscard]] const EpParameters* GetInEpOnlyEvserv() const {
    return in_ep_only_evserv_.has_value() ?
      &in_ep_only_evserv_.value() : nullptr;
  }

  void AddDaqListUsbEndpoint() {
    daq_list_usb_endpoint_list_.emplace_back(std::move(daq_list_usb_endpoint_));
    daq_list_usb_endpoint_.Reset();
  }
  [[nodiscard]] const std::vector<DaqListUsbEndpoint>& GetDaqListUsbEndpoint() const {
    return daq_list_usb_endpoint_list_;
  }

  void AddUsbSubCmd(const std::string& cmd);
  [[nodiscard]] const UsbSubCmdList& GetUsbSubCmds() const {
    return optional_tl_subcommand_list_;
  }
  EpParameters& GetEpParameters() { return ep_parameters_; }

  DaqListUsbEndpoint& GetDaqListUsbEndpoint() { return daq_list_usb_endpoint_; }

  void Reset() override;
private:
  uint16_t version_ = 0;
  uint16_t vendor_id_ = 0;
  uint16_t product_id_ = 0;
  uint8_t number_of_interfaces_ = 0;
  HeaderLength header_length_ = HeaderLength::HEADER_LEN_BYTE;
  std::optional<EpParameters> out_ep_cmd_stim_;
  std::optional<EpParameters> in_ep_reserr_daq_evserv_;
  std::optional<uint8_t> alternate_setting_no_;
  std::optional<std::string> interface_string_descriptor_;
  std::vector<EpParameters> out_ep_only_stim_list_;
  std::vector<EpParameters> in_ep_only_daq_list_;
  std::optional<EpParameters> in_ep_only_evserv_;
  std::vector<DaqListUsbEndpoint> daq_list_usb_endpoint_list_;
  UsbSubCmdList optional_tl_subcommand_list_;

  EpParameters ep_parameters_; ///< Temporary for the parser
  DaqListUsbEndpoint daq_list_usb_endpoint_; ///< Used by the parser
};
}



