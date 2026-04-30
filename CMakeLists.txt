# Copyright 2023 Ingemar Hedvall
# SPDX-License-Identifier: MIT
cmake_minimum_required(VERSION 3.20)
include(CMakePrintHelpers)

if("${CMAKE_TOOLCHAIN_FILE}" STREQUAL "")
    set(USE_VCPKG OFF)
else()
    set(USE_VCPKG ON)
endif()

option(BUILD_SHARED_LIBS "Static libraries are preferred" OFF)
option(A2L_DOC "If doxygen is installed, then build documentation in Release mode" OFF)
option(A2L_TOOLS "Building applications" OFF)
option(A2L_TEST "Building unit test" OFF)
option(A2L_FLEX "Create FLEX/BISON files" OFF)

if(A2L_TOOLS AND USE_VCPKG)
    list(APPEND VCPKG_MANIFEST_FEATURES "tools")
endif()

project(a2llib
        VERSION 1.0
        DESCRIPTION "ASAP 2 parser C++ library."
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_DEBUG_POSTFIX d)

include(script/boost.cmake)

if (A2L_TOOLS)
    include(script/wxwidgets.cmake)
endif()

if (A2L_TEST)
    include(script/googletest.cmake)
endif()

if (A2L_DOC)
    include(script/doxygen.cmake)
endif()

if (A2L_FLEX)
    include(script/flex.cmake)
    include(script/bison.cmake)
endif()

if (BISON_FOUND AND A2L_FLEX)
    BISON_TARGET(A2L_PARSER src/a2lparser.y ${CMAKE_CURRENT_SOURCE_DIR}/src/a2lparser.cpp
            COMPILE_FLAGS "")
    cmake_print_variables(BISON_A2L_PARSER_DEFINED
            BISON_A2L_PARSER_INPUT
            BISON_A2L_PARSER_OUTPUT_SOURCE
            BISON_A2L_PARSER_OUTPUT_HEADER
            BISON_A2L_PARSER_OUTPUTS
            BISON_A2L_PARSER_COMPILE_FLAGS
            BISON_INCLUDE_DIRS)

    BISON_TARGET(AML_PARSER src/amlparser.y ${CMAKE_CURRENT_SOURCE_DIR}/src/amlparser.cpp
            COMPILE_FLAGS "")
    cmake_print_variables(BISON_AML_PARSER_DEFINED
            BISON_AML_PARSER_INPUT
            BISON_AML_PARSER_OUTPUT_SOURCE
            BISON_AML_PARSER_OUTPUT_HEADER
            BISON_AML_PARSER_OUTPUTS
            BISON_AML_PARSER_COMPILE_FLAGS
            BISON_INCLUDE_DIRS)

    BISON_TARGET(IF_DATA_PARSER src/ifdataparser.y ${CMAKE_CURRENT_SOURCE_DIR}/src/ifdataparser.cpp
            COMPILE_FLAGS "")
    cmake_print_variables(BISON_IF_DATA_PARSER_DEFINED
            BISON_IF_DATA_PARSER_INPUT
            BISON_IF_DATA_PARSER_OUTPUT_SOURCE
            BISON_IF_DATA_PARSER_OUTPUT_HEADER
            BISON_IF_DATA_PARSER_OUTPUTS
            BISON_IF_DATA_PARSER_COMPILE_FLAGS
            BISON_INCLUDE_DIRS)

    BISON_TARGET(XCP_DATA_PARSER src/xcp/xcpdataparser.y ${CMAKE_CURRENT_SOURCE_DIR}/src/xcp/xcpdataparser.cpp
            COMPILE_FLAGS "-Wcounterexamples")
    cmake_print_variables(BISON_XCP_DATA_PARSER_DEFINED
            BISON_XCP_DATA_PARSER_INPUT
            BISON_XCP_DATA_PARSER_OUTPUT_SOURCE
            BISON_XCP_DATA_PARSER_OUTPUT_HEADER
            BISON_XCP_DATA_PARSER_OUTPUTS
            BISON_XCP_DATA_PARSER_COMPILE_FLAGS
            BISON_INCLUDE_DIRS)
