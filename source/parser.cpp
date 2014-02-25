#include "parser.h"

#include <algorithm>

#include "types_tiny_au3.h"
#include "expression.h"
#include "debug.h"
#include "error.h"

using namespace std;
using namespace tiny_au3;


bool IsVariableExpression(const Lexer::TokenArray& token_array)
{
    /* FIXME: Process the Local, Global, Const and Static keywords */
    if ( token_array[0].GetType() == kVariableToken )
        return true;

    return false;
}

BINARY_FUNCTOR(ProcessVariableImpl, Token, token, Expression&, expression)
    /* FIXME: Process the Local, Global, Const and Static keywords */
    if ( token.GetType() == kVariableToken )
    {
        expression.var_name_ = token.GetValue();
        return;
    }

    if ( token.GetType() == kNumberToken )
    {
        /* FIXME: Implement double variable processing */
        Variable variable(kIntVariable);
        variable.SetValue(token.GetValue());
        expression.variable_ = variable;
        return;
    }

    if ( token.GetType() == kStringToken )
    {
        Variable variable(kStringVariabie);
        variable.SetValue(token.GetValue());
        expression.variable_ = variable;
        return;
    }

    if ( token.GetType() == kKeywordToken )
    {
        expression.code_ = token.GetCode();
        return;
    }

    Error::Print(kTokenError, "", 0, token.GetValue());
END_BINARY_FUNCTOR

void Parser::ProcessVariable(const Lexer::TokenArray& token_array)
{
    Expression expression;

    for_each(token_array.begin(), token_array.end(),
             bind2nd(ProcessVariableImpl(), expression));

    Execute(expression);
}

void Parser::Execute(const Expression& expression)
{
    if ( expression.code_ == kEqualKey )
    {
        var_table_.SetVariable(expression.var_name_, expression.variable_);
        return;
    }

    Error::Print(kKeywordError, "", 0, expression.code_);
}

void Parser::ProcessToken(const Lexer::TokenArray token_array)
{
    if ( IsVariableExpression(token_array) )
        ProcessVariable(token_array);
}

void Parser::Process(const Lexer::TokenContainer& tokens)
{
    for_each(tokens.begin(), tokens.end(),
             bind1st(mem_fun(&Parser::ProcessToken), this));
}
