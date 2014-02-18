#ifndef SCRIPT_H
#define SCRIPT_H

#include <string>

#include "debug.h"
#include "lexer.h"
#include "scope.h"

namespace tiny_au3
{

class Script : protected Debug
{
public:
    Script(std::string& filename) : Debug("debug.log"), filename_(filename),
                                    global_scope_(kGlobalScope) {}

    void Execute();

private:
    std::string filename_;
    Scope global_scope_;
    Lexer lexer_;
};

}

#endif
