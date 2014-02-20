#include "error.h"

#include <iostream>
#include <cstdlib>

using namespace std;
using namespace tiny_au3;


Error::ErrorMap Error::error_map_ = CreateMap();

Error::ErrorMap Error::CreateMap()
{
    ErrorMap result;

    result[kTokenError] = " is undefined token";
    result[kKeywordError] = " is undefined keyword";
    result[kUndefinedError] = " - occured undefined error";

    return result;
}

void Error::Print(const ErrorCode& code, const std::string& filename,
                  const size_t line_number, const string& word)
{
    if (error_map_.count(code) != 0)
        cerr << filename << ":" << line_number << ": error `"
             << word << "`" << error_map_[code] << endl;
    else
        cerr << filename << ":" << line_number << ": error `"
             << word << "`" << error_map_[kUndefinedError] << endl;
    exit(1);
}

