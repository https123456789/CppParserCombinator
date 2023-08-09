#include <string>
#include <iostream>
#include <cpp_parser_combinator/cpp_parser_combinator.hpp>

using namespace cpp_parser_combinator;


ParserState NumberParser::run(ParserState state) {
    ParserState nextState(state);
    std::string res = "";

    do {
        char c = nextState.input[nextState.index++];
        
        if (c < '0' || c > '9') {
            break;
        }
        
        res += c;
    } while (nextState.index < nextState.input.size());

    nextState.results.push_back(res);
    
    if (nextState.index - 1 == state.index) {
        nextState.is_error = true;
        nextState.error = "Expected digit but none where to be found.";
        nextState.results.clear();
    }
    
    return nextState;
}
