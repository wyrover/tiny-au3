#ifndef DEBUG_H
#define DEBUG_H

#include <fstream>

#define DEBUG_PTR Debug::Instance()
#define DEBUG *DEBUG_PTR
#define DEBUG_PRINT DEBUG_PTR->Print

namespace tiny_au3
{

class Debug
{
public:
    static Debug* Instance();

    void SetLogfile(const std::string& log_file);
    void Print(const char* fmt, ...);
    std::ostream& operator<<(const std::string& value);

private:
    static Debug* instance_;
    std::ofstream file_;

    Debug() {};
};

}

#endif
