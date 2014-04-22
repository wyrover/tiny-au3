#ifndef STATEMENT_H
#define STATEMENT_H

#include <string>
#include <deque>

#include "statement_element.h"
#include "variable_table.h"

namespace tiny_au3
{

class Statement
{
public:
    virtual ~Statement() {};

    void Reduce();
    void AddElement(StatementElement* element);

private:
    StatementElement* last_;
};

}

#endif
