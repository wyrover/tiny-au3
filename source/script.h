#ifndef SCRIPT_H
#define SCRIPT_H

#include <string>

#include "lexer.h"
#include "parser.h"

namespace tiny_au3
{

class Script
{
public:
    Script(const std::string& input_file) :
        input_file_(input_file) {}

    void Execute();

private:
    std::string input_file_;
    Lexer lexer_;
    Parser parser_;
};

}

#endif
