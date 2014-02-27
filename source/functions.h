#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>

namespace tiny_au3
{

std::string StringToUpper(const std::string& str);
int StringToInt(const std::string& str);
std::string IntToString(const int& value);
std::string EraseFirst(const std::string& str);
std::string EraseLast(const std::string& str);

}

#endif
