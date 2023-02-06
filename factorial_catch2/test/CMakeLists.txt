cmake_minimum_required(VERSION 3.24)

project(factorial_catch2_tests LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.2.0
    GIT_SHALLOW    TRUE)
FetchContent_Declare(
    FakeIt
    GIT_REPOSITORY https://github.com/eranpeer/FakeIt.git
    GIT_TAG        2.3.2
    GIT_SHALLOW    TRUE)
FetchContent_MakeAvailable(Catch2)
FetchContent_MakeAvailable(FakeIt)

add_executable(factorial_catch2_tests factorial_test.cpp)

target_include_directories(factorial_catch2_tests PUBLIC "${CMAKE_SOURCE_DIR}"
    "${fakeit_SOURCE_DIR}/single_header/catch")
target_link_libraries(factorial_catch2_tests PUBLIC Catch2::Catch2WithMain factorial_catch2)

list(APPEND CMAKE_MODULE_PATH "${Catch2_SOURCE_DIR}/extras")
include(CTest)
include(Catch)
catch_discover_tests(factorial_catch2_tests)
