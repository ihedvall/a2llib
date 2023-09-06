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
#include "a2l/recordlayout.h"
#include "a2l/transformer.h"
#include "a2l/structure.h"
#include "a2l/unit.h"

namespace a2l {

class Module : public A2lObject {
 public:
  [[nodiscard]] A2lModCommon& ModCommon() { return mod_common_; }
  [[nodiscard]] const A2lModCommon& ModCommon() const  { return mod_common_; }

  [[nodiscard]] A2lModPar& ModPar() { return mod_par_; }
  [[nodiscard]] const A2lModPar& ModPar() const  { return mod_par_; }

  [[nodiscard]] A2lVariantCoding& VariantCoding() { return variant_coding_; }
  [[nodiscard]] const A2lVariantCoding& VariantCoding() const  {
    return variant_coding_;
  }
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

  void AddRecordLayout(std::unique_ptr<RecordLayout>& record_layout);
  [[nodiscard]] const RecordLayoutList& RecordLayouts() const {
    return record_layout_list_;
  }

  void AddTransformer(std::unique_ptr<Transformer>& transformer);
  [[nodiscard]] const TransformerList& Transformers() const {
    return transformer_list_;
  }

  void AddTypedefAxis(std::unique_ptr<AxisPts>& axis);
  [[nodiscard]] const AxisPtsList& TypedefAxiss() { return typedef_axis_list_; }

  void AddTypedefBlob(std::unique_ptr<Blob>& blob);
  [[nodiscard]] const BlobList& TypedefBlobs() { return typedef_blob_list_; }

  void AddTypedefCharacteristic(std::unique_ptr<Characteristic>&
      characteristic);
  [[nodiscard]] const CharacteristicList& TypedefCharacteristics() {
    return typedef_characteristic_list_;
  }

  void AddTypedefMeasurement(std::unique_ptr<Measurement>& measurement);
  [[nodiscard]] const MeasurementList& TypedefMeasurements() {
    return typedef_measurement_list_;
  }

  void AddTypedefStructure(std::unique_ptr<Structure>& structure);
  [[nodiscard]] const StructureList& TypedefStructures() {
    return typedef_structure_list_;
  }

  void AddUnit(std::unique_ptr<Unit>& unit);
  [[nodiscard]] const UnitList& Units() {
    return unit_list_;
  }

  void AddUserRight(std::unique_ptr<A2lUserRight>& user_right);
  [[nodiscard]] const UserRightList& UserRights() {
    return user_right_list_;
  }

 private:
  A2lModCommon mod_common_ = {};
  A2lModPar mod_par_ = {};
  A2lVariantCoding variant_coding_ = {};
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
  RecordLayoutList record_layout_list_;
  TransformerList transformer_list_;
  AxisPtsList typedef_axis_list_;
  BlobList typedef_blob_list_;
  CharacteristicList typedef_characteristic_list_;
  MeasurementList typedef_measurement_list_;
  StructureList typedef_structure_list_;
  UnitList unit_list_;
  UserRightList user_right_list_;
};

}  // namespace a2l
