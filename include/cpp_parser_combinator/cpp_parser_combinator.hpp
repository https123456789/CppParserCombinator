#ifndef CPP_PARSER_COMBINATOR_HPP_
#define CPP_PARSER_COMBINATOR_HPP_

#include <memory>
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

    class StringParser: public Parser {
      public:
        StringParser(std::string target);
        ParserState run(ParserState state) override;

        std::string target_string;
    };

    class SequenceOfParser: public Parser {
      public:
        SequenceOfParser(std::initializer_list<std::shared_ptr<Parser>> parser_list);
        ParserState run(ParserState state) override;
      private:
        std::vector<std::shared_ptr<Parser>> parsers;
    };

    ParserState run(Parser& parser, std::string input);
}

#endif  // CPP_PARSER_COMBINATOR_HPP_
