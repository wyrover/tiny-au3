#ifndef SCRIPT_H
#define SCRIPT_H

#include <string>

#include "lexer.h"
#include "scope.h"

namespace tiny_au3
{

class Script
{
public:
    Script(std::string& filename) : filename_(filename) {}

    void Execute();

private:
    std::string filename_;
    Scope local_;
    Lexer lexer_;
};

}

#endif
