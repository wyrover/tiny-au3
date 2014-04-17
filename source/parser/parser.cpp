#include "parser.h"

#include <algorithm>

#include "types_tiny_au3.h"
#include "statement.h"
#include "debug.h"
#include "error.h"

using namespace std;
using namespace tiny_au3;


BINARY_FUNCTOR(ProcessVariableImpl, Token*, token, Statement&, statement)
    /* FIXME: Process the Local, Global, Const and Static keywords */

    StatementElement* element = token->Produce();
    statement.AddElement(element);
END_BINARY_FUNCTOR

void ProcessTokenLine(const Lexer::TokenArray token_array)
{
    Statement statement;

    for_each(token_array.begin(), token_array.end(),
             bind2nd(ProcessVariableImpl(), statement));

    statement.Reduce();
}

void Parser::Process(const Lexer::TokenContainer& tokens)
{
    for_each(tokens.begin(), tokens.end(), ProcessTokenLine);
}
