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

    void SetValue(const std::string& value);

private:
    std::string value_;
};

}

#endif
