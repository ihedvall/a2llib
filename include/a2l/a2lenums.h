/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include <string>
#include <vector>
#include <string_view>
namespace a2l {

using EnumStringList = std::vector<std::string_view>;

enum class A2lAddressType {
  PBYTE,
  PWORD,
  PLONG,
  PLONGLONG,
  DIRECT,
  UNKNOWN
};
A2lAddressType StringToAddressType(const std::string& text);
std::string_view AddressTypeToString(A2lAddressType type);
EnumStringList AddressTypeToStringList();

enum class A2lAxisType {
  CURVE_AXIS,
  COM_AXIS,
  FIX_AXIS,
  RES_AXIS,
  STD_AXIS,
  UNKNOWN
};
A2lAxisType StringToAxisType(const std::string& text);
std::string_view AxisTypeToString(A2lAxisType type);
EnumStringList AxisTypeToStringList();

enum class A2lByteOrder {
  MSB_FIRST,
  MSB_LAST,
  MSB_FIRST_MSW_LAST,
  MSB_LAST_MSW_FIRST,
  UNKNOWN
};
A2lByteOrder StringToByteOrder(const std::string& order);
std::string_view ByteOrderToString(A2lByteOrder type);
EnumStringList ByteOrderToStringList();

enum class A2lCalibrationAccess {
  CALIBRATION,
  NO_CALIBRATION,
  NOT_IN_MCD_SYSTEM,
  OFFLINE_CALIBRATION,
  UNKNOWN
};
A2lCalibrationAccess StringToCalibrationAccess(const std::string& text);
std::string_view CalibrationAccessToString(A2lCalibrationAccess access);
EnumStringList CalibrationAccessToStringList();

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
A2lCharacteristicType StringToCharacteristicType(const std::string& text);
std::string_view CharacteristicTypeToString(A2lCharacteristicType type);
EnumStringList CharacteristicTypeToStringList();

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
A2lConversionType StringToConversionType(const std::string& text);
std::string_view ConversionTypeToString(A2lConversionType type);
EnumStringList ConversionTypeToStringList();

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
std::string_view DataTypeToString(A2lDataType type);
EnumStringList DataTypeToStringList();

enum class A2lDeposit {
  A2L_ABSOLUTE,
  A2L_DIFFERENCE,
  UNKNOWN
};
A2lDeposit StringToDeposit(const std::string& mode);
std::string_view DepositToString(A2lDeposit deposit);
EnumStringList DepositToStringList();

enum class A2lEncoding {
  ASCII, ///< 8-bit characters
  UTF8,
  UTF16,
  UTF32,
  UNKNOWN
};
A2lEncoding StringToEncoding(const std::string& enc);
std::string_view EncodingToString(A2lEncoding encoding);
EnumStringList EncodingToStringList();


enum class A2lIndexMode {
  ALTERNATE_CURVES,
  ALTERNATE_WITH_X,
  ALTERNATE_WITH_Y,
  COLUMN_DIR,
  ROW_DIR,
  UNKNOWN
};
A2lIndexMode StringToIndexMode(const std::string& text);
std::string_view IndexModeToString(A2lIndexMode mode);
EnumStringList IndexModeToStringList();

enum class A2lIndexOrder {
  INDEX_INCR,
  INDEX_DECR,
  UNKNOWN
};
A2lIndexOrder StringToIndexOrder(const std::string& text);
std::string_view IndexOrderToString(A2lIndexOrder order);
EnumStringList IndexOrderToStringList();

enum class A2lLayout {
  ROW_DIR,
  COLUMN_DIR,
  UNKNOWN
};
A2lLayout StringToLayout(const std::string& text);
std::string_view LayoutToString(A2lLayout layout);
EnumStringList LayoutToStringList();

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
std::string_view MemoryTypeToString(A2lMemoryType type);
EnumStringList MemoryTypeToStringList();

enum class A2lMemoryAttribute {
  INTERN,
  EXTERN,
  UNKNOWN
};
A2lMemoryAttribute StringToMemoryAttribute(const std::string& text);
std::string_view MemoryAttributeToString(A2lMemoryAttribute attr);
EnumStringList MemoryAttributeToStringList();

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
A2lMonotony StringToMonotony(const std::string& text);
std::string_view MonotonyToString(A2lMonotony type);
EnumStringList MonotonyToStringList();


enum class A2lPrgType {
  PRG_CODE,
  PRG_DATA,
  PRG_RESERVED,
  UNKNOWN
};
A2lPrgType StringToPrgType(const std::string& text);
std::string_view PrgTypeToString(A2lPrgType type);
EnumStringList PrgTypeToStringList();

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
std::string_view SegmentTypeToString(A2lSegmentType type);
EnumStringList SegmentTypeToStringList();

enum class A2lTrigger {
  ON_CHANGE,
  ON_USER_REQUEST,
  UNKNOWN
};
A2lTrigger StringToTrigger(const std::string& text);
std::string_view TriggerToString(A2lTrigger trigger);
EnumStringList TriggerToStringList();


enum class A2lTypedefType {
  TYPEDEF_AXIS,
  TYPEDEF_BLOB,
  TYPEDEF_CHARACTERISTIC,
  TYPEDEF_MEASUREMENT,
  TYPEDEF_STRUCTURE,
  UNKNOWN
};
A2lTypedefType StringToTypedefType(const std::string& text);
std::string_view TypedefTypeToString(A2lTypedefType type);
EnumStringList TypedefTypeToStringList();

enum class A2lUnitType {
  DERIVED,
  EXTENDED_SI,
  UNKNOWN
};
A2lUnitType StringToUnitType(const std::string& text);
std::string_view UnitTypeToString(A2lUnitType type);
EnumStringList UnitTypeToStringList();
} // end namespace
