#ifndef PARSER_H
#define PARSER_H

#include <map>

#include "lexer.h"
#include "variable.h"

namespace tiny_au3
{

class Parser
{
public:
    typedef std::map<std::string, Variable> VariableMap;

public:
    void Process(const Lexer::TokenList& tokens) {};

private:
    VariableMap variables_;
};

}

#endif
