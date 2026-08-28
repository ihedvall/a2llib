# Copyright 2021 Ingemar Hedvall
# SPDX-License-Identifier: MIT
include (CMakePrintHelpers)
if (NOT EXPAT_FOUND)
    set(EXPAT_USE_STATIC_LIBS ON)
    if (COMP_DIR)
        set(EXPAT_ROOT ${COMP_DIR}/expat/master)
    endif()
    find_package(EXPAT REQUIRED)
endif()

cmake_print_variables(EXPAT_FOUND EXPAT_VERSION EXPAT_INCLUDE_DIRS EXPAT_LIBRARIES)
cmake_print_properties(TARGETS EXPAT::EXPAT
                       PROPERTIES INTERFACE_COMPILE_DEFINITIONS
                                  INTERFACE_INCLUDE_DIRECTORIES
                                  INTERFACE_LINK_LIBRARIES)
