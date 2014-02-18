#include "script.h"

#include <string>
#include <fstream>

#include "debug.h"

using namespace std;
using namespace tiny_au3;


void Script::Execute()
{
    ifstream infile(input_file_.c_str());

    string line;
    while ( getline(infile, line) )
    {
        lexer_.Process(line);
    }
}

