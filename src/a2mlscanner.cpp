/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#include "a2mlscanner.h"

namespace a2l {

A2mlScanner::A2mlScanner(std::istream& message)
    : a2mlFlexLexer(&message), yylval(nullptr) {

}


}  // namespace a2l