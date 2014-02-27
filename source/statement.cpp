#include "statement.h"

#include "error.h"

using namespace std;
using namespace tiny_au3;

void Statement::AddVariable(const Variable& variable)
{
    StatementElement element;
    element.variable_ = variable;
    elements_.push_back(element);
}

void Statement::AddOperator(const KeywordCode& code)
{
    StatementElement element;
    element.operator_ = code;
    elements_.push_back(element);
}

void Statement::Reduce()
{
    for( size_t i = 0; i < elements_.size(); i++ )
    {
        if ( elements_[i].operator_ == kMultiplyKey )
        {
            /* FIXME: Implement this operator */
            elements_[i-1].variable_ = elements_[i-1].variable_ * elements_[i+1].variable_;
            /* FIXME: Delete extra elements at i and i+1 indexes */
        }
    }
}
