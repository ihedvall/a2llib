/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include "a2l/a2lobject.h"
#include <map>
#include <memory>
#include "a2l/a2lstructs.h"
namespace a2l {

class Structure : public A2lObject {
 public:
  void Size(uint64_t size) { size_ = size; }
  [[nodiscard]] uint64_t Size() const { return size_; }

  void AddressType(A2lAddressType type) { address_type_ = type; }
  [[nodiscard]] A2lAddressType AddressType() const { return address_type_; }

  void ConsistentExchange(bool value) { consistent_exchange_ = value; }
  [[nodiscard]] bool ConsistentExchange() const { return consistent_exchange_; }

  void AddStructureComponent(std::unique_ptr<A2lStructureComponent>&
      component) {
    structure_component_list_.emplace(component->Name, std::move(component));
  }
  [[nodiscard]] const StructureComponentList& StructureComponents() const {
    return structure_component_list_;
  }

  void SymbolTypeLink(const std::string& link) { symbol_type_link_ = link; }
  [[nodiscard]] const std::string& SymbolTypeLink() const {
    return symbol_type_link_; }

 private:
  uint64_t size_ = 0;
  A2lAddressType address_type_ = A2lAddressType::DIRECT;
  bool consistent_exchange_ = false;
  StructureComponentList structure_component_list_;
  std::string symbol_type_link_;

};

using StructureList = std::map<std::string, std::unique_ptr<Structure>>;
} // end namespace
