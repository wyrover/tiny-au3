#ifndef TOKEN_BUILDER_H
#define TOKEN_BUILDER_H

#include <string>

#include "token.h"

namespace tiny_au3
{

class TokenBuilder
{
public:
    static Token CreateString(const std::string& word);
    static Token CreateNumber(const std::string& word);
    static Token CreateKeyword(const std::string& word);
    static Token CreateVariable(const std::string& word);
};

}

#endif
