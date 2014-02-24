#include "variable.h"

#include "debug.h"

using namespace std;
using namespace tiny_au3;


void Variable::SetValue(const std::string& value)
{
    str_value_ = value;
}

string Variable::GetValue() const
{
    return str_value_;
}
