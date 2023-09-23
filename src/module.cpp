/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2l/module.h"

namespace a2l {

void Module::AddAxisPts(std::unique_ptr<AxisPts>& axis_pts) {
  axis_pts_list_.emplace(axis_pts->Name(), std::move(axis_pts));
}

void Module::AddBlob(std::unique_ptr<Blob>& blob) {
  blob_list_.emplace(blob->Name(), std::move(blob));
}

void Module::AddCharacteristic(std::unique_ptr<Characteristic>&
    characteristic) {
  characteristic_list_.emplace(characteristic->Name(),
                               std::move(characteristic));
}

void Module::AddCompuMethod(std::unique_ptr<CompuMethod>& method) {
  compu_method_list_.emplace(method->Name(), std::move(method));
}

void Module::AddCompuTab(std::unique_ptr<CompuTab>& tab) {
  compu_tab_list_.emplace(tab->Name(), std::move(tab));
}

void Module::AddCompuVtab(std::unique_ptr<CompuVtab>& tab) {
  compu_vtab_list_.emplace(tab->Name(), std::move(tab));
}

void Module::AddCompuVtabRange(std::unique_ptr<CompuVtabRange>& tab) {
  compu_vtab_range_list_.emplace(tab->Name(), std::move(tab));
}

void Module::AddFrame(std::unique_ptr<Frame>& frame) {
  frame_list_.emplace(frame->Name(), std::move(frame));
}

void Module::AddFunction(std::unique_ptr<Function>& func) {
  function_list_.emplace(func->Name(), std::move(func));
}

void Module::AddGroup(std::unique_ptr<Group>& group) {
  group_list_.emplace(group->Name(), std::move(group));
}

void Module::AddInstance(std::unique_ptr<Instance>& instance) {
  instance_list_.emplace(instance->Name(), std::move(instance));
}

void Module::AddMeasurement(std::unique_ptr<Measurement>& measurement) {
  measurement_list_.emplace(measurement->Name(), std::move(measurement));
}

void Module::AddRecordLayout(std::unique_ptr<RecordLayout>& record_layout) {
  record_layout_list_.emplace(record_layout->Name(), std::move(record_layout));
}

void Module::AddTransformer(std::unique_ptr<Transformer>& transformer) {
  transformer_list_.emplace(transformer->Name(), std::move(transformer));
}

void Module::AddTypedefAxis(std::unique_ptr<AxisPts>& axis) {
  typedef_axis_list_.emplace(axis->Name(), std::move(axis));
}

void Module::AddTypedefBlob(std::unique_ptr<Blob>& blob) {
  typedef_blob_list_.emplace(blob->Name(), std::move(blob));
}

void Module::AddTypedefCharacteristic(std::unique_ptr<Characteristic>&
    characteristic) {
  typedef_characteristic_list_.emplace(characteristic->Name(),
                                       std::move(characteristic));
}

void Module::AddTypedefMeasurement(std::unique_ptr<Measurement>& measurement){
  typedef_measurement_list_.emplace(measurement->Name(),
                                    std::move(measurement));
}

void Module::AddTypedefStructure(std::unique_ptr<Structure>& structure){
  typedef_structure_list_.emplace(structure->Name(), std::move(structure));
}

void Module::AddUnit(std::unique_ptr<Unit>& unit){
  unit_list_.emplace(unit->Name(), std::move(unit));
}

void Module::AddUserRight(std::unique_ptr<A2lUserRight>& user_right){
  user_right_list_.emplace(user_right->UserLevelId, std::move(user_right));
}

AxisPts* Module::GetAxisPts(const std::string& name) {
  auto itr = axis_pts_list_.find(name);
  return itr == axis_pts_list_.end() ? nullptr : itr->second.get();
}

Blob* Module::GetBlob(const std::string& name) {
  auto itr = blob_list_.find(name);
  return itr == blob_list_.end() ? nullptr : itr->second.get();
}

Characteristic* Module::GetCharacteristic(const std::string& name) {
  auto itr = characteristic_list_.find(name);
  return itr == characteristic_list_.end() ? nullptr : itr->second.get();
}

CompuTab* Module::GetCompuTab(const std::string& name) {
  auto itr = compu_tab_list_.find(name);
  return itr == compu_tab_list_.end() ? nullptr : itr->second.get();
}

CompuVtab* Module::GetCompuVtab(const std::string& name) {
  auto itr = compu_vtab_list_.find(name);
  return itr == compu_vtab_list_.end() ? nullptr : itr->second.get();
}

CompuVtabRange* Module::GetCompuVtabRange(const std::string& name) {
  auto itr = compu_vtab_range_list_.find(name);
  return itr == compu_vtab_range_list_.end() ? nullptr : itr->second.get();
}

Measurement* Module::GetMeasurement(const std::string& name) {
  auto itr = measurement_list_.find(name);
  return itr == measurement_list_.end() ? nullptr : itr->second.get();
}

AxisPts* Module::GetTypedefAxis(const std::string& name) {
  auto itr = typedef_axis_list_.find(name);
  return itr == typedef_axis_list_.end() ? nullptr : itr->second.get();
}

Blob* Module::GetTypedefBlob(const std::string& name) {
  auto itr = typedef_blob_list_.find(name);
  return itr == typedef_blob_list_.end() ? nullptr : itr->second.get();
}

Characteristic* Module::GetTypedefCharacteristic(const std::string& name) {
  auto itr = typedef_characteristic_list_.find(name);
  return itr == typedef_characteristic_list_.end() ? nullptr : itr->second.get();
}

Measurement* Module::GetTypedefMeasurement(const std::string& name) {
  auto itr = typedef_measurement_list_.find(name);
  return itr == typedef_measurement_list_.end() ? nullptr : itr->second.get();
}

Structure* Module::GetTypedefStructure(const std::string& name) {
  auto itr = typedef_structure_list_.find(name);
  return itr == typedef_structure_list_.end() ? nullptr : itr->second.get();
}

}  // namespace a2l