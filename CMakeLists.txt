cmake_minimum_required(VERSION 3.24)

project("cpp-unit-testing-frameworks-demo" VERSION 1.0 DESCRIPTION "Demo of multiple C++ unit testing frameworks" LANGUAGES CXX)

option(BUILD_FACTORIAL_BOOST_TEST_LIB "Build library that uses Boost.Test") # OFF by default

# Enable CTest at the current directory and below (before add_subdirectory())
enable_testing()

if(BUILD_FACTORIAL_BOOST_TEST_LIB)
    ADD_DEFINITIONS(-DBUILD_FACTORIAL_BOOST_TEST_LIB)
    add_subdirectory(factorial_boost)
endif()

if(UNIX AND NOT APPLE)
    add_subdirectory(factorial_criterion)
endif()

add_subdirectory(factorial_catch2)
add_subdirectory(factorial_doctest)
add_subdirectory(factorial_gtest)
add_subdirectory(factorial_lest)

add_subdirectory(app_factorial)
