/*
* Copyright 2022 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>
#include "a2lhelper.h"
#include <bit>

namespace a2l::test {

TEST(A2lHelper, TestDouble) {
  uint8_t buffer[8] = {};
  for (double orig = -122.34; orig < 122.34; orig += 0.1) { //NOLINT
  if (std::endian::native == std::endian::little) {
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

TEST(DbcHelper, TestFloat) {
  uint8_t buffer[8] = {}; // I'm using last 4 bytes only
  for (float orig = -122.34F; orig < 122.34F; orig += 0.1F) { //NOLINT

    if (std::endian::native == std::endian::little) {
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

TEST(DbcHelper, TestSigned) {
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

TEST(DbcHelper, TestUnsigned) {
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

TEST(DbcHelper, TestGetStem) {
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

}
