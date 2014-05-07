#include "variable_table.h"

#include <cassert>

#include "functions.h"
#include "debug.h"

using namespace std;
using namespace tiny_au3;


VariableTable* VariableTable::instance_ = NULL;

VariableTable* VariableTable::Instance()
{
    if (instance_ == NULL)
        instance_ = new VariableTable();

    return instance_;
}

void VariableTable::SetValue(const string& name, const std::string& value)
{
    Debug::Print("VariableTable::SetValue() - name = %s value = %s\n",
            name.c_str(), value.c_str());

    string upper_name = StringToUpper(name);

    if ( variables_.count(upper_name) == 0 )
    {
        variables_.insert(VariableMap::value_type(upper_name, value));
    }
    else
        variables_[upper_name] = value;
}

string VariableTable::GetValue(const std::string& name) const
{
    Debug::Print("VariableTable::GetValue() - name = %s\n",
            name.c_str());

    string upper_name = StringToUpper(name);

    assert( variables_.count(upper_name) != 0 );

    return variables_[upper_name];
}
