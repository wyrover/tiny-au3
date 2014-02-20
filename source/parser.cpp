#include "parser.h"

#include <algorithm>

#include "types_tiny_au3.h"
#include "debug.h"

using namespace std;
using namespace tiny_au3;



BINARY_FUNCTOR(ProcessToken, Token, token, VariableTable&, var_table)
    //tokens.push_back(CreateToken(word));
END_BINARY_FUNCTOR

void Parser::Process(const Lexer::TokenList& tokens)
{
    for_each(tokens.begin(), tokens.end(),
             bind2nd(ProcessToken(), var_table_));
}
