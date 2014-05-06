#ifndef LITERAL_H
#define LITERAL_H

#include <string>

#include "statement_element.h"

namespace tiny_au3
{

class Literal : public StatementElement
{
public:
    explicit Literal(const std::string& value)
        : StatementElement(value), value_(value) {};

    virtual ~Literal() {};
    virtual void Reduce(StatementElement* next);
    virtual std::string GetValue() const;

private:
    std::string value_;
};

}

#endif
