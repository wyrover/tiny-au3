#include "parser.h"

#include <algorithm>

#include "types_tiny_au3.h"
#include "statement.h"
#include "element_factory.h"
#include "debug.h"
#include "error.h"

using namespace std;
using namespace tiny_au3;


#if 0
BINARY_FUNCTOR(ProcessVariableImpl, Token, token, Statement&, statement)
    /* FIXME: Process the Local, Global, Const and Static keywords */

    StatementElement* element = ElementFactory::CreateElement(token);
    statement.AddElement(element);
END_BINARY_FUNCTOR
#endif

void Parser::ProcessVariable(const Lexer::TokenArray& token_array)
{
    /* FIXME: Implement this method */
#if 0
    Statement statement(variables_);

    for_each(token_array.begin(), token_array.end(),
             bind2nd(ProcessVariableImpl(), statement));

    statement.Reduce();
#endif
}

void Parser::ProcessToken(const Lexer::TokenArray token_array)
{
    /* FIXME: Implement this method */
#if 0
    if ( IsVariableStatement(token_array) )
        ProcessVariable(token_array);
#endif
}

void Parser::Process(const Lexer::TokenContainer& tokens)
{
    for_each(tokens.begin(), tokens.end(),
             bind1st(mem_fun(&Parser::ProcessToken), this));
}
