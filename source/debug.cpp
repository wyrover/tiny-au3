#include "debug.h"

#include <cstdio>
#include <cstring>
#include <cstdarg>
#include <cassert>

using namespace std;
using namespace tiny_au3;

static const string kDefaultLogfile = "/dev/null";

Debug* Debug::instance_ = NULL;

Debug* Debug::Instance()
{
    if (instance_ == NULL)
        instance_ = new Debug();

    return instance_;
}

void Debug::SetLogfile(const string& log_file)
{
#ifdef __DEBUG__
    if ( file_.is_open() )
        return;

    if ( ! log_file.empty() )
        file_.open(log_file.c_str(), ios::out | ios::app);
    else
        file_.open(kDefaultLogfile.c_str(), ios::out | ios::app);
#endif
}

void Debug::Print(const char* fmt, ...)
{
#ifdef __DEBUG__
    assert( file_.is_open() );
    char buf[4096];
    va_list arg_list;
    va_start(arg_list, fmt);
    vsprintf(buf, fmt, arg_list);

    file_ << buf << endl;
    va_end(arg_list);
#endif
}

ostream& Debug::operator<<(const string& value)
{
#ifdef __DEBUG__
    file_ << value << endl;
    return file_;
#endif
}
