#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "variable_table.h"
#include "expression.h"

namespace tiny_au3
{

class Parser
{
public:
    void Process(const Lexer::TokenContainer& tokens);

private:
    /* FIXME: This can be a singleton object */
    VariableTable variables_;

    void ProcessToken(const Lexer::TokenArray token_array);
    void ProcessVariable(const Lexer::TokenArray& token_array);
};

}

#endif
