#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>

#include "variable.h"
#include "keywords.h"

namespace tiny_au3
{

struct Expression
{
    std::string var_name_;
    Variable variable_;
    KeywordCode code_;
};

}

#endif
