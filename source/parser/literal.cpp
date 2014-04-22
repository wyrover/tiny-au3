#include "literal.h"

#include <assert.h>

using namespace std;
using namespace tiny_au3;

void Literal::Init(const string& value)
{
    value_ = value;
}

StatementElement* Literal::Reduce(StatementElement* lhs, StatementElement* rhs)
{
    return NULL;
}
