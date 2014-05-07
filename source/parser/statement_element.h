#ifndef STATEMENT_ELEMENT_H
#define STATEMENT_ELEMENT_H

#include <string>

namespace tiny_au3
{

class StatementElement
{
public:
    explicit StatementElement(const std::string& id) : prev_(NULL) {};
    virtual ~StatementElement() {};

    virtual void Reduce(StatementElement* next) = 0;
    virtual std::string GetId() const;

    void SetPrev(StatementElement* prev);
    StatementElement* GetPrev();

private:
    StatementElement* prev_;
};

}

#endif
