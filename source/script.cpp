#include "script.h"

#include <string>
#include <fstream>

using namespace std;
using namespace tiny_au3;


void Script::Execute()
{
    ifstream infile(filename_.c_str());

    string line;
    while ( getline(infile, line) )
    {
        Log("line = %s\n", line.c_str());

        /* FIXME: Implement the input file parsing here */
    }
}

