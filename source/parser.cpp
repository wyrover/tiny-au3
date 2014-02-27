#include "parser.h"

#include <algorithm>

#include "types_tiny_au3.h"
#include "statement.h"
#include "debug.h"
#include "error.h"

using namespace std;
using namespace tiny_au3;


bool IsVariableStatement(const Lexer::TokenArray& token_array)
{
    /* FIXME: Process the Local, Global, Const and Static keywords */
    if ( token_array[0].GetType() == kVariableToken )
        return true;

    return false;
}

BINARY_FUNCTOR(ProcessVariableImpl, Token, token, Statement&, statement)
    /* FIXME: Process the Local, Global, Const and Static keywords */
    if ( token.GetType() == kVariableToken )
    {
        Variable variable;
        variable.SetName(token.GetValue());
        statement.AddVariable(variable);
        return;
    }

    if ( token.GetType() == kNumberToken )
    {
        /* FIXME: Implement double variable processing */
        Variable variable(kIntVariable);
        variable.SetValue(token.GetValue());
        statement.AddVariable(variable);
        return;
    }

    if ( token.GetType() == kStringToken )
    {
        Variable variable(kStringVariabie);
        variable.SetValue(token.GetValue());
        statement.AddVariable(variable);
        return;
    }

    if ( token.GetType() == kKeywordToken )
    {
        statement.AddOperator(token.GetCode());
        return;
    }

    Error::Print(kTokenError, "", 0, token.GetValue());
END_BINARY_FUNCTOR

void Parser::ProcessVariable(const Lexer::TokenArray& token_array)
{
    Statement statement(variables_);

    for_each(token_array.begin(), token_array.end(),
             bind2nd(ProcessVariableImpl(), statement));

    statement.Reduce();
}

void Parser::ProcessToken(const Lexer::TokenArray token_array)
{
    if ( IsVariableStatement(token_array) )
        ProcessVariable(token_array);
}

void Parser::Process(const Lexer::TokenContainer& tokens)
{
    for_each(tokens.begin(), tokens.end(),
             bind1st(mem_fun(&Parser::ProcessToken), this));
}
