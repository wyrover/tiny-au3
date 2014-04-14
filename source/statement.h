#ifndef STATEMENT_H
#define STATEMENT_H

#include <string>
#include <deque>

#include "statement_element.h"
#include "variable_table.h"

namespace tiny_au3
{

class Statement : public StatementElement
{
public:
    typedef std::deque<StatementElement> ElementDeque;

public:
    Statement(VariableTable& variables) : variables_(variables) {};

    virtual void Reduce();
    virtual ~Statement() {};

    void AddElement(const StatementElement& element);

private:
    VariableTable& variables_;
    ElementDeque elements_;
};

}

#endif
