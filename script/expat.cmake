# Copyright 2021 Ingemar Hedvall
# SPDX-License-Identifier: MIT

if (NOT EXPAT_FOUND)
    find_package(EXPAT)
    message(STATUS "EXPAT Found (Try 1): "  ${EXPAT_FOUND})
    if (NOT EXPAT_FOUND)
        set(EXPAT_USE_STATIC_LIBS ON)
        if (COMP_DIR)
            set(EXPAT_ROOT ${COMP_DIR}/expat/master)
        endif()

        find_package(EXPAT REQUIRED)
        message(STATUS "EXPAT Found (Try 2): "  ${EXPAT_FOUND})
    endif()
    message(STATUS "EXPAT Include Dirs: "  ${EXPAT_INCLUDE_DIRS})
    message(STATUS "EXPAT Libraries: " ${EXPAT_LIBRARIES})
endif()


