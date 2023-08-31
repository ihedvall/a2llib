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
#include "a2l/compumethod.h"
#include "a2l/computab.h"
#include "a2l/compuvtab.h"
#include "a2l/compuvtabrange.h"
#include "a2l/frame.h"
#include "a2l/function.h"
#include "a2l/group.h"
#include "a2l/instance.h"
#include "a2l/measurement.h"

namespace a2l {

class Module : public A2lObject {
 public:
  void A2ml(const std::string& a2ml) { a2ml_ = a2ml; }
  [[nodiscard]] const std::string& A2ml() const { return a2ml_;}

  void AddAxisPts(std::unique_ptr<AxisPts>& axis_pts);
  [[nodiscard]] const AxisPtsList& AxisPtss() { return axis_pts_list_; }

  void AddBlob(std::unique_ptr<Blob>& blob);
  [[nodiscard]] const BlobList& Blobs() const { return blob_list_; }

  void AddCharacteristic(std::unique_ptr<Characteristic>& characteristic);
  [[nodiscard]] const CharacteristicList& Characteristics() const {
    return characteristic_list_;
  }

  void AddCompuMethod(std::unique_ptr<CompuMethod>& method);
  [[nodiscard]] const CompuMethodList& CompuMethods() const {
    return compu_method_list_;
  }

  void AddCompuTab(std::unique_ptr<CompuTab>& tab);
  [[nodiscard]] const CompuTabList& CompuTabs() const {
    return compu_tab_list_;
  }

  void AddCompuVtab(std::unique_ptr<CompuVtab>& tab);
  [[nodiscard]] const CompuVtabList& CompuVtabs() const {
    return compu_vtab_list_;
  }

  void AddCompuVtabRange(std::unique_ptr<CompuVtabRange>& tab);
  [[nodiscard]] const CompuVtabRangeList& CompuVtabRanges() const {
    return compu_vtab_range_list_;
  }

  void AddFrame(std::unique_ptr<Frame>& frame);
  [[nodiscard]] const FrameList& Frames() const {
    return frame_list_;
  }

  void AddFunction(std::unique_ptr<Function>& func);
  [[nodiscard]] const FuncList& Functions() const {
    return function_list_;
  }

  void AddGroup(std::unique_ptr<Group>& group);
  [[nodiscard]] const GroupList& Groups() const {
    return group_list_;
  }

  void AddInstance(std::unique_ptr<Instance>& instance);
  [[nodiscard]] const InstanceList& Instances() const {
    return instance_list_;
  }

  void AddMeasurement(std::unique_ptr<Measurement>& measurement);
  [[nodiscard]] const MeasurementList& Measurements() const {
    return measurement_list_;
  }

 private:
  std::string a2ml_;
  AxisPtsList axis_pts_list_;
  BlobList blob_list_;
  CharacteristicList characteristic_list_;
  CompuMethodList compu_method_list_;
  CompuTabList compu_tab_list_;
  CompuVtabList compu_vtab_list_;
  CompuVtabRangeList compu_vtab_range_list_;
  FrameList frame_list_;
  FuncList function_list_;
  GroupList group_list_;
  InstanceList instance_list_;
  MeasurementList measurement_list_;
};

}  // namespace a2l
