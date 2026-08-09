/*
 * Copyright 2023 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
#pragma once

#include <gtest/gtest.h>

namespace a2l::test {

class TestLabelFile : public testing::Test {
public:
  static void SetUpTestSuite();
  static void TearDownTestSuite();


};

}  // namespace a2l::test
