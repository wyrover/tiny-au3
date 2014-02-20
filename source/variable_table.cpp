#include "variable_table.h"

#include "debug.h"

using namespace std;
using namespace tiny_au3;


void VariableTable::SetVariable(const string& name, const Variable& variable)
{
    variables_[name] = variable;
}
