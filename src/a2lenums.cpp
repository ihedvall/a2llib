/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */
#include "a2l/a2lenums.h"
#include <array>
namespace {

template <typename T, size_t S>
T StringToEnum(const std::string& text,
               const std::array<std::pair<std::string_view, T>, S>& list) {
  auto type = T::UNKNOWN;
  for (const auto& [idx_text, idx_type] : list) {
    if (idx_text == text) {
      type = idx_type;
      break;
    }
  }
  return type;
}

template <typename T, size_t S>
std::string_view EnumToString(T type,
               const std::array<std::pair<std::string_view, T>, S>& list) {
  for (const auto& [idx_text, idx_type] : list) {
    if (idx_type == type) {
      return idx_text;
    }
  }
  return "UNKNOWN";
}

template <typename T, size_t S>
a2l::EnumStringList EnumToStringList(
    const std::array<std::pair<std::string_view, T>, S>& list) {
  a2l::EnumStringList enum_list;
  const auto end_type = T::UNKNOWN;
  for (const auto& [idx_text, idx_type] : list) {
    if (idx_type == end_type) {
      break;
    }
    enum_list.emplace_back(idx_text);
  }
  return enum_list;
}

} // end namespace

namespace a2l {

/*------------- ADDRESS TYPE ---------------------------*/
using StringAddressType = std::pair<std::string_view, A2lAddressType>;
constexpr std::array<StringAddressType , 5> kAddressTypeList = {
    StringAddressType("PBYTE", A2lAddressType::PBYTE),
    StringAddressType("PWORD", A2lAddressType::PWORD),
    StringAddressType("PLONG", A2lAddressType::PLONG),
    StringAddressType("PLONGLONG", A2lAddressType::PLONGLONG),
    StringAddressType("DIRECT", A2lAddressType::DIRECT)
};

A2lAddressType StringToAddressType(const std::string& text) {
  return StringToEnum<A2lAddressType, 5>(text, kAddressTypeList);
}
std::string_view AddressTypeToString(A2lAddressType type) {
  return EnumToString<A2lAddressType, 5>(type, kAddressTypeList);
}

EnumStringList AddressTypeToStringList() {
  return EnumToStringList<A2lAddressType,5>(kAddressTypeList);
}


/* ----------------AXIS TYPE ------------------------*/
using StringAxisType = std::pair<std::string_view, A2lAxisType>;
constexpr std::array<StringAxisType , 5> kAxisTypeList = {
    StringAxisType("CURVE_AXIS", A2lAxisType::CURVE_AXIS),
    StringAxisType("COM_AXIS", A2lAxisType::COM_AXIS),
    StringAxisType("FIX_AXIS", A2lAxisType::FIX_AXIS),
    StringAxisType("RES_AXIS", A2lAxisType::RES_AXIS),
    StringAxisType("STD_AXIS", A2lAxisType::STD_AXIS)
};

A2lAxisType StringToAxisType(const std::string& text) {
  return StringToEnum<A2lAxisType, 5>(text, kAxisTypeList);
}

std::string_view AxisTypeToString(A2lAxisType type) {
  return EnumToString<A2lAxisType, 5>(type, kAxisTypeList);
}

EnumStringList AxisTypeToStringList() {
  return EnumToStringList<A2lAxisType,5>(kAxisTypeList);
}

/*----------------- BYTE ORDER -------------------------*/
using StringByteOrder = std::pair<std::string_view, A2lByteOrder>;
constexpr std::array<StringByteOrder , 4> kByteOrderList = {
    StringByteOrder("MSB_FIRST", A2lByteOrder::MSB_FIRST),
    StringByteOrder("MSB_LAST", A2lByteOrder::MSB_LAST),
    StringByteOrder("MSB_FIRST_MSW_LAST", A2lByteOrder::MSB_FIRST_MSW_LAST),
    StringByteOrder("MSB_LAST_MSW_FIRST", A2lByteOrder::MSB_LAST_MSW_FIRST)
};

A2lByteOrder StringToByteOrder(const std::string& text) {
  return StringToEnum<A2lByteOrder,4>(text, kByteOrderList);
}
std::string_view ByteOrderToString(A2lByteOrder type) {
  return EnumToString<A2lByteOrder, 4>(type, kByteOrderList);
}

EnumStringList ByteOrderToStringList() {
  return EnumToStringList<A2lByteOrder,4>(kByteOrderList);
}

/*--------------- CALIBRATION ACCESS ---------------------*/
using StringCalibrationAccess = std::pair<std::string_view,
                                          A2lCalibrationAccess>;
constexpr std::array<StringCalibrationAccess , 4> kCalibrationAccessList = {
    StringCalibrationAccess("CALIBRATION", A2lCalibrationAccess::CALIBRATION),
    StringCalibrationAccess("NO_CALIBRATION",
                            A2lCalibrationAccess::NO_CALIBRATION),
    StringCalibrationAccess("NOT_IN_MCD_SYSTEM",
                            A2lCalibrationAccess::NOT_IN_MCD_SYSTEM),
    StringCalibrationAccess("OFFLINE_CALIBRATION",
                            A2lCalibrationAccess::OFFLINE_CALIBRATION)
};

A2lCalibrationAccess StringToCalibrationAccess(const std::string& text) {
  return StringToEnum<A2lCalibrationAccess,4>(text, kCalibrationAccessList);
}

std::string_view CalibrationAccessToString(A2lCalibrationAccess access) {
  return EnumToString<A2lCalibrationAccess, 4>(access, kCalibrationAccessList);
}

EnumStringList CalibrationAccessToStringList() {
  return EnumToStringList<A2lCalibrationAccess,4>(kCalibrationAccessList);
}

/*----------------- CHARACTERISTIC TYPE -----------------------------*/
using StringCharacteristicType= std::pair<std::string_view,
                                          A2lCharacteristicType>;

constexpr std::array<StringCharacteristicType , 8> kCharacteristicTypeList = {
    StringCharacteristicType("ASCII", A2lCharacteristicType::ASCII),
    StringCharacteristicType("CURVE", A2lCharacteristicType::CURVE),
    StringCharacteristicType("MAP", A2lCharacteristicType::MAP),
    StringCharacteristicType("CUBOID", A2lCharacteristicType::CUBOID),
    StringCharacteristicType("CUBE_4", A2lCharacteristicType::CUBE_4),
    StringCharacteristicType("CUBE_5", A2lCharacteristicType::CUBE_5),
    StringCharacteristicType("VAL_BLK", A2lCharacteristicType::VAL_BLK),
    StringCharacteristicType("VALUE", A2lCharacteristicType::VALUE),
};

A2lCharacteristicType StringToCharacteristicType(const std::string& text) {
  return StringToEnum<A2lCharacteristicType,8>(text, kCharacteristicTypeList);
}

std::string_view CharacteristicTypeToString(A2lCharacteristicType type) {
  return EnumToString<A2lCharacteristicType, 8>(type, kCharacteristicTypeList);
}

EnumStringList CharacteristicTypeToStringList() {
  return EnumToStringList<A2lCharacteristicType,8>(kCharacteristicTypeList);
}

/*---------------------- CONVERSION TYPE ------------------------*/
using StringConversionType = std::pair<std::string_view,
                                           A2lConversionType>;

constexpr std::array<StringConversionType , 7> kConversionTypeList = {
    StringConversionType("IDENTICAL", A2lConversionType::IDENTICAL),
    StringConversionType("FORM", A2lConversionType::FORM),
    StringConversionType("LINEAR", A2lConversionType::LINEAR),
    StringConversionType("RAT_FUNC", A2lConversionType::RAT_FUNC),
    StringConversionType("TAB_INP", A2lConversionType::TAB_INP),
    StringConversionType("TAB_NOINTP", A2lConversionType::TAB_NOINTP),
    StringConversionType("TAB_VERB", A2lConversionType::TAB_VERB),
};

A2lConversionType StringToConversionType(const std::string& text) {
  return StringToEnum<A2lConversionType,7>(text, kConversionTypeList);
}

std::string_view ConversionTypeToString(A2lConversionType type) {
  return EnumToString<A2lConversionType, 7>(type, kConversionTypeList);
}

EnumStringList ConversionTypeToStringList() {
  return EnumToStringList<A2lConversionType,7>(kConversionTypeList);
}

/*-------------- DAtA TYPE --------------------------*/
using StringDataType = std::pair<std::string_view,
                                       A2lDataType>;

constexpr std::array<StringDataType, 11> kDataTypeList = {
    StringDataType("UBYTE", A2lDataType::UBYTE),
    StringDataType("SBYTE", A2lDataType::SBYTE),
    StringDataType("UWORD", A2lDataType::UWORD),
    StringDataType("SWORD", A2lDataType::SWORD),
    StringDataType("ULONG", A2lDataType::ULONG),
    StringDataType("SLONG", A2lDataType::SLONG),
    StringDataType("A_UINT64", A2lDataType::A_UINT64),
    StringDataType("A_INT64", A2lDataType::A_INT64),
    StringDataType("FLOAT16_IEEE", A2lDataType::FLOAT16_IEEE),
    StringDataType("FLOAT32_IEEE", A2lDataType::FLOAT32_IEEE),
    StringDataType("FLOAT64_IEEE", A2lDataType::FLOAT64_IEEE),
};

A2lDataType StringToDataType(const std::string& text) {
  return StringToEnum<A2lDataType,11>(text, kDataTypeList);
}

std::string_view DataTypeToString(A2lDataType type) {
  return EnumToString<A2lDataType, 11>(type, kDataTypeList);
}

EnumStringList DataTypeToStringList() {
  return EnumToStringList<A2lDataType,11>(kDataTypeList);
}

/*--------------- DEPOSIT ---------------------*/

using StringDeposit = std::pair<std::string_view, A2lDeposit>;
constexpr std::array<StringDeposit , 2> kDepositList = {
    StringDeposit("ABSOLUTE", A2lDeposit::A2L_ABSOLUTE),
    StringDeposit("DIFFERENCE", A2lDeposit::A2L_DIFFERENCE)
};

A2lDeposit StringToDeposit(const std::string& text) {
  return StringToEnum<A2lDeposit,2>(text, kDepositList);
}

std::string_view DepositToString(A2lDeposit deposit) {
  return EnumToString<A2lDeposit, 2>(deposit, kDepositList);
}

EnumStringList DepositToStringList() {
  return EnumToStringList<A2lDeposit,2>(kDepositList);
}

/*----------------- ENCODING ---------------------------*/
using StringEncoding = std::pair<std::string_view, A2lEncoding>;
constexpr std::array<StringEncoding, 4> kEncodingList = {
    StringEncoding("", A2lEncoding::ASCII),
    StringEncoding("UTF8", A2lEncoding::UTF8),
    StringEncoding("UTF16", A2lEncoding::UTF16),
    StringEncoding("UTF32", A2lEncoding::UTF32)
};

A2lEncoding StringToEncoding(const std::string& text) {
  return StringToEnum<A2lEncoding,4>(text, kEncodingList);
}

std::string_view EncodingToString(A2lEncoding encoding) {
  return EnumToString<A2lEncoding, 4>(encoding, kEncodingList);
}

EnumStringList EncodingToStringList() {
  return EnumToStringList<A2lEncoding,4>(kEncodingList);
}

/*----------------------- INDEX MODE --------------------*/

using StringIndexMode = std::pair<std::string_view, A2lIndexMode>;
constexpr std::array<StringIndexMode , 5> kIndexModeList = {
    StringIndexMode("ALTERNATE_CURVES", A2lIndexMode::ALTERNATE_CURVES),
    StringIndexMode("ALTERNATE_WITH_X", A2lIndexMode::ALTERNATE_WITH_X),
    StringIndexMode("ALTERNATE_WITH_Y", A2lIndexMode::ALTERNATE_WITH_Y),
    StringIndexMode("COLUMN_DIR", A2lIndexMode::COLUMN_DIR),
    StringIndexMode("ROW_DIR", A2lIndexMode::ROW_DIR)
};

A2lIndexMode StringToIndexMode(const std::string& text) {
  return StringToEnum<A2lIndexMode,5>(text, kIndexModeList);
}

std::string_view IndexModeToString(A2lIndexMode mode) {
  return EnumToString<A2lIndexMode, 5>(mode, kIndexModeList);
}

EnumStringList IndexModeToStringList() {
  return EnumToStringList<A2lIndexMode,5>(kIndexModeList);
}

/*----------------- INDEX ORDER --------------------------*/

using StringIndexOrder = std::pair<std::string_view, A2lIndexOrder>;
constexpr std::array<StringIndexOrder , 2> kIndexOrderList = {
    StringIndexOrder("INDEX_INCR", A2lIndexOrder::INDEX_INCR),
    StringIndexOrder("INDEX_DECR", A2lIndexOrder::INDEX_DECR)
};

A2lIndexOrder StringToIndexOrder(const std::string& text) {
  return StringToEnum<A2lIndexOrder,2>(text, kIndexOrderList);
}

std::string_view IndexOrderToString(A2lIndexOrder order) {
  return EnumToString<A2lIndexOrder, 2>(order, kIndexOrderList);
}

EnumStringList IndexOrderToStringList() {
  return EnumToStringList<A2lIndexOrder,2>(kIndexOrderList);
}

/*------------------ LAYOUT -----------------------------*/
using StringLayout = std::pair<std::string_view, A2lLayout>;
constexpr std::array<StringLayout , 2> kLayoutList = {
    StringLayout("ROW_DIR", A2lLayout::ROW_DIR),
    StringLayout("COLUMN_DIR", A2lLayout::COLUMN_DIR)
};

A2lLayout StringToLayout(const std::string& text) {
  return StringToEnum<A2lLayout,2>(text, kLayoutList);
}

std::string_view LayoutToString(A2lLayout layout) {
  return EnumToString<A2lLayout, 2>(layout, kLayoutList);
}

EnumStringList LayoutToStringList() {
  return EnumToStringList<A2lLayout,2>(kLayoutList);
}

/*------------------- MEMORY TYPE ------------------------*/
using StringMemoryType = std::pair<std::string_view, A2lMemoryType>;
constexpr std::array<StringMemoryType, 7> kMemoryList = {
    StringMemoryType("EEPROM", A2lMemoryType::EEPROM),
    StringMemoryType("EPROM", A2lMemoryType::EPROM),
    StringMemoryType("FLASH", A2lMemoryType::FLASH),
    StringMemoryType("RAM", A2lMemoryType::RAM),
    StringMemoryType("ROM", A2lMemoryType::ROM),
    StringMemoryType("REGISTER", A2lMemoryType::REGISTER),
    StringMemoryType("NOT_IN_ECU", A2lMemoryType::NOT_IN_ECU),
};

A2lMemoryType StringToMemoryType(const std::string& text) {
    return StringToEnum<A2lMemoryType,7>(text, kMemoryList);
}

std::string_view MemoryTypeToString(A2lMemoryType type) {
    return EnumToString<A2lMemoryType, 7>(type, kMemoryList);
}

EnumStringList MemoryTypeToStringList() {
    return EnumToStringList<A2lMemoryType,7>(kMemoryList);
}


/*------------ MEMORY ATTRIBUTE -------------------------*/
using StringMemoryAttribute = std::pair<std::string_view, A2lMemoryAttribute>;
constexpr std::array<StringMemoryAttribute, 2> kAttributeList = {
    StringMemoryAttribute("INTERN", A2lMemoryAttribute::INTERN),
    StringMemoryAttribute("EXTERN", A2lMemoryAttribute::EXTERN),
};

A2lMemoryAttribute StringToMemoryAttribute(const std::string& text) {
    return StringToEnum<A2lMemoryAttribute,2>(text, kAttributeList);
}
std::string_view MemoryAttributeToString(A2lMemoryAttribute attr) {
    return EnumToString<A2lMemoryAttribute, 2>(attr, kAttributeList);
}

EnumStringList MemoryAttributeToStringList() {
    return EnumToStringList<A2lMemoryAttribute,2>(kAttributeList);
}

/*-------------------------- MONOTONY -------------------------*/
using StringMonotony = std::pair<std::string_view, A2lMonotony>;
constexpr std::array<StringMonotony, 7> kMonotonyList = {
    StringMonotony("MON_DECREASE", A2lMonotony::MON_DECREASE),
    StringMonotony("MON_INCREASE", A2lMonotony::MON_INCREASE),
    StringMonotony("STRICT_DECREASE", A2lMonotony::STRICT_DECREASE),
    StringMonotony("STRICT_INCREASE", A2lMonotony::STRICT_INCREASE),
    StringMonotony("MONOTONOUS", A2lMonotony::MONOTONOUS),
    StringMonotony("STRICT_MON", A2lMonotony::STRICT_MON),
    StringMonotony("NOT_MON", A2lMonotony::NOT_MON),
};
A2lMonotony StringToMonotony(const std::string& text) {
  return StringToEnum<A2lMonotony,7>(text, kMonotonyList);
}
std::string_view MonotonyToString(A2lMonotony type) {
  return EnumToString<A2lMonotony, 7>(type, kMonotonyList);
}

EnumStringList MonotonyToStringList() {
  return EnumToStringList<A2lMonotony,7>(kMonotonyList);
}

/*------------------ PRG TYPE -----------------------------*/
using StringPrgType = std::pair<std::string_view, A2lPrgType>;
constexpr std::array<StringPrgType, 3> kPrgList = {
    std::pair("PRG_CODE", A2lPrgType::PRG_CODE),
    std::pair("PRG_DATA", A2lPrgType::PRG_DATA),
    std::pair("PRG_RESERVED", A2lPrgType::PRG_RESERVED),
};

A2lPrgType StringToPrgType(const std::string& text) {
  return StringToEnum<A2lPrgType, 3>(text, kPrgList);
}

std::string_view PrgTypeToString(A2lPrgType type) {
  return EnumToString<A2lPrgType, 3>(type, kPrgList);
}

EnumStringList PrgTypeToStringList() {
  return EnumToStringList<A2lPrgType,3>(kPrgList);
}

/*----------------- SEGMENT TYPE -----------------------*/
using StringSegmentType = std::pair<std::string_view, A2lSegmentType>;
constexpr std::array<StringSegmentType, 8> kSegmentList = {
    std::pair("CALIBRATION_VARIABLES", A2lSegmentType::CALIBRATION_VARIABLES),
    std::pair("CODE", A2lSegmentType::CODE),
    std::pair("DATA", A2lSegmentType::DATA),
    std::pair("EXCLUDE_FROM_FLASH", A2lSegmentType::EXCLUDE_FROM_FLASH),
    std::pair("OFFLINE_DATA", A2lSegmentType::OFFLINE_DATA),
    std::pair("RESERVED", A2lSegmentType::RESERVED),
    std::pair("SERAM", A2lSegmentType::SERAM),
    std::pair("VARIABLES", A2lSegmentType::VARIABLES),
};

A2lSegmentType StringToSegmentType(const std::string& text) {
  return StringToEnum<A2lSegmentType, 8>(text, kSegmentList);
}

std::string_view SegmentTypeToString(A2lSegmentType type) {
  return EnumToString<A2lSegmentType, 8>(type, kSegmentList);
}

EnumStringList SegmentTypeToStringList() {
  return EnumToStringList<A2lSegmentType,8>(kSegmentList);
}

/*------------------- TRIGGER ------------------------------*/
using StringTrigger = std::pair<std::string_view, A2lTrigger>;
constexpr std::array<StringTrigger, 2> kTriggerList = {
    std::pair("ON_CHANGE", A2lTrigger::ON_CHANGE),
    std::pair("ON_USER_REQUEST", A2lTrigger::ON_USER_REQUEST),
};

A2lTrigger StringToTrigger(const std::string& text) {
  return StringToEnum<A2lTrigger, 2>(text, kTriggerList);
}

std::string_view TriggerToString(A2lTrigger trigger) {
  return EnumToString<A2lTrigger, 2>(trigger, kTriggerList);
}

EnumStringList TriggerToStringList() {
  return EnumToStringList<A2lTrigger,2>(kTriggerList);
}

/*------------------ TYPEDEF TYPE ---------------------*/
using StringTypedef = std::pair<std::string_view, A2lTypedefType>;
constexpr std::array<StringTypedef, 5> kTypedefList = {
    std::pair("TYPEDEF_AXIS", A2lTypedefType::TYPEDEF_AXIS),
    std::pair("TYPEDEF_BLOB", A2lTypedefType::TYPEDEF_BLOB),
    std::pair("TYPEDEF_CHARACTERISTIC", A2lTypedefType::TYPEDEF_CHARACTERISTIC),
    std::pair("TYPEDEF_MEASUREMENT", A2lTypedefType::TYPEDEF_MEASUREMENT),
    std::pair("TYPEDEF_STRUCTURE", A2lTypedefType::TYPEDEF_STRUCTURE),
};

A2lTypedefType StringToTypedefType(const std::string& text) {
  return StringToEnum<A2lTypedefType, 5>(text, kTypedefList);
}

std::string_view TypedefTypeToString(A2lTypedefType type) {
  return EnumToString<A2lTypedefType, 5>(type, kTypedefList);
}

EnumStringList TypedefTypeToStringList() {
  return EnumToStringList<A2lTypedefType,5>(kTypedefList);
}

/*------------------- UNIT TYPE ----------------------*/
using StringUnit = std::pair<std::string_view, A2lUnitType>;
constexpr std::array<StringUnit, 2> kUnitList = {
    std::pair("DERIVED", A2lUnitType::DERIVED),
    std::pair("EXTENDED_SI", A2lUnitType::EXTENDED_SI),
};

A2lUnitType StringToUnitType(const std::string& text) {
  return StringToEnum<A2lUnitType, 2>(text, kUnitList);
}

std::string_view UnitTypeToString(A2lUnitType type) {
  return EnumToString<A2lUnitType, 2>(type, kUnitList);
}

EnumStringList UnitTypeToStringList() {
  return EnumToStringList<A2lUnitType,2>(kUnitList);
}

}
