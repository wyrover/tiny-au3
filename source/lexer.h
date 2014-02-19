#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <list>

#include "token.h"

namespace tiny_au3
{

class Lexer
{
public:
    typedef std::list<Token> TokenList;
    typedef std::list<std::string> StringList;

public:
    Lexer() {}

    void Process(const std::string& line);

private:
    TokenList tokens_;
};

}

#endif
