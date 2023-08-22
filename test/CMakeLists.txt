# Copyright 2023 Ingemar Hedvall
# SPDX-License-Identifier: MIT

project(TestA2l
        VERSION 1.0
        DESCRIPTION "Google unit tests for the A2L library"
        LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

add_executable(test_a2l
        testparse.cpp testparse.h
        test_a2lhelper.cpp)

target_include_directories(test_a2l PRIVATE
        ../src  # dbchelper.h
        ${GTEST_INCLUDE_DIRS}
        ${Boost_INCLUDE_DIRS})

if (MINGW)
    target_link_options(test_a2l PRIVATE -static -fstack-protector)
elseif (MSVC)
    target_compile_definitions(test_a2l PRIVATE -D_WIN32_WINNT=0x0A00)
endif ()

target_link_libraries(test_a2l PRIVATE a2l)
target_link_libraries(test_a2l PRIVATE ${GTEST_BOTH_LIBRARIES})
target_link_libraries(test_a2l PRIVATE ${Boost_LIBRARIES})
include(GoogleTest)
gtest_discover_tests(test_a2l)


