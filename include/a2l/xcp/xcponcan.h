/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <cstdint>
#include <string>
#include <optional>
#include "a2l/xcp/protocol.h"

namespace a2l::xcp {

enum class CanSampleRate : uint8_t {
  SINGLE = 1,
  TRIPLE = 3
};

enum class CanSyncEdge : uint8_t {
  SINGLE = 1,
  DUAL = 2
};

enum class TransceiverDelayCompensation : uint8_t {
  OFF = 0,
  ON = 1
};

enum class CanSubCmd : uint8_t {
  GET_SLAVE_ID = 0xFF,
  GET_DAQ_ID = 0xFE,
  SET_DAQ_ID = 0xFD,
  GET_DAQ_CLOCK_MULTICAST = 0xFA
};

struct DaqListCanId {
  uint16_t number = 0;
  bool variable = false;
  uint32_t fixed = 0;
  void Reset() {
    number = 0;
    variable = false;
    fixed = 0;
  }
};

struct EventCanIdList {
  uint16_t number = 0;
  std::vector<uint32_t> fixed_list;
  void Reset() {
    number = 0;
    fixed_list.clear();
  }
};

struct CanFd {
  std::optional<uint16_t> max_dlc;
  std::optional<uint32_t> baudrate;
  std::optional<uint8_t> sample_point;
  std::optional<uint8_t> btl_cycles;
  std::optional<uint8_t> sjw;
  std::optional<CanSyncEdge> sync_edge;
  bool max_dlc_required = false;
  std::optional<uint8_t> secondary_sample_point;
  std::optional<TransceiverDelayCompensation> transceiver_delay_compensation;

  void SetSyncEdge(const std::string& tdc);
  void SetTransceiverDelayCompensation(const std::string& tdc);
  void Reset();
};

class XcpOnCan : public Protocol {
public:
  void SetVersion(uint64_t version) { version_ = static_cast<uint16_t>(version); }
  [[nodiscard]] uint16_t GetVersion() const { return version_; }
  [[nodiscard]] std::string GetVersionAsString() const;

  void SetCanIdBroadcast(uint64_t can_id_broadcast) {
    can_id_broadcast_ = static_cast<uint32_t>(can_id_broadcast);
  }
  [[nodiscard]] const std::optional<uint32_t>& GetCanIdBroadcast() const {
    return can_id_broadcast_;
  }

  void SetCanIdMaster(uint64_t can_id_master) {
    can_id_master_ = static_cast<uint32_t>(can_id_master);
  }
  [[nodiscard]] const std::optional<uint32_t>& GetCanIdMaster() const {
    return can_id_master_;
  }

  void SetCanIdMasterIncremental() {
    can_id_master_incremental_ = true;
  }
  [[nodiscard]] bool GetCanIdMasterIncremental() const {
    return can_id_master_incremental_;
  }

  void SetCanIdSlave(uint64_t can_id_slave) {
    can_id_slave_ = static_cast<uint32_t>(can_id_slave);
  }
  [[nodiscard]] const std::optional<uint32_t>& GetCanIdSlave() const {
    return can_id_slave_;
  }

  void SetCanIdGetDaqClockMulticast(uint64_t can_id_get_daq_clock_multicast) {
    can_id_get_daq_clock_multicast_ = static_cast<uint32_t>(can_id_get_daq_clock_multicast);
  }
  [[nodiscard]] const std::optional<uint32_t>& GetCanIdGetDaqClockMulticast() const {
    return can_id_get_daq_clock_multicast_;
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

  void SetSampleRate(const std::string& sample_rate);
  [[nodiscard]] const std::optional<CanSampleRate>& GetSampleRate() const {
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

  void SetSyncEdge(const std::string& sync_edge);
  [[nodiscard]] const std::optional<CanSyncEdge>& GetSyncEdge() const {
    return sync_edge_;
  }

  void SetMaxDlcRequired() {
    max_dlc_required_ = true;
  }
  [[nodiscard]] bool GetMaxDlcRequired() const {
    return max_dlc_required_;
  }

  void AddSubCmd(const std::string& cmd);
  [[nodiscard]] const std::vector<CanSubCmd>& GetSubCmdList() const {
    return optional_tl_subcmd_list_;
  }
  void AddDaqList() {
    daq_list_can_id_list_.emplace_back(current_daq_list_);
    current_daq_list_.Reset();
  }
  DaqListCanId& GetCurrentDaqList() { return current_daq_list_; }

  void AddCanIdEventList(EventCanIdList list) {
    event_can_id_list_.emplace_back(std::move(list));
  }
  [[nodiscard]] const std::vector<EventCanIdList>& GetCanIdEventList() const {
    return event_can_id_list_;
  }

  void SetMaxBusLoad(uint64_t max_bus_load) {
    max_bus_load_ = static_cast<uint32_t>(max_bus_load);
  }
  [[nodiscard]] const std::optional<uint32_t>& GetMaxBusLoad() const {
    return max_bus_load_;
  }

  void SetMeasurementSplitAllowed() {
    measurement_split_allowed_ = true;
  }
  [[nodiscard]] bool GetMeasurementSplitAllowed() const {
    return measurement_split_allowed_;
  }

  void SetCanFd() {
    can_fd_ = current_fd_;
    current_fd_.Reset();
  }
  [[nodiscard]] const std::optional<CanFd>& GetCanFd() const {
    return can_fd_;
  }

  CanFd& GetCurrentFd() { return current_fd_; }

  void Reset() override;
private:
  uint16_t version_ = 0;
  std::optional<uint32_t> can_id_broadcast_;
  std::optional<uint32_t> can_id_master_;
  bool can_id_master_incremental_ = false;
  std::optional<uint32_t> can_id_slave_;
  std::optional<uint32_t> can_id_get_daq_clock_multicast_;
  std::optional<uint32_t> baudrate_;
  std::optional<uint8_t> sample_point_;
  std::optional<CanSampleRate> sample_rate_;
  std::optional<uint8_t> btl_cycles_;
  std::optional<uint8_t> sjw_;
  std::optional<CanSyncEdge> sync_edge_;
  bool max_dlc_required_ = false;
  std::vector<DaqListCanId> daq_list_can_id_list_;
  std::vector<EventCanIdList> event_can_id_list_;
  std::optional<uint32_t> max_bus_load_;
  bool measurement_split_allowed_ = false;
  std::optional<CanFd> can_fd_;
  std::vector<CanSubCmd> optional_tl_subcmd_list_;

  CanFd current_fd_;
  DaqListCanId current_daq_list_;
};

}  // namespace a2l::xcp



