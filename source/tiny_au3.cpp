#include <iostream>

#include "program_options.h"

using namespace std;
using namespace tiny_au3;

void PrintUsage()
{
    cout << "Usage: tiny-au3 [options] <input-file>" << endl;
    cout << "Options:" << endl;
    cout << "\t-v\t\tShow program version and exit" << endl;
    cout << "\t-h\t\tPrint help and exit" << endl;
}

void PrintVersion()
{
    /* FIXME: Use global variable with version number instead the literal */
    cout << "Tiny AU3 version 0.1" << endl;
}


int main(int argc, char *argv[])
{
    ProgramOptions options(argv, argv+argc);

    if ( options.IsOptionExist("-h") )
    {
        PrintUsage();
        return 1;
    }

    if ( options.IsOptionExist("-v") )
    {
        PrintVersion();
        return 1;
    }

    /* FIXME: Implement script input file processing */

    return 0;
}
