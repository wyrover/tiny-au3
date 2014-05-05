#include "operator_equal.h"

#include "variable_table.h"

/* FIXME: Remove this header */
#include "debug.h"

using namespace std;
using namespace tiny_au3;

void OperatorEqual::Reduce(StatementElement* lhs, StatementElement* rhs)
{
    /* FIXME: Now this works for literals only.
     * Implement Variable::Reduce() method to prepare correct
     * Variable::GetValue() result */
    VariableTable::Instance()->SetVariable(lhs->GetValue(), rhs->GetValue());
}
