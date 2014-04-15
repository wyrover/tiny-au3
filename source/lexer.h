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
    typedef std::vector<Token*> TokenArray;
    typedef std::vector<TokenArray> TokenContainer;
    typedef std::list<std::string> StringList;

public:
    void Process(const std::string& line);

    TokenContainer& GetTokens() const;

private:
    mutable TokenContainer tokens_;

    void ProcessWord(const std::string word);
};

}

#endif
