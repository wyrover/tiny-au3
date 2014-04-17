#ifndef TOKEN_H
#define TOKEN_H

#include <string>

namespace tiny_au3
{

class StatementElement;

class Token
{
public:
    virtual ~Token() {};

    virtual StatementElement* Produce() const = 0;
    virtual bool IsComplete() const = 0;
    virtual void SetValue(const std::string& value) = 0;
};

}

#endif
