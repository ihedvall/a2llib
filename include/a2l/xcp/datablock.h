/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include <string>

#include "a2l/xcp/commonparameters.h"
#include "a2l/xcp/xcponcan.h"
#include "a2l/xcp/xcponsxi.h"
#include "a2l/xcp/xcpontcpip.h"
#include "a2l/xcp/xcponudpip.h"
#include "a2l/xcp/xcponflx.h"
#include "a2l/xcp/xcponusb.h"
#include "a2l/xcp/xcponsimulink.h"

namespace a2l::xcp {

class XcpDataScanner;

class DataBlock {
 public:
  DataBlock() = delete;
  explicit DataBlock(std::string if_data);

  [[nodiscard]] bool IsOk() const { return parse_; }
  [[nodiscard]] const std::string& LastError() const { return last_error_; }

  uint16_t GetVersion() const { return version_; }
  const CommonParameters& GetCommonParameters() const {
    return common_parameters_;
  }

  [[nodiscard]] const std::vector<XcpOnCan>& GetXcpOnCans() const {
    return xcp_on_can_list_;
  }

  [[nodiscard]] const std::vector<XcpOnSxi>& GetXcpOnSxis() const {
    return xcp_on_sxi_list_;
  }

  [[nodiscard]] const std::vector<XcpOnTcpIp>& GetXcpOnTcpIps() const {
    return xcp_on_tcp_list_;
  }

  [[nodiscard]] const std::vector<XcpOnUdpIp>& GetXcpOnUdpIps() const {
    return xcp_on_udp_list_;
  }

  [[nodiscard]] const std::vector<XcpOnUsb>& GetXcpOnUsb() const {
    return xcp_on_usb_list_;
  }

  [[nodiscard]] const std::vector<XcpOnFlx>& GetXcpOnFlx() const {
    return xcp_on_flx_list_;
  }

  [[nodiscard]] const std::vector<XcpOnSimulink>& GetXcpOnSimulinks() const {
    return xcp_on_simulink_list_;
  }

 private:
  bool parse_ = false;
  std::string last_error_;

  uint16_t version_ = 0;
  CommonParameters common_parameters_;
  std::vector<XcpOnSimulink> xcp_on_simulink_list_;
  std::vector<XcpOnFlx> xcp_on_flx_list_;
  std::vector<XcpOnUsb> xcp_on_usb_list_;
  std::vector<XcpOnUdpIp> xcp_on_udp_list_;
  std::vector<XcpOnTcpIp> xcp_on_tcp_list_;
  std::vector<XcpOnSxi> xcp_on_sxi_list_;
  std::vector<XcpOnCan> xcp_on_can_list_;

  void TransferData(XcpDataScanner& scanner);


};

}

