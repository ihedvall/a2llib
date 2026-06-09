/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2l/ccp/qpblob.h"

namespace {
  constexpr uint32_t kCanIdMask = 0x1FFFFFFF;

}
namespace a2l::ccp {

std::optional<uint32_t> QpBlob::GetCanIdFixed() const {
  if (can_id_fixed_.has_value()) {
    return kCanIdMask & can_id_fixed_.value();
  }
  return can_id_fixed_;
}

const std::optional<uint32_t>& QpBlob::GetMessageIdFixed() const {
  return can_id_fixed_;
}

void QpBlob::Reset() {
  number_ = 0;
  length_.reset();
  can_id_variable_ = false;
  can_id_fixed_.reset();
  raster_list_.clear();
  exclusive_list_.clear();
  reduction_allowed_ = false;
  first_pid_.reset();
}
} // a2l::ccp