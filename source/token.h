#ifndef TOKEN_H
#define TOKEN_H

#include <string>

#include "keywords.h"

namespace tiny_au3
{

enum TokenType
{
    kUndefinedToken = 0,
    kVariableToken,
    kNumberToken,
    kStringToken,
    kKeywordToken
};

class Token
{
public:
    Token(const TokenType& type) : type_(type) {};

    void SetValue(const std::string& value);
    void AppendValue(const std::string& value);
    void SetCode(const KeywordCode& code);

    TokenType GetType() const;
    std::string GetValue() const;
    KeywordCode GetCode() const;

private:
    TokenType type_;
    KeywordCode code_;
    std::string value_;

};

}

#endif
