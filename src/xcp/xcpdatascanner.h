/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#ifndef yyFlexLexerOnce

#undef yyFlexLexer
#define yyFlexLexer xcpFlexLexer
#include "../FlexLexer.h"

#endif

#include <string>
#include <vector>

#include "a2l/xcp/commonparameters.h"
#include "a2l/xcp/xcponcan.h"
#include "a2l/xcp/xcponsxi.h"
#include "a2l/xcp/xcpontcpip.h"
#include "a2l/xcp/xcponudpip.h"
#include "a2l/xcp/xcponflx.h"
#include "a2l/xcp/xcponusb.h"
#include "a2l/xcp/xcponsimulink.h"
#include "xcpdataparser.hpp"

namespace a2l::xcp {

class XcpDataScanner : public xcpFlexLexer {
public:
  friend class DataBlock;


  XcpDataScanner(std::istream& in);

  int xcplex(XcpDataParser::value_type* yylval);

  void LastError(std::string error) { last_error_ = std::move(error); }
  [[nodiscard]] std::string LastError() const { return last_error_; }

  void SetVersion(uint64_t version) {
    version_ = static_cast<uint16_t>(version);
  }
  [[nodiscard]] uint16_t GetVersion() const { return version_; }

  [[nodiscard]] CommonParameters& GetCommonParameters() {
    return current_common_parameters_;
  }

  [[nodiscard]] Clock& GetClock() {
    return current_clock_;
  }

  [[nodiscard]] TimeCorrelation& GetTimeCorrelation() {
    return current_time_correlation_;
  }

  [[nodiscard]] Page& GetPage() {
    return current_page_;
  }

  [[nodiscard]] Checksum& GetChecksum() {
    return current_checksum_;
  }

  [[nodiscard]] Segment& GetSegment() {
    return current_segment_;
  }

  [[nodiscard]] Pgm& GetPgm() {
    return current_pgm_;
  }

  [[nodiscard]] Pag& GetPag() {
    return current_pag_;
  }

  [[nodiscard]] DaqEvent& GetDaqEvent() {
    return current_daq_event_;
  }

  [[nodiscard]] Daq& GetDaq() {
    return current_daq_;
  }

  [[nodiscard]] Event& GetEvent() {
    return current_event_;
  }

 [[nodiscard]] DaqList& GetDaqList() {
    return current_daq_list_;
  }

  [[nodiscard]] CommunicationMode& GetCommunicationMode() {
    return current_communication_mode_;
  }

  [[nodiscard]] CpuLoadConsumption& GetCpuLoadConsumption() {
    return current_cpu_load_consumption_;
  }

  [[nodiscard]] ProtocolLayer& GetProtocolLayer() {
    return current_protocol_layer_;
  }

  void SaveCommonParameters();

  [[nodiscard]] XcpOnCan& GetXcpOnCan() { return current_can_; }
  void SaveXcpOnCan() {
    xcp_on_can_list_.emplace_back(std::move(current_can_));
    current_can_.Reset();
  }

  [[nodiscard]] XcpOnSxi& GetXcpOnSxi() { return current_sxi_; }
  void SaveXcpOnSxi() {
    xcp_on_sxi_list_.emplace_back(std::move(current_sxi_));
    current_sxi_.Reset();
  }

  [[nodiscard]] XcpOnTcpIp& GetXcpOnTcpIp() { return current_tcp_; }
  void SaveXcpOnTcpIp() {
    xcp_on_tcp_list_.emplace_back(std::move(current_tcp_));
    current_tcp_.Reset();
  }


  [[nodiscard]] XcpOnUdpIp& GetXcpOnUdpIp() { return current_udp_; }
  void SaveXcpOnUdpIp() {
    xcp_on_udp_list_.emplace_back(std::move(current_udp_));
    current_udp_.Reset();
  }

  [[nodiscard]] XcpOnUsb& GetXcpOnUsb() { return current_usb_; }
  void SaveXcpOnUsb() {
    xcp_on_usb_list_.emplace_back(std::move(current_usb_));
    current_usb_.Reset();
  }

  [[nodiscard]] XcpOnFlx& GetXcpOnFlx() { return current_flx_; }
  void SaveXcpOnFlx() {
    xcp_on_flx_list_.emplace_back(std::move(current_flx_));
    current_flx_.Reset();
  }

  [[nodiscard]] XcpOnSimulink& GetXcpOnSimulink() { return current_simulink_; }
  void SaveXcpOnSimulink() {
    xcp_on_simulink_list_.emplace_back(std::move(current_simulink_));
    current_simulink_.Reset();
  }

private:
  XcpDataParser::semantic_type* yylval = nullptr;
  std::string last_error_;

  uint16_t version_ = 0;
  XcpOnSimulink current_simulink_;
  XcpOnFlx current_flx_;
  XcpOnUsb current_usb_;
  XcpOnUdpIp current_udp_;
  XcpOnTcpIp current_tcp_;
  XcpOnSxi current_sxi_;
  XcpOnCan current_can_;

  CommonParameters current_common_parameters_;
  Clock current_clock_;
  TimeCorrelation current_time_correlation_;
  Page current_page_;
  Checksum current_checksum_;
  Segment current_segment_;
  CommunicationMode current_communication_mode_;
  Pgm current_pgm_;
  Pag current_pag_;
  DaqEvent current_daq_event_;
  Daq current_daq_;
  CpuLoadConsumption current_cpu_load_consumption_;
  Event current_event_;
  DaqList current_daq_list_;
  ProtocolLayer current_protocol_layer_;

  CommonParameters common_parameters_;
  std::vector<XcpOnSimulink> xcp_on_simulink_list_;
  std::vector<XcpOnFlx> xcp_on_flx_list_;
  std::vector<XcpOnUsb> xcp_on_usb_list_;
  std::vector<XcpOnUdpIp> xcp_on_udp_list_;
  std::vector<XcpOnTcpIp> xcp_on_tcp_list_;
  std::vector<XcpOnSxi> xcp_on_sxi_list_;
  std::vector<XcpOnCan> xcp_on_can_list_;
};

}


