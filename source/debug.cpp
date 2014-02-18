#include "debug.h"

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

using namespace std;
using namespace tiny_au3;

static const string kDefaultLogfile = "/dev/null";

std::ofstream Debug::file_;


void Debug::Init(const string& log_file)
{
#ifdef __DEBUG__
    if ( ! log_file.empty() )
        file_.open(log_file.c_str(), ios::out | ios::app);
    else
        file_.open(kDefaultLogfile.c_str(), ios::out | ios::app);
#endif
}

void Debug::Log(const char* fmt, ...)
{
#ifdef __DEBUG__
    char buf[4096];
    va_list arg_list;
    va_start(arg_list, fmt);
    vsprintf(buf, fmt, arg_list);

    file_ << buf;
    va_end(arg_list);
#endif
}
