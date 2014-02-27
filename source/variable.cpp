#include "variable.h"

#include "debug.h"
#include "functions.h"

using namespace std;
using namespace tiny_au3;


Variable::Variable(const VariableType& type) : type_(type)
{
    ClearValues();
}

void Variable::SetValue(const std::string& value)
{
    str_value_ = value;
}

void Variable::SetName(const std::string& name)
{
    name_ = name;
}

string Variable::GetStrValue() const
{
    return str_value_;
}

int Variable::GetIntValue() const
{
    /* FIXME: Implement conversion from string and double if needed */
    return int_value_;
}

double Variable::GetDoubleValue() const
{
    /* FIXME: Implement conversion from string and int if needed */
    return double_value_;
}

string Variable::GetName() const
{
    return name_;
}

Variable& Variable::operator=(const Variable& rhs)
{
    if (this == &rhs)
        return *this;

    ClearValues();

    type_ = rhs.type_;

    switch(type_)
    {
        case kStringVariabie:
            str_value_ = rhs.GetStrValue();
            break;
        case kIntVariable:
            int_value_ = rhs.GetIntValue();
            break;
        case kDoubleVariable:
            double_value_ = rhs.GetDoubleValue();
            break;
        default:
            break;
    }

    return *this;
}

Variable& Variable::operator*(const Variable& rhs)
{
    /* FIXME: Implement this operator */
    return *this;
}

void Variable::ClearValues()
{
    str_value_.clear();
}
