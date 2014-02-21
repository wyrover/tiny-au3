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

    return Token(kUndefinedToken);
}

void Lexer::ProcessWord(const string word)
{
    Token token = CreateToken(word);

    if (token.GetType() == kUndefinedToken)
        Error::Print(kTokenError, "", tokens_.size(), word);

    tokens_.back().push_back(CreateToken(word));
}

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

    tokens_.push_back(TokenArray());
    for_each(words.begin(), words.end(),
             bind1st(mem_fun(&Lexer::ProcessWord), this));
}

Lexer::TokenContainer& Lexer::GetTokens() const
{
    return tokens_;
}
