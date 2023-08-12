cmake_minimum_required(VERSION 3.14)
project(CppParserCombinator)
include(FetchContent)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_POSITION_INDEPENDENT_CODE TRUE)
cmake_policy(SET CMP0135 NEW)

# Get GoogleTest
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)
add_subdirectory("${PROJECT_SOURCE_DIR}/3rd-party/fmtlib")

### The library ###

add_library(
    CppParserCombinator
    src/parser_state.cpp
    src/run.cpp
    src/number_parser.cpp
    src/string_parser.cpp
)
target_include_directories(
    CppParserCombinator PUBLIC
    "${PROJECT_SOURCE_DIR}/include"
    "${fmt_SOURCE_DIR}/include"
)
target_link_libraries(CppParserCombinator fmt::fmt)


### Testing ###

enable_testing()

## NumberParser ##
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

## StringParser ##

add_executable(
    string_parser_test
    test/string_parser_test.cpp
)
target_link_libraries(
    string_parser_test
    CppParserCombinator
    GTest::gtest_main
)
target_include_directories(
    string_parser_test PUBLIC
    "${PROJECT_SOURCE_DIR}/include"
)

include(GoogleTest)
gtest_discover_tests(number_parser_test)
gtest_discover_tests(string_parser_test)
