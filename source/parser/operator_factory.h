#ifndef OPERATOR_FACTORY_H
#define OPERATOR_FACTORY_H

#include <string>

namespace tiny_au3
{

class OperatorFactory
{
public:
    OperatorImpl* CreateOperator(const std::string& word);
};

}

#endif
