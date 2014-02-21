#include "variable.h"

#include "debug.h"

using namespace std;
using namespace tiny_au3;


void Variable::SetValue(const std::string& value)
{
    value_ = value;
}

string Variable::GetValue() const
{
    return value_;
}
