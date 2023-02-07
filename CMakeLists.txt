cmake_minimum_required(VERSION 3.24)

project("cpp-unit-testing-frameworks-demo" VERSION 1.0 DESCRIPTION "Demo of multiple C++ unit testing frameworks" LANGUAGES CXX)

# Enable CTest at the current directory and below (before add_subdirectory())
enable_testing()

add_subdirectory(app_factorial)
add_subdirectory(factorial_catch2)
add_subdirectory(factorial_gtest)
add_subdirectory(factorial_doctest)
add_subdirectory(factorial_boost)
