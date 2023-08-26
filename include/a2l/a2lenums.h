/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include <string>
namespace a2l {

enum class A2lAddressType {
  PBYTE,
  PWORD,
  PLONG,
  PLONGLONG,
  DIRECT,
  UNKNOWN
};
A2lAddressType StringToAddressType(const std::string& type);

enum class A2lAxisType {
  CURVE_AXIS,
  COM_AXIS,
  FIX_AXIS,
  RES_AXIS,
  STD_AXIS,
  UNKNOWN
};
A2lAxisType StringToAxisType(const std::string& type);

enum class A2lByteOrder {
  MSB_FIRST,
  MSB_LAST,
  MSB_FIRST_MSW_LAST,
  MSB_LAST_MSW_FIRST,
  UNKNOWN
};
A2lByteOrder StringToByteOrder(const std::string& order);

enum class A2lCalibrationAccess {
  CALIBRATION,
  NO_CALIBRATION,
  NOT_IN_MCD_SYSTEM,
  OFFLINE_CALIBRATION,
  UNKNOWN
};
A2lCalibrationAccess StringToCalibrationAccess(const std::string& access);

enum class A2lCharacteristicType {
  ASCII,
  CURVE,
  MAP,
  CUBOID,
  CUBE_4,
  CUBE_5,
  VAL_BLK,
  VALUE,
  UNKNOWN
};
A2lCharacteristicType StringToCharacteristicType(const std::string& type);

enum class A2lDeposit {
  ABSOLUTE,
  DIFFERENCE,
  UNKNOWN
};
A2lDeposit StringToDeposit(const std::string& mode);


enum class A2lEncoding {
  ASCII, ///< 8-bit characters
  UTF8,
  UTF16,
  UTF32
};
A2lEncoding StringToEncoding(const std::string& enc);

enum class A2lMonotony {
  MON_DECREASE,
  MON_INCREASE,
  STRICT_DECREASE,
  STRICT_INCREASE,
  MONOTONOUS,
  STRICT_MON,
  NOT_MON,
  UNKNOWN
};

A2lMonotony StringToMonotony(const std::string& mon);
} // end namespace
