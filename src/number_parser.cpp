#include <string>
#include <cpp_parser_combinator/cpp_parser_combinator.hpp>

using namespace cpp_parser_combinator;


ParserState NumberParser::run(ParserState state) {
    ParserState next_state(state);
    std::string res = "";

    do {
        char c = next_state.input[next_state.index++];

        if (c < '0' || c > '9') {
            break;
        }

        res += c;
    } while (next_state.index < next_state.input.size());

    next_state.results.push_back(res);

    if (next_state.index - 1 == state.index) {
        next_state.is_error = true;
        next_state.error = "Expected digit but none were to be found";
        next_state.results.clear();
    }

    return next_state;
}
