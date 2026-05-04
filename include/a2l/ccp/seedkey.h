/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include <string>

namespace a2l::ccp {

class SeedKey {
public:
  void SetCalDll(std::string cal_dll) { cal_dll_ = std::move(cal_dll); }
  [[nodiscard]] const std::string& GetCalDll() const { return cal_dll_; }

  void SetDaqDll(std::string daq_dll) { daq_dll_ = std::move(daq_dll); }
  [[nodiscard]] const std::string& GetDaqDll() const { return daq_dll_; }

  void SetPgmDll(std::string pgm_dll) { pgm_dll_ = std::move(pgm_dll); }
  [[nodiscard]] const std::string& GetPgmDll() const { return pgm_dll_; }
private:
  std::string cal_dll_;
  std::string daq_dll_;
  std::string pgm_dll_;
};

}  // namespace a2l::ccp

