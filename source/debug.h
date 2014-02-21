#ifndef DEBUG_H
#define DEBUG_H

#include <fstream>

namespace tiny_au3
{

class Debug
{
public:
    static void Init(const std::string& log_file);
    static void Print(const char* fmt, ...);

private:
    static std::ofstream file_;
};

}

#endif
