/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include "a2l/a2lobject.h"
#include <map>
#include <memory>
#include "a2l/overwrite.h"

namespace a2l {
class Instance : public A2lObject {
 public:
  void RefTypeDef(const std::string& type) { ref_type_def_ = type; }
  [[nodiscard]] const std::string& RefTypeDef() const {
    return ref_type_def_;
  }

  void Address(uint64_t address) { address_ = address; }
  [[nodiscard]] uint64_t Address() const { return address_; }

  void AddressType(A2lAddressType type) { address_type_ = type; }
  [[nodiscard]] A2lAddressType AddressType() const { return address_type_; }

  void Layout(A2lLayout layout) { layout_ = layout; }
  [[nodiscard]] A2lLayout Layout() const { return layout_; }

  void AddOverwrite(std::unique_ptr<Overwrite>& overwrite);
  [[nodiscard]] const OverwriteList& Overwrites() const {
    return overwrite_list_;
  }
  void ReadWrite(bool read_write) { read_write_ = read_write; }
  [[nodiscard]] bool ReadWrite() const { return read_write_; }
 private:
  std::string ref_type_def_;
  uint64_t address_ = 0;
  A2lAddressType address_type_ = A2lAddressType::UNKNOWN;
  A2lLayout layout_ = A2lLayout::UNKNOWN;
  OverwriteList overwrite_list_;
  bool read_write_ = false;
};

using InstanceList = std::map< std::string, std::unique_ptr<Instance>>;

} // end namespace a2l