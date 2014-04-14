#include "lexer.h"

#include <algorithm>
#include <functional>
#include <iterator>
#include <sstream>
#include <cctype>

#include "types_tiny_au3.h"
#include "debug.h"
#include "error.h"
#include "token_builder.h"

using namespace std;
using namespace tiny_au3;


bool IsComment(const string& line)
{
    /* FIXME: Comment must be placed in any position */
    return (line[0] == ';');
}

Token CreateToken(const string& word)
{
    /* FIXME: Refactoring this method with polymorphism */
    Token result = TokenBuilder::CreateString(word);

    if (result.GetType() != kUndefinedToken)
        return result;

    result = TokenBuilder::CreateNumber(word);

    if (result.GetType() != kUndefinedToken)
        return result;

    result = TokenBuilder::CreateKeyword(word);

    if (result.GetType() != kUndefinedToken)
        return result;

    result = TokenBuilder::CreateVariable(word);

    if (result.GetType() != kUndefinedToken)
        return result;

    return Token(kUndefinedToken);
}

void Lexer::ProcessWord(const string word)
{
    Token token = CreateToken(word);

    if (token.GetType() == kUnfinishedToken)
        return;

    if (token.GetType() == kUndefinedToken)
        Error::Print(kTokenError, "", tokens_.size(), word);

    tokens_.back().push_back(token);
}

void Lexer::Process(const string& line)
{
    if ( line.empty() || IsComment(line) )
        return;

    Debug::Print("%s\n", line.c_str());

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
