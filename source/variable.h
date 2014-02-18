#ifndef VARIABLE_H
#define VARIABLE_H

namespace tiny_au3
{

enum VariableType
{
    kStringVariabie = 0,
    kIntVariable,
    kDoubleVariable
};

class Variable
{
public:
    Variable() {}

private:
    VariableType type_;
};

}

#endif
