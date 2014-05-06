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
    typedef std::map<std::string, std::string> VariableMap;

public:
    static VariableTable* Instance();

    void SetValue(const std::string& name, const std::string& value);
    std::string GetValue(const std::string& name) const;

private:
    static VariableTable* instance_;
    VariableMap variables_;

    VariableTable() {};
};

}

#endif
