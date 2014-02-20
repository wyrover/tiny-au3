#ifndef VARIABLE_TABLE_H
#define VARIABLE_TABLE_H

#include <map>

#include "variable.h"

namespace tiny_au3
{

class VariableTable
{
public:
    typedef std::map<std::string, Variable> VariableMap;

private:
    VariableType type_;
};

}

#endif
