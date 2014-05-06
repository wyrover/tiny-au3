#include "literal.h"

#include <assert.h>

using namespace std;
using namespace tiny_au3;


void Literal::Reduce(StatementElement* next)
{
    GetPrev()->Reduce(this);
}

string Literal::GetValue() const
{
    return value_;
}
