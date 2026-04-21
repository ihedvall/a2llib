/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <gtest/gtest.h>

namespace a2l::test {

class TestXcp : public testing::Test  {
public:
  static void SetUpTestSuite();
  static void TearDownTestSuite();
private:
};
}


