/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>
#include <optional>
#include <vector>

#include "a2l/ccp/canparam.h"
#include "a2l/ccp/checksumparam.h"
#include "a2l/ccp/definedpages.h"

namespace a2l::ccp {

enum class SyncEdge : uint8_t {
  SINGLE = 0,
  DUAL = 1
};

enum class DaqMode : uint8_t {
  ALTERNATING = 0,
  BURST = 1
};

enum class Consistency : uint8_t {
  DAQ = 0,
  ODT = 1
};

enum class AddressExtension : uint8_t {
  DAQ = 0,
  ODT = 1
};

class TpBlob {
public:
  void SetVersion(uint64_t version) {
    version_ = static_cast<uint16_t>(version);
  }
  [[nodiscard]] uint16_t GetVersion() const { return version_; }
  [[nodiscard]] std::string GetVersionAsString() const;

  void SetBlobVersion(uint64_t blob_version) {
    blob_version_ = static_cast<uint16_t>(blob_version);
  }
  [[nodiscard]] uint16_t GetBlobVersion() const { return blob_version_; }
  [[nodiscard]] std::string GetBlobVersionAsString() const;

  void SetTransmitMessageId(uint64_t transmit_message_id) {
    transmit_message_id_ = static_cast<uint32_t>(transmit_message_id);
  }
  [[nodiscard]] uint32_t GetTransmitMessageId() const { return transmit_message_id_; }

  void SetReceiveMessageId(uint64_t receive_message_id) {
    receive_message_id_ = static_cast<uint32_t>(receive_message_id);
  }
  [[nodiscard]] uint32_t GetReceiveMessageId() const { return receive_message_id_; }

  void SetAddress(uint64_t address) {
    address_ = static_cast<uint16_t>(address);
  }
  [[nodiscard]] uint16_t GetAddress() const { return address_; }

  void SetByteOrder(uint64_t byte_order) {
    byte_order_ = static_cast<uint16_t>(byte_order);
  }
  [[nodiscard]] uint16_t GetByteOrder() const { return byte_order_; }

  void SetCanParam(const CanParam& can_param) {
    can_param_ = can_param;
  }
  [[nodiscard]] const CanParam* GetCanParam() const {
    return can_param_.has_value() ? &can_param_.value() : nullptr;
  }

  void SetBaudrate(uint64_t baudrate) {
    baudrate_ = static_cast<uint32_t>(baudrate);
  }
  [[nodiscard]] const std::optional<uint32_t>& GetBaudrate() const {
    return baudrate_;
  }

  void SetSamplePoint(uint64_t sample_point) {
    sample_point_ = static_cast<uint8_t>(sample_point);
  }
  [[nodiscard]] const std::optional<uint8_t>& GetSamplePoint() const {
    return sample_point_;
  }

  void SetSampleRate(uint64_t sample_rate) {
    sample_rate_ = static_cast<uint8_t>(sample_rate);
  }
  [[nodiscard]] const std::optional<uint8_t>& GetSampleRate() const {
    return sample_rate_;
  }

  void SetBtlCycles(uint64_t btl_cycles) {
    btl_cycles_ = static_cast<uint8_t>(btl_cycles);
  }
  [[nodiscard]] const std::optional<uint8_t>& GetBtlCycles() const {
    return btl_cycles_;
  }

  void SetSjw(uint64_t sjw) {
    sjw_ = static_cast<uint8_t>(sjw);
  }
  [[nodiscard]] const std::optional<uint8_t>& GetSjw() const {
    return sjw_;
  }

  void SetSyncEdge(uint64_t sync_edge) {
    sync_edge_ = static_cast<SyncEdge>(sync_edge);
  }
  void SetSyncEdge(const std::string& sync_edge);
  [[nodiscard]] const std::optional<SyncEdge>& GetSyncEdge() const {
    return sync_edge_;
  }

  void SetDaqMode(const std::string& daq_mode);
  [[nodiscard]] const std::optional<DaqMode>& GetDaqMode() const {
    return daq_mode_;
  }

  void SetBytesOnly() { bytes_only_ = true; }
  [[nodiscard]] bool GetBytesOnly() const { return bytes_only_; }

  void SetResumeSupported() { resume_supported_ = true; }
  [[nodiscard]] bool GetResumeSupported() const { return resume_supported_; }

  void SetStoreSupported() { store_supported_ = true; }
  [[nodiscard]] bool GetStoreSupported() const { return store_supported_; }

  void SetConsistency(const std::string& consistency);
  [[nodiscard]] const std::optional<Consistency>& GetConsistency() const {
    return consistency_;
  }

  void SetAddressExtension(const std::string& address_extension);
  [[nodiscard]] const std::optional<AddressExtension>& GetAddressExtension() const {
    return address_extension_;
  }

  void SetChecksumParam(const ChecksumParam& checksum_param) {
    checksum_param_ = checksum_param;
  }
  [[nodiscard]] const ChecksumParam* GetChecksumParam() const {
    return checksum_param_.has_value() ? &checksum_param_.value() : nullptr;
  }

  void AddDefinedPages(DefinedPages defined_pages) {
    defined_pages_list_.emplace_back(std::move(defined_pages));
  }
  [[nodiscard]] const std::vector<DefinedPages>& GetDefinedPages() const {
    return defined_pages_list_;
  }
  void AddOptionalCmd(uint64_t optional_cmd) {
    optional_cmd_list_.emplace_back(static_cast<uint16_t>(optional_cmd));
  }
  [[nodiscard]] const std::vector<uint16_t>& GetOptionalCmds() const {
    return optional_cmd_list_;
  }

  void Reset();


private:
  uint16_t version_ = 0;
  uint16_t blob_version_ = 0;
  uint32_t transmit_message_id_ = 0;
  uint32_t receive_message_id_ = 0;
  uint16_t address_ = 0;
  uint16_t byte_order_ = 2;

  std::optional<CanParam> can_param_;
  std::optional<uint32_t> baudrate_;
  std::optional<uint8_t> sample_point_;
  std::optional<uint8_t> sample_rate_;
  std::optional<uint8_t> btl_cycles_;
  std::optional<uint8_t> sjw_;
  std::optional<SyncEdge> sync_edge_;
  std::optional<DaqMode> daq_mode_;
  bool bytes_only_ = false;
  bool resume_supported_ = false;
  bool store_supported_ = false;
  std::optional<Consistency> consistency_;
  std::optional<AddressExtension> address_extension_;
  std::optional<ChecksumParam> checksum_param_;
  std::vector<DefinedPages> defined_pages_list_;
  std::vector<uint16_t> optional_cmd_list_;
};

}  // namespace a2l::ccp


