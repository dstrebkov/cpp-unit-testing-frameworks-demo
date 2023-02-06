cmake_minimum_required(VERSION 3.24)

project(factorial_doctest LANGUAGES CXX)

add_library(factorial_doctest STATIC src/factorial.cpp include/factorial.h)

target_sources(factorial_doctest PUBLIC src/factorial.cpp)
target_include_directories(factorial_doctest PUBLIC "${CMAKE_SOURCE_DIR}")

add_subdirectory(test EXCLUDE_FROM_ALL)
