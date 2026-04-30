/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#include "a2l/xcp/epparameters.h"

#include <array>
#include <string_view>

namespace a2l::xcp {

void EpParameters::SetTransferType(const std::string& transfer_type) {
  constexpr std::array<std::string_view, 2> kTypeList = {
    "BULK_TRANSFER",
    "INTERRUPT_TRANSFER"
  };
  for (size_t index = 0; index < kTypeList.size(); ++index) {  
    if (transfer_type == kTypeList[index]) {
      constexpr size_t kOffset = 2;
      transfer_type_ = static_cast<UsbTransferType>(index + kOffset);
      break;
    }
  }
}

void EpParameters::SetMessagePacking(const std::string& message_packing) {
  constexpr std::array<std::string_view, 3> kMessagePackingList = {
    "MESSAGE_PACKING_SINGLE",
    "MESSAGE_PACKING_MULTIPLE",
    "MESSAGE_PACKING_STREAMING"
  };
  for (size_t index = 0; index < kMessagePackingList.size(); ++index) {
    if (message_packing == kMessagePackingList[index]) {
      message_packing_ = static_cast<MessagePacking>(index);
      break;
    }
  }
}

void EpParameters::SetUsbAlignment(const std::string& usb_alignment) {
  constexpr std::array<std::string_view, 4> kUsbAlignmentList = {
    "ALIGNMENT_8_BIT",
    "ALIGNMENT_16_BIT",
    "ALIGNMENT_32_BIT",
    "ALIGNMENT_64_BIT"
  };
  for (size_t index = 0; index < kUsbAlignmentList.size(); ++index) {
    if (usb_alignment == kUsbAlignmentList[index]) {
      alignment_ = static_cast<UsbAlignment>(index);
      break;
    }
  }
}

void EpParameters::Reset() {
  endpoint_number_ = 0;
  transfer_type_ = UsbTransferType::BULK_TRANSFER;
  max_packet_size_ = 0;
  interval_ = 0;
  message_packing_ = MessagePacking::MESSAGE_PACKING_SINGLE;
  alignment_ = UsbAlignment::ALIGNMENT_8_BIT;
  recommended_host_bufsize_.reset();
}

}  // namespace a2l::xcp