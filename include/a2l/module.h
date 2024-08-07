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
  [[nodiscard]] AxisPtsList& AxisPtss() { return axis_pts_list_; }
  [[nodiscard]] const AxisPtsList& AxisPtss() const  { return axis_pts_list_; }
  [[nodiscard]] AxisPts* GetAxisPts(const std::string& name);

  void AddBlob(std::unique_ptr<Blob>& blob);
  [[nodiscard]] BlobList& Blobs() { return blob_list_; }
  [[nodiscard]] const BlobList& Blobs() const { return blob_list_; }
  [[nodiscard]] Blob* GetBlob(const std::string& name);

  void AddCharacteristic(std::unique_ptr<Characteristic>& characteristic);
  [[nodiscard]] CharacteristicList& Characteristics() {
    return characteristic_list_;
  }
  [[nodiscard]] const CharacteristicList& Characteristics() const {
    return characteristic_list_;
  }
  [[nodiscard]] Characteristic* GetCharacteristic(const std::string& name);

  void AddCompuMethod(std::unique_ptr<CompuMethod>& method);
  [[nodiscard]] CompuMethodList& CompuMethods() {
    return compu_method_list_;
  }
  [[nodiscard]] const CompuMethodList& CompuMethods() const {
    return compu_method_list_;
  }

  void AddCompuTab(std::unique_ptr<CompuTab>& tab);
  [[nodiscard]] CompuTabList& CompuTabs() {
    return compu_tab_list_;
  }
  [[nodiscard]] const CompuTabList& CompuTabs() const {
    return compu_tab_list_;
  }
  [[nodiscard]] CompuTab* GetCompuTab(const std::string& name);

  void AddCompuVtab(std::unique_ptr<CompuVtab>& tab);
  [[nodiscard]] CompuVtabList& CompuVtabs() {
    return compu_vtab_list_;
  }
  [[nodiscard]] const CompuVtabList& CompuVtabs() const {
    return compu_vtab_list_;
  }
  [[nodiscard]] CompuVtab* GetCompuVtab(const std::string& name);


  void AddCompuVtabRange(std::unique_ptr<CompuVtabRange>& tab);
  [[nodiscard]] CompuVtabRangeList& CompuVtabRanges() {
    return compu_vtab_range_list_;
  }
  [[nodiscard]] const CompuVtabRangeList& CompuVtabRanges() const {
    return compu_vtab_range_list_;
  }
  [[nodiscard]] CompuVtabRange* GetCompuVtabRange(const std::string& name);

  void AddControllerAddress(A2lControllerAddress controller_address) {
    controller_address_list_.emplace_back(controller_address);
  }
  [[nodiscard]] ControllerAddressList& ControllerAddresses() {
    return controller_address_list_;
  }
  [[nodiscard]] const ControllerAddressList& ControllerAddresses() const {
    return controller_address_list_;
  }

  void AddFrame(std::unique_ptr<Frame>& frame);
  [[nodiscard]] FrameList& Frames() {
    return frame_list_;
  }
  [[nodiscard]] const FrameList& Frames() const {
    return frame_list_;
  }

  void AddFunction(std::unique_ptr<Function>& func);
  [[nodiscard]] FuncList& Functions() {
    return function_list_;
  }
  [[nodiscard]] const FuncList& Functions() const {
    return function_list_;
  }

  void AddGroup(std::unique_ptr<Group>& group);
  [[nodiscard]] GroupList& Groups() {
    return group_list_;
  }
  [[nodiscard]] const GroupList& Groups() const {
    return group_list_;
  }

  void AddInstance(std::unique_ptr<Instance>& instance);
  [[nodiscard]] InstanceList& Instances() {
    return instance_list_;
  }
  [[nodiscard]] const InstanceList& Instances() const {
    return instance_list_;
  }

  void AddMeasurement(std::unique_ptr<Measurement>& measurement);
  [[nodiscard]] MeasurementList& Measurements() {
    return measurement_list_;
  }
  [[nodiscard]] const MeasurementList& Measurements() const {
    return measurement_list_;
  }
  [[nodiscard]] Measurement* GetMeasurement(const std::string& name);

  void AddRecordLayout(std::unique_ptr<RecordLayout>& record_layout);
  [[nodiscard]] RecordLayoutList& RecordLayouts() {
    return record_layout_list_;
  }
  [[nodiscard]] const RecordLayoutList& RecordLayouts() const {
    return record_layout_list_;
  }

  void AddTransformer(std::unique_ptr<Transformer>& transformer);
  [[nodiscard]] TransformerList& Transformers() {
    return transformer_list_;
  }
  [[nodiscard]] const TransformerList& Transformers() const {
    return transformer_list_;
  }

  void AddTypedefAxis(std::unique_ptr<AxisPts>& axis);
  [[nodiscard]] AxisPtsList& TypedefAxiss() { return typedef_axis_list_; }
  [[nodiscard]] const AxisPtsList& TypedefAxiss() const {
    return typedef_axis_list_;
  }
  [[nodiscard]] AxisPts* GetTypedefAxis(const std::string& name);

  void AddTypedefBlob(std::unique_ptr<Blob>& blob);
  [[nodiscard]] BlobList& TypedefBlobs() {
    return typedef_blob_list_;
  }
  [[nodiscard]] const BlobList& TypedefBlobs() const {
    return typedef_blob_list_;
  }
  [[nodiscard]] Blob* GetTypedefBlob(const std::string& name);

  void AddTypedefCharacteristic(std::unique_ptr<Characteristic>&
      characteristic);
  [[nodiscard]] CharacteristicList& TypedefCharacteristics() {
    return typedef_characteristic_list_;
  }
  [[nodiscard]] const CharacteristicList& TypedefCharacteristics() const  {
    return typedef_characteristic_list_;
  }
  [[nodiscard]] Characteristic* GetTypedefCharacteristic(const std::string&
                                                             name);

  void AddTypedefMeasurement(std::unique_ptr<Measurement>& measurement);
  [[nodiscard]] const MeasurementList& TypedefMeasurements() const {
    return typedef_measurement_list_;
  }
  [[nodiscard]] MeasurementList& TypedefMeasurements() {
    return typedef_measurement_list_;
  }
  [[nodiscard]] Measurement* GetTypedefMeasurement(const std::string& name);

  void AddTypedefStructure(std::unique_ptr<Structure>& structure);
  [[nodiscard]] StructureList& TypedefStructures() {
    return typedef_structure_list_;
  }
  [[nodiscard]] const StructureList& TypedefStructures() const {
    return typedef_structure_list_;
  }
  [[nodiscard]] Structure* GetTypedefStructure(const std::string& name);

  void AddUnit(std::unique_ptr<Unit>& unit);
  [[nodiscard]] UnitList& Units() {
    return unit_list_;
  }
  [[nodiscard]] const UnitList& Units() const {
    return unit_list_;
  }

  void AddUserRight(std::unique_ptr<A2lUserRight>& user_right);
  [[nodiscard]] UserRightList& UserRights() {
    return user_right_list_;
  }
  [[nodiscard]] const UserRightList& UserRights() const {
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
  ControllerAddressList controller_address_list_;
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
