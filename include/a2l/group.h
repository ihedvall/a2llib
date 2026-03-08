/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once
#include <map>
#include <memory>
#include <string>
#include <deque>

#include "a2l/a2lobject.h"


namespace a2l {
class Group : public A2lObject {
 public:
  void Root(bool root) { root_ = root; }
  [[nodiscard]] bool Root() const { return root_; }

  void RefCharacteristics(std::deque<std::string> list) {
    ref_characteristic_list_ = std::move(list);
  }
  [[nodiscard]] const std::deque<std::string>& RefCharacteristics() const {
    return ref_characteristic_list_;
  }

  void RefMeasurements(std::deque<std::string> list) {
    ref_measurement_list_ = std::move(list);
  }
  [[nodiscard]] const std::deque<std::string>& RefMeasurements() const {
    return ref_measurement_list_;
  }

  void SubGroups(std::deque<std::string> list) {
    sub_group_list_ = std::move(list);
  }
  [[nodiscard]] const std::deque<std::string>& SubGroups() const {
    return sub_group_list_;
  }
 private:
  bool root_ = false;
  std::deque<std::string> ref_characteristic_list_;
  std::deque<std::string> ref_measurement_list_;
  std::deque<std::string> sub_group_list_;
};

using GroupList = std::map<std::string, std::unique_ptr<Group>>;

} // end namespace a2l
