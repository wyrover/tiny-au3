#include "parser.h"

#include <algorithm>

#include "types_tiny_au3.h"
#include "debug.h"
#include "error.h"

using namespace std;
using namespace tiny_au3;


bool IsVariableOperation(const Lexer::TokenArray& token_array)
{
    /* FIXME: Process the Local, Global, Const and Static keywords */
    if ( token_array[0].GetType() == kVariableToken )
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
        /* FIXME: Implement double variable processing */
        Variable variable(kIntVariable);
        variable.SetValue(token.GetValue());
        operation.variable_ = variable;
        return;
    }

    if ( token.GetType() == kStringToken )
    {
        Variable variable(kStringVariabie);
        variable.SetValue(token.GetValue());
        operation.variable_ = variable;
        return;
    }

    if ( token.GetType() == kKeywordToken )
    {
        operation.code_ = token.GetCode();
        return;
    }

    Error::Print(kTokenError, "", 0, token.GetValue());
END_BINARY_FUNCTOR

void Parser::ProcessVariable(const Lexer::TokenArray& token_array)
{
    VariableOperation operation;

    for_each(token_array.begin(), token_array.end(),
             bind2nd(ProcessVariableImpl(), operation));

    Execute(operation);
}

void Parser::Execute(const VariableOperation& operation)
{
    if ( operation.code_ == kEqualKey )
    {
        var_table_.SetVariable(operation.var_name_, operation.variable_);
        return;
    }

    Error::Print(kKeywordError, "", 0, operation.code_);
}

void Parser::ProcessToken(const Lexer::TokenArray token_array)
{
    if ( IsVariableOperation(token_array) )
        ProcessVariable(token_array);
}

void Parser::Process(const Lexer::TokenContainer& tokens)
{
    for_each(tokens.begin(), tokens.end(),
             bind1st(mem_fun(&Parser::ProcessToken), this));
}
