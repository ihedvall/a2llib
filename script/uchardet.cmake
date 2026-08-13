# Copyright 2026 Ingemar Hedvall
# SPDX-License-Identifier: MIT

include (CMakePrintHelpers)

if (NOT uchardet_FOUND)
    if (COMP_DIR)
        set(uchardet_ROOT ${COMP_DIR}/uchardet/master)
    endif()
    find_package(uchardet CONFIG REQUIRED)
endif()

cmake_print_variables(uchardet_FOUND
                      uchardet_VERSION
                      uchardet_LOCATION
                      uchardet_ROOT)
cmake_print_properties(TARGETS uchardet::libuchardet
                       PROPERTIES INTERFACE_INCLUDE_DIRECTORIES INTERFACE_LOCATION )
