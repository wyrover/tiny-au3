#ifndef OPERATOR_IMPL_H
#define OPERATOR_IMPL_H

namespace tiny_au3
{

class StatementElement;

class OperatorImpl
{
public:
    virtual ~OperatorImpl() {};
    virtual StatementElement* Reduce(StatementElement* lhs, StatementElement* rhs) = 0;
};

}

#endif