endif ()

if (FLEX_FOUND AND A2L_FLEX)
    FLEX_TARGET(A2L_SCANNER src/a2lflexer.l ${CMAKE_CURRENT_SOURCE_DIR}/src/a2lflexer.cpp)
    cmake_print_variables(FLEX_A2L_SCANNER_DEFINED
            FLEX_A2L_SCANNER_OUTPUTS
            FLEX_A2L_SCANNER_INPUT
            FLEX_A2L_SCANNER_OUTPUT_HEADER
            FLEX_INCLUDE_DIRS)

    FLEX_TARGET(AML_SCANNER src/amlflexer.l ${CMAKE_CURRENT_SOURCE_DIR}/src/amlflexer.cpp)
    cmake_print_variables(FLEX_AML_SCANNER_DEFINED
            FLEX_AML_SCANNER_OUTPUTS
            FLEX_AML_SCANNER_INPUT
            FLEX_AML_SCANNER_OUTPUT_HEADER
            FLEX_INCLUDE_DIRS)

    FLEX_TARGET(IF_DATA_SCANNER src/ifdataflexer.l ${CMAKE_CURRENT_SOURCE_DIR}/src/ifdataflexer.cpp)
    cmake_print_variables(FLEX_IF_DATA_SCANNER_DEFINED
            FLEX_IF_DATA_SCANNER_OUTPUTS
            FLEX_IF_DATA_SCANNER_INPUT
            FLEX_IF_DATA_SCANNER_OUTPUT_HEADER
            FLEX_INCLUDE_DIRS)

    FLEX_TARGET(XCP_DATA_SCANNER src/xcp/xcpdataflexer.l ${CMAKE_CURRENT_SOURCE_DIR}/src/xcp/xcpdataflexer.cpp)
    cmake_print_variables(FLEX_XCP_DATA_SCANNER_DEFINED
            FLEX_XCP_DATA_SCANNER_OUTPUTS
            FLEX_XCP_DATA_SCANNER_INPUT
            FLEX_XCP_DATA_SCANNER_OUTPUT_HEADER
            FLEX_INCLUDE_DIRS)
    # Copy FlexLexer.h. This is a dirty trick to avoid flex/bison installation in windows build
    file(COPY_FILE ${FLEX_INCLUDE_DIRS}/FlexLexer.h ${CMAKE_CURRENT_SOURCE_DIR}/src/FlexLexer.h)
endif ()

if (FLEX_FOUND AND BISON_FOUND)
    ADD_FLEX_BISON_DEPENDENCY(A2L_SCANNER A2L_PARSER)
    ADD_FLEX_BISON_DEPENDENCY(AML_SCANNER AML_PARSER)
    ADD_FLEX_BISON_DEPENDENCY(IF_DATA_SCANNER IF_DATA_PARSER)
    ADD_FLEX_BISON_DEPENDENCY(XCP_DATA_SCANNER XCP_DATA_PARSER)
endif()

