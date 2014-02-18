#include "script.h"

#include <string>
#include <fstream>

using namespace std;
using namespace tiny_au3;


void Script::Execute()
{
    ifstream infile(input_file_.c_str());

    string line;
    while ( getline(infile, line) )
    {
        Log("line = %s\n", line.c_str());

        lexer_.Process(line);
    }
}

