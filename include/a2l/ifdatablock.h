/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include "a2l/ifdataitem.h"
#include <string>
#include <vector>

namespace a2l {

class IfDataBlock {
 public:
  explicit IfDataBlock(const std::string& ifdata);
  [[nodiscard]] bool IsOk() const { return parse_; }

  [[nodiscard]] const std::string& Protocol() const {
    return protocol_;
  }
  [[nodiscard]] const std::vector<IfDataItem>& ItemList() const {
    return item_list_;
  }
  [[nodiscard]] const std::string& LastError() const { return last_error_; }

  [[nodiscard]] std::string AsString() const;
 private:
  bool parse_ = false;
  std::string last_error_;
  std::string protocol_;
  std::vector<IfDataItem> item_list_;

  [[nodiscard]] std::string AsString(size_t tab_level,
                                     const IfDataItem& block_item) const;
};

}  // namespace a2l
