#ifndef STATEMENT_ELEMENT_H
#define STATEMENT_ELEMENT_H

namespace tiny_au3
{

struct StatementElement
{
    virtual ~StatementElement() {};

    virtual void Reduce(StatementElement* lhs, StatementElement* rhs) = 0;
    virtual void Init(const std::string& value) = 0;
};

}

#endif
