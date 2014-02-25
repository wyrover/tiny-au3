#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>

#include "variable.h"
#include "variable_table.h"
#include "keywords.h"

namespace tiny_au3
{

class Expression
{
public:
    Expression(const VariableTable& variables) : variables_(variables) {};

    void SetLeft(const Variable& left);
    void SetRight(const Variable& right);
    void SetOperator(const KeywordCode& code);
    void Reduce();

private:
    VariableTable variables_;
    Variable left_;
    Variable right_;
    Variable result_;
    KeywordCode operator_;
};

}

#endif
