#ifndef TOKEN_VARIABLE_H
#define TOKEN_VARIABLE_H

#include <string>

#include "token.h"

namespace tiny_au3
{

class StatementElement;

class TokenVariable : public Token
{
public:
    virtual ~TokenVariable() {};

    virtual StatementElement* Produce() const;
    virtual bool IsComplete() const;
};

}

#endif
