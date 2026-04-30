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
  void SetProtocolLayer(ProtocolLayer protocol_layer) {
    protocol_layer_ = std::move(protocol_layer);
  }
  [[nodiscard]] ProtocolLayer* GetProtocolLayer() {
    return protocol_layer_.has_value() ? &protocol_layer_.value() : nullptr;
  }
  [[nodiscard]] const ProtocolLayer* GetProtocolLayer() const {
    return protocol_layer_.has_value() ? &protocol_layer_.value() : nullptr;
  }

  void SetTimeCorrelation(TimeCorrelation time_correlation) {
    time_correlation_ = std::move(time_correlation);
  }
  [[nodiscard]] TimeCorrelation* GetTimeCorrelation() {
    return time_correlation_.has_value() ? &time_correlation_.value() : nullptr;
  }
  [[nodiscard]] const TimeCorrelation* GetTimeCorrelation() const {
    return time_correlation_.has_value() ? &time_correlation_.value() : nullptr;
  }

  void SetSegment(Segment segment) {
    segment_ = std::move(segment);
  }
  [[nodiscard]] Segment* GetSegment() {
    return segment_.has_value() ? &segment_.value() : nullptr;
  }
  [[nodiscard]] const Segment* GetSegment() const {
    return segment_.has_value() ? &segment_.value() : nullptr;
  }

  void SetDaq(Daq daq) {
    daq_ = std::move(daq);
  }
  [[nodiscard]] Daq* GetDaq() {
    return daq_.has_value() ? &daq_.value() : nullptr;
  }
  [[nodiscard]] const Daq* GetDaq() const {
    return daq_.has_value() ? &daq_.value() : nullptr;
  }

  void SetPag(Pag pag) {
    pag_ = std::move(pag);
  }
  [[nodiscard]] Pag* GetPag() {
    return pag_.has_value() ? &pag_.value() : nullptr;
  }
  [[nodiscard]] const Pag* GetPag() const {
    return pag_.has_value() ? &pag_.value() : nullptr;
  }

  void SetPgm(Pgm pgm) {
    pgm_ = std::move(pgm);
  }
  [[nodiscard]] Pgm* GetPgm() {
    return pgm_.has_value() ? &pgm_.value() : nullptr;
  }
  [[nodiscard]] const Pgm* GetPgm() const {
    return pgm_.has_value() ? &pgm_.value() : nullptr;
  }

  void SetDaqEvent(DaqEvent daq_event) {
    daq_event_ = std::move(daq_event);
  }
  [[nodiscard]] DaqEvent* GetDaqEvent() {
    return daq_event_.has_value() ? &daq_event_.value() : nullptr;
  }
  [[nodiscard]] const DaqEvent* GetDaqEvent() const {
    return daq_event_.has_value() ? &daq_event_.value() : nullptr;
  }

  void Reset();

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




