#include "program_options.h"

#include <algorithm>

using namespace std;
using namespace tiny_au3;

char* ProgramOptions::GetString(const string& option)
{
    char ** itr = find(begin_, end_, option);

    if ( (itr != end_) && (++itr != end_) )
        return *itr;
    else
        return 0;
}

int ProgramOptions::GetInt(const string& option)
{
    char* value = GetString(option);

    /* FIXME: We need unsigned int here */
    return atoi(value);
}

bool ProgramOptions::IsOptionExist(const string& option)
{
    return find(begin_, end_, option) != end_;
}
