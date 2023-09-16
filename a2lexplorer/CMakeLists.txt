# Copyright 2023 Ingemar Hedvall
# SPDX-License-Identifier: MIT
cmake_minimum_required(VERSION 3.20)
project(
  A2lExplorer
  VERSION 1.0
  DESCRIPTION "Simple A2L file explorer"
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

include("../script/utillib.cmake")

add_executable(a2lexplorer
        src/a2lexplorer.cpp src/a2lexplorer.h
        src/mainframe.cpp src/mainframe.h
        src/a2ldocument.cpp src/a2ldocument.h
        src/a2lview.cpp src/a2lview.h
        src/a2lexplorer.rc
        src/childframe.cpp src/childframe.h
        src/windowid.h
        src/a2ltreelist.cpp
        src/a2ltreelist.h
        src/a2lpropertygrid.cpp
        src/a2lpropertygrid.h)

target_include_directories(a2lexplorer PRIVATE a2l)


if(MSVC)
  target_link_options(a2lexplorer PRIVATE /SUBSYSTEM:WINDOWS)
  target_compile_definitions(a2lexplorer PRIVATE _WIN32_WINNT=0x0A00)
endif()

if(MINGW)
  target_link_options(a2lexplorer PRIVATE -mwindows -static -fstack-protector)
endif()

target_link_libraries(a2lexplorer PRIVATE a2l)
target_link_libraries(a2lexplorer PRIVATE util)

if(VCPKG)
  find_package(expat CONFIG REQUIRED)
  target_link_libraries(a2lexplorer PRIVATE expat::expat)

  find_package(Boost REQUIRED COMPONENTS filesystem locale)
  target_link_libraries(a2lexplorer PRIVATE Boost::boost Boost::filesystem Boost::locale)

  find_package(wxWidgets CONFIG REQUIRED)
  target_link_libraries(a2lexplorer PRIVATE wx::propgrid wx::adv wx::core wx::base)
else()
  include("../script/expat.cmake")
  include("../script/wxwidgets.cmake")
  include("../script/boost.cmake")


  target_include_directories(a2lexplorer PRIVATE ${wxWidgets_INCLUDE_DIRS})
  target_include_directories(a2lexplorer PRIVATE ${Boost_INCLUDE_DIRS})

  target_compile_definitions(a2lexplorer PRIVATE XML_STATIC)

  target_link_libraries(a2lexplorer PRIVATE EXPAT::EXPAT)
  target_link_libraries(a2lexplorer PRIVATE ${wxWidgets_LIBRARIES})
  target_link_libraries(a2lexplorer PRIVATE ${wxWidgets_LIB_DIR}/wxscintillad.lib)
  target_link_libraries(a2lexplorer PRIVATE ${wxWidgets_LIB_DIR}/wxlexillad.lib)
  target_link_libraries(a2lexplorer PRIVATE ${Boost_LIBRARIES})
endif()


if(MINGW)
  target_link_options(a2lexplorer PRIVATE -mwindows -static -fstack-protector)
  target_link_libraries(a2lexplorer PRIVATE iconv)
elseif (MSVC)
  target_link_options(a2lexplorer PRIVATE /SUBSYSTEM:WINDOWS)
  target_compile_definitions(a2lexplorer PRIVATE -D_WIN32_WINNT=0x0A00)
endif ()


if(WIN32)
  target_link_libraries(a2lexplorer PRIVATE bcrypt)
  target_link_libraries(a2lexplorer PRIVATE ws2_32)
  target_link_libraries(a2lexplorer PRIVATE mswsock)
endif()

if(UNIX)
  target_link_libraries(a2lexplorer PRIVATE rt icuuc icui18n)
endif(UNIX)
