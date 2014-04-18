#include "statement.h"

#include "null_element.h"

using namespace std;
using namespace tiny_au3;

void Statement::AddElement(StatementElement* element)
{
    elements_.push_back(element);
}

void Statement::Reduce()
{
    if ( elements_.empty() )
        return;

    NullElement null;
    size_t size = elements_.size();

    for (size_t i = 0; i < size; ++i)
    {
        if ( i == 0 )
            elements_[i]->Reduce(&null, elements_[i+1]);
        else if ( i == size )
            elements_[i]->Reduce(elements_[i-1], &null);
        else
            elements_[i]->Reduce(elements_[i-1], elements_[i+1]);
    }
}
