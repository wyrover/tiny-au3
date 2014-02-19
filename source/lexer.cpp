#include "lexer.h"

#include <algorithm>
#include <functional>
#include <iterator>
#include <sstream>

#include "types_tiny_au3.h"
#include "debug.h"

using namespace std;
using namespace tiny_au3;


BINARY_FUNCTOR(ProcessWord, string, word, Lexer::TokenList&, tokens)
    /* FIXME: Implement the token creation */
END_BINARY_FUNCTOR

void Lexer::Process(const string& line)
{
    Debug::Log("%s\n", line.c_str());

    StringList words;

    istringstream iss(line);
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(words));

    for_each(words.begin(), words.end(),
             bind2nd(ProcessWord(), tokens_));
}

