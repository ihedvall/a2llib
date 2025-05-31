/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once
#include <map>
#include <memory>
#include <string>
#include <cstdint>
#include <vector>

#include "a2l/a2lobject.h"


namespace a2l {

class Measurement : public A2lObject {
 public:
  void DataType(A2lDataType type) { data_type_ = type; }
  [[nodiscard]] A2lDataType DataType() const { return data_type_; }

  void Conversion(const std::string& conversion) { conversion_ = conversion; }
  [[nodiscard]] const std::string& Conversion() const { return conversion_; }

  void Resolution(uint64_t resolution) { resolution_ = resolution; }
  [[nodiscard]] uint64_t Resolution() const { return resolution_; }

  void Accuracy(double accuracy) { accuracy_ = accuracy; }
  [[nodiscard]] double Accuracy() const { return accuracy_; }

  void LowerLimit(double limit) { lower_limit_ = limit; }
  [[nodiscard]] double LowerLimit() const { return lower_limit_; }

  void UpperLimit(double limit) { upper_limit_ = limit; }
  [[nodiscard]] double UpperLimit() const { return upper_limit_; }

  void AddressType(A2lAddressType type) { address_type_ = type; }
  [[nodiscard]] A2lAddressType AddressType() const { return address_type_; }

  void ArraySize(uint64_t size) { array_size_ = size; }
  [[nodiscard]] uint64_t ArraySize() const { return array_size_; }

  void BitMask(uint64_t mask) { bit_mask_ = mask; }
  [[nodiscard]] uint64_t BitMask() const { return bit_mask_; }

  void BitOperation(const A2lBitOperation& operation) {
    bit_operation_ = operation;
  }
  [[nodiscard]] const A2lBitOperation& BitOperation() const {
    return bit_operation_;
  }

  void EcuAddress(uint64_t address) { ecu_address_ = address; }
  [[nodiscard]] uint64_t EcuAddress() const { return ecu_address_; }

  void ErrorMask(uint64_t mask) { error_mask_ = mask; }
  [[nodiscard]] uint64_t ErrorMask() const { return error_mask_; }

  void Layout(A2lLayout layout) { layout_ = layout; }
  [[nodiscard]] A2lLayout Layout() const { return layout_; }

  void ReadWrite(bool read_write) { read_write_ = read_write; }
  [[nodiscard]] bool ReadWrite() const { return read_write_; }

  void Virtuals(const std::vector<std::string>& list) {
    virtual_list_ = list;
  }
  [[nodiscard]] const std::vector<std::string>& Virtuals() const {
    return virtual_list_;
  }

 private:
  A2lDataType data_type_ = A2lDataType::UNKNOWN;
  std::string conversion_;
  uint64_t resolution_ = 0;
  double accuracy_ = 0.0;
  double lower_limit_ = 0.0;
  double upper_limit_ = 0.0;
  A2lAddressType address_type_ = A2lAddressType::UNKNOWN;
  uint64_t array_size_ = 0;
  uint64_t bit_mask_ = 0;
  A2lBitOperation bit_operation_ = {};
  uint64_t ecu_address_ = 0;
  uint64_t error_mask_ = 0;
  A2lLayout layout_ = A2lLayout::UNKNOWN;
  bool read_write_ = false;
  std::vector<std::string> virtual_list_;
};

using MeasurementList = std::map<std::string, std::unique_ptr<Measurement>>;
}
