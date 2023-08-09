#ifndef CPP_PARSER_COMBINATOR_HPP_
#define CPP_PARSER_COMBINATOR_HPP_

#include <string>
#include <vector>


namespace cpp_parser_combinator {
    class ParserState {
      public:
        ParserState(std::string raw_input);
        ParserState(const ParserState& state);
    
        std::string input;
        std::vector<std::string> results;
        int index;
        bool is_error;
        std::string error;
    };
    
    class Parser {
      public:
        virtual ParserState run(ParserState state) = 0;
    };

    class NumberParser: public Parser {
      public:
        ParserState run(ParserState state) override;
    };

    ParserState run(Parser& parser, std::string input);
}

#endif  // CPP_PARSER_COMBINATOR_HPP_
