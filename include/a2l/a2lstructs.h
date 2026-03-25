/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */
#pragma once

#include <cstdint>
#include <string>
#include <deque>
#include <unordered_map>

#include <memory>

#include "a2l/a2lenums.h"

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
  std::deque<std::string> Text;
};
using AnnotationList = std::deque<A2lAnnotation>;

struct A2lAxisPts {
  uint64_t Position = 0;
  A2lDataType DataType = A2lDataType::UNKNOWN;
  A2lIndexOrder IndexOrder = A2lIndexOrder::UNKNOWN;
  A2lAddressType AddressType = A2lAddressType::UNKNOWN;
};

struct A2lAxisRescale {
  uint64_t Position = 0;
  A2lDataType DataType = A2lDataType::UNKNOWN;
  uint64_t MaxNoRescalePairs = 0;
  A2lIndexOrder IndexOrder = A2lIndexOrder::UNKNOWN;
  A2lAddressType AddressType = A2lAddressType::UNKNOWN;
};

struct A2lBitOperation {
  uint64_t LeftShift = 0;
  uint64_t RightShift = 0;
  bool SignExtended = false;
};

struct A2lCalibrationHandle {
  std::string Comment;
  std::deque<int64_t> HandleList;
};

struct A2lCalibrationMethod {
  std::string Method;
  uint64_t    Version = 0;
  std::deque<A2lCalibrationHandle> CalibrationHandleList;
};

struct A2lControllerAddress {
  uint64_t Index = 0;
  A2lByteOrder ByteOrder = A2lByteOrder::MSB_LAST;
  uint64_t StartAddress = 0;
  uint64_t Length = 0;
};
using ControllerAddressList = std::deque<A2lControllerAddress>;

struct A2lDependentCharacteristic {
  std::string Formula;
  std::deque<std::string> CharacteristicList;
};

struct A2lDistOp {
  uint64_t Position = 0;
  A2lDataType DataType = A2lDataType::UNKNOWN;
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

struct A2lFncValue {
  uint64_t Position = 0;
  A2lDataType DataType = A2lDataType::UNKNOWN;
  A2lIndexMode IndexMode = A2lIndexMode::UNKNOWN;
  A2lAddressType AddressType = A2lAddressType::UNKNOWN;
};

struct A2lHeader {
  std::string Comment;
  std::string VersionNo;
  std::string ProjectNo;
};

struct A2lIdentification {
  uint64_t Position = 0;
  A2lDataType DataType = A2lDataType::UNKNOWN;
};

struct A2lLimits {
  double LowerLimit = 0.0;
  double UpperLimit = 0.0;
};

struct A2lMaxRefresh {
  uint64_t ScalingUnit = 0;
  uint64_t Rate = 0;
};

struct A2lMemoryLayout {
  A2lPrgType Type = A2lPrgType::UNKNOWN;
  uint64_t   Address = 0;
  uint64_t   Size = 0;
  std::deque<int64_t> OffsetList;
  std::unordered_map<std::string, std::string> IfDataList;
};

struct A2lMemorySegment {
  std::string Name;
  std::string Description;
  A2lSegmentType SegmentType = A2lSegmentType::UNKNOWN;
  A2lMemoryType MemoryType = A2lMemoryType::UNKNOWN;
  A2lMemoryAttribute Attribute = A2lMemoryAttribute::UNKNOWN;
  uint64_t Address = 0;
  uint64_t Size = 0;
  std::deque<int64_t> OffsetList;
  std::unordered_map<std::string, std::string> IfDataList;
};


struct A2lModCommon {
  std::string Comment;
  uint64_t AlignmentByte = 0;
  uint64_t AlignmentWord = 0;
  uint64_t AlignmentLong = 0;
  uint64_t AlignmentInt64 = 0;
  uint64_t AlignmentFloat16 = 0;
  uint64_t AlignmentFloat32 = 0;
  uint64_t AlignmentFloat64 = 0;
  A2lByteOrder ByteOrder = A2lByteOrder::UNKNOWN;
  uint64_t DataSize = 0;
  A2lDeposit Deposit = A2lDeposit::UNKNOWN;
};

struct A2lModPar {
  std::string Comment;
  std::deque<uint64_t> AddressEpkList;
  std::deque<A2lCalibrationMethod> CalibrationMethodList;
  std::string CpuType;
  std::string Customer;
  std::string CustomerNo;
  std::string Ecu;
  int64_t     EcuCalibrationOffset = 0;
  std::string Epk;
  std::deque<A2lMemoryLayout> MemoryLayoutList;
  std::deque<A2lMemorySegment> MemorySegmentList;
  uint64_t NoOfInterfaces = 0;
  std::string PhoneNo;
  std::string Supplier;
  std::unordered_map<std::string, std::string> SystemConstantList;
  std::string User;
  std::string Version;
};

struct A2lSiExponents {
  int64_t Length = 0;
  int64_t Mass = 0;
  int64_t Time = 0;
  int64_t ElectricCurrent = 0;
  int64_t Temperature = 0;
  int64_t AmountOfSubstance = 0;
  int64_t LuminousIntensity = 0;

  [[nodiscard]] bool HasExponent() const {
    return Length != 0 || Mass != 0 || Time != 0 || ElectricCurrent != 0 ||
        Temperature != 0 || AmountOfSubstance != 0 || LuminousIntensity != 0;
  }
};


struct A2lStructureComponent {
  std::string Name;
  std::string Typedef;
  uint64_t AddressOffset = 0;
  A2lAddressType AddressType = A2lAddressType::DIRECT;
  A2lLayout Layout = A2lLayout::ROW_DIR;
  std::deque<uint64_t> MatrixDim;
  std::string SymbolTypeLink;
};
using StructureComponentList = std::unordered_map<std::string,
                std::unique_ptr<A2lStructureComponent>>;

struct A2lSymbolLink {
  std::string SymbolName;
  int64_t Offset = 0;
};

struct A2lUserRights {
  std::string UserLevelId;
  bool ReadOnly = false;
  std::deque<std::deque<std::string>> RefGroupList;
};

using UserRightsList = std::unordered_map<std::string, std::unique_ptr<A2lUserRights>>;

struct A2lVarCharacteristic {
  std::string Name;
  std::deque<std::string> CriterionNameList;
  std::deque<uint64_t> AddressList;
};

struct A2lVarCriterion {
  std::string Name;
  std::string Description;
  std::deque<std::string> ValueList;
  std::string Measurement;
  std::string SelectionCharacteristic;
};

struct A2lVariantCoding {
  std::unordered_map<std::string, A2lVarCharacteristic> CharacteristicList;
  std::unordered_map<std::string, A2lVarCriterion> CriterionList;
  std::deque<std::unordered_map<std::string, std::string>> ForbiddenCombList;
  std::string Naming;
  std::string Separator;
  [[nodiscard]] bool HasCoding() const {
    return !CharacteristicList.empty() || !CriterionList.empty() ||
      !ForbiddenCombList.empty() || !Naming.empty() || !Separator.empty();
  }
};

} // end namespace a2l
