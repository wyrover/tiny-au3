#include "parser.h"

#include <algorithm>

#include "types_tiny_au3.h"
#include "debug.h"

using namespace std;
using namespace tiny_au3;


bool IsVariableAction(const Lexer::TokenList& tokens)
{
    /* FIXME: Process the Local, Global, Const and Static keywords */
    if ( tokens[0].GetType() == kVariableToken )
        return true;

    return false;
}

BINARY_FUNCTOR(ProcessVariableImpl, Token, token, VariableTable&, var_table)
    /* FIXME: Process the variable assignment */
END_BINARY_FUNCTOR

void Parser::ProcessVariable(const Lexer::TokenList& tokens)
{
    for_each(tokens.begin(), tokens.end(),
             bind2nd(ProcessVariableImpl(), var_table_));
}

void Parser::Process(const Lexer::TokenList& tokens)
{
    if ( IsVariableAction(tokens) )
        ProcessVariable(tokens);
}
