#include <gtest/gtest.h>
#include <cpp_parser_combinator/cpp_parser_combinator.hpp>

using namespace cpp_parser_combinator;


TEST(StringParser, SingleLetter) {
    StringParser parser("T");
    ParserState results = cpp_parser_combinator::run(parser, "Test");
    EXPECT_FALSE(results.is_error);
    EXPECT_STREQ(results.results[0].c_str(), "T");
}

TEST(StringParser, MultipleLetters) {
    StringParser parser("hello");
    ParserState results = cpp_parser_combinator::run(parser, "hello world!");
    EXPECT_FALSE(results.is_error);
    EXPECT_STREQ(results.results[0].c_str(), "hello");
}

TEST(StringParser, TargetNotInInput) {
    StringParser parser("target");
    ParserState results = cpp_parser_combinator::run(parser, "not in the input");
    EXPECT_TRUE(results.is_error);
    EXPECT_STREQ(
        results.error.c_str(),
        "Target 'target' is not in 'not in the input'"
    );
}

TEST(StringParser, TargetNotAtBeginning) {
    StringParser parser("hello");
    ParserState results = cpp_parser_combinator::run(parser, "world hello!");
    EXPECT_TRUE(results.is_error);
    EXPECT_STREQ(
        results.error.c_str(),
        "Target 'hello' is not at the beginning of 'world hello!'"
    );
}
