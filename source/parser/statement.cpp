#include "statement.h"

#include "error.h"
#include "debug.h"

using namespace std;
using namespace tiny_au3;

void Statement::AddElement(StatementElement* element)
{
    elements_.push_back(element);
}

void Statement::Reduce()
{
    /* FIXME: Implement this method */
}
