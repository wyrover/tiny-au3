#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>

#include "statement_element.h"

namespace tiny_au3
{

class Variable : public StatementElement
{
public:
    explicit Variable(const std::string& value);

    virtual ~Variable() {};
    virtual void Reduce(StatementElement* next);
    virtual std::string GetValue() const;

private:
    std::string value_;
};

}

#endif
