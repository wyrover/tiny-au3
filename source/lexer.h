#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <list>
#include <vector>

#include "token.h"

namespace tiny_au3
{

class Lexer
{
public:
    typedef std::vector<Token> TokenList;
    typedef std::list<std::string> StringList;

public:
    void Process(const std::string& line);
    TokenList& GetTokens() const;

private:
    mutable TokenList tokens_;
};

}

#endif
