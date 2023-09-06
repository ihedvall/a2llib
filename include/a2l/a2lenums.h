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

enum class A2lConversionType {
  IDENTICAL,
  FORM,
  LINEAR,
  RAT_FUNC,
  TAB_INP,
  TAB_NOINTP,
  TAB_VERB,
  UNKNOWN
};
A2lConversionType StringToConversionType(const std::string& type);

enum class A2lDataType {
  UBYTE,
  SBYTE,
  UWORD,
  SWORD,
  ULONG,
  SLONG,
  A_UINT64,
  A_INT64,
  FLOAT16_IEEE,
  FLOAT32_IEEE,
  FLOAT64_IEEE,
  UNKNOWN
};

A2lDataType StringToDataType(const std::string& text);

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

enum class A2lIndexMode {
  ALTERNATE_CURVES,
  ALTERNATE_WITH_X,
  ALTERNATE_WITH_Y,
  COLUMN_DIR,
  ROW_DIR,
  UNKNOWN
};
A2lIndexMode StringToIndexMode(const std::string& text);

enum class A2lIndexOrder {
  INDEX_INCR,
  INDEX_DECR,
  UNKNOWN
};
A2lIndexOrder StringToIndexOrder(const std::string& text);

enum class A2lLayout {
  ROW_DIR,
  COLUMN_DIR,
  UNKNOWN
};
A2lLayout StringToLayout(const std::string& text);

enum class A2lMemoryType {
  EEPROM,
  EPROM,
  FLASH,
  RAM,
  ROM,
  REGISTER,
  NOT_IN_ECU,
  UNKNOWN
};
A2lMemoryType StringToMemoryType(const std::string& text);

enum class A2lMemoryAttribute {
  INTERN,
  EXTERN,
  UNKNOWN
};
A2lMemoryAttribute StringToMemoryAttribute(const std::string& text);

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

enum class A2lPrgType {
  PRG_CODE,
  PRG_DATA,
  PRG_RESERVED,
  UNKNOWN
};
A2lPrgType StringToPrgType(const std::string& text);

enum class A2lSegmentType {
  CALIBRATION_VARIABLES,
  CODE,
  DATA,
  EXCLUDE_FROM_FLASH,
  OFFLINE_DATA,
  RESERVED,
  SERAM,
  VARIABLES,
  UNKNOWN
};
A2lSegmentType StringToSegmentType(const std::string& text);

enum class A2lTrigger {
  ON_CHANGE,
  ON_USER_REQUEST,
  UNKNOWN
};
A2lTrigger StringToTrigger(const std::string& text);

enum class A2lTypedefType {
  TYPEDEF_AXIS,
  TYPEDEF_BLOB,
  TYPEDEF_CHARACTERISTIC,
  TYPEDEF_MEASUREMENT,
  TYPEDEF_STRUCTURE,
  UNKNOWN
};
A2lTypedefType StringToTypedefType(const std::string& text);

enum class A2lUnitType {
  DERIVED,
  EXTENDED_SI,
  UNKNOWN
};
A2lUnitType StringToUnitType(const std::string& text);

} // end namespace
