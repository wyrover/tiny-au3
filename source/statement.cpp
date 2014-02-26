#include "statement.h"

#include "error.h"

using namespace std;
using namespace tiny_au3;

void Statement::SetLeft(const Variable& left)
{
    left_ = left;
}

void Statement::SetRight(const Variable& right)
{
    right_ = right;
}

void Statement::SetOperator(const KeywordCode& code)
{
    operator_ = code;
}

void Statement::Reduce()
{
    if ( operator_ == kEqualKey )
    {
        /* FIXME: Implement the variable assignment method */
        variables_.SetVariable(left_.GetName(), right_);
        right_.SetName(left_.GetName());
        result_ = left_;
        return;
    }

    Error::Print(kKeywordError, "", 0, operator_);
}
