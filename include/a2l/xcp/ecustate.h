/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
#pragma once

#include <cstdint>

#include <string>
#include <vector>

#include "a2l/xcp/memoryaccess.h"

namespace a2l::xcp {

enum class CalPagResource : uint8_t {
  NOT_ACTIVE = 0,
  ACTIVE = 1,
  GETTER_ONLY = 2,
};

enum class DaqResource : uint8_t {
  NOT_ACTIVE = 0,
  ACTIVE = 1,
};

enum class StimResource : uint8_t {
  NOT_ACTIVE = 0,
  ACTIVE = 1,
};

enum class PgmResource : uint8_t {
  NOT_ACTIVE = 0,
  ACTIVE = 1,
};

using MemoryAccessList = std::vector<MemoryAccess>;

class EcuState {
public:
  void SetNumber(uint64_t number) {
    number_ = static_cast<uint8_t>(number);
  }
  [[nodiscard]] uint8_t GetNumber() const { return number_; }

  void SetName(std::string name) { name_ = std::move(name); }
  [[nodiscard]] const std::string& GetName() const { return name_; }

  void SetEcuSwithedToDefaultPage(bool value) {
    ecu_swithed_to_default_page_ = value;
  }
  [[nodiscard]] bool GetEcuSwithedToDefaultPage() const {
    return ecu_swithed_to_default_page_;
  }

  void SetCalPagResource(const std::string& resource);
  [[nodiscard]] CalPagResource GetCalPagResource() const {
    return cal_pag_resource_;
  }

  void SetDaqResource(const std::string& resource);
  [[nodiscard]] DaqResource GetDaqResource() const { return daq_resource_; }

  void SetPgmResource(const std::string& resource);
  [[nodiscard]] PgmResource GetPgmResource() const { return pgm_resource_; }

  void SetStimResource(const std::string& resource);
  [[nodiscard]] StimResource GetStimResource() const { return stim_resource_; }

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
  CalPagResource cal_pag_resource_ = CalPagResource::NOT_ACTIVE;
  DaqResource daq_resource_ = DaqResource::NOT_ACTIVE;
  StimResource stim_resource_ = StimResource::NOT_ACTIVE;
  PgmResource pgm_resource_ = PgmResource::NOT_ACTIVE;
  std::vector<MemoryAccess> resource_list_;
};

};





