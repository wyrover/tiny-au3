#ifndef TOKEN_H
#define TOKEN_H

namespace tiny_au3
{

enum TokenType
{
    kVariableToken = 0,
    kNumberToken,
    kStringToken,
    kKeywordToken
};

class Token
{
public:
    Token(const TokenType& type) : type_(type) {};

    void SetValue(const std::string& value) {};
    void SetValue(const int& value) {};

private:
    TokenType type_;
};

}

#endif
