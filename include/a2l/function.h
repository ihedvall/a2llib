/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include "a2l/a2lobject.h"
#include <map>
#include <memory>

namespace a2l {
class Function : public A2lObject {
 public:
  void ComponentType(const std::string& type) { component_type_ = type; }
  [[nodiscard]] const std::string& ComponentType() const {
    return component_type_;
  }

  void PrototypeOf(const std::string& type) { prototype_of_ = type; }
  [[nodiscard]] const std::string& PrototypeOf() const {
    return prototype_of_;
  }

  void DefaultCharacteristics(const std::vector<std::string>& list) {
    default_characteristic_list_ = list;
  }
  [[nodiscard]] const std::vector<std::string>& DefaultCharacteristics() const {
    return default_characteristic_list_;
  }

  void Version(const std::string& version) { version_ = version; }
  [[nodiscard]] const std::string& Version() const { return version_; }

  void InMeasurements(const std::vector<std::string>& list) {
    in_measurement_list_ = list;
  }
  [[nodiscard]] const std::vector<std::string>& InMeasurements() const {
    return in_measurement_list_;
  }

  void LocMeasurements(const std::vector<std::string>& list) {
    loc_measurement_list_ = list;
  }
  [[nodiscard]] const std::vector<std::string>& LocMeasurements() const {
    return loc_measurement_list_;
  }

  void OutMeasurements(const std::vector<std::string>& list) {
    out_measurement_list_ = list;
  }
  [[nodiscard]] const std::vector<std::string>& OutMeasurements() const {
    return out_measurement_list_;
  }

  void RefCharacteristics(const std::vector<std::string>& list) {
    ref_characteristic_list_ = list;
  }
  [[nodiscard]] const std::vector<std::string>& RefCharacteristics() const {
    return ref_characteristic_list_;
  }

  void SubFunctions(const std::vector<std::string>& list) {
    sub_function_list_ = list;
  }
  [[nodiscard]] const std::vector<std::string>& SubFunctions() const {
    return sub_function_list_;
  }

 private:
  std::string component_type_;
  std::string prototype_of_;
  std::vector<std::string> default_characteristic_list_;
  std::string version_;
  std::vector<std::string> in_measurement_list_;
  std::vector<std::string> loc_measurement_list_;
  std::vector<std::string> out_measurement_list_;
  std::vector<std::string> ref_characteristic_list_;
  std::vector<std::string> sub_function_list_;
};

using FuncList = std::map<std::string, std::unique_ptr<Function>>;

} // end namespace a2l
