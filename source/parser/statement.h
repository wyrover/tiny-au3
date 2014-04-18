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
    typedef std::deque<StatementElement*> ElementDeque;

public:
    virtual ~Statement() {};

    virtual void Reduce();
    virtual void Init(const std::string& value) {};

    void AddElement(StatementElement* element);

private:
    ElementDeque elements_;
};

}

#endif
