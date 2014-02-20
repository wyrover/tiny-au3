#include "token.h"

#include <string.h>

using namespace std;
using namespace tiny_au3;


void Token::SetValue(const std::string& value)
{
    string_ = value;
}

void Token::SetValue(const int& value)
{
    integer_ = value;
}

TokenType Token::GetType() const
{
    return type_;
}
