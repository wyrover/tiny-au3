#include "variable_table.h"

#include <algorithm>

#include "functions.h"

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

void VariableTable::SetVariable(const string& name, const std::string& value)
{
    string upper_name = StringToUpper(name);

    /* FIXME: Algorithm:
     * 1) Create new variable if needed
     * 2) Set new value of the existed or new variable */
    //variables_[upper_name] = variable;
}
