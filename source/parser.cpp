#include "parser.h"

#include <algorithm>

#include "types_tiny_au3.h"
#include "debug.h"
#include "error.h"

using namespace std;
using namespace tiny_au3;


bool IsVariableAction(const Lexer::TokenList& tokens)
{
    /* FIXME: Process the Local, Global, Const and Static keywords */
    if ( tokens[0].GetType() == kVariableToken )
        return true;

    return false;
}

BINARY_FUNCTOR(ProcessVariableImpl, Token, token, VariableOperation&, operation)
    /* FIXME: Process the Local, Global, Const and Static keywords */
    if ( token.GetType() == kVariableToken )
    {
        operation.var_name_ = token.GetValue();
        return;
    }

    if ( token.GetType() == kNumberToken )
    {
        operation.var_value_ = token.GetValue();
        return;
    }

    if ( token.GetType() == kKeywordToken )
    {
        operation.code_ = token.GetCode();
        return;
    }

    Error::Print(kTokenError, "", 0, token.GetValue());
END_BINARY_FUNCTOR

void Parser::ProcessVariable(const Lexer::TokenList& tokens)
{
    VariableOperation operation;

    for_each(tokens.begin(), tokens.end(),
             bind2nd(ProcessVariableImpl(), operation));
}

void Parser::Process(const Lexer::TokenList& tokens)
{
    if ( IsVariableAction(tokens) )
        ProcessVariable(tokens);
}
