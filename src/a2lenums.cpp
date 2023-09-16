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

A2lAddressType StringToAddressType(const std::string& type) {
  auto address_type = A2lAddressType::UNKNOWN;
  if (type == "PBYTE") {
    address_type = A2lAddressType::PBYTE;
  } else if (type == "PWORD") {
    address_type = A2lAddressType::PWORD;
  } else if (type == "PLONG") {
    address_type = A2lAddressType::PLONG;
  } else if (type == "PLONGLONG") {
    address_type = A2lAddressType::PLONGLONG;
  } else if (type == "DIRECT") {
    address_type = A2lAddressType::DIRECT;  }
  return address_type;
}

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

EnumStringList ByteOrderToStringList() {
  return EnumToStringList<A2lByteOrder,4>(kByteOrderList);
}

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

A2lCharacteristicType StringToCharacteristicType(const std::string& type) {
  auto characteristic_type = A2lCharacteristicType::UNKNOWN;
  if (type == "ASCII") {
    characteristic_type = A2lCharacteristicType::ASCII;
  } else if (type == "CURVE") {
    characteristic_type = A2lCharacteristicType::CURVE;
  } else if (type == "MAP") {
    characteristic_type = A2lCharacteristicType::MAP;
  } else if (type == "CUBOID") {
    characteristic_type = A2lCharacteristicType::CUBOID;
  } else if (type == "CUBE_4") {
    characteristic_type = A2lCharacteristicType::CUBE_4;
  } else if (type == "CUBE_5") {
    characteristic_type = A2lCharacteristicType::CUBE_5;
  } else if (type == "VAL_BLK") {
    characteristic_type = A2lCharacteristicType::VAL_BLK;
  } else if (type == "VALUE") {
    characteristic_type = A2lCharacteristicType::VALUE;
  }
  return characteristic_type;
}

A2lConversionType StringToConversionType(const std::string& type) {
  auto conversion_type = A2lConversionType::UNKNOWN;
  if (type == "IDENTICAL") {
    conversion_type = A2lConversionType::IDENTICAL;
  } else if (type == "FORM") {
    conversion_type = A2lConversionType::FORM;
  } else if (type == "LINEAR") {
    conversion_type = A2lConversionType::LINEAR;
  } else if (type == "RAT_FUNC") {
    conversion_type = A2lConversionType::RAT_FUNC;
  } else if (type == "TAB_INP") {
    conversion_type = A2lConversionType::TAB_INP;
  } else if (type == "TAB_NOINTP") {
    conversion_type = A2lConversionType::TAB_NOINTP;
  } else if (type == "TAB_VERB") {
    conversion_type = A2lConversionType::TAB_VERB;
  }
  return conversion_type;
}

A2lDataType StringToDataType(const std::string& text) {
  auto type = A2lDataType::UNKNOWN;
  if (text == "UBYTE") {
    type = A2lDataType::UBYTE;
  } else if (text == "SBYTE") {
    type = A2lDataType::SBYTE;
  } else if (text == "UWORD") {
    type = A2lDataType::UWORD;
  } else if (text == "SWORD") {
    type = A2lDataType::SWORD;
  } else if (text == "ULONG") {
    type = A2lDataType::ULONG;
  } else if (text == "SLONG") {
    type = A2lDataType::SLONG;
  } else if (text == "A_UINT64") {
    type = A2lDataType::A_UINT64;
  } else if (text == "A_INT64") {
    type = A2lDataType::A_INT64;
  } else if (text == "FLOAT16_IEEE") {
    type = A2lDataType::FLOAT16_IEEE;
  } else if (text == "FLOAT32_IEEE") {
    type = A2lDataType::FLOAT32_IEEE;
  } else if (text == "FLOAT64_IEEE") {
    type = A2lDataType::FLOAT64_IEEE;
  }
  return type;
}

using StringDeposit = std::pair<std::string_view, A2lDeposit>;
constexpr std::array<StringDeposit , 2> kDepositList = {
    StringDeposit("ABSOLUTE", A2lDeposit::A2L_ABSOLUTE),
    StringDeposit("DIFFERENCE", A2lDeposit::A2L_DIFFERENCE)
};

A2lDeposit StringToDeposit(const std::string& text) {
  return StringToEnum<A2lDeposit,2>(text, kDepositList);
}

EnumStringList DepositToStringList() {
  return EnumToStringList<A2lDeposit,2>(kDepositList);
}


A2lEncoding StringToEncoding(const std::string& enc) {
  auto encoding = A2lEncoding::ASCII;
  if (enc == "UTF8") {
    encoding = A2lEncoding::UTF8;
  } else if (enc == "UTF16") {
    encoding = A2lEncoding::UTF16;
  }  else if (enc == "UTF32") {
    encoding = A2lEncoding::UTF32;
  }
  return encoding;
}

