#include <string>
#include <fmt/core.h>
#include <cpp_parser_combinator/cpp_parser_combinator.hpp>

using namespace cpp_parser_combinator;


StringParser::StringParser(std::string target) {
    targetString = target;
}

ParserState StringParser::run(ParserState state) {
    ParserState nextState(state);
    
    std::size_t found = state.input.substr(state.index).find(targetString);
    
    if (found == std::string::npos) {
        nextState.is_error = true;
        nextState.error = fmt::format(
            "Target '{}' is not in '{}'",
            targetString,
            state.input
        );
        nextState.results.clear();
        return nextState;
    }
    if (found != 0) {
        nextState.is_error = true;
        nextState.error = fmt::format(
            "Target '{}' is not at the beginning of '{}'",
            targetString,
            state.input
        );
        nextState.results.clear();
        return nextState;
    }

    nextState.results.push_back(std::string(targetString));
    
    return nextState;
}
