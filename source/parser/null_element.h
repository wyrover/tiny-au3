#ifndef NULL_ELEMENT_H
#define NULL_ELEMENT_H

#include <string>

#include "statement_element.h"

namespace tiny_au3
{

class NullElement : public StatementElement
{
public:
    static NullElement* Instance();

    virtual ~NullElement() {};
    virtual void Reduce(StatementElement* next) {};

private:
    static NullElement* instance_;

    NullElement() : StatementElement("") {};
};

}

#endif
