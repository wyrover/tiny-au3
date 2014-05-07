#include "token_operator.h"

#include "operator.h"

using namespace std;
using namespace tiny_au3;


StatementElement* TokenOperator::Produce() const
{
    StatementElement* result = new Operator(id_);

    return result;
}

bool TokenOperator::IsComplete() const
{
    return true;
}
