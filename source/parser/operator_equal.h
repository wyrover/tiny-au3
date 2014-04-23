#ifndef OPERATOR_EQUAL_H
#define OPERATOR_EQUAL_H

#include "operator_impl.h"

namespace tiny_au3
{

class StatementElement;

class OperatorEqual : public OperatorImpl
{
public:
    virtual ~OperatorEqual() {};
    virtual void Reduce(StatementElement* lhs, StatementElement* rhs);
};

}

#endif
