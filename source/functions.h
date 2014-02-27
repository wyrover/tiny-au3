#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>

namespace tiny_au3
{

std::string StringToUpper(const std::string& str);

template<typename T>
T StringToNumber(const std::string& number);

template<typename T>
std::string NumberToString(const T& number);

std::string EraseFirst(const std::string& str);
std::string EraseLast(const std::string& str);

}

#endif
