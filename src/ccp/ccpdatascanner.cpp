/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "ccpdatascanner.h"

namespace a2l::ccp {
CcpDataScanner::CcpDataScanner(std::istream& message)
    : ccpFlexLexer(&message), yylval(nullptr) {

}

}