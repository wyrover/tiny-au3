#include "functions.h"

#include <algorithm>
#include <string>

using namespace std;
using namespace tiny_au3;


string tiny_au3::StringToUpper(const string& str)
{
    string result("");

    result.resize(str.length());

    transform(str.begin(), str.end(), result.begin(), ::toupper);

    return result;
}