using StringIndexMode = std::pair<std::string_view, A2lIndexMode>;
constexpr std::array<StringIndexMode , 5> kIndexModeList = {
    StringIndexMode("ALTERNATE_CURVES", A2lIndexMode::ALTERNATE_CURVES),
    StringIndexMode("ALTERNATE_WITH_X", A2lIndexMode::ALTERNATE_WITH_X),
    StringIndexMode("ALTERNATE_WITH_Y", A2lIndexMode::ALTERNATE_WITH_Y),
    StringIndexMode("COLUMN_DIR", A2lIndexMode::COLUMN_DIR),
    StringIndexMode("ROW_DIR", A2lIndexMode::ROW_DIR)
};

A2lIndexMode StringToIndexMode(const std::string& text) {
  auto type = A2lIndexMode::UNKNOWN;
  for (const auto& [idx_text, idx_type] : kIndexModeList) {
    if (idx_text == text) {
      type = idx_type;
      break;
    }
  }
  return type;
}

using StringIndexOrder = std::pair<std::string_view, A2lIndexOrder>;
constexpr std::array<StringIndexOrder , 2> kIndexOrderList = {
    StringIndexOrder("INDEX_INCR", A2lIndexOrder::INDEX_INCR),
    StringIndexOrder("INDEX_DECR", A2lIndexOrder::INDEX_DECR)
};

A2lIndexOrder StringToIndexOrder(const std::string& text) {
  auto type = A2lIndexOrder::UNKNOWN;
  for (const auto& [idx_text, idx_type] : kIndexOrderList) {
    if (idx_text == text) {
      type = idx_type;
    }
  }
  return type;
}

A2lLayout StringToLayout(const std::string& text) {
    auto layout = A2lLayout::UNKNOWN;
    if (text == "ROW_DIR") {
      layout = A2lLayout::ROW_DIR;
    } else if (text == "COLUMN_DIR") {
      layout = A2lLayout::COLUMN_DIR;
    }
    return layout;
}

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

EnumStringList MemoryTypeToStringList() {
    return EnumToStringList<A2lMemoryType,7>(kMemoryList);
}

using StringMemoryAttribute = std::pair<std::string_view, A2lMemoryAttribute>;
constexpr std::array<StringMemoryAttribute, 2> kAttributeList = {
    StringMemoryAttribute("INTERN", A2lMemoryAttribute::INTERN),
    StringMemoryAttribute("EXTERN", A2lMemoryAttribute::EXTERN),
};

A2lMemoryAttribute StringToMemoryAttribute(const std::string& text) {
    return StringToEnum<A2lMemoryAttribute,2>(text, kAttributeList);
}
EnumStringList MemoryAttributeToStringList() {
    return EnumToStringList<A2lMemoryAttribute,2>(kAttributeList);
}


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

EnumStringList SegmentTypeToStringList() {
  return EnumToStringList<A2lSegmentType,8>(kSegmentList);
}

using StringTrigger = std::pair<std::string_view, A2lTrigger>;
constexpr std::array<StringTrigger, 2> kTriggerList = {
    std::pair("ON_CHANGE", A2lTrigger::ON_CHANGE),
    std::pair("ON_USER_REQUEST", A2lTrigger::ON_USER_REQUEST),
};

A2lTrigger StringToTrigger(const std::string& text) {
  auto type = A2lTrigger::UNKNOWN;
  for (const auto& [trg_text, trg_type] : kTriggerList) {
      if (trg_text == text) {
        type = trg_type;
        break;
      }
  }
  return type;
}

using StringTypedef = std::pair<std::string_view, A2lTypedefType>;
constexpr std::array<StringTypedef, 5> kTypedefList = {
    std::pair("TYPEDEF_AXIS", A2lTypedefType::TYPEDEF_AXIS),
    std::pair("TYPEDEF_BLOB", A2lTypedefType::TYPEDEF_BLOB),
    std::pair("TYPEDEF_CHARACTERISTIC", A2lTypedefType::TYPEDEF_CHARACTERISTIC),
    std::pair("TYPEDEF_MEASUREMENT", A2lTypedefType::TYPEDEF_MEASUREMENT),
    std::pair("TYPEDEF_STRUCTURE", A2lTypedefType::TYPEDEF_STRUCTURE),
};

A2lTypedefType StringToTypedefType(const std::string& text) {
  auto type = A2lTypedefType::UNKNOWN;
  for (const auto& [def_text, def_type] : kTypedefList) {
      if (def_text == text) {
        type = def_type;
        break;
      }
  }
  return type;
}

using StringUnit = std::pair<std::string_view, A2lUnitType>;
constexpr std::array<StringUnit, 2> kUnitList = {
    std::pair("DERIVED", A2lUnitType::DERIVED),
    std::pair("EXTENDED_SI", A2lUnitType::EXTENDED_SI),
};

A2lUnitType StringToUnitType(const std::string& text) {
  auto type = A2lUnitType::UNKNOWN;
  for (const auto& [unit_text, unit_type] : kUnitList) {
      if (unit_text == text) {
        type = unit_type;
        break;
      }
  }
  return type;
}
}
