#ifndef NULL_ELEMENT_H
#define NULL_ELEMENT_H

#include <string>

#include "statement_element.h"

namespace tiny_au3
{

class NullElement : public StatementElement
{
public:
    virtual ~Variable() {};
    virtual void Reduce(StatementElement* lhs, StatementElement* rhs) {};
    virtual void Init(const std::string& value) {};
};

}

#endif
