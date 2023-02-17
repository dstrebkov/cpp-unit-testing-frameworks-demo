cmake_minimum_required(VERSION 3.14)

project(factorial_criterion LANGUAGES CXX)

add_library(factorial_criterion STATIC src/factorial.cpp include/factorial.h)

target_sources(factorial_criterion PUBLIC src/factorial.cpp)
target_include_directories(factorial_criterion PUBLIC "${CMAKE_SOURCE_DIR}")

add_subdirectory(test)
