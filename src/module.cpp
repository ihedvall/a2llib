/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2l/module.h"

#include <algorithm>
#include <iterator>
#include <vector>
#include <utility>
#include <memory>
#include <string>
#include <ranges>
#include <unordered_map>

namespace {
template <typename T>
void CheckFlatMapList(const std::unordered_map<std::string,std::unique_ptr<T>>& source,
            std::vector<T*>& destination) {
  const size_t count = source.size();
  if (count == destination.size()) {
    return;
  }

  try {
    destination.resize(count, nullptr);
    std::ranges::transform(source, destination.begin(),
          [](const auto& pair) {
                  return pair.second.get();
       });
    std::ranges::sort(destination,
        [](const T* lhs, const T* rhs) -> bool {
      if (lhs == nullptr || rhs == nullptr) {
        return false;
      }
      return lhs->Name() < rhs->Name();
    });

  } catch (std::exception& ) {
    destination.clear();
  }
}

}

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

Frame * Module::GetFrame(const std::string &name) const {
  auto itr = frame_list_.find(name);
  return itr == frame_list_.end() ? nullptr : itr->second.get();
}

Frame * Module::GetFrame(long index) const {
  if (index < 0 || index >= frame_list_.size()) {
    return nullptr;
  }
  auto itr = frame_list_.cbegin();
  std::advance(itr, index);
  return itr->second.get();
}

void Module::AddFunction(std::unique_ptr<Function>& func) {
  function_list_.emplace(func->Name(), std::move(func));
}

Function *Module::GetFunction(const std::string &name) const {
  const auto itr = function_list_.find(name);
  return itr == function_list_.cend() ? nullptr : itr->second.get();
}

Function *Module::GetFunction(long index) const {
  if (index < 0 || index >= function_list_.size()) {
    return nullptr;
  }
  auto itr = function_list_.cbegin();
  std::advance(itr, index);
  return itr->second.get();
}

void Module::AddGroup(std::unique_ptr<Group>& group) {
  group_list_.emplace(group->Name(), std::move(group));
}

Group *Module::GetGroup(const std::string &name) const {
  const auto itr = group_list_.find(name);
  return itr == group_list_.cend() ? nullptr : itr->second.get();
}

Group *Module::GetGroup(long index) const {
  if (index < 0 || index >= group_list_.size()) {
    return nullptr;
  }
  auto itr = group_list_.cbegin();
  std::advance(itr, index);
  return itr->second.get();
}

void Module::AddInstance(std::unique_ptr<Instance>& instance) {
  instance_list_.emplace(instance->Name(), std::move(instance));
}

Instance *Module::GetInstance(const std::string &name) const {
  const auto itr = instance_list_.find(name);
  return itr == instance_list_.cend() ? nullptr : itr->second.get();
}

Instance *Module::GetInstance(long index) const {
  if (index < 0 || index >= instance_list_.size()) {
    return nullptr;
  }
  auto itr = instance_list_.cbegin();
  std::advance(itr, index);
  return itr->second.get();
}

void Module::AddMeasurement(std::unique_ptr<Measurement>& measurement) {
  measurement_list_.emplace(measurement->Name(), std::move(measurement));
}

void Module::AddRecordLayout(std::unique_ptr<RecordLayout>& record_layout) {
  record_layout_list_.emplace(record_layout->Name(), std::move(record_layout));
}

RecordLayout* Module::GetRecordLayout(const std::string& name) const {
  const auto itr = record_layout_list_.find(name);
  return itr == record_layout_list_.cend() ? nullptr : itr->second.get();
}

RecordLayout* Module::GetRecordLayout(long index) const {
  if (index < 0 || index >= record_layout_list_.size()) {
    return nullptr;
  }
  auto itr = record_layout_list_.cbegin();
  std::advance(itr, index);
  return itr->second.get();
}

void Module::AddTransformer(std::unique_ptr<Transformer>& transformer) {
  transformer_list_.emplace(transformer->Name(), std::move(transformer));
}

