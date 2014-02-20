#ifndef VARIABLE_TABLE_H
#define VARIABLE_TABLE_H

#include <map>
#include <string>

#include "variable.h"

namespace tiny_au3
{

class VariableTable
{
public:
    typedef std::map<std::string, Variable> VariableMap;

public:
    void CreateVariable(const std::string& name);
    void SetVariable(const std::string& name);

private:
    VariableType type_;
};

}

#endif
