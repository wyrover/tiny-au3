#ifndef OPERATOR_MULTIPLY_H
#define OPERATOR_MULTIPLY_H

namespace tiny_au3
{

class StatementElement;

class OperatorMultiply
{
public:
    virtual ~OperatorMultiply() {};
    virtual void Reduce(StatementElement* next) {};
};

}

#endif
