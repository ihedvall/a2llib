/*
* Copyright 2022 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include <bit>

#include "a2l/a2lhelper.h"
#include "a2l/characteristic.h"
#include "a2l/measurement.h"
#include "a2l/module.h"

namespace a2l::test {

TEST(A2lHelper, TestDouble) {
  uint8_t buffer[8] = {};
  for (double orig = -122.34; orig < 122.34; orig += 0.1) { //NOLINT
  if constexpr (std::endian::native == std::endian::little) {
      A2lHelper::DoubleToRaw(true, 0, sizeof(orig)*8, orig, buffer);
      double native = 0;
      memcpy(&native, buffer, sizeof(native));
      EXPECT_DOUBLE_EQ(native, orig);
      native = A2lHelper::RawToDouble(true, 0, sizeof(orig)*8, buffer);
      EXPECT_DOUBLE_EQ(native, orig);

      A2lHelper::DoubleToRaw(false, 7, sizeof(orig)*8, orig, buffer);
      const double big = A2lHelper::RawToDouble(false, 7,
                                                sizeof(orig)*8, buffer);
      EXPECT_DOUBLE_EQ(orig, big);

      // Test faulty start bit
      A2lHelper::DoubleToRaw(false, 0, sizeof(orig)*8, orig, buffer);
    } else {
      A2lHelper::DoubleToRaw(false, 7, sizeof(orig)*8, orig, buffer);
      double native = 0;
      memcpy(&native, buffer, sizeof(native));
      EXPECT_DOUBLE_EQ(native, orig);
      native = A2lHelper::RawToDouble(false, 7, sizeof(orig)*8, buffer);
      EXPECT_DOUBLE_EQ(native, orig);

      A2lHelper::DoubleToRaw(true, 0, sizeof(orig)*8, orig, buffer);
      const double little = A2lHelper::RawToDouble(true, 0,
                                                sizeof(orig)*8, buffer);
      EXPECT_DOUBLE_EQ(orig, little);
    }

  }
}


TEST(A2lHelper, SearchMeasurementsWildcard) {
  Module module;

  {
    auto measurement = std::make_unique<Measurement>();
    measurement->Name("VehicleSpeed");
    module.AddMeasurement(measurement);
  }
  {
    auto measurement = std::make_unique<Measurement>();
    measurement->Name("VehicleStatus");
    module.AddMeasurement(measurement);
  }
  {
    auto measurement = std::make_unique<Measurement>();
    measurement->Name("EngineSpeed");
    module.AddMeasurement(measurement);
  }

  const auto all_vehicle = module.SearchMeasurements(FilterList("Vehicle*"));
  ASSERT_EQ(all_vehicle.size(), 2);
  EXPECT_EQ(all_vehicle[0], "VehicleSpeed");
  EXPECT_EQ(all_vehicle[1], "VehicleStatus");

  const auto exact = module.SearchMeasurements(FilterList("EngineSpeed"));
  ASSERT_EQ(exact.size(), 1);
  EXPECT_EQ(exact[0], "EngineSpeed");

  const auto none = module.SearchMeasurements(FilterList("Missing*"));
  EXPECT_TRUE(none.empty());

  const auto ptr_all = module.GetFlatMeasurementList();
  ASSERT_EQ(ptr_all.size(), 3);
  EXPECT_EQ(ptr_all[0]->Name(), "EngineSpeed");
  EXPECT_EQ(ptr_all[1]->Name(), "VehicleSpeed");
  EXPECT_EQ(ptr_all[2]->Name(), "VehicleStatus");

  module.SetMeasurementFilter(FilterList("Vehicle*"));
  const auto ptr_filtered = module.GetFlatMeasurementList();
  ASSERT_EQ(ptr_filtered.size(), 2);
  EXPECT_EQ(ptr_filtered[0]->Name(), "VehicleSpeed");
  EXPECT_EQ(ptr_filtered[1]->Name(), "VehicleStatus");
}

TEST(A2lHelper, SearchCharacteristicsWildcard) {
  Module module;

  {
    auto characteristic = std::make_unique<Characteristic>();
    characteristic->Name("AirTemp");
    module.AddCharacteristic(characteristic);
  }
  {
    auto characteristic = std::make_unique<Characteristic>();
    characteristic->Name("AirFuelRatio");
    module.AddCharacteristic(characteristic);
  }
  {
    auto characteristic = std::make_unique<Characteristic>();
    characteristic->Name("EngineTemp");
    module.AddCharacteristic(characteristic);
  }

  const auto all_air = module.SearchCharacteristics(FilterList("Air*"));
  ASSERT_EQ(all_air.size(), 2);
  EXPECT_EQ(all_air[0], "AirFuelRatio");
  EXPECT_EQ(all_air[1], "AirTemp");

  const auto single = module.SearchCharacteristics(FilterList("*Temp"));
  ASSERT_EQ(single.size(), 2);
  EXPECT_EQ(single[0], "AirTemp");
  EXPECT_EQ(single[1], "EngineTemp");

  const auto question = module.SearchCharacteristics(FilterList("A?rTemp"));
  ASSERT_EQ(question.size(), 1);
  EXPECT_EQ(question[0], "AirTemp");

  const auto ptr_all = module.GetFlatCharacteristicList();
  ASSERT_EQ(ptr_all.size(), 3);
  EXPECT_EQ(ptr_all[0]->Name(), "AirFuelRatio");
  EXPECT_EQ(ptr_all[1]->Name(), "AirTemp");
  EXPECT_EQ(ptr_all[2]->Name(), "EngineTemp");

  module.SetCharacteristicFilter(FilterList("*Temp"));
  const auto ptr_filtered = module.GetFlatCharacteristicList();
  ASSERT_EQ(ptr_filtered.size(), 2);
  EXPECT_EQ(ptr_filtered[0]->Name(), "AirTemp");
  EXPECT_EQ(ptr_filtered[1]->Name(), "EngineTemp");
}

TEST(A2lHelper, TestFloat) {
  uint8_t buffer[8] = {}; // I'm using last 4 bytes only
  for (float orig = -122.34F; orig < 122.34F; orig += 0.1F) { //NOLINT

    if constexpr (std::endian::native == std::endian::little) {
      A2lHelper::FloatToRaw(true, 32, sizeof(orig)*8, orig, buffer);
      float native = 0;
      memcpy(&native, buffer + 4, sizeof(native));
      EXPECT_FLOAT_EQ(native, orig);
      native = A2lHelper::RawToFloat(true, 32, sizeof(orig)*8, buffer);
      EXPECT_FLOAT_EQ(native, orig);

      A2lHelper::FloatToRaw(false, 39, sizeof(orig)*8, orig, buffer);
      const float big = A2lHelper::RawToFloat(false, 39,
                                                sizeof(orig)*8, buffer);
      EXPECT_FLOAT_EQ(orig, big);

      // Test faulty start bit
      A2lHelper::FloatToRaw(false, 32, sizeof(orig)*8, orig, buffer);
    } else {
      A2lHelper::FloatToRaw(false, 39, sizeof(orig)*8, orig, buffer);
      float native = 0;
      memcpy(&native, buffer + 4, sizeof(native));
      EXPECT_FLOAT_EQ(native, orig);
      native = A2lHelper::RawToFloat(true, 39, sizeof(orig)*8, buffer);
      EXPECT_FLOAT_EQ(native, orig);

      A2lHelper::FloatToRaw(true, 32, sizeof(orig)*8, orig, buffer);
      const float little = A2lHelper::RawToFloat(true, 32,
                                                   sizeof(orig)*8, buffer);
      EXPECT_FLOAT_EQ(orig, little);
    }
  }
}

TEST(A2lHelper, TestSigned) {
  uint8_t buffer[8] = {};
  for (size_t length = 3; length <= 64; ++length) {
    for (int64_t orig = -3; orig <= 3; ++orig ) {
      A2lHelper::SignedToRaw(true, 0, length, orig, buffer);
      const auto little = A2lHelper::RawToSigned(true, 0, length, buffer);
      EXPECT_EQ(little, orig);

      A2lHelper::SignedToRaw(false, 7, length, orig, buffer);
      const auto big = A2lHelper::RawToSigned(false, 7, length, buffer);
      EXPECT_EQ(big, orig);
    }
  }

  int64_t orig0 = 0;
  A2lHelper::SignedToRaw(true, 0, 0, orig0, buffer);
  const auto little0 = A2lHelper::RawToSigned(true, 0, 0, buffer);
  EXPECT_EQ(little0, orig0);

  int64_t orig1 = -1;
  A2lHelper::SignedToRaw(true, 62, 1, orig1, buffer);
  const auto little1 = A2lHelper::RawToSigned(true, 62, 1, buffer);
  EXPECT_EQ(little1, orig1);

  int64_t orig64 = INT64_MIN;
  A2lHelper::SignedToRaw(true, 0, 64, orig64, buffer);
  const auto little64 = A2lHelper::RawToSigned(true, 0, 64, buffer);
  EXPECT_EQ(little64, orig64);
}

TEST(A2lHelper, TestUnsigned) {
  uint8_t buffer[8] = {};
  for (size_t length = 2; length <= 64; ++length) {
    for (uint64_t orig = 0; orig <= 3; ++orig ) {
      A2lHelper::UnsignedToRaw(true, 0, length, orig, buffer);
      const auto little = A2lHelper::RawToUnsigned(true, 0, length, buffer);
      EXPECT_EQ(little, orig);

      A2lHelper::UnsignedToRaw(false, 7, length, orig, buffer);
      const auto big = A2lHelper::RawToUnsigned(false, 7, length, buffer);
      EXPECT_EQ(big, orig);
    }
  }

  uint64_t orig0 = 0;
  A2lHelper::UnsignedToRaw(true, 0, 0, orig0, buffer);
  const auto little0 = A2lHelper::RawToUnsigned(true, 0, 0, buffer);
  EXPECT_EQ(little0, orig0);

  uint64_t orig1 = 1;
  A2lHelper::UnsignedToRaw(true, 62, 1, orig1, buffer);
  const auto little1 = A2lHelper::RawToUnsigned(true, 62, 1, buffer);
  EXPECT_EQ(little1, orig1);

  uint64_t orig64 = UINT64_MAX;
  A2lHelper::UnsignedToRaw(true, 0, 64, orig64, buffer);
  const auto little64 = A2lHelper::RawToUnsigned(true, 0, 64, buffer);
  EXPECT_EQ(little64, orig64);
}

TEST(A2lHelper, TestGetStem) {
  {
    const auto stem = A2lHelper::GetStem("");
    EXPECT_TRUE(stem.empty());
  }

  {
    const auto stem = A2lHelper::GetStem("olle.txt");
    EXPECT_STREQ(stem.c_str(), "olle");
  }

  {
    const auto stem = A2lHelper::GetStem("c:\\olle.txt");
    EXPECT_STREQ(stem.c_str(), "olle");
  }

  {
    const auto stem = A2lHelper::GetStem("c:\\daddy.cool/olle.txt");
    EXPECT_STREQ(stem.c_str(), "olle");
  }

  {
    const auto stem = A2lHelper::GetStem("//daddy.cool/olle.txt");
    EXPECT_STREQ(stem.c_str(), "olle");
  }
}

TEST(A2lHelper, TestTrim) {
  std::string text1 = " OLLE \n";
  A2lHelper::Trim(text1);
  EXPECT_EQ(text1, "OLLE");

  std::string text2 = " OL LE \n";
  A2lHelper::Trim(text2);
  EXPECT_EQ(text2, "OL LE");
}

TEST(A2lHelper, TestSplit) {
  {
    const std::string text = "Measurement01;10ms&100ms;12;Olle comment";
    auto split_list = A2lHelper::Split(text, ';');
    ASSERT_EQ(split_list.size(), 4);
    EXPECT_STREQ(split_list[0].c_str(), "Measurement01");
    EXPECT_STREQ(split_list[1].c_str(), "10ms&100ms");
    EXPECT_STREQ(split_list[2].c_str(), "12");
    EXPECT_STREQ(split_list[3].c_str(), "Olle comment");
  }
  {
    const std::string text = "Measurement01;;;Olle comment";
    auto split_list = A2lHelper::Split(text, ';');
    ASSERT_EQ(split_list.size(), 4);
    EXPECT_STREQ(split_list[0].c_str(), "Measurement01");
    EXPECT_STREQ(split_list[1].c_str(), "");
    EXPECT_STREQ(split_list[2].c_str(), "");
    EXPECT_STREQ(split_list[3].c_str(), "Olle comment");
  }
  {
    const std::string text = "Measurement01;;;Olle comment;";
    auto split_list = A2lHelper::Split(text, ';');
    ASSERT_EQ(split_list.size(), 5);
    EXPECT_STREQ(split_list[0].c_str(), "Measurement01");
    EXPECT_STREQ(split_list[1].c_str(), "");
    EXPECT_STREQ(split_list[2].c_str(), "");
    EXPECT_STREQ(split_list[3].c_str(), "Olle comment");
    EXPECT_STREQ(split_list[4].c_str(), "");
  }
}

}
