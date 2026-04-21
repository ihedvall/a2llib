/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <optional>

#include "a2l/xcp/daqevent.h"
#include "a2l/xcp/protocollayer.h"
#include "a2l/xcp/daq.h"
#include "a2l/xcp/pag.h"
#include "a2l/xcp/pgm.h"
#include "a2l/xcp/segment.h"
#include "a2l/xcp/timecorrelation.h"

namespace a2l::xcp {
class CommonParameters {
public:
private:
  std::optional<ProtocolLayer> protocol_layer_;
  std::optional<TimeCorrelation> time_correlation_;
  std::optional<Segment> segment_;
  std::optional<Daq> daq_;
  std::optional<Pag> pag_;
  std::optional<Pgm> pgm_;
  std::optional<DaqEvent> daq_event_;
};
}




