#include <memory>
#include <cpp_parser_combinator/cpp_parser_combinator.hpp>
#include <gtest/gtest.h>

using cpp_parser_combinator::SequenceOfParser;
using cpp_parser_combinator::StringParser;
using cpp_parser_combinator::NumberParser;
using cpp_parser_combinator::ParserState;


TEST(SequenceOfParser, StringAndNumber) {
    SequenceOfParser parser({
        std::make_shared<StringParser>("hello"),
        std::make_shared<NumberParser>()
    });
    ParserState results = cpp_parser_combinator::run(parser, "hello123");
    EXPECT_FALSE(results.is_error);
    EXPECT_EQ(results.results.size(), 2);
    EXPECT_EQ(results.results[0], "hello");
    EXPECT_EQ(results.results[1], "123");
}

TEST(SequenceOfParser, SequenceError) {
    SequenceOfParser parser({
        std::make_shared<StringParser>("hello"),
        std::make_shared<NumberParser>()
    });
    ParserState results = cpp_parser_combinator::run(parser, "hello");
    EXPECT_TRUE(results.is_error);
    EXPECT_EQ(
        results.error,
        "Expected digit but none were to be found"
    );
    EXPECT_EQ(results.results.size(), 0);
}
