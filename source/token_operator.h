#ifndef TOKEN_OPERATOR_H
#define TOKEN_OPERATOR_H

#include <string>

#include "keywords.h"

namespace tiny_au3
{

class TokenOperator : public Token
{
public:
    virtual ~TokenOperator() {};

    virtual StatementElement* Produce() {};
};

}

#endif
