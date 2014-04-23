#ifndef STATEMENT_H
#define STATEMENT_H

#include "null_element.h"

namespace tiny_au3
{

class StatementElement;

class Statement
{
public:
    Statement() : last_(NullElement::Instance()) {};
    virtual ~Statement() {};

    void Reduce();
    void AddElement(StatementElement* element);

private:
    StatementElement* last_;
};

}

#endif
