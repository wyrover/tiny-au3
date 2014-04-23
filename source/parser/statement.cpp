#include "statement.h"

#include "null_element.h"

using namespace std;
using namespace tiny_au3;

void Statement::AddElement(StatementElement* element)
{
    StatementElement* prev= last_;

    last_ = element;

    last_->SetPrev(prev);
}

void Statement::Reduce()
{
    last_->Reduce(NullElement::Instance());
}
