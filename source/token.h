#ifndef TOKEN_H
#define TOKEN_H

namespace tiny_au3
{

enum TokenType
{
    kVariableToken = 0,
    kNumberToken,
    kStringToken
};

class Token
{
public:
    Token() {}

private:
    TokenType type_;
};

}

#endif
