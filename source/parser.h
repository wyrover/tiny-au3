#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "variable_table.h"

namespace tiny_au3
{

class Parser
{
public:
    void Process(const Lexer::TokenList& tokens);

private:
    VariableTable var_table_;

    void ProcessVariable(const Lexer::TokenList& tokens);
};

}

#endif
