cmake_minimum_required(VERSION 3.24)

project(app_factorial LANGUAGES CXX)

add_executable(app_factorial)

target_sources(app_factorial PRIVATE src/main.cpp)
target_include_directories(app_factorial PUBLIC "${CMAKE_SOURCE_DIR}")

if(BUILD_FACTORIAL_BOOST_TEST_LIB)
    set(UNIT_TESTING_FRAMEWORKS factorial_catch2 factorial_gtest factorial_doctest factorial_boost)
else()
    set(UNIT_TESTING_FRAMEWORKS factorial_catch2 factorial_gtest factorial_doctest)
endif()

target_link_libraries(app_factorial PRIVATE ${UNIT_TESTING_FRAMEWORKS})
