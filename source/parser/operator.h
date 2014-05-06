#ifndef OPERATOR_H
#define OPERATOR_H

#include <string>

#include "statement_element.h"
#include "operator_null.h"
#include "types_tiny_au3.h"

namespace tiny_au3
{

class OperatorImpl;

class Operator : public StatementElement
{
public:
    Operator() : impl_(OperatorNull::Instance()) {};
    explicit Operator(const std::string& value);

    virtual ~Operator() {};
    virtual void Reduce(StatementElement* next);
    virtual void Init(const std::string& value);

private:
    OperatorImpl* impl_;

    DISALLOW_COPY_AND_ASSIGN(Operator);
};

}

#endif
