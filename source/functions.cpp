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

string tiny_au3::EraseFirst(const string& str)
{
    if (str.empty())
        return string("");

    string result(str);
    return result.erase(0, 1);
}

string tiny_au3::EraseLast(const string& str)
{
    if (str.empty())
        return string("");

    string result(str);
    return result.erase(result.size() - 1);
}
