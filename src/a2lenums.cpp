/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */
#include "a2l/a2lenums.h"

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

A2lByteOrder StringToByteOrder(const std::string& order) {
  auto byte_order = A2lByteOrder::UNKNOWN;
  if (order == "MSB_FIRST") {
    byte_order = A2lByteOrder::MSB_FIRST;
  } else if (order == "MSB_LAST") {
    byte_order = A2lByteOrder::MSB_LAST;
  } else if (order == "MSB_FIRST_MSW_LAST") {
    byte_order = A2lByteOrder::MSB_FIRST_MSW_LAST;
  } else if (order == "MSB_LAST_MSW_FIRST") {
    byte_order = A2lByteOrder::MSB_LAST_MSW_FIRST;
  }
  return byte_order;
}

A2lAxisType StringToAxisType(const std::string& type) {
  auto axis_type = A2lAxisType::UNKNOWN;
  if (type == "CURVE_AXIS") {
    axis_type = A2lAxisType::CURVE_AXIS;
  } else if (type == "COM_AXIS") {
    axis_type = A2lAxisType::COM_AXIS;
  } else if (type == "FIX_AXIS") {
    axis_type = A2lAxisType::FIX_AXIS;
  } else if (type == "RES_AXIS") {
    axis_type = A2lAxisType::RES_AXIS;
  } else if (type == "STD_AXIS") {
    axis_type = A2lAxisType::STD_AXIS;
  }
  return axis_type;
}

A2lCalibrationAccess StringToCalibrationAccess(const std::string& access) {
  auto cal = A2lCalibrationAccess::UNKNOWN;
  if (access == "CALIBRATION") {
    cal = A2lCalibrationAccess::CALIBRATION;
  } else if (access == "NO_CALIBRATION") {
    cal = A2lCalibrationAccess::NO_CALIBRATION;
  } else if (access == "NOT_IN_MCD_SYSTEM") {
    cal = A2lCalibrationAccess::NOT_IN_MCD_SYSTEM;
  } else if (access == "OFFLINE_CALIBRATION") {
    cal = A2lCalibrationAccess::OFFLINE_CALIBRATION;
  }
  return cal;
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

A2lDeposit StringToDeposit(const std::string& mode) {
  auto deposit = A2lDeposit::UNKNOWN;
  if (mode == "ABSOLUTE") {
    deposit = A2lDeposit::ABSOLUTE;
  } else if (mode == "DIFFERENCE") {
    deposit = A2lDeposit::DIFFERENCE;
  }
  return deposit;
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

A2lLayout StringToLayout(const std::string& text) {
    auto layout = A2lLayout::UNKNOWN;
    if (text == "ROW_DIR") {
      layout = A2lLayout::ROW_DIR;
    } else if (text == "COLUMN_DIR") {
      layout = A2lLayout::COLUMN_DIR;
    }
    return layout;
}

A2lMonotony StringToMonotony(const std::string& mon) {
  auto monotony = A2lMonotony::UNKNOWN;
  if (mon == "MON_DECREASE") {
    monotony = A2lMonotony::MON_DECREASE;
  } else if (mon == "MON_INCREASE") {
      monotony = A2lMonotony::MON_INCREASE;
  } else if (mon == "STRICT_DECREASE") {
      monotony = A2lMonotony::STRICT_DECREASE;
  } else if (mon == "STRICT_INCREASE") {
      monotony = A2lMonotony::STRICT_INCREASE;
  } else if (mon == "MONOTONOUS") {
      monotony = A2lMonotony::MONOTONOUS;
  } else if (mon == "STRICT_MON") {
      monotony = A2lMonotony::STRICT_MON;
  } else if (mon == "NOT_MON") {
      monotony = A2lMonotony::NOT_MON;
  }
  return monotony;
}


}
