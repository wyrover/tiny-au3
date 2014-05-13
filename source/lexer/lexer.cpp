#include "lexer.h"

#include <algorithm>
#include <functional>
#include <iterator>
#include <sstream>
#include <cctype>

#include "types_tiny_au3.h"
#include "debug.h"
#include "error.h"
#include "token_factory.h"

using namespace std;
using namespace tiny_au3;


bool IsComment(const string& line)
{
    /* FIXME: Comment can be placed in any position */
    return (line[0] == ';');
}

Token* CreateToken(const string& word)
{
    static TokenFactory factory;

    return factory.CreateToken(word);
}

void Lexer::ProcessWord(const string word)
{
    Token* token = CreateToken(word);

    if ( ! token->IsComplete() )
        return;

    tokens_.back().push_back(token);
}

void Lexer::Process(const string& line)
{
    if ( line.empty() || IsComment(line) )
        return;

    DEBUG << "Lexer::Process() - " << line << endl;

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
