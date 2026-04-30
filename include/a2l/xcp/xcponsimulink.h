/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <optional>
#include <string>

#include "a2l/xcp/protocol.h"

namespace a2l::xcp {

class XcpOnSimulink : public Protocol {
public:
  XcpOnSimulink() = default;
  ~XcpOnSimulink() override = default;

  void SetModelName(std::string model_name) {
    model_name_ = std::move(model_name);
  }
  [[nodiscard]] const std::string& GetModelName() const {
    return model_name_;
  }

  void Reset() override;
private:
  std::string model_name_;

};
}
