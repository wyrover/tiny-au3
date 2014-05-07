#include "operator.h"

#include <cassert>

#include "operator_factory.h"

using namespace std;
using namespace tiny_au3;


Operator::Operator(const std::string& id)
    : StatementElement(id)
{
    static OperatorFactory factory;

    impl_ = factory.CreateOperator(id);
}

void Operator::Reduce(StatementElement* next)
{
    impl_->Reduce(GetPrev(), next);

    GetPrev()->Reduce(this);
}
