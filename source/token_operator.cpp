#include "token_operator.h"

using namespace std;
using namespace tiny_au3;


StatementElement* TokenOperator::Produce() const
{
    /* FIXME: Implement this method */
    return 0;
}

bool TokenOperator::IsComplete() const
{
    return true;
}

void TokenOperator::SetValue(const string& value)
{
    value_ = value;
}
