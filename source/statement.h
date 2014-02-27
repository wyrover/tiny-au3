#ifndef STATEMENT_H
#define STATEMENT_H

#include <string>
#include <deque>

#include "variable.h"
#include "variable_table.h"
#include "keywords.h"

namespace tiny_au3
{

struct StatementElement
{
    StatementElement() : operator_(kUndefinedKey) {};

    Variable variable_;
    KeywordCode operator_;
};

class Statement
{
public:
    typedef std::deque<StatementElement> ElementDeque;

public:
    Statement(const VariableTable& variables) : variables_(variables) {};

    void AddVariable(const Variable& variable);
    void AddOperator(const KeywordCode& code);
    void Reduce();

private:
    VariableTable variables_;
    ElementDeque elements_;
    Variable result_;
};

}

#endif
