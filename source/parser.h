#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "variable_table.h"

namespace tiny_au3
{

class Parser
{
public:
    void Process(const Lexer::TokenContainer& tokens);
};

}

#endif