Transformer* Module::GetTransformer(const std::string& name) const {
  const auto itr = transformer_list_.find(name);
  return itr == transformer_list_.cend() ? nullptr : itr->second.get();
}

Transformer* Module::GetTransformer(long index) const {
  if (index < 0 || index >= transformer_list_.size()) {
    return nullptr;
  }
  auto itr = transformer_list_.cbegin();
  std::advance(itr, index);
  return itr->second.get();
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



AxisPts* Module::GetAxisPts(const std::string& name) const {
  auto itr = axis_pts_list_.find(name);
  return itr == axis_pts_list_.end() ? nullptr : itr->second.get();
}

AxisPts* Module::GetAxisPts(long index) const {
  if (index < 0 || index >= axis_pts_list_.size()) {
    return nullptr;
  }
  auto itr = axis_pts_list_.cbegin();
  std::advance(itr, index);
  return itr->second.get();
}

Blob* Module::GetBlob(const std::string& name) {
  auto itr = blob_list_.find(name);
  return itr == blob_list_.end() ? nullptr : itr->second.get();
}

Blob* Module::GetBlob(long index) {
  if (index < 0 || index >= blob_list_.size()) {
    return nullptr;
  }
  auto itr = blob_list_.cbegin();
  std::advance(itr, index);
  return itr->second.get();
}

Characteristic* Module::GetCharacteristic(const std::string& name) const {
  auto itr = characteristic_list_.find(name);
  return itr == characteristic_list_.end() ? nullptr : itr->second.get();
}

Characteristic* Module::GetCharacteristic(long index) const {
  CheckFlatMapList(characteristic_list_, flat_characteristic_list_);
  if (index < 0 || index >= flat_characteristic_list_.size()) {
    return nullptr;
  }
  return flat_characteristic_list_[index];
}

CompuMethod* Module::GetCompuMethod(const std::string& name) const {
  auto itr = compu_method_list_.find(name);
  return itr == compu_method_list_.cend() ? nullptr : itr->second.get();
}

CompuMethod* Module::GetCompuMethod(long index) const {
  if (index < 0 || index >= compu_method_list_.size()) {
    return nullptr;
  }
  auto itr = compu_method_list_.cbegin();
  std::advance(itr, index);
  return itr->second.get();
}

CompuTab* Module::GetCompuTab(const std::string& name) const {
  auto itr = compu_tab_list_.find(name);
  return itr == compu_tab_list_.end() ? nullptr : itr->second.get();
}

CompuTab* Module::GetCompuTab(long index) const {
  if (index < 0 || index >= compu_tab_list_.size()) {
    return nullptr;
  }
  auto itr = compu_tab_list_.cbegin();
  std::advance(itr, index);
  return itr->second.get();
}

CompuVtab* Module::GetCompuVtab(const std::string& name) const  {
  auto itr = compu_vtab_list_.find(name);
  return itr == compu_vtab_list_.end() ? nullptr : itr->second.get();
}

CompuVtab* Module::GetCompuVtab(long index) const {
  if (index < 0 || index >= compu_vtab_list_.size()) {
    return nullptr;
  }
  auto itr = compu_vtab_list_.cbegin();
  std::advance(itr, index);
  return itr->second.get();
}

CompuVtabRange* Module::GetCompuVtabRange(const std::string& name) const {
  auto itr = compu_vtab_range_list_.find(name);
  return itr == compu_vtab_range_list_.end() ? nullptr : itr->second.get();
}

CompuVtabRange* Module::GetCompuVtabRange(long index) const {
  if (index < 0 || index >= compu_vtab_range_list_.size()) {
    return nullptr;
  }
  auto itr = compu_vtab_range_list_.cbegin();
  std::advance(itr, index);
  return itr->second.get();
}

void Module::AddControllerAddress(const A2lControllerAddress& controller_address) {
  controller_address_list_.push_back(controller_address);
}

Measurement* Module::GetMeasurement(const std::string& name) const {
  const auto itr = measurement_list_.find(name);
  return itr == measurement_list_.cend() ? nullptr : itr->second.get();
}

Measurement* Module::GetMeasurement(long index) const {
  CheckFlatMapList(measurement_list_, flat_measurement_list_);
  if (index < 0 || index >= flat_measurement_list_.size()) {
    return nullptr;
  }
  return flat_measurement_list_[index];
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

void Module::CheckFlatTypedefList() const {
  const size_t count = typedef_axis_list_.size() +
                       typedef_blob_list_.size() +
                       typedef_characteristic_list_.size() +
                       typedef_measurement_list_.size() +
                       typedef_structure_list_.size();

  if (count == flat_typedef_list_.size()) {
    return;
  }

  try {
    flat_typedef_list_.resize(count, FlatTypedefPair{A2lTypedefType::UNKNOWN, nullptr});
    size_t index = 0;
    for (const auto& axis_item : typedef_axis_list_ | std::views::values) {
      flat_typedef_list_[index] = {A2lTypedefType::TYPEDEF_AXIS,axis_item.get()};
      ++index;
    }
   for (const auto& blob_item : typedef_blob_list_ | std::views::values) {
      flat_typedef_list_[index] = {A2lTypedefType::TYPEDEF_BLOB,blob_item.get()};
      ++index;
    }
    for (const auto& characteristic_item : typedef_characteristic_list_ | std::views::values) {
      flat_typedef_list_[index] = {A2lTypedefType::TYPEDEF_CHARACTERISTIC,characteristic_item.get()};
      ++index;
    }
    for (const auto& measurement_item : typedef_measurement_list_ | std::views::values) {
      flat_typedef_list_[index] = {A2lTypedefType::TYPEDEF_MEASUREMENT,measurement_item.get()};
      ++index;
    }
    for (const auto& structure_item : typedef_structure_list_ | std::views::values) {
      flat_typedef_list_[index] = {A2lTypedefType::TYPEDEF_STRUCTURE,structure_item.get()};
      ++index;
    }

    std::ranges::sort(flat_typedef_list_,
        [](const FlatTypedefPair& lhs, const FlatTypedefPair& rhs) -> bool {
      if (lhs.second == nullptr || rhs.second == nullptr) {
        return false;
      }
      return lhs.second->Name() < rhs.second->Name();
    });

  } catch (std::exception& ) {
    flat_typedef_list_.clear();
  }
}

FlatTypedefList& Module::GetTypedefList() const {
  CheckFlatTypedefList();
  return flat_typedef_list_;
}

FlatTypedefPair Module::GetTypedef(long index) const {
  CheckFlatTypedefList();
  if (index < 0 || index >= flat_typedef_list_.size()) {
    return FlatTypedefPair{A2lTypedefType::UNKNOWN, nullptr};
  }
  return flat_typedef_list_[index];
}

void Module::AddUnit(std::unique_ptr<Unit>& unit){
  if (unit) {
    unit_list_.emplace(unit->Name(), std::move(unit));
  }
}

Unit* Module::GetUnit(const std::string& name) const {
  const auto itr = unit_list_.find(name);
  return itr == unit_list_.cend() ? nullptr : itr->second.get();
}

Unit* Module::GetUnit(long index) const {
  if (index < 0 || index >= unit_list_.size()) {
    return nullptr;
  }
  auto itr = unit_list_.cbegin();
  std::advance(itr, index);
  return itr->second.get();
}


void Module::AddUserRights(std::unique_ptr<A2lUserRights>& user_right) {
  if (user_right) {
    user_rights_list_.emplace(user_right->UserLevelId, std::move(user_right));
  }
}

A2lUserRights* Module::GetUserRights(const std::string& name) const {
  const auto itr = user_rights_list_.find(name);
  return itr == user_rights_list_.cend() ? nullptr : itr->second.get();
}

A2lUserRights* Module::GetUserRights(long index) const {
  if (index < 0 || index >= user_rights_list_.size()) {
    return nullptr;
  }
  auto itr = user_rights_list_.cbegin();
  std::advance(itr, index);
  return itr->second.get();
}

}  // namespace a2l