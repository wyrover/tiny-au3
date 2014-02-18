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
    Script(const std::string& log_file, const std::string& input_file) :
        Debug(log_file), input_file_(input_file), global_scope_(kGlobalScope) {}

    void Execute();

private:
    std::string input_file_;
    Scope global_scope_;
    Lexer lexer_;
};

}

#endif
