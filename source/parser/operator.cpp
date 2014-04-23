#include "operator.h"

#include <assert.h>

#include "operator_factory.h"

using namespace std;
using namespace tiny_au3;

void Operator::Init(const string& value)
{
    static OperatorFactory factory;

    impl_ = factory.CreateOperator(value);
}

void Operator::Reduce(StatementElement* next)
{
    impl_->Reduce(GetPrev(), next);

    GetPrev()->Reduce(this);
}
