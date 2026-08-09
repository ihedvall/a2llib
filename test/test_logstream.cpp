/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */
#include <gtest/gtest.h>

#include "a2l/a2llogstream.h"

namespace a2l::test {
TEST(A2lLogStream, LogToConsole) {
  A2lLogStream::SetLogFunction(A2lLogStream::LogToConsole);

  A2lLogStream::ShowLocation(true);
  A2L_TRACE() << "With Location";
  A2lLogStream::ShowLocation(false);
  A2L_DEBUG() << "Without Location";

  A2lLogStream::ShowLocation(true);
  A2L_INFO() << "Coyote and Road Runner";
  A2L_ERROR() << "ACME Exploding Tennis Balls";
  A2lLogStream::ResetLogFunction();
}

}