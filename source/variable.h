#ifndef VARIABLE_H
#define VARIABLE_H

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

    void SetValue(const std::string& value) {};

private:
    VariableType type_;
};

}

#endif
