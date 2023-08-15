#include <string>
#include <fmt/core.h>
#include <cpp_parser_combinator/cpp_parser_combinator.hpp>

using namespace cpp_parser_combinator;


StringParser::StringParser(std::string target) {
    target_string = target;
}

ParserState StringParser::run(ParserState state) {
    ParserState next_state(state);
    
    std::size_t found = state.input.substr(state.index).find(target_string);
    
    if (found == std::string::npos) {
        next_state.is_error = true;
        next_state.error = fmt::format(
            "Target '{}' is not in '{}'",
            target_string,
            state.input
        );
        next_state.results.clear();
        return next_state;
    }
    if (found != 0) {
        next_state.is_error = true;
        next_state.error = fmt::format(
            "Target '{}' is not at the beginning of '{}'",
            target_string,
            state.input
        );
        next_state.results.clear();
        return next_state;
    }

    next_state.results.push_back(std::string(target_string));
    next_state.index += target_string.length();
    
    return next_state;
}
