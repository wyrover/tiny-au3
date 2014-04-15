#ifndef OPERATOR_H
#define OPERATOR_H

#include "statement_element.h"
#include "keywords.h"

namespace tiny_au3
{

class Operator : public StatementElement
{
public:
    Operator(KeywordCode code) {};

    virtual ~Operator() {};
    virtual void Reduce() {};
};

}

#endif
