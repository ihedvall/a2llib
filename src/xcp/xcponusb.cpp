/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#include "a2l/xcp/xcponusb.h"

#include <sstream>
namespace a2l::xcp {

std::string XcpOnUsb::GetVersionAsString() const {
  std::ostringstream temp;
  temp << version_ / 256 << "." << version_ % 256;
  return temp.str();
}

void XcpOnUsb::SetHeaderLength(const std::string& header_length) {
  constexpr std::array<std::string_view,6> kHeaderLengthList = {
    "HEADER_LEN_BYTE",
    "HEADER_LEN_CTR_BYTE",
    "HEADER_LEN_FILL_BYTE",
    "HEADER_LEN_WORD",
    "HEADER_LEN_CTR_WORD",
    "HEADER_LEN_FILL_WORD"
  };
  for (size_t index = 0; index < kHeaderLengthList.size(); ++index) {
    if (header_length == kHeaderLengthList[index]) {
      header_length_ = static_cast<HeaderLength>(index);
      return;
    }
  }
}

void XcpOnUsb::AddUsbSubCmd(const std::string& cmd) {
  constexpr std::array<std::string_view,2> kUsbSubCmdList = {
    "SET_DAQ_EP",
    "GET_DAQ_EP"
  };
  for (size_t index = 0; index < kUsbSubCmdList.size(); ++index) {
    if (cmd == kUsbSubCmdList[index]) {
      constexpr size_t kOffset = 0xFE;
      optional_tl_subcommand_list_.push_back(
        static_cast<UsbSubCmd>(kOffset + index));
      break;
    }
  }

}
void XcpOnUsb::Reset() {
  Protocol::Reset();
  version_ = 0;
  vendor_id_ = 0;
  product_id_ = 0;
  number_of_interfaces_ = 0;
  header_length_ = HeaderLength::HEADER_LEN_BYTE;
  out_ep_cmd_stim_.reset();
  in_ep_reserr_daq_evserv_.reset();
  alternate_setting_no_.reset();
  out_ep_only_stim_list_.clear();
  in_ep_only_daq_list_.clear();
  in_ep_only_evserv_.reset();
  daq_list_usb_endpoint_list_.clear();

  ep_parameters_.Reset();
  daq_list_usb_endpoint_.Reset();
}

}  // namespace a2l::xcp