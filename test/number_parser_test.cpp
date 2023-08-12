#include <cpp_parser_combinator/cpp_parser_combinator.hpp>
#include <gtest/gtest.h>

using cpp_parser_combinator::NumberParser;
using cpp_parser_combinator::ParserState;


TEST(NumberParser, SingleDigit) {
    NumberParser parser = NumberParser();
    ParserState results = cpp_parser_combinator::run(parser, "5");
    EXPECT_STREQ(results.results[0].c_str(), "5");
}

TEST(NumberParser, MultiDigit) {
    NumberParser parser = NumberParser();
    ParserState results = cpp_parser_combinator::run(parser, "982398");
    EXPECT_STREQ(results.results[0].c_str(), "982398");
}

TEST(NumberParser, StopsAtNonDigit) {
    NumberParser parser = NumberParser();
    ParserState results = cpp_parser_combinator::run(parser, "1234y");
    EXPECT_STREQ(results.results[0].c_str(), "1234");
}

TEST(NumberParser, ErrorWhenNoDigits) {
    NumberParser parser = NumberParser();
    ParserState results = cpp_parser_combinator::run(parser, "u8kj");
    EXPECT_EQ(results.is_error, true);
    EXPECT_STRNE(results.error.c_str(), "");
}
