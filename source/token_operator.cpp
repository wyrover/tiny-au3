#include "token_operator.h"

#include "operator.h"

using namespace std;
using namespace tiny_au3;


StatementElement* TokenOperator::Produce() const
{
    StatementElement* result = new Operator();

    result->Init(value_);

    return result;
}

bool TokenOperator::IsComplete() const
{
    return true;
}

void TokenOperator::SetValue(const string& value)
{
    value_ = value;
}
