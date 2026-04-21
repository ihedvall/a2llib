/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include <string>

namespace a2l::xcp {

class DataBlock {
 public:
  DataBlock() = delete;
  explicit DataBlock(std::string if_data);

  [[nodiscard]] bool IsOk() const { return parse_; }
  [[nodiscard]] const std::string& LastError() const { return last_error_; }
 private:
  bool parse_ = false;
  std::string last_error_;
};

}

