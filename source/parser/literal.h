#ifndef LITERAL_H
#define LITERAL_H

#include <string>

#include "statement_element.h"

namespace tiny_au3
{

class Literal : public StatementElement
{
public:
    virtual ~Literal() {};
    virtual void Reduce(StatementElement* next);
    virtual void Init(const std::string& value);
    virtual std::string GetValue() const;

private:
    std::string value_;
};

}

#endif
