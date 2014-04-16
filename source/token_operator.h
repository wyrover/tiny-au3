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

    virtual StatementElement* Produce() const;
    virtual bool IsComplete() const;
    virtual void SetValue(const std::string& value);
};

}

#endif
