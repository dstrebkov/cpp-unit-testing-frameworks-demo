cmake_minimum_required(VERSION 3.24)

project(factorial_boost_tests LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(
    boost
    GIT_REPOSITORY https://github.com/boostorg/boost.git
    GIT_TAG        boost-1.81.0
    GIT_SHALLOW    TRUE)
FetchContent_MakeAvailable(boost)

add_executable(factorial_boost_tests factorial_test.cpp)
target_link_libraries(factorial_boost_tests PRIVATE factorial_boost)

set(FACTORIAL_BOOST_TEST_INCLUDE_DIRS
    "${boost_test_SOURCE_DIR}/include"
    "${boost_config_SOURCE_DIR}/include"
    "${boost_type_traits_SOURCE_DIR}/include"
    "${boost_core_SOURCE_DIR}/include"
    "${boost_preprocessor_SOURCE_DIR}/include"
    "${boost_utility_SOURCE_DIR}/include"
    "${boost_smart_ptr_SOURCE_DIR}/include"
    "${boost_throw_exception_SOURCE_DIR}/include"
    "${boost_assert_SOURCE_DIR}/include"
    "${boost_detail_SOURCE_DIR}/include"
    "${boost_function_SOURCE_DIR}/include"
    "${boost_integer_SOURCE_DIR}/include"
    "${boost_static_assert_SOURCE_DIR}/include"
    "${boost_type_index_SOURCE_DIR}/include"
    "${boost_container_hash_SOURCE_DIR}/include"
    "${boost_bind_SOURCE_DIR}/include"
    "${boost_move_SOURCE_DIR}/include"
    "${boost_mpl_SOURCE_DIR}/include"
    "${boost_iterator_SOURCE_DIR}/include"
    "${boost_exception_SOURCE_DIR}/include"
    "${boost_io_SOURCE_DIR}/include"
    "${boost_numeric_conversion_SOURCE_DIR}/include"
    "${boost_algorithm_SOURCE_DIR}/include"
    "${boost_range_SOURCE_DIR}/include")

target_include_directories(factorial_boost_tests PUBLIC "${CMAKE_SOURCE_DIR}" ${FACTORIAL_BOOST_TEST_INCLUDE_DIRS})

add_test(NAME factorial_boost_tests COMMAND factorial_boost_tests)
