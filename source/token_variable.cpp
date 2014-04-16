#include "token_variable.h"

#include "variable.h"

using namespace std;
using namespace tiny_au3;


StatementElement* TokenVariable::Produce() const
{
    StatementElement* result = new Variable();

    result->Init(value_);

    return result;
}

bool TokenVariable::IsComplete() const
{
    return true;
}

void TokenVariable::SetValue(const string& value)
{
    value_ = value;
}
