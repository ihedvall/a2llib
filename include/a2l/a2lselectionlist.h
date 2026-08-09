/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include "a2l/selectionlist.h"
#include "a2l/a2lfile.h"

namespace a2l {

class A2lSelectionList : public SelectionList {
public:
  A2lSelectionList() = default;
  ~A2lSelectionList() override = default;

  void AttachA2lFile(const A2lFile& a2l_file);

private:
  void AttachMeasurements(const Module& module);
  void AttachCharacteristics(const Module& module);
  void AttachFunctions(const Module& module);
  void AttachGroups(const Module& module);
};

}  // namespace a2l

