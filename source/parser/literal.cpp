#include "literal.h"

#include <assert.h>

using namespace std;
using namespace tiny_au3;

void Literal::Init(const string& value)
{
    value_ = value;
}

void Literal::Reduce(StatementElement* next)
{
    /* FIXME: Implement this method */
}
