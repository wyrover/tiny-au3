#include "variable.h"

#include <assert.h>

#include "variable_table.h"

using namespace std;
using namespace tiny_au3;


Variable::Variable(const string& value)
    : StatementElement(value), value_(value)
{
    VariableTable::Instance()->SetValue(value_, "");
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
