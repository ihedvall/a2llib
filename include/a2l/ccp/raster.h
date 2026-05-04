/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace a2l::ccp {

class Raster {
public:
  void SetName(std::string name) { name_ = std::move(name); }
  [[nodiscard]] const std::string& GetName() const { return name_; }

  void SetShortName(std::string short_name) { short_name_ = std::move(short_name); }
  [[nodiscard]] const std::string& GetShortName() const { return short_name_; }

  void SetNumber(uint64_t number) {
    number_ = static_cast<uint8_t>(number);
  }
  [[nodiscard]] uint8_t GetNumber() const { return number_; }

  void SetPeriod(int64_t period) {
    period_ = static_cast<int16_t>(period);
  }
  [[nodiscard]] int16_t GetPeriod() const { return period_; }

  void SetSampleRate(int64_t sample_rate) {
    sample_rate_ = static_cast<int32_t>(sample_rate);
  }
  [[nodiscard]] int32_t GetSampleRate() const { return sample_rate_; }

  void SetExclusiveList(std::vector<uint8_t> exclusive_list) {
    exclusive_list_ = std::move(exclusive_list);
  }
  [[nodiscard]] const std::vector<uint8_t>& GetExclusiveList() const {
    return exclusive_list_;
  }
private:
  std::string name_;
  std::string short_name_;
  uint8_t number_ = 0;
  int16_t period_ = 0;
  int32_t sample_rate_ = 0;
  std::vector<uint8_t> exclusive_list_;
};

}  // namespace a2l::ccp


