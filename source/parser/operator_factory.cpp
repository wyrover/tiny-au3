#include "operator_factory.h"

#include "operator_table.h"
#include "operator_multiply.h"
#include "operator_null.h"
#include "operator_equal.h"
#include "error.h"

using namespace std;
using namespace tiny_au3;

OperatorImpl* OperatorFactory::CreateOperator(const string& word)
{
    OperatorCode code = OperatorTable::GetCode(word);

    switch (code)
    {
        case kMultiply:
            return new OperatorMultiply();

        case kEqual:
            return new OperatorEqual();

        default:
            Error::Print("Invalid operator `%s`\n", word.c_str());
    }

    return OperatorNull::Instance();
}
