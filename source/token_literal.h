#ifndef TOKEN_LITERAL_H
#define TOKEN_LITERAL_H

#include <string>

#include "token.h"

namespace tiny_au3
{

class StatementElement;

class TokenLiteral : public Token
{
public:
    virtual ~TokenLiteral() {};

    virtual StatementElement* Produce() const;
    virtual bool IsComplete() const;
    virtual void SetValue(const std::string& value);

private:
    std::string value_;
};

}

#endif
