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
class Function : public A2lObject {
 public:
  void ComponentType(std::string type) { component_type_ = std::move(type); }
  [[nodiscard]] const std::string& ComponentType() const {
    return component_type_;
  }

  void PrototypeOf(std::string type) { prototype_of_ = std::move(type); }
  [[nodiscard]] const std::string& PrototypeOf() const {
    return prototype_of_;
  }

  void DefaultCharacteristics(std::deque<std::string> list) {
    default_characteristic_list_ = std::move(list);
  }
  [[nodiscard]] const std::deque<std::string>& DefaultCharacteristics() const {
    return default_characteristic_list_;
  }

  void Version(std::string version) { version_ = std::move(version); }
  [[nodiscard]] const std::string& Version() const { return version_; }

  void InMeasurements(std::deque<std::string> list) {
    in_measurement_list_ = std::move(list);
  }
  [[nodiscard]] const std::deque<std::string>& InMeasurements() const {
    return in_measurement_list_;
  }

  void LocMeasurements(std::deque<std::string> list) {
    loc_measurement_list_ = std::move(list);
  }
  [[nodiscard]] const std::deque<std::string>& LocMeasurements() const {
    return loc_measurement_list_;
  }

  void OutMeasurements(std::deque<std::string> list) {
    out_measurement_list_ = std::move(list);
  }
  [[nodiscard]] const std::deque<std::string>& OutMeasurements() const {
    return out_measurement_list_;
  }

  void RefCharacteristics(std::deque<std::string> list) {
    ref_characteristic_list_ = std::move(list);
  }

  [[nodiscard]] const std::deque<std::string>& RefCharacteristics() const {
    return ref_characteristic_list_;
  }

  void SubFunctions(std::deque<std::string> list) {
    sub_function_list_ = std::move(list);
  }

  [[nodiscard]] const std::deque<std::string>& SubFunctions() const {
    return sub_function_list_;
  }

 private:
  std::string component_type_;
  std::string prototype_of_;
  std::deque<std::string> default_characteristic_list_;
  std::string version_;
  std::deque<std::string> in_measurement_list_;
  std::deque<std::string> loc_measurement_list_;
  std::deque<std::string> out_measurement_list_;
  std::deque<std::string> ref_characteristic_list_;
  std::deque<std::string> sub_function_list_;
};

using FuncList = std::map<std::string, std::unique_ptr<Function>>;

} // end namespace a2l
