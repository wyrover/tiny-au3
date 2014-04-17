#include "operator_table.h"

#include "functions.h"

using namespace std;
using namespace tiny_au3;

OperatorTable::OperatorMap OperatorTable::operators_ = CreateMap();

OperatorTable::OperatorMap OperatorTable::CreateMap()
{
    OperatorMap result;

    result["="] = kEqual;
    result["+"] = kPlus;
    result["-"] = kMinus;
    result["*"] = kMultiply;
    result["/"] = kDivide;
    result["^"] = kPower;

    return result;
}

OperatorCode OperatorTable::GetCode(const string& oper)
{
    string upper_key = StringToUpper(oper);

    if ( operators_.count(upper_key) != 0 )
        return operators_[upper_key];
    else
        return kUndefinedOperator;
}
