#include "variable_table.h"

#include <algorithm>

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

void RemoveVariable(VariableTable::VariableMap::value_type variable_pair)
{
    delete variable_pair.second;
}

VariableTable::~VariableTable()
{
    if ( variables_.empty() )
        return;

    for_each(variables_.begin(), variables_.end(),
             RemoveVariable);
}

void VariableTable::SetVariable(const string& name, Variable* variable)
{
    string upper_name = StringToUpper(name);

    Debug::Print("VariableTable::SetVariable() - var_name = %s var_value = %s\n",
                 upper_name.c_str(), variable->GetStrValue().c_str());
    variables_[upper_name] = variable;
}
