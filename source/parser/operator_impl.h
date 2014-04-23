#ifndef OPERATOR_IMPL_H
#define OPERATOR_IMPL_H

namespace tiny_au3
{

class StatementElement;

class OperatorImpl
{
public:
    virtual ~OperatorImpl() {};
    virtual void Reduce(StatementElement* next) {};
};

}

#endif
