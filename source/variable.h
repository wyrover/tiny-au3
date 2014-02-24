#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>

namespace tiny_au3
{

enum VariableType
{
    kNoInitVariable = 0,
    kStringVariabie,
    kIntVariable,
    kDoubleVariable
};

class Variable
{
public:
    Variable(const VariableType& type = kNoInitVariable) : type_(type) {};

    void SetValue(const std::string& value);
    std::string GetValue() const;

private:
    VariableType type_;
    std::string str_value_;
    int int_value_
    double double_value_;
};

}

#endif
