# Copyright 2022 Ingemar Hedvall
# SPDX-License-Identifier: MIT

include(CMakePrintHelpers)
if (NOT BISON_FOUND)
    find_package(BISON)
    cmake_print_variables(BISON_FOUND BISON_EXECUTABLE BISON_VERSION)
endif()