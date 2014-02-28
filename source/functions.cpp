#include "functions.h"

#include <algorithm>
#include <sstream>
#include <string>

#include "error.h"

using namespace std;
using namespace tiny_au3;


template int tiny_au3::StringToNumber<int>(const string& number);
template double tiny_au3::StringToNumber<double>(const string& number);
template string tiny_au3::NumberToString<int>(const int& number);
template string tiny_au3::NumberToString<double>(const double& number);


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

template<typename T>
T tiny_au3::StringToNumber(const string& number)
{
    T result;

    stringstream stream(number);
    stream >> result;
    if (stream.fail()) {
        Error::Print("Invalid string `%s` to number conversion\n", number.c_str());
    }
    return result;
}

template<typename T>
string tiny_au3::NumberToString(const T& number)
{
    stringstream stream;
    stream << number;
    if (stream.fail()) {
        Error::Print("Invalid number `%d` to string conversion", number);
    }
    return stream.str();
}