set(A2L_HEADERS
        include/a2l/a2lfile.h
        include/a2l/a2lstructs.h
        include/a2l/a2lproject.h
        include/a2l/module.h
        include/a2l/a2lobject.h
        include/a2l/a2lenums.h
        include/a2l/axispts.h
        include/a2l/blob.h
        include/a2l/characteristic.h
        include/a2l/axisdescr.h
        include/a2l/compumethod.h
        include/a2l/compuvtab.h
        include/a2l/computab.h
        include/a2l/compuvtabrange.h
        include/a2l/frame.h
        include/a2l/function.h
        include/a2l/group.h
        include/a2l/instance.h
        include/a2l/overwrite.h
        include/a2l/measurement.h
        include/a2l/recordlayout.h
        include/a2l/transformer.h
        include/a2l/structure.h
        include/a2l/unit.h
        include/a2l/amlmember.h
        include/a2l/amlsection.h
        include/a2l/amldefinition.h
        include/a2l/ifdataitem.h
        include/a2l/ifdatablock.h
        include/a2l/xcp/protocollayer.h
        include/a2l/xcp/ecustate.h
        include/a2l/xcp/memoryaccess.h
        include/a2l/xcp/daq.h
        include/a2l/xcp/daqlist.h
        include/a2l/xcp/event.h
        include/a2l/xcp/daqevent.h
        include/a2l/xcp/pag.h
        include/a2l/xcp/pgm.h
        include/a2l/xcp/communicationmode.h
        include/a2l/xcp/segment.h
        include/a2l/xcp/page.h
        include/a2l/xcp/timecorrelation.h
        include/a2l/xcp/clock.h
        include/a2l/xcp/timestampresolution.h
        include/a2l/xcp/timestamp.h
        include/a2l/xcp/timestampcharacteristic.h
        include/a2l/xcp/commonparameters.h
        include/a2l/xcp/datablock.h
        include/a2l/xcp/xcponsimulink.h
        include/a2l/xcp/protocol.h
        include/a2l/xcp/xcponflx.h
        include/a2l/xcp/flxbuffer.h
        include/a2l/xcp/xcponusb.h
        include/a2l/xcp/epparameters.h
        include/a2l/xcp/xcponudpip.h
        include/a2l/xcp/xcpontcpip.h
        include/a2l/xcp/xcponsxi.h
        include/a2l/xcp/xcponcan.h
)

add_library(a2l
        src/a2lparser.cpp src/a2lparser.hpp
        src/amlparser.cpp src/amlparser.hpp
        src/ifdataparser.cpp src/ifdataparser.hpp
        src/xcp/xcpdataparser.cpp src/xcp/xcpdataparser.hpp
        src/FlexLexer.h
        src/a2lflexer.cpp
        src/amlflexer.cpp
        src/ifdataflexer.cpp
        src/xcp/xcpdataflexer.cpp
        ${A2L_HEADERS}
        src/a2lscanner.cpp src/a2lscanner.h
        src/a2lfile.cpp
        src/a2lhelper.cpp src/a2lhelper.h
        src/a2lproject.cpp
        src/module.cpp
        src/a2lobject.cpp
        src/axispts.cpp
        src/a2lenums.cpp
        src/blob.cpp
        src/characteristic.cpp
        src/axisdescr.cpp
        src/compumethod.cpp
        src/compuvtab.cpp
        src/computab.cpp
        src/compuvtabrange.cpp
        src/frame.cpp
        src/function.cpp
        src/group.cpp
        src/instance.cpp
        src/overwrite.cpp
        src/measurement.cpp
        src/recordlayout.cpp
        src/transformer.cpp
        src/structure.cpp
        src/unit.cpp
        src/amlscanner.cpp
        src/amlscanner.h
        src/amlmember.cpp
        src/amldefinition.cpp
        src/amlsection.cpp
        src/ifdatascanner.cpp
        src/ifdatascanner.h
        src/ifdatablock.cpp
        src/xcp/protocollayer.cpp
        src/xcp/memoryaccess.cpp
        src/xcp/ecustate.cpp
        src/xcp/daq.cpp
        src/xcp/daqlist.cpp
        src/xcp/event.cpp
        src/xcp/daqevent.cpp
        src/xcp/pag.cpp
        src/xcp/pgm.cpp
        src/xcp/communicationmode.cpp
        src/xcp/segment.cpp
        src/xcp/page.cpp
        src/xcp/timecorrelation.cpp
        src/xcp/clock.cpp
        src/xcp/timestampresolution.cpp
        src/xcp/timestamp.cpp
        src/xcp/timestampcharacteristic.cpp
        src/xcp/commonparameters.cpp
        src/xcp/xcpdatascanner.cpp
        src/xcp/xcpdatascanner.h
        src/xcp/datablock.cpp
        src/xcp/xcponsimulink.cpp
        src/xcp/protocol.cpp
        src/xcp/xcponflx.cpp
        src/xcp/flxbuffer.cpp
        src/xcp/xcponusb.cpp
        src/xcp/epparameters.cpp
        src/xcp/xcponudpip.cpp
        src/xcp/xcpontcpip.cpp
        src/xcp/xcponsxi.cpp
        src/xcp/xcponcan.cpp
)

