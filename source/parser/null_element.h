#ifndef NULL_ELEMENT_H
#define NULL_ELEMENT_H

#include <string>

#include "statement_element.h"

namespace tiny_au3
{

class NullElement : public StatementElement
{
public:
    virtual ~NullElement() {};
    virtual StatementElement* Reduce(StatementElement* lhs, StatementElement* rhs)
    {
        return NULL;
    }
    virtual void Init(const std::string& value) {};
};

}

#endif
