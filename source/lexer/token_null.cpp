#include "token_null.h"

#include "null_element.h"

using namespace std;
using namespace tiny_au3;


StatementElement* TokenNull::Produce() const
{
    return NullElement::Instance();
}

bool TokenNull::IsComplete() const
{
    return false;
}
