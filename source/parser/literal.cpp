#include "literal.h"

#include <cassert>

#include "variable_table.h"

using namespace std;
using namespace tiny_au3;


Literal::Literal(const string& id)
    : StatementElement(id), id_(id)
{
    VariableTable::Instance()->SetValue(id_, id_);
}

void Literal::Reduce(StatementElement* next)
{
    GetPrev()->Reduce(this);
}

string Literal::GetId() const
{
    return id_;
}
