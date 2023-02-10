cmake_minimum_required(VERSION 3.24)

project(factorial_lest LANGUAGES CXX)

add_library(factorial_lest STATIC src/factorial.cpp include/factorial.h)

target_sources(factorial_lest PUBLIC src/factorial.cpp)
target_include_directories(factorial_lest PUBLIC "${CMAKE_SOURCE_DIR}")

add_subdirectory(test)
