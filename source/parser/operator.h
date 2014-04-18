#ifndef OPERATOR_H
#define OPERATOR_H

#include <string>

#include "statement_element.h"

namespace tiny_au3
{

class Operator : public StatementElement
{
public:
    virtual ~Operator() {};
    virtual void Reduce(StatementElement* lhs, StatementElement* rhs) {};
    virtual void Init(const std::string& value);
};

}

#endif
