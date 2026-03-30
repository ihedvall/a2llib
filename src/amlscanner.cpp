/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#include "amlscanner.h"

namespace a2l {

AmlScanner::AmlScanner(std::istream& message)
    : amlFlexLexer(&message), yylval(nullptr) {

}


}  // namespace a2l