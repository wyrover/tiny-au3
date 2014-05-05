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
    typedef std::map<std::string, Variable*> VariableMap;

public:
    static VariableTable* Instance();

    ~VariableTable();

    void SetVariable(const std::string& name, const std::string& value);

private:
    static VariableTable* instance_;
    VariableMap variables_;

    VariableTable() {};
};

}

#endif
