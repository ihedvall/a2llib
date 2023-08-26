/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#pragma once


#include "a2l/a2lobject.h"
#include "a2l/a2lstructs.h"
#include "a2l/axisdescr.h"
#include "a2l/axispts.h"
#include "a2l/blob.h"
#include "a2l/characteristic.h"
namespace a2l {

class Module : public A2lObject {
 public:
  void A2ml(const std::string& a2ml) { a2ml_ = a2ml; }
  [[nodiscard]] const std::string& A2ml() const { return a2ml_;}

  void AddAxisPts(std::unique_ptr<AxisPts>& axis_pts);
  [[nodiscard]] const AxisPtsList& AxisPtss() { return axis_pts_list_; }

  void AddBlob(std::unique_ptr<Blob>& blob);
  [[nodiscard]] const BlobList& Blobs() { return blob_list_; }

  void AddCharacteristic(std::unique_ptr<Characteristic>& characteristic);
  [[nodiscard]] const CharacteristicList& Characteristics() {
    return characteristic_list_;
  }
 private:
  std::string a2ml_;
  AxisPtsList axis_pts_list_;
  BlobList blob_list_;
  CharacteristicList characteristic_list_;
};

}  // namespace a2l
