#include <string>
#include <vector>
#include <cpp_parser_combinator/cpp_parser_combinator.hpp>

using cpp_parser_combinator::ParserState;


ParserState::ParserState(std::string raw_input) {
    input = raw_input;
    results = std::vector<std::string>();
    is_error = false;
    error = "";
    index = 0;
}

ParserState::ParserState(const ParserState& state) {
    input = state.input;
    results = state.results;
    index = state.index;
    is_error = state.is_error;
    error = state.error;
}
