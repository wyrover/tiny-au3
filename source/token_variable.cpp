#include "token_variable.h"

using namespace std;
using namespace tiny_au3;


StatementElement* TokenVariable::Produce() const
{
    /* FIXME: Implement this method */
    return 0;
}

bool TokenVariable::IsComplete() const
{
    return true;
}

void TokenVariable::SetValue(const string& value)
{
    value_ = value;
}
