#ifndef OPERATOR_H
#define OPERATOR_H

#include <string>

#include "statement_element.h"

namespace tiny_au3
{

class OperatorImpl;

class Operator : public StatementElement
{
public:
    virtual ~Operator() {};
    virtual void Reduce(StatementElement* next);
    virtual void Init(const std::string& value);

private:
    OperatorImpl* impl_;
};

}

#endif
