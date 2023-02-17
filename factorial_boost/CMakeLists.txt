cmake_minimum_required(VERSION 3.14)

project(factorial_boost LANGUAGES CXX)

add_library(factorial_boost STATIC src/factorial.cpp include/factorial.h)

target_sources(factorial_boost PUBLIC src/factorial.cpp)
target_include_directories(factorial_boost PUBLIC "${CMAKE_SOURCE_DIR}")

add_subdirectory(test)
