#ifndef TOKEN_NULL_H
#define TOKEN_NULL_H

#include "token.h"

namespace tiny_au3
{

class StatementElement;

class TokenNull : public Token
{
public:
    virtual ~TokenNull() {};

    virtual StatementElement* Produce() const;
    virtual bool IsComplete() const;
    virtual void SetValue(const std::string& value) {};
};

}

#endif
