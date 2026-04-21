/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "xcpdatascanner.h"

namespace a2l::xcp {
XcpDataScanner::XcpDataScanner(std::istream& message)
    : xcpFlexLexer(&message), yylval(nullptr) {

}

}