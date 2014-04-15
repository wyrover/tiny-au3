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

    virtual StatementElement* Produce() const
    {
        /* FIXME: Use NULL-object here */
        return 0;
    }

    virtual bool IsComplete() const
    {
        return false;
    }
};

}

#endif
