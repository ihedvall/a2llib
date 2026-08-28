# Copyright 2021 Ingemar Hedvall
# SPDX-License-Identifier: MIT

include (CMakePrintHelpers)
if (NOT wxWidgets_FOUND )
  find_package(wxWidgets COMPONENTS propgrid adv base core)
endif()

if (wxWidgets_FOUND)
  include(UsewxWidgets)
endif()

if (NOT wxWidgets_FOUND)
    if (COMP_DIR)
        set(wxWidgets_ROOT_DIR ${COMP_DIR}/wxwidgets/master)
    endif()
#        if (MINGW)
#            set(wxWidgets_LIB_DIR ${COMP_DIR}/wxwidgets/master/lib/gcc_x64_lib)
#        else()
#            set(wxWidgets_LIB_DIR ${COMP_DIR}/wxwidgets/master/lib/vc_x64_lib)
#        endif()
#    else()
#        set(CMAKE_FIND_ROOT_PATH ${COMP_DIR}/wxwidgets/master)
        set(wxWidgets_USE_STATIC ON)
        set(wxWidgets_USE_UNICODE ON)
        if (CMAKE_BUILD_TYPE MATCHES "^[Dd]ebug")
            set(wxWidgets_USE_DEBUG ON)
        else()
            set(wxWidgets_USE_DEBUG OFF)
        endif()
        set(wxWidgets_USE_UNIVERSAL OFF)
#    endif()
    find_package(wxWidgets REQUIRED COMPONENTS propgrid adv base core)
    include(UsewxWidgets)

endif()
cmake_print_variables(wxWidgets_FOUND
                      wxWidgets_VERSION
                      wxWidgets_INCLUDE_DIRS
                      wxWidgets_LIBRARIES
                      wxWidgets_LIBRARY_DIRS
                      wxWidgets_DEFINITIONS)

cmake_print_properties(TARGETS wxWidgets::wxWidgets
                       PROPERTIES INTERFACE_INCLUDE_DIRECTORIES
                                  INTERFACE_LINK_LIBRARIES )

if (USE_VCPKG)
    find_package(WebP CONFIG REQUIRED)

endif()


