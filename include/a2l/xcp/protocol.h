/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once
#include "a2l/xcp/commonparameters.h"

namespace a2l::xcp {
class Protocol {
public:
  virtual ~Protocol() = default;
  void SetOverrulingParameters(CommonParameters& current);
  [[nodiscard]] const CommonParameters& GetOverrulingParameters() const {
    return overruling_parameters_;
  }
  void SetTransportLayerInstance(std::string instance) {
    transport_layer_instance_ = std::move(instance);
  }
  [[nodiscard]] const std::string& GetTransportLayerInstance() const {
    return transport_layer_instance_;
  }

  virtual void Reset();
private:
  CommonParameters overruling_parameters_;
  std::string transport_layer_instance_;
};
}



