/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
#pragma once

#include <cstdint>
#include <set>
#include <string>
#include <vector>

#include "a2l/xcp/memoryaccess.h"

namespace a2l::xcp {

enum class XcpCalPagResource : uint8_t {
  NOT_ACTIVE = 0,
  ACTIVE = 1,
  GETTER_ONLY = 2,
};

enum class XcpDaqResource : uint8_t {
  NOT_ACTIVE = 0,
  ACTIVE = 1,
};

enum class XcpStimResource : uint8_t {
  NOT_ACTIVE = 0,
  ACTIVE = 1,
};

enum class XcpPgmResource : uint8_t {
  NOT_ACTIVE = 0,
  ACTIVE = 1,
};

using MemoryAccessList = std::vector<MemoryAccess>;

class EcuState {
public:
  void Number(uint8_t number) { number_ = number; }
  [[nodiscard]] uint8_t Number() const { return number_; }

  void Name(std::string name) { name_ = std::move(name); }
  [[nodiscard]] const std::string& Name() const { return name_; }

  void EcuSwithedToDefaultPage(bool value) { ecu_swithed_to_default_page_ = value; }
  [[nodiscard]] bool EcuSwithedToDefaultPage() const { return ecu_swithed_to_default_page_; }

  void CalPagResource(const std::string& resource);
  [[nodiscard]] XcpCalPagResource CalPagResource() const { return cal_pag_resource_; }

  void DaqResource(const std::string& resource);
  [[nodiscard]] XcpDaqResource DaqResource() const { return daq_resource_; }

  void PgmResource(const std::string& resource);
  [[nodiscard]] XcpPgmResource PgmResource() const { return pgm_resource_; }

  void StimResource(const std::string& resource);
  [[nodiscard]] XcpStimResource StimResource() const { return stim_resource_; }

  void SetMemoryAccessList(MemoryAccessList list) {
    resource_list_ = std::move(list);
  }
  [[nodiscard]] const std::vector<MemoryAccess>& GetMemoryAccessList() const {
    return resource_list_;
  }
private:
  uint8_t number_ = 0;
  std::string name_;
  bool ecu_swithed_to_default_page_ = false;
  XcpCalPagResource cal_pag_resource_ = XcpCalPagResource::NOT_ACTIVE;
  XcpDaqResource daq_resource_ = XcpDaqResource::NOT_ACTIVE;
  XcpStimResource stim_resource_ = XcpStimResource::NOT_ACTIVE;
  XcpPgmResource pgm_resource_ = XcpPgmResource::NOT_ACTIVE;
  std::vector<MemoryAccess> resource_list_;

};

};





