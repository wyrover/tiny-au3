#include "null_element.h"

using namespace std;
using namespace tiny_au3;


NullElement* NullElement::instance_ = NULL;

NullElement* NullElement::Instance()
{
    if (instance_ == NULL)
        instance_ = new NullElement();

    return instance_;
}
