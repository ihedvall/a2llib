/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */
#include <string>
#include <vector>
#pragma once

namespace a2l {

struct Asap2Version {
  uint64_t VersionNo = 0;
  uint64_t UpgradeNo = 0;
  void FromString(const std::string& version) {
    // Assume "Version.Upgrade"
    try {
      const auto dot = version.find('.');
      if (dot == std::string::npos) {
        VersionNo = std::stoull(version);
      } else {
        VersionNo = std::stoull(version.substr(0, dot));
        UpgradeNo = std::stoull(version.substr(dot + 1));
      }
    } catch (const std::exception& ) {}
  }
};

struct A2lAnnotation {
  std::string Label;
  std::string Origin;
  std::vector<std::string> Text;
};
using AnnotationList = std::vector<A2lAnnotation>;

struct A2lBitOperation {
  uint64_t LeftShift = 0;
  uint64_t RightShift = 0;
  bool SignExtended = false;
};

struct A2lDependentCharacteristic {
  std::string Formula;
  std::vector<std::string> CharacteristicList;
};

struct A2lExtendedLimits {
  double LowerLimits = 0.0;
  double UpperLimits = 0.0;
};

struct A2lFixAxisPar {
  double   Offset = 0.0;
  double   Shift = 0.0;
  uint64_t NoAxisPoints  = 0;
};

struct A2lFixAxisParDist {
  double   Offset = 0.0;
  double   Distance = 0.0;
  uint64_t NoAxisPoints  = 0;
};

struct A2lHeader {
  std::string Comment;
  std::string VersionNo;
  std::string ProjectNo;
};

struct A2lMaxRefresh {
  uint64_t ScalingUnit = 0;
  uint64_t Rate = 0;
};

struct A2lSymbolLink {
  std::string SymbolName;
  int64_t Offset = 0;
};


} // end namespace a2l
