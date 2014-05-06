#include "operator_equal.h"

#include "variable_table.h"

/* FIXME: Remove this header */
#include "debug.h"

using namespace std;
using namespace tiny_au3;

void OperatorEqual::Reduce(StatementElement* lhs, StatementElement* rhs)
{
    string lhs_name = lhs->GetValue();
    string rhs_value = VariableTable::Instance()->GetValue(rhs->GetValue());

    VariableTable::Instance()->SetValue(lhs_name, rhs_value);
}
