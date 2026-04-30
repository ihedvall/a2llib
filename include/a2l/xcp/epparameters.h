/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>
#include <string>
#include <optional>

namespace a2l::xcp {

enum class UsbTransferType : uint8_t {
  BULK_TRANSFER = 2,
  INTERRUPT_TRANSFER = 3
};

enum class MessagePacking : uint8_t {
  MESSAGE_PACKING_SINGLE = 0,
  MESSAGE_PACKING_MULTIPLE = 1,
  MESSAGE_PACKING_STREAMING = 2
};

enum class UsbAlignment : uint8_t {
  ALIGNMENT_8_BIT = 0,
  ALIGNMENT_16_BIT = 1,
  ALIGNMENT_32_BIT = 2,
  ALIGNMENT_64_BIT = 3
};

class EpParameters {
public:
  void SetEndpointNumber(uint64_t endpoint_number) {
    endpoint_number_ = static_cast<uint8_t>(endpoint_number);
  }
  [[nodiscard]] uint8_t GetEndpointNumber() const { return endpoint_number_; }

  void SetTransferType(const std::string& transfer_type);
  [[nodiscard]] UsbTransferType GetTransferType() const { return transfer_type_; }

  void SetMaxPacketSize(uint64_t max_packet_size) {
    max_packet_size_ = static_cast<uint16_t>(max_packet_size);
  }
  [[nodiscard]] uint16_t GetMaxPacketSize() const { return max_packet_size_; }

  void SetInterval(uint64_t interval) {
    interval_ = static_cast<uint8_t>(interval);
  }
  [[nodiscard]] uint8_t GetInterval() const { return interval_; }

  void SetMessagePacking(const std::string& message_packing);
  [[nodiscard]] MessagePacking GetMessagePacking() const {
    return message_packing_;
  }

  void SetUsbAlignment(const std::string& usb_alignment);
  [[nodiscard]] UsbAlignment GetUsbAlignment() const { return alignment_; }

  void SetRecommendedHostBufsize(uint64_t recommended_host_bufsize) {
    recommended_host_bufsize_ = static_cast<uint16_t>(recommended_host_bufsize);
  }
  [[nodiscard]] const std::optional<uint16_t>& GetRecommendedHostBufsize() const {
    return recommended_host_bufsize_;
  }

  void Reset();
private:
  uint8_t endpoint_number_ = 0;
  UsbTransferType transfer_type_ = UsbTransferType::BULK_TRANSFER;
  uint16_t max_packet_size_ = 0;
  uint8_t interval_ = 0;
  MessagePacking message_packing_ = MessagePacking::MESSAGE_PACKING_SINGLE;
  UsbAlignment alignment_ = UsbAlignment::ALIGNMENT_8_BIT;
  std::optional<uint16_t> recommended_host_bufsize_;
};

}


