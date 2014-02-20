#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "variable_table.h"
#include "keywords.h"

namespace tiny_au3
{

struct VariableOperation
{
    std::string var_name_;
    std::string var_value_;
    KeywordCode code_;
};

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
