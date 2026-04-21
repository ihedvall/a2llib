/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */
#pragma once

#include <string>
#include <vector>


namespace a2l {

class IfDataItem {
public:
  void Value(std::string value) { value_ = std::move(value); }
  [[nodiscard]] const std::string& Value() const { return value_; }
  void BlockName(std::string block_name) { block_name_ = std::move(block_name); }
  [[nodiscard]] const std::string& BlockName() const { return block_name_; }

  void ItemList(std::vector<IfDataItem> item_list) { item_list_ = std::move(item_list); }
  [[nodiscard]] const std::vector<IfDataItem>& ItemList() const { return item_list_; }

private:
  std::string value_;
  std::string block_name_;
  std::vector<IfDataItem> item_list_;
};


} // end namespace a2l