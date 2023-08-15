# CppParserCombinator

A parser combinator library for C++

## Usage

```cpp
#include <cpp_parser_combinator/cpp_parser_combinator.hpp>
#include <iostream>
#include <memory>

using namespace cp_parser_combinator;
using std::make_shared;


int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Invalid args" << std::endl;
        return -1;
    }

    // Create the parser
    // This parser will accept any input that starts with 'hello' and is
    // followed by 1+ numerical digits
    SequenceOfParser parser({
        make_shared<StringParser>("hello"),
        make_shared<NumberParser>()
    });

    // Run the parser on the program's input
    ParserState result = cpp_parser_combinator::run(parser, argv[1]);

    // Print the error if one exists
    if (result.is_error) {
        std::cerr << result.error << std::endl;
        return -1;
    }

    // Print out the results
    std::cout << "[" << std::endl;
    for (auto item: result.results) {
        std::cout << "\t" << item << std::endl;
    }
    std::cout << "]" << std::endl;
}
```
