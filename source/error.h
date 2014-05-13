#ifndef ERROR_H
#define ERROR_H

#include <string>
#include <map>

namespace tiny_au3
{

enum ErrorCode
{
    kUndefinedError = 0,
    kTokenError,
    kKeywordError,
};

/* FIXME: This class is ineffective now.
 * Remove it or make refactoring */
class Error
{
public:
    typedef std::map<ErrorCode, std::string> ErrorMap;

public:
    static ErrorMap CreateMap();
    static void Print(const ErrorCode& code, const std::string& filename,
                      const size_t line_number, const std::string& word);

    static void Print(const char* fmt, ...);

private:
    static ErrorMap error_map_;
};

}

#endif
