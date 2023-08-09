#include <string>
#include <vector>
#include <cpp_parser_combinator/cpp_parser_combinator.hpp>

using namespace cpp_parser_combinator;


ParserState cpp_parser_combinator::run(Parser& parser, std::string input) {
    ParserState state(input);
    return parser.run(input);
}
