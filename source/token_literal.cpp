#include "token_literal.h"

using namespace std;
using namespace tiny_au3;


StatementElement* TokenLiteral::Produce() const
{
    /* FIXME: Implement this method */
    return 0;
}

bool TokenLiteral::IsComplete() const
{
    return true;
}

void TokenLiteral::SetValue(const string& value)
{
    value_ = value;
}
