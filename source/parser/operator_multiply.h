#ifndef OPERATOR_MULTIPLY_H
#define OPERATOR_MULTIPLY_H

#include "operator_impl.h"

namespace tiny_au3
{

class StatementElement;

class OperatorMultiply : public OperatorImpl
{
public:
    virtual ~OperatorMultiply() {};
    virtual void Reduce(StatementElement* next) {};
};

}

#endif
