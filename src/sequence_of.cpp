#include <memory>
#include <cpp_parser_combinator/cpp_parser_combinator.hpp>

using namespace cpp_parser_combinator;


SequenceOfParser::SequenceOfParser(
    std::initializer_list<std::shared_ptr<Parser>> parser_list
) {
    parsers = std::vector<std::shared_ptr<Parser>>{parser_list};
}

ParserState SequenceOfParser::run(ParserState state) {
    ParserState next_state(state);
    std::vector<std::string> results = {};

    for (std::shared_ptr<Parser> parser: parsers) {
        next_state = parser->run(next_state);

        for (auto result: next_state.results) {
            results.push_back(result);
        }
    }

    return next_state;
}
