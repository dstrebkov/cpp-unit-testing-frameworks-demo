cmake_minimum_required(VERSION 3.24)

project(factorial_doctest_tests LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(
    doctest
    GIT_REPOSITORY https://github.com/onqtam/doctest.git
    GIT_TAG        v2.4.9
)
FetchContent_MakeAvailable(doctest)

add_executable(factorial_doctest_tests factorial_test.cpp)
target_include_directories(factorial_doctest_tests PUBLIC "${doctest_SOURCE_DIR}" "${CMAKE_SOURCE_DIR}")
target_link_libraries(factorial_doctest_tests PUBLIC doctest::doctest factorial_doctest)
