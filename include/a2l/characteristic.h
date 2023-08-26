/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include "a2l/a2lobject.h"
#include <memory>
#include "a2l/a2lenums.h"
#include "a2l/axisdescr.h"
namespace a2l {

class Characteristic : public A2lObject {
 public:
  void BitMask(uint64_t mask) { bit_mask_ = mask; }
  [[nodiscard]] uint64_t BitMask() const { return bit_mask_; }

  void ComparisonQuantity(const std::string& quantity) {
    comparison_quantity_ = quantity;
  }
  [[nodiscard]] const std::string& ComparisonQuantity() const {
    return comparison_quantity_;
  }

  void DependentCharacteristic(const A2lDependentCharacteristic& dependent) {
    dependent_characteristic_ = dependent;
  }
  [[nodiscard]] const A2lDependentCharacteristic& DependentCharacteristic()
      const { return dependent_characteristic_;
  }

  void Encoding(A2lEncoding encoding) { encoding_ = encoding;  }
  [[nodiscard]] A2lEncoding Encoding() const { return encoding_; }

  void MapList(const std::vector<std::string>& list) { map_list_ = list; }
  [[nodiscard]] const std::vector<std::string>& MapList() const {
    return map_list_;
  }

  void Number(uint64_t number) { number_ = number; }
  [[nodiscard]] uint64_t Number() const { return number_; }

  void Type(A2lCharacteristicType type) { type_ = type; }
  [[nodiscard]] A2lCharacteristicType Type() const { return type_; }

  void VirtualCharacteristic(const A2lDependentCharacteristic& virt) {
    virtual_characteristic_ = virt;
  }
  [[nodiscard]] const A2lDependentCharacteristic& VirtualCharacteristic()
      const { return virtual_characteristic_;
  }
  void AddAxisDescr(std::unique_ptr<AxisDescr>& axis_descr);
  [[nodiscard]] const AxisDescrList& AxisPtss() { return axis_descr_list_; }

 private:
  A2lCharacteristicType type_ = A2lCharacteristicType::UNKNOWN;
  AxisDescrList axis_descr_list_;
  uint64_t bit_mask_ = 0;
  std::string comparison_quantity_;
  A2lDependentCharacteristic dependent_characteristic_ = {};
  A2lEncoding encoding_ = A2lEncoding::ASCII;
  std::vector<std::string> map_list_;
  uint64_t number_ = 0;
  A2lDependentCharacteristic virtual_characteristic_ = {};
};

using CharacteristicList = std::map<std::string,
                                    std::unique_ptr<Characteristic>>;
} // end namespace a2l
