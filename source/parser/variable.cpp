#include "variable.h"

#include <assert.h>

#include "variable_table.h"

using namespace std;
using namespace tiny_au3;


Variable::Variable(const string& id)
    : StatementElement(id), id_(id)
{
    VariableTable::Instance()->SetValue(id_, "");
}

void Variable::Reduce(StatementElement* next)
{
    /* FIXME: Set value_ field before calling Reduce */
    GetPrev()->Reduce(this);
}

string Variable::GetId() const
{
    return id_;
}
