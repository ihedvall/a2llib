/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "xcpdatascanner.h"

namespace a2l::xcp {
XcpDataScanner::XcpDataScanner(std::istream& message)
    : xcpFlexLexer(&message), yylval(nullptr) {

}
void XcpDataScanner::SaveCommonParameters() {
  CommonParameters& current = current_common_parameters_;
  CommonParameters& common = common_parameters_;

  if (ProtocolLayer* protocol = current.GetProtocolLayer(); protocol != nullptr) {
    common.SetProtocolLayer(std::move(*protocol));;
  }

  if (TimeCorrelation* time = current.GetTimeCorrelation(); time != nullptr) {
    common.SetTimeCorrelation(std::move(*time));;
  }

  if (Segment* segment = current.GetSegment(); segment != nullptr) {
    common.SetSegment(std::move(*segment));;
  }

  if (Daq* daq = current.GetDaq(); daq != nullptr) {
    common.SetDaq(std::move(*daq));;
  }

  if (Pag* pag = current.GetPag(); pag != nullptr) {
    common.SetPag(std::move(*pag));;
  }

  if (Pgm* pgm = current.GetPgm(); pgm != nullptr) {
    common.SetPgm(std::move(*pgm));;
  }

  if (DaqEvent* daq_event = current.GetDaqEvent(); daq_event != nullptr) {
    common.SetDaqEvent(std::move(*daq_event));;
  }

  current.Reset();
}
}