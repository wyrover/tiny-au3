#include "operator_multiply.h"

#include "variable_table.h"
#include "functions.h"
#include "literal.h"

/* FIXME: Remove this header */
#include "debug.h"

using namespace std;
using namespace tiny_au3;

StatementElement* OperatorMultiply::Reduce(StatementElement* lhs, StatementElement* rhs)
{
    string lhs_value = VariableTable::Instance()->GetValue(lhs->GetId());
    string rhs_value = VariableTable::Instance()->GetValue(rhs->GetId());
    string result_value = NumberToString<double>(StringToNumber<double>(lhs_value) *
            StringToNumber<double>(rhs_value));

    StatementElement* result = new Literal(result_value);
    result->SetPrev(lhs->GetPrev());

    return result;
}
