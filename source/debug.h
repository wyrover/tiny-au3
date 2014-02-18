#ifndef DEBUG_H
#define DEBUG_H

#include <fstream>

#include "types_tiny_au3.h"

namespace tiny_au3
{

class Debug
{
public:
    Debug(const char* log_file);
    virtual ~Debug();

    void Log(const char* fmt, ...) const;

private:
    mutable std::ofstream file_;

    DISALLOW_COPY_AND_ASSIGN(Debug);
};

}

#endif
