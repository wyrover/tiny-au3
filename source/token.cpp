#include "token.h"

#include <string.h>

using namespace std;
using namespace tiny_au3;


void Token::SetValue(const std::string& value)
{
    value_ = value;
}

void Token::SetCode(const KeywordCode& code)
{
    code_ = code;
}

string Token::GetValue() const
{
    return value_;
}

TokenType Token::GetType() const
{
    return type_;
}

KeywordCode Token::GetCode() const
{
    return code_;
}
