#include "operator_null.h"

#include <cstddef>

using namespace std;
using namespace tiny_au3;


OperatorNull* OperatorNull::instance_ = NULL;

OperatorNull* OperatorNull::Instance()
{
    if (instance_ == NULL)
        instance_ = new OperatorNull();

    return instance_;
}
