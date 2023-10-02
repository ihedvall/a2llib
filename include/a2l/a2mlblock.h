/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include "a2l/a2mlobject.h"
#include <string>

namespace a2l {

class A2mlBlock {
 public:
  explicit A2mlBlock(const std::string& a2ml);
  [[nodiscard]] bool IsOk() const { return parse_; }
  [[nodiscard]] const A2mlBlockList& BlockList() const { return block_list_; }
  [[nodiscard]] const std::string& LastError() const { return last_error_; }
 private:
  bool parse_ = false;
  std::string last_error_;
  A2mlBlockList block_list_;

};

}  // namespace a2l
