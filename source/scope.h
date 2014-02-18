#ifndef SCOPE_H
#define SCOPE_H

#include <map>
#include "variable.h"

namespace tiny_au3
{

enum ScopeType
{
    kLocalScope = 0,
    kGlobalScope
};

class Scope
{
public:
    typedef std::map<std::string, Variable> VariableMap;

public:
    Scope() {}

private:
    ScopeType type_;
    VariableMap variables_;
};

}

#endif
