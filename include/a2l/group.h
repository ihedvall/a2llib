/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include "a2l/a2lobject.h"
#include <map>
#include <memory>

namespace a2l {
class Group : public A2lObject {
 public:
  void Root(bool root) { root_ = root; }
  [[nodiscard]] bool Root() const { return root_; }

  void RefCharacteristics(const std::vector<std::string>& list) {
    ref_characteristic_list_ = list;
  }
  [[nodiscard]] const std::vector<std::string>& RefCharacteristics() const {
    return ref_characteristic_list_;
  }

  void RefMeasurements(const std::vector<std::string>& list) {
    ref_measurement_list_ = list;
  }
  [[nodiscard]] const std::vector<std::string>& RefMeasurements() const {
    return ref_measurement_list_;
  }

  void SubGroups(const std::vector<std::string>& list) {
    sub_group_list_ = list;
  }
  [[nodiscard]] const std::vector<std::string>& SubGroups() const {
    return sub_group_list_;
  }
 private:
  bool root_ = false;
  std::vector<std::string> ref_characteristic_list_;
  std::vector<std::string> ref_measurement_list_;
  std::vector<std::string> sub_group_list_;
};

using GroupList = std::map<std::string, std::unique_ptr<Group>>;

} // end namespace a2l
