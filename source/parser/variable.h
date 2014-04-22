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
    virtual void Reduce(StatementElement* next) {};
    virtual void Init(const std::string& value);
};

}

#endif
