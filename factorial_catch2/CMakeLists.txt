cmake_minimum_required(VERSION 3.14)

project(factorial_catch2 LANGUAGES CXX)

add_library(factorial_catch2 STATIC src/factorial.cpp include/factorial.h)

target_sources(factorial_catch2 PUBLIC src/factorial.cpp)
target_include_directories(factorial_catch2 PUBLIC "${CMAKE_SOURCE_DIR}")

add_subdirectory(test)
