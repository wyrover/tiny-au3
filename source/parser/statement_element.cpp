#include "statement_element.h"

using namespace std;
using namespace tiny_au3;

void StatementElement::SetPrev(StatementElement* prev)
{
    prev_ = prev;
}

StatementElement* StatementElement::GetPrev()
{
    return prev_;
}
