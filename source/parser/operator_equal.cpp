#include "operator_equal.h"

#include "variable_table.h"

using namespace std;
using namespace tiny_au3;


StatementElement* OperatorEqual::Reduce(StatementElement* lhs, StatementElement* rhs)
{
    string lhs_name = lhs->GetId();
    string rhs_value = VariableTable::Instance()->GetValue(rhs->GetId());

    VariableTable::Instance()->SetValue(lhs_name, rhs_value);

    return lhs;
}
