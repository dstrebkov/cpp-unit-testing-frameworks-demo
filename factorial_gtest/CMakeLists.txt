cmake_minimum_required(VERSION 3.14)

project(factorial_gtest LANGUAGES CXX)

add_library(factorial_gtest STATIC src/factorial.cpp include/factorial.h)

target_sources(factorial_gtest PUBLIC src/factorial.cpp)
target_include_directories(factorial_gtest PUBLIC "${CMAKE_SOURCE_DIR}")

add_subdirectory(test)
