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
  DISPLAY = 0,
  DISPLAY_ONLY = 1,
  RECORDER_ONLY = 2,
  DO_NOT_USE = 3,
};

using RasterList = std::vector<std::string>;

class SelectionObject {
public:
  void SetType(ObjectType type) { type_ = type; }
  [[nodiscard]] ObjectType GetType() const { return type_; }

  void SetName(std::string name) { name_ = std::move(name); }
  [[nodiscard]] const std::string& GetName() const { return name_; }

  void SetDescription(std::string description) {
    description_= std::move(description);
  }
  [[nodiscard]] const std::string& GetDescription() const {
    return description_;
  }

  void AddRaster(std::string raster) {
    raster_list_.emplace_back(std::move(raster));
  }
  [[nodiscard]] std::string GetRaster(size_t index) const;
  void DeleteRaster(size_t index);

  [[nodiscard]] const RasterList& GetRasterList() const {
    return raster_list_;
  }
  [[nodiscard]] RasterList& GetRasterList() {
    return raster_list_;
  }

  [[nodiscard]] std::vector<double> GetSamplingRates() const;

  void SetDisplayType(ObjectDisplayType display_type) {
    display_type_ = display_type;
  }
  [[nodiscard]] ObjectDisplayType GetDisplayType() const {
    return display_type_;
  }

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
  std::vector<std::string> raster_list_;
  ObjectDisplayType display_type_ = ObjectDisplayType::DISPLAY;
  uint64_t order_ = 0;
  std::string device_;
};

}  // namespace a2l


