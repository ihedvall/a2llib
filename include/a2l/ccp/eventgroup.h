/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace a2l::ccp {

class EventGroup {
public:
  void SetName(std::string name) { name_ = std::move(name); }
  [[nodiscard]] const std::string& GetName() const { return name_; }

  void SetShortName(std::string short_name) {
    short_name_ = std::move(short_name);
  }
  [[nodiscard]] const std::string& GetShortName() const { return short_name_; }

  void SetRasterList(std::vector<uint8_t> raster_list) {
    raster_list_ = std::move(raster_list);
  }
  [[nodiscard]] const std::vector<uint8_t>& GetRasterList() const {
    return raster_list_;
  }

private:
  std::string name_;
  std::string short_name_;
  std::vector<uint8_t> raster_list_;
};

}  // namespace a2l::ccp


