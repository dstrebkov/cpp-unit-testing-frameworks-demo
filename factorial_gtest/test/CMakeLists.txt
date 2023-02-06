cmake_minimum_required(VERSION 3.24)

project(factorial_gtest_tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.13.0)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(factorial_gtest_tests factorial_test.cpp)
target_include_directories(factorial_gtest_tests PUBLIC "${CMAKE_SOURCE_DIR}")
target_link_libraries(factorial_gtest_tests GTest::gtest_main factorial_gtest)

include(GoogleTest)
gtest_discover_tests(factorial_gtest_tests)
