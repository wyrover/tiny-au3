#ifndef LEXER_H
#define LEXER_H

#include <string>

namespace tiny_au3
{

class Lexer
{
public:
    Lexer() {}

    void Process(const std::string& line);
};

}

#endif
