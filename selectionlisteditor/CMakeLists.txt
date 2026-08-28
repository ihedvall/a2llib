# Copyright 2026 Ingemar Hedvall
# SPDX-License-Identifier: MIT
cmake_minimum_required(VERSION 3.20)
project(SelectionListEditor
  VERSION 1.0
  DESCRIPTION "Simple Label File Editor"
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

add_executable(selectionlisteditor
        src/selectionlisteditor.cpp src/selectionlisteditor.h
        src/selectionlistdocument.cpp src/selectionlistdocument.h
        src/selectionlistframe.cpp src/selectionlistframe.h
        src/mainframe.cpp src/mainframe.h
        src/windowid.h
        src/selectionlist.rc
        src/selectiongrid.cpp src/selectiongrid.h
        src/selectiongridtable.cpp src/selectiongridtable.h
        src/selectionlistview.cpp src/selectionlistview.h
        src/objectlistpanel.cpp src/objectlistpanel.h
        src/characteristiclistview.cpp src/characteristiclistview.h
        src/filterlistview.cpp src/filterlistview.h
        src/selectionpage.cpp
        src/selectionpage.h
        src/selectionlistpanel.cpp
        src/selectionlistpanel.h
        src/rasterlistview.cpp
        src/rasterlistview.h
        src/measurementlistview.cpp
        src/measurementlistview.h
        src/functionlistview.cpp
        src/functionlistview.h
        src/grouplistview.cpp
        src/grouplistview.h
)

if(MSVC)
  target_link_options(selectionlisteditor PRIVATE /SUBSYSTEM:WINDOWS)
  target_compile_definitions(selectionlisteditor PRIVATE _WIN32_WINNT=0x0A00)
endif()

if(MINGW)
  target_link_options(selectionlisteditor PRIVATE -mwindows -static -fstack-protector)
endif()

target_link_libraries(selectionlisteditor PRIVATE a2l)
target_link_libraries(selectionlisteditor PRIVATE util)
target_link_libraries(selectionlisteditor PRIVATE uchardet::libuchardet)
target_link_libraries(selectionlisteditor PRIVATE EXPAT::EXPAT)
target_link_libraries(selectionlisteditor PRIVATE Boost::boost Boost::filesystem Boost::locale Boost::process)
target_link_libraries(selectionlisteditor PRIVATE ${wxWidgets_LIBRARIES})
if (USE_VCPKG)
  target_link_libraries(selectionlisteditor PRIVATE WebP::webp WebP::webpdemux )
endif()


