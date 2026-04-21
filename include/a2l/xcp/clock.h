/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>
#include <optional>
#include <string>

#include "a2l/xcp/timestampcharacteristic.h"

namespace a2l::xcp {

enum class XcpClockType : uint8_t {
  XCP_SLAVE_CLOCK = 0,
  ECU_CLOCK = 1,
  XCP_SLAVE_GRANDMASTER_CLOCK = 2,
  ECU_GRANDMASTER_CLOCK = 3,
};

enum class XcpClockReadability : uint8_t {
  RANDOMLY_READABLE = 0,
  LIMITED_READABLE = 1,
  NOT_READABLE = 2,
};

enum class XcpSynchronization : uint8_t {
  SYN_UNSUPPORTED = 0,
  SYNCHRONIZATION_ONLY = 1,
  SYNTONIZATION_ONLY = 2,
  SYN_ALL = 3
};

enum class XcpEpoch : uint8_t {
  ATOMIC_TIME = 0,
  UNIVERSAL_COORDINATED_TIME = 1,
  ARBITRARY = 2
};

class Clock {
public:
private:
  std::string uuid_;
  XcpClockType type_ = XcpClockType::XCP_SLAVE_CLOCK;
  XcpClockReadability readability_ = XcpClockReadability::RANDOMLY_READABLE;
  XcpSynchronization synchronization_ = XcpSynchronization::SYN_UNSUPPORTED;
  uint8_t clock_quality_ = 0;
  std::optional<TimestampCharacteristic> characteristic_;
  uint64_t max_timestamp_value_before_wrap_around_ = 0;
  XcpEpoch epoch_ = XcpEpoch::UNIVERSAL_COORDINATED_TIME;

};

}


