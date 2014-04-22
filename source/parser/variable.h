#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>

#include "statement_element.h"

namespace tiny_au3
{

class Variable : public StatementElement
{
public:
    virtual ~Variable() {};
    virtual StatementElement* Reduce(StatementElement* lhs, StatementElement* rhs)
    {
        return NULL;
    }
    virtual void Init(const std::string& value);
};

}

#endif