target_include_directories(a2l PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
       )
target_include_directories(a2l PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(a2l PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/xcp)
target_include_directories(a2l PRIVATE ${Boost_INCLUDE_DIRS})

cmake_print_properties(TARGETS a2l PROPERTIES INCLUDE_DIRECTORIES)

if (MSVC)
    target_compile_definitions(a2l PRIVATE _WIN32_WINNT=0x0A00)
endif ()


if (wxWidgets_FOUND AND A2L_TOOLS)
    add_subdirectory(a2lexplorer)
endif ()

if (A2L_TEST)
    enable_testing()
    add_subdirectory(test)
endif ()

if (DOXYGEN_FOUND AND (CMAKE_BUILD_TYPE MATCHES "^[Rr]elease") AND A2L_DOC)
    set(DOXYGEN_RECURSIVE NO)
    set(DOXYGEN_REPEAT_BRIEF NO)
    set(DOXYGEN_PROJECT_NAME "A2lLib")
    set(DOXYGEN_HTML_EXTRA_STYLESHEET doxygen/a2llib.css)
    set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/docs/manual)
    doxygen_add_docs(doc_liba2l ALL
            include/dbc doxygen
            COMMENT "A2L Library generating API documentation with Doxygen")
endif ()


##################################################################################
#####  Packaging and installation  ###############################################
##################################################################################
# install headers
# FILE_SET makes problems with GTest
#if (${CMAKE_MINOR_VERSION} GREATER_EQUAL 23)
#    target_sources(dbc PUBLIC
#                        FILE_SET HEADERS
#                        TYPE HEADERS
#                        BASE_DIRS include/dbc
#                        FILES ${HEADERS})
#else()
    if (WIN32)
        install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/a2l DESTINATION a2l/include)
    else()
        install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/a2l DESTINATION include)
    endif()
#endif()

if (WIN32)
    install(TARGETS a2l
            EXPORT a2lTargets
            LIBRARY DESTINATION a2l/lib
            ARCHIVE DESTINATION a2l/lib
            RUNTIME DESTINATION a2l/bin
#            FILE_SET HEADERS DESTINATION dbc/include
    )
else()
    install(TARGETS a2l
            EXPORT a2lTargets
            LIBRARY DESTINATION lib
            ARCHIVE DESTINATION lib
            RUNTIME DESTINATION bin
#            PUBLIC_HEADER
#            FILE_SET HEADERS DESTINATION include/dbc
        )
endif()

include(CMakePackageConfigHelpers)

set(CONFIG_VERSION_FILE "${CMAKE_CURRENT_BINARY_DIR}/a2l/a2lConfigVersion.cmake")
# generate *Version.cmake
write_basic_package_version_file(
        ${CONFIG_VERSION_FILE}
        VERSION ${PACKAGE_VERSION}
        COMPATIBILITY AnyNewerVersion)

# Export dbcTargets to file *Targets.cmake
export(EXPORT a2lTargets
  FILE "${CMAKE_CURRENT_BINARY_DIR}/liba2l/a2lTargets.cmake"
  NAMESPACE Upstream::
)

set(ConfigPackageLocation lib/cmake/a2l)
set(CONFIG_CMAKE "${CMAKE_CURRENT_BINARY_DIR}/a2l/a2lConfig.cmake")
# create final a2l *Config.make file
# https://cmake.org/cmake/help/latest/module/CMakePackageConfigHelpers.html
configure_package_config_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake/a2lConfig.cmake.in"
  ${CONFIG_CMAKE}
  INSTALL_DESTINATION ${ConfigPackageLocation}
)

# install *Targets.cmake
install(EXPORT a2lTargets
  FILE
    a2lTargets.cmake
  NAMESPACE
    A2l::
  DESTINATION
    ${ConfigPackageLocation}
)

# Install *Version.cmake and *Config.cmake
install(
  FILES
    ${CONFIG_VERSION_FILE}
    ${CONFIG_CMAKE}
  DESTINATION
    ${ConfigPackageLocation}
  COMPONENT
    Devel
)
