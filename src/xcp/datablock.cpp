/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2l/xcp/datablock.h"

#include <sstream>
#include <stdexcept>

#include "xcpdatascanner.h"

namespace a2l::xcp {

DataBlock::DataBlock( std::string if_data)
{
  try {
    if (if_data.empty()) {
      throw std::runtime_error("Nothing to parse");
    }
    std::istringstream temp(if_data);
    XcpDataScanner scanner(temp);
    XcpDataParser parser(scanner);
    parse_ = parser.parse() == 0;
    last_error_ = scanner.LastError();
    TransferData(scanner);

  } catch (const std::exception& err) {
    last_error_ = err.what();
    parse_ = false;
  }
}

void DataBlock::TransferData(XcpDataScanner& scanner) {
  version_ = scanner.GetVersion();
  common_parameters_ = std::move(scanner.common_parameters_);
  xcp_on_can_list_ = std::move(scanner.xcp_on_can_list_);
  xcp_on_sxi_list_ = std::move(scanner.xcp_on_sxi_list_);
  xcp_on_tcp_list_ = std::move(scanner.xcp_on_tcp_list_);
  xcp_on_udp_list_ = std::move(scanner.xcp_on_udp_list_);
  xcp_on_flx_list_ = std::move(scanner.xcp_on_flx_list_);
  xcp_on_usb_list_ = std::move(scanner.xcp_on_usb_list_);
  xcp_on_simulink_list_ = std::move(scanner.xcp_on_simulink_list_);

}
}  // namespace a2l::xcp