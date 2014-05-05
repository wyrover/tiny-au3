#include "variable.h"

#include <assert.h>

using namespace std;
using namespace tiny_au3;

void Variable::Init(const string& value)
{
    /* FIXME: Implement this method
     * 1) Set variable name
     * 2) Link the variable name and VariableTable account */
}

void Variable::Reduce(StatementElement* next)
{
    /* FIXME: Set value_ field before calling Reduce */
    GetPrev()->Reduce(this);
}

string Variable::GetValue() const
{
    return value_;
}
