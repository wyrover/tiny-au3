#include "variant.h"

#include "debug.h"
#include "functions.h"

using namespace std;
using namespace tiny_au3;

void StringVariant::SetValue(const string& value)
{
    value_ = value;
}

string StringVariant::GetString() const
{
    return value_;
}

int StringVariant::GetInt() const
{
    return StringToNumber<int>(value_);
}

double StringVariant::GetDouble() const
{
    return StringToNumber<double>(value_);
}


void IntVariant::SetValue(const string& value)
{
    value_ = StringToNumber<int>(value);
}

string IntVariant::GetString() const
{
    return NumberToString<int>(value_);
}

int IntVariant::GetInt() const
{
    return value_;
}

double IntVariant::GetDouble() const
{
    return value_;
}


void DoubleVariant::SetValue(const string& value)
{
    value_ = StringToNumber<double>(value);
}

string DoubleVariant::GetString() const
{
    return NumberToString<double>(value_);
}

int DoubleVariant::GetInt() const
{
    return value_;
}

double DoubleVariant::GetDouble() const
{
    return value_;
}
