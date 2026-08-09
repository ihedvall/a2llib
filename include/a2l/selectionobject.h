/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace a2l {
enum class ObjectType : int {
  RAMCELL = 0,  ///< A2L Measurement
  LABEL = 1,    ///< A2L Charqcteristic
  FUNCTION = 2, ///< A2L Function
  GROUP = 3     ///< A2L Group
};

enum class ObjectDisplayType : int {
  UNKNOWN = 0,
  DISPLAY = 1,
  DISPLAY_ONLY = 2,
  RECORD_ONLY = 3, // Is RecorderOnly in specification !?
  DO_NOT_USE = 4,
};

using RasterList = std::vector<std::string>;

class SelectionObject {
public:
  [[nodiscard]] bool IsAttached() const { return user_object_ != nullptr; }
  void SetUserObject(void* user_object) { user_object_ = user_object; }
  [[nodiscard]] void* GetUserObject() const { return user_object_; }

  void SetObjectType(ObjectType type) { type_ = type; }
  [[nodiscard]] ObjectType GetObjectType() const { return type_; }

  void SetName(std::string name) { name_ = std::move(name); }
  [[nodiscard]] const std::string& GetName() const { return name_; }

  void SetDescription(std::string description) {
    description_ = std::move(description);
  }
  [[nodiscard]] const std::string& GetDescription() const {
    return description_;
  }

  void SetComment(std::string comment) {
    comment_= std::move(comment);
  }

  [[nodiscard]] const std::string& GetComment() const {
    return comment_;
  }

  void SetUnit(std::string unit) { unit_ = std::move(unit); }
  [[nodiscard]] const std::string& GetUnit() const { return unit_; }

  void SetLowerLimit(double lower_limit) { lower_limit_ = lower_limit; }
  [[nodiscard]] double GetLowerLimit() const { return lower_limit_; }

  void SetUpperLimit(double upper_limit) { upper_limit_ = upper_limit; }
  [[nodiscard]] double GetUpperLimit() const { return upper_limit_; }

  void AddRaster(std::string raster) {
    raster_list_.emplace_back(std::move(raster));
  }
  [[nodiscard]] const RasterList& GetRasterList() const {
    return raster_list_;
  }
  [[nodiscard]] RasterList& GetRasterList() {
    return raster_list_;
  }

  void SetDisplayType(ObjectDisplayType display_type) {
    display_type_ = display_type;
  }
  [[nodiscard]] ObjectDisplayType GetDisplayType() const {
    return display_type_;
  }
  void SetDisplayTypeAsString(const std::string& display_type);
  [[nodiscard]] const std::string_view& GetDisplayTypeAsString() const;

  void SetOrder(int64_t order) { order_ = order; }
  [[nodiscard]] int64_t GetOrder() const { return order_; }

  void SetDevice(std::string device) {
    device_= std::move(device);
  }
  [[nodiscard]] const std::string& GetDevice() const {
    return device_;
  }

private:
  ObjectType type_ = ObjectType::RAMCELL;
  std::string name_;
  std::string description_;
  std::string comment_;
  std::string unit_;
  double lower_limit_ = 0.0;
  double upper_limit_ = 0.0;
  std::vector<std::string> raster_list_;
  ObjectDisplayType display_type_ = ObjectDisplayType::UNKNOWN;
  int64_t order_ = -1;
  std::string device_;
  void* user_object_ = nullptr;
};

}  // namespace a2l


