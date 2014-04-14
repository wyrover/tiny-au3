#include "element_factory.h"

#include "token.h"
#include "operator.h"

using namespace std;
using namespace tiny_au3;


StatementElement* ElementFactory::CreateElement(const Token& token)
{
    /* FIXME: Implement this method */
    return new Operator(kUndefinedKey);
}
