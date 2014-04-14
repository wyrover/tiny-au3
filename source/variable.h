#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>

#include "variant.h"
#include "statement_element.h"

namespace tiny_au3
{

enum VariableType
{
    kNoInitVariable = 0,
    kStringVariable,
    kIntVariable,
    kDoubleVariable
};

class Variable : public StatementElement
{
public:
    explicit Variable(const VariableType& type = kNoInitVariable);
    explicit Variable(const Variable& rhs);

    virtual ~Variable() {};
    virtual void Reduce() {};

    void SetName(const std::string& name);
    void SetValue(const std::string& value);
    std::string GetName() const;
    std::string GetStrValue() const;
    int GetIntValue() const;
    double GetDoubleValue() const;

    Variable& operator=(const Variable& rhs);
    Variable& operator*(const Variable& rhs);

private:
    VariableType type_;
    std::string name_;
    Variant* variant_;

    void InitVariant(const VariableType& type);
};

}

#endif
