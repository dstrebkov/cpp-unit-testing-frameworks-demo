cmake_minimum_required(VERSION 3.24)

project(factorial_lest_tests LANGUAGES CXX)

option(LEST_BUILD_TEST    "Build tests for lest" OFF)
option(LEST_BUILD_EXAMPLE "Build examples"       OFF)
option(LEST_BUILD_CONTRIB "Build contrib"        OFF)

include(FetchContent)
FetchContent_Declare(
    lest
    GIT_REPOSITORY https://github.com/martinmoene/lest.git
    GIT_TAG        v1.35.1
    GIT_SHALLOW    TRUE)
FetchContent_MakeAvailable(lest)

add_executable(factorial_lest_tests factorial_test.cpp)
target_include_directories(factorial_lest_tests PUBLIC "${lest_SOURCE_DIR}/include" "${CMAKE_SOURCE_DIR}")
target_link_libraries(factorial_lest_tests factorial_lest)

add_test(NAME factorial_lest_tests COMMAND factorial_lest_tests)
