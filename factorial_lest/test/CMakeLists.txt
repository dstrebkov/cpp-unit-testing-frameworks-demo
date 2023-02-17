cmake_minimum_required(VERSION 3.14)

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
FetchContent_Declare(
    trompeloeil
    GIT_REPOSITORY https://github.com/rollbear/trompeloeil.git
    GIT_TAG        v43
    GIT_SHALLOW    TRUE)
FetchContent_MakeAvailable(lest)
FetchContent_MakeAvailable(trompeloeil)

add_executable(factorial_lest_tests factorial_test.cpp)

set_target_properties(factorial_lest_tests PROPERTIES CXX_STANDARD 14)

# To get rid from error "error: macro "lest_CASE" passed 2 arguments, but takes just 1", doing...
ADD_DEFINITIONS(-Dlest_FEATURE_AUTO_REGISTER=1)

target_include_directories(factorial_lest_tests PUBLIC "${lest_SOURCE_DIR}/include" "${trompeloeil_SOURCE_DIR}/include"
    "${CMAKE_SOURCE_DIR}")
target_link_libraries(factorial_lest_tests factorial_lest)

add_test(NAME factorial_lest_tests COMMAND factorial_lest_tests)
