cmake_minimum_required(VERSION 3.24)

project(factorial_criterion_tests LANGUAGES CXX)

if(UNIX AND NOT APPLE)
    set(CRITERION_ARCHIVE_URL https://github.com/Snaipe/Criterion/releases/download/v2.4.1/criterion-2.4.1-linux-x86_64.tar.xz)
else()
    message(FATAL_ERROR "Criterion binaries are only available for Linux platform")
endif()

include(FetchContent)
FetchContent_Declare(
    Criterion
    URL        ${CRITERION_ARCHIVE_URL}
    SOURCE_DIR ${CMAKE_BINARY_DIR}/criterion-src
)
FetchContent_Populate(Criterion)

set(CRITERION_LIB_DIR  ${CMAKE_BINARY_DIR}/criterion-src/lib)
set(CRITERION_INCLUDES ${CMAKE_BINARY_DIR}/criterion-src/include)

FetchContent_Declare(
    trompeloeil
    GIT_REPOSITORY https://github.com/rollbear/trompeloeil.git
    GIT_TAG        v43
    GIT_SHALLOW    TRUE)
FetchContent_MakeAvailable(trompeloeil)

add_executable(factorial_criterion_tests factorial_test.cpp)

target_include_directories(factorial_criterion_tests PUBLIC "${CRITERION_INCLUDES}" "${trompeloeil_SOURCE_DIR}/include"
    "${CMAKE_SOURCE_DIR}")
target_link_libraries(factorial_criterion_tests factorial_criterion ${CRITERION_LIB_DIR}/libcriterion.so)

add_test(NAME factorial_criterion_tests COMMAND factorial_criterion_tests)
