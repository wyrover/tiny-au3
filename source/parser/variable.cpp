#include "variable.h"

#include <assert.h>

using namespace std;
using namespace tiny_au3;


void Variable::Reduce(StatementElement* next)
{
    /* FIXME: Set value_ field before calling Reduce */
    GetPrev()->Reduce(this);
}

string Variable::GetValue() const
{
    return value_;
}
