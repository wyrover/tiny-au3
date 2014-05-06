#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>

#include "statement_element.h"

namespace tiny_au3
{

class Variable : public StatementElement
{
public:
    /* FIXME: Implement this constructor
     * 1) Set variable name
     * 2) Link the variable name and VariableTable account */

    explicit Variable(const std::string& value)
        : StatementElement(value), value_(value) {};

    virtual ~Variable() {};
    virtual void Reduce(StatementElement* next);
    virtual std::string GetValue() const;

private:
    std::string value_;
};

}

#endif
