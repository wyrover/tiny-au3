#include "statement_element.h"

#include <cassert>

using namespace std;
using namespace tiny_au3;

void StatementElement::SetPrev(StatementElement* prev)
{
    prev_ = prev;
}

StatementElement* StatementElement::GetPrev()
{
    assert( prev_ != NULL );

    return prev_;
}

string StatementElement::GetId() const
{
    return string("");
}
