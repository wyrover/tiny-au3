#ifndef STATEMENT_ELEMENT_H
#define STATEMENT_ELEMENT_H

namespace tiny_au3
{

struct StatementElement
{
    virtual ~StatementElement() {};

    virtual void Reduce() = 0;
};

}

#endif
