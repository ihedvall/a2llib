/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "ifdatascanner.h"


namespace a2l {

IfDataScanner::IfDataScanner(std::istream& message)
    : ifdataFlexLexer(&message), yylval(nullptr) {

}

}  // namespace a2l