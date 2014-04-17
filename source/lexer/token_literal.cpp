#include "token_literal.h"

#include "literal.h"

using namespace std;
using namespace tiny_au3;


StatementElement* TokenLiteral::Produce() const
{
    StatementElement* result = new Literal();

    result->Init(value_);

    return result;
}

bool TokenLiteral::IsComplete() const
{
    return true;
}

void TokenLiteral::SetValue(const string& value)
{
    value_ = value;
}
