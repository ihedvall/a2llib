/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include "a2l/a2lobject.h"
#include <memory>
namespace a2l {
class Blob : public A2lObject {
 public:
  void Address(uint64_t address) { address_ = address; }
  [[nodiscard]] uint64_t Address() const { return address_; }

  void Size(uint64_t size) { size_ = size; }
  [[nodiscard]] uint64_t Size() const { return size_;}

  void AddressType(A2lAddressType type) { address_type_ = type; }
  [[nodiscard]] A2lAddressType AddressType() const { return address_type_;}

 private:
  uint64_t address_ = 0;
  uint64_t size_ = 0;

  A2lAddressType address_type_ = A2lAddressType::UNKNOWN;
};

using BlobList = std::map<std::string, std::unique_ptr<Blob>>;
} // end namespace a2l