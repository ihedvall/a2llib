/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2l/a2lselectionlist.h"

#include <ranges>

namespace a2l {

void A2lSelectionList::AttachA2lFile(const A2lFile& a2l_file) {

  const auto& project = a2l_file.Project();
  const auto& module_list = project.Modules();
  for (const auto& module : module_list | std::views::values) {
    if (!module) {
      continue;
    }
    AttachMeasurements(*module);
    AttachCharacteristics(*module);
    AttachFunctions(*module);
    AttachGroups(*module);
  }
}

void A2lSelectionList::AttachMeasurements(const Module& module) {
  const std::string& device = module.Name();
  for (SelectionObject& object : object_list_) {
    if (object.IsAttached() || object.GetObjectType() != ObjectType::RAMCELL) {
      continue;
    }
    const std::string& name = object.GetName();
    const Measurement* meas = module.GetMeasurement(name);
    if (meas == nullptr ) {
      continue;
    }
    object.SetUserObject(const_cast<Measurement*>(meas));
    object.SetDescription(meas->Description());
    const std::string& conversion = meas->Conversion();
    if (const CompuMethod* compu_method =
        module.GetCompuMethod(conversion); compu_method != nullptr) {
      object.SetUnit(compu_method->PhysUnit());
    } else {
      object.SetUnit(meas->PhysUnit());
    }

    object.SetLowerLimit(meas->LowerLimit());
    object.SetUpperLimit(meas->UpperLimit());
    object.SetDevice(device);
  }
}

void A2lSelectionList::AttachCharacteristics(const Module& module) {
  const std::string& device = module.Name();
  for (SelectionObject& object : object_list_) {
    if (object.IsAttached() || object.GetObjectType() != ObjectType::LABEL) {
      continue;
    }
    const std::string& name = object.GetName();
    const Characteristic* parameter = module.GetCharacteristic(name);
    if (parameter == nullptr ) {
      continue;
    }
    object.SetUserObject(const_cast<Characteristic*>(parameter));
    object.SetDescription(parameter->Description());
    const std::string& conversion = parameter->Conversion();
    if (const CompuMethod* compu_method =
        module.GetCompuMethod(conversion); compu_method != nullptr) {
      object.SetUnit(compu_method->PhysUnit());
    } else {
      object.SetUnit(parameter->PhysUnit());
    }

    object.SetLowerLimit(parameter->LowerLimit());
    object.SetUpperLimit(parameter->UpperLimit());
    object.SetDevice(device);
  }
}

void A2lSelectionList::AttachFunctions(const Module& module) {
  const std::string& device = module.Name();
  for (SelectionObject& object : object_list_) {
    if (object.IsAttached() || object.GetObjectType() != ObjectType::FUNCTION) {
      continue;
    }
    const std::string& name = object.GetName();

    const Function* func = module.GetFunction(name);
    if (func == nullptr ) {
      continue;
    }
    object.SetUserObject(const_cast<Function*>(func));
    object.SetDescription(func->Description());
    object.SetDevice(device);
  }
}

void A2lSelectionList::AttachGroups(const Module& module) {
  const std::string& device = module.Name();
  for (SelectionObject& object : object_list_) {
    if (object.IsAttached() || object.GetObjectType() != ObjectType::GROUP) {
      continue;
    }
    const std::string& name = object.GetName();

    const Group* group = module.GetGroup(name);
    if (group == nullptr ) {
      continue;
    }
    object.SetUserObject(const_cast<Group*>(group));
    object.SetDescription(group->Description());
    object.SetDevice(device);
  }
}
} // a2l