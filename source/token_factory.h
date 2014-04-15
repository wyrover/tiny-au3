#ifndef TOKEN_FACTORY_H
#define TOKEN_FACTORY_H

#include <string>

#include "token.h"
#include "types_tiny_au3.h"

namespace tiny_au3
{

class TokenFactory
{
public:
    TokenFactory() : is_string_(false) {};
    Token* CreateToken(const std::string& word);

private:
    bool is_string_;

    Token* CreateString(const std::string& word);
    Token* CreateNumber(const std::string& word);
    Token* CreateKeyword(const std::string& word);
    Token* CreateVariable(const std::string& word);

    DISALLOW_COPY_AND_ASSIGN(TokenFactory);
};

}

#endif
