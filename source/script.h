#ifndef SCRIPT_H
#define SCRIPT_H

#include <string>

#include "lexer.h"

namespace tiny_au3
{

class Script
{
public:
    Script() {}

    void Execute();

private:
    Lexer lexer_;
};

}

#endif
