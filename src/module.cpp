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

}  // namespace a2l