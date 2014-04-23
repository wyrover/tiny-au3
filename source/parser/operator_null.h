#ifndef OPERATOR_NULL_H
#define OPERATOR_NULL_H

#include "operator_impl.h"

namespace tiny_au3
{

class StatementElement;

class OperatorNull: public OperatorImpl
{
public:
    static OperatorNull* Instance();

    virtual ~OperatorNull() {};
    virtual void Reduce(StatementElement* next) {};

private:
    static OperatorNull* instance_;

    OperatorNull() {};
};

}

#endif
