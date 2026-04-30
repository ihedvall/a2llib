/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>
#include <optional>
#include <string>
#include <array>

#include "a2l/xcp/timestampcharacteristic.h"

namespace a2l::xcp {

enum class ClockType : uint8_t {
  XCP_SLAVE_CLOCK = 0,
  ECU_CLOCK = 1,
  XCP_SLAVE_GRANDMASTER_CLOCK = 2,
  ECU_GRANDMASTER_CLOCK = 3,
};

enum class ClockReadability : uint8_t {
  RANDOMLY_READABLE = 0,
  LIMITED_READABLE = 1,
  NOT_READABLE = 2,
};

enum class Synchronization : uint8_t {
  SYN_UNSUPPORTED = 0,
  SYNCHRONIZATION_ONLY = 1,
  SYNTONIZATION_ONLY = 2,
  SYN_ALL = 3
};

enum class Epoch : uint8_t {
  ATOMIC_TIME = 0,
  UNIVERSAL_COORDINATED_TIME = 1,
  ARBITRARY = 2
};

class Clock {
public:
  void SetUuid(int64_t uuid, size_t offset);
 [[nodiscard]] std::string GetUuid() const;

  void SetType(const std::string& type);
  [[nodiscard]] ClockType GetType() const { return type_; }

  void SetReadability(const std::string& readability);
  [[nodiscard]] ClockReadability GetReadability() const {
    return readability_;
  }

  void SetSynchronization(const std::string& synchronization);
  [[nodiscard]] Synchronization GetSynchronization() const {
    return synchronization_;
  }

  void SetClockQuality(uint64_t clock_quality) {
    clock_quality_ = static_cast<uint8_t>(clock_quality);
  }
  [[nodiscard]] uint8_t GetClockQuality() const { return clock_quality_; }

  void SetCharacteristic(TimestampCharacteristic characteristic) {
    characteristic_ = std::move(characteristic);
  }
  [[nodiscard]] const std::optional<TimestampCharacteristic>& GetCharacteristic() const {
    return characteristic_;
  }

  void SetMaxTimestampValueBeforeWrapAround(uint64_t max_timestamp) {
    max_timestamp_value_before_wrap_around_ = max_timestamp;
  }
  [[nodiscard]] uint64_t GetMaxTimestampValueBeforeWrapAround() const {
    return max_timestamp_value_before_wrap_around_;
  }

  void SetEpoch(const std::string& epoch);
  [[nodiscard]] Epoch GetEpoch() const { return epoch_; }

  void Reset();
private:
  std::array<char, 8> uuid_ = {'\0'};
  ClockType type_ = ClockType::XCP_SLAVE_CLOCK;
  ClockReadability readability_ = ClockReadability::RANDOMLY_READABLE;
  Synchronization synchronization_ = Synchronization::SYN_UNSUPPORTED;
  uint8_t clock_quality_ = 0;
  std::optional<TimestampCharacteristic> characteristic_;
  uint64_t max_timestamp_value_before_wrap_around_ = 0;
  Epoch epoch_ = Epoch::UNIVERSAL_COORDINATED_TIME;

};

}


