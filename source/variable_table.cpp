#include "variable_table.h"

#include "functions.h"
#include "debug.h"

using namespace std;
using namespace tiny_au3;


void VariableTable::SetVariable(const string& name, const Variable& variable)
{
    string upper_name = StringToUpper(name);

    Debug::Print("var_name = %s var_value = %s\n",
                 upper_name.c_str(), variable.GetValue().c_str());
    variables_[upper_name] = variable;
}
