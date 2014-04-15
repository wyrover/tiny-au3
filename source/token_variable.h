#ifndef TOKEN_VARIABLE_H
#define TOKEN_VARIABLE_H

namespace tiny_au3
{

class TokenVariable
{
public:
    virtual ~TokenVariable() {};

    virtual StatementElement* Produce() {};
};

}

#endif
