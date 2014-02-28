#include "variable.h"

#include <assert.h>

#include "debug.h"
#include "error.h"
#include "functions.h"

using namespace std;
using namespace tiny_au3;


Variable::Variable(const VariableType& type) : type_(type)
{
    InitVariant(type_);
}

Variable::Variable(const Variable& rhs)
{
    type_ = rhs.type_;

    InitVariant(type_);
    *variant_ = *rhs.variant_;
}

void Variable::InitVariant(const VariableType& type)
{
    switch(type)
    {
        /* FIXME: Is this default string type correctness ? */
        default:
        case kStringVariable:
            variant_ = new StringVariant();
            break;
        case kIntVariable:
            variant_ = new IntVariant();
            break;
        case kDoubleVariable:
            variant_ = new DoubleVariant();
            break;
    }
}

void Variable::SetValue(const std::string& value)
{
    variant_->SetValue(value);
}

void Variable::SetName(const std::string& name)
{
    name_ = name;
}

string Variable::GetStrValue() const
{
    return variant_->GetString();
}

int Variable::GetIntValue() const
{
    return variant_->GetInt();
}

double Variable::GetDoubleValue() const
{
    return variant_->GetDouble();
}

string Variable::GetName() const
{
    return name_;
}

Variable& Variable::operator=(const Variable& rhs)
{
    if (this == &rhs)
        return *this;

    type_ = rhs.type_;
    delete variant_;

    InitVariant(type_);
    *variant_ = *rhs.variant_;

    return *this;
}

Variable& Variable::operator*(const Variable& rhs)
{
    double result;

    if ( type_ == kDoubleVariable || rhs.type_ == kDoubleVariable )
    {
        result = variant_->GetDouble() * rhs.variant_->GetDouble();

        if ( type_ != kDoubleVariable )
        {
            type_ = rhs.type_;
            delete variant_;
            InitVariant(type_);
        }

        variant_->SetValue(NumberToString<double>(result));
        return *this;
    }

    if ( type_ == kIntVariable || rhs.type_ == kIntVariable )
    {
        result = variant_->GetInt() * rhs.variant_->GetInt();

        if ( type_ != kIntVariable )
        {
            type_ = rhs.type_;
            delete variant_;
            InitVariant(type_);
        }

        variant_->SetValue(NumberToString<int>(result));
        return *this;
    }


    /* FIXME: Implement the multiplying string */

    return *this;
}
