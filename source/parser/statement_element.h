#ifndef STATEMENT_ELEMENT_H
#define STATEMENT_ELEMENT_H

#include <string>

namespace tiny_au3
{

struct StatementElement
{
    virtual ~StatementElement() {};

    virtual void Reduce(StatementElement* next) = 0;
    virtual void Init(const std::string& value) = 0;

    void SetPrev(StatementElement* prev);
    StatementElement* GetPrev();

private:
    StatementElement* prev_;
};

}

#endif
