/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#include "a2l/xcp/clock.h"

namespace a2l::xcp {

void Clock::SetUuid(int64_t uuid, size_t offset) {
  if (offset <= uuid_.size()) {
    uuid_[offset] = static_cast<char>(uuid);
  }
}

std::string Clock::GetUuid() const {
  return std::string(uuid_.cbegin(), uuid_.cend());
}

void Clock::SetType(const std::string& type) {
  constexpr std::array<std::string_view, 4> kTypeList ={
    "XCP_SLAVE_CLOCK",
    "ECU_CLOCK",
    "XCP_SLAVE_GRANDMASTER_CLOCK",
    "ECU_GRANDMASTER_CLOCK"
  };
  for (size_t index = 0; index < kTypeList.size(); ++index) {
    if (type == kTypeList[index]) {
      type_ = static_cast<ClockType>(index);
      break;
    }
  }
}

void Clock::SetReadability(const std::string& readability) {
  constexpr std::array<std::string_view, 3> kReadabilityList = {
    "RANDOMLY_READABLE",
    "LIMITED_READABLE",
    "NOT_READABLE"
  };
  for (size_t index = 0; index < kReadabilityList.size(); ++index) {
    if (readability == kReadabilityList[index]) {
      readability_ = static_cast<ClockReadability>(index);
      break;
    }
  }

  }
void Clock::SetSynchronization(const std::string& synchronization) {
  constexpr std::array<std::string_view, 4> kSynchronizationList = {
    "SYN_UNSUPPORTED",
    "SYNCHRONIZATION_ONLY",
    "SYNTONIZATION_ONLY",
    "SYN_ALL"
   };
  for (size_t index = 0; index < kSynchronizationList.size(); ++index) {
    if (synchronization == kSynchronizationList[index]) {
      synchronization_ = static_cast<Synchronization>(index);
      break;
    }
  }
}

void Clock::SetEpoch(const std::string& epoch) {
  constexpr std::array<std::string_view, 3> kEpochList = {
    "ATOMIC_TIME",
    "UNIVERSAL_COORDINATED_TIME",
    "ARBITRARY"
  };
  for (size_t index = 0; index < kEpochList.size(); ++index) {
    if (epoch == kEpochList[index]) {
      epoch_ = static_cast<Epoch>(index);
      break;
    }
  }
}

void Clock::Reset() {
  uuid_.fill(0);
  type_ = ClockType::XCP_SLAVE_CLOCK;
  readability_ = ClockReadability::RANDOMLY_READABLE;
  synchronization_ = Synchronization::SYN_UNSUPPORTED;
  clock_quality_ = 0;
  characteristic_.reset();
  max_timestamp_value_before_wrap_around_ = 0;
  epoch_ = Epoch::UNIVERSAL_COORDINATED_TIME;
};

}  // namespace a2l::xcp
