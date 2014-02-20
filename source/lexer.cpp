#include "lexer.h"

#include <algorithm>
#include <functional>
#include <iterator>
#include <sstream>
#include <cctype>

#include "types_tiny_au3.h"
#include "debug.h"
#include "error.h"
#include "keywords.h"

using namespace std;
using namespace tiny_au3;


bool IsKeyword(const string& word)
{
    return (Keywords::GetCode(word) != kUndefinedKey);
}

bool IsVariable(const string& word)
{
    return (word[0] == '$');
}

bool IsNumber(const string& word)
{
    string::const_iterator it = word.begin();

    while (it != word.end())
    {
         if ( ! isdigit(*it) && (*it != '.') && (*it != '-') )
             break;

         ++it;
    }

    return (it == word.end());
}

bool IsComment(const string& line)
{
    /* FIXME: Comment must be placed in any position */
    return (line[0] == ';');
}

Token CreateToken(const string& word)
{
    if (IsNumber(word))
    {
        Token result(kNumberToken);
        /* FIXME: Process the double and long variables */
        result.SetValue(word);
        return result;
    }

    if (IsKeyword(word))
    {
        Token result(kKeywordToken);
        result.SetCode(Keywords::GetCode(word));
        return result;
    }

    if (IsVariable(word))
    {
        Token result(kVariableToken);
        /* FIXME: Remove the `$` symbol */
        result.SetValue(word);
        return result;
    }

    Error::Print(kTokenError, "", 0, word);
    return Token(kUndefinedToken);
}

BINARY_FUNCTOR(ProcessWord, string, word, Lexer::TokenList&, tokens)
    tokens.push_back(CreateToken(word));
END_BINARY_FUNCTOR


void Lexer::Process(const string& line)
{
    if ( line.empty() || IsComment(line) )
        return;

    Debug::Log("%s\n", line.c_str());

    StringList words;

    istringstream iss(line);
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(words));

    for_each(words.begin(), words.end(),
             bind2nd(ProcessWord(), tokens_));
}

Lexer::TokenList& Lexer::GetTokens() const
{
    return tokens_;
}
