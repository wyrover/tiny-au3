#ifndef TOKEN_BUILDER_H
#define TOKEN_BUILDER_H

#include <string>

#include "token.h"
#include "types_tiny_au3.h"

namespace tiny_au3
{

class TokenBuilder
{
public:
    TokenBuilder() : is_string_(false) {};
    Token CreateToken(const std::string& word);

private:
    bool is_string_;

    Token CreateString(const std::string& word);
    Token CreateNumber(const std::string& word);
    Token CreateKeyword(const std::string& word);
    Token CreateVariable(const std::string& word);

    DISALLOW_COPY_AND_ASSIGN(TokenBuilder);
};

}

#endif
