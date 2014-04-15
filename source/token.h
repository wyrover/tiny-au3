#ifndef TOKEN_H
#define TOKEN_H

namespace tiny_au3
{

class StatementElement;

class Token
{
public:
    virtual ~Token() {};

    virtual StatementElement* Produce() const = 0;
    virtual bool IsComplete() const = 0;
};

}

#endif
