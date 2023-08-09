cmake_minimum_required(VERSION 3.14)
project(CppParserCombinator)
include(FetchContent)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
cmake_policy(SET CMP0135 NEW)

# Get GoogleTest
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(
    CppParserCombinator
    src/parser_state.cpp
    src/run.cpp
    src/number_parser.cpp
)
target_include_directories(
    CppParserCombinator PUBLIC
    "${PROJECT_SOURCE_DIR}/include"
)


### Testing ###

enable_testing()

add_executable(
    number_parser_test
    test/number_parser_test.cpp
)
target_link_libraries(
    number_parser_test
    CppParserCombinator
    GTest::gtest_main
)
target_include_directories(
    number_parser_test PUBLIC
    "${PROJECT_SOURCE_DIR}/include"
)

include(GoogleTest)
gtest_discover_tests(number_parser_test)
