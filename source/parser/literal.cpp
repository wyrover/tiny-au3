#include "literal.h"

#include <assert.h>

#include "variable_table.h"

using namespace std;
using namespace tiny_au3;


Literal::Literal(const string& value)
    : StatementElement(value), value_(value)
{
    VariableTable::Instance()->SetVariable(value_, value_);
}

void Literal::Reduce(StatementElement* next)
{
    GetPrev()->Reduce(this);
}

string Literal::GetValue() const
{
    return value_;
}
