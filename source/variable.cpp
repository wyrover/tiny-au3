#include "variable.h"

#include "debug.h"

using namespace std;
using namespace tiny_au3;


void Variable::SetValue(const std::string& value)
{
    str_value_ = value;
}

void Variable::SetName(const std::string& name)
{
    name_ = name;
}

string Variable::GetValue() const
{
    return str_value_;
}

string Variable::GetName() const
{
    return name_;
}
