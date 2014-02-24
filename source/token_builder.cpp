#include "token_builder.h"

#include "functions.h"

using namespace std;
using namespace tiny_au3;


bool IsKeyword(const string& word)
{
    return (Keywords::GetCode(word) != kUndefinedKey);
}

bool IsVariable(const string& word)
{
    return (*word.begin() == '$');
}

bool IsStringBegin(const string& word)
{
    char first = *word.begin();
    return (first == '"' || first == '\'');
}

bool IsStringEnd(const string& word)
{
    char last = *word.rbegin();
    return (last == '"' || last == '\'');
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

Token TokenBuilder::CreateString(const string& word)
{
    /* FIXME: Refactor this method */
    static bool is_string = false;
    static std::string str("");

    if ( IsStringBegin(word) )
    {
        if ( ! is_string )
        {
            is_string = true;
            str.append(EraseFirst(word));
            return Token(kUnfinishedToken);
        }
    }

    if ( IsStringEnd(word) )
    {
        if (  is_string )
        {
            is_string = false;
            str.append(" " + EraseLast(word));
            Token result(kStringToken);
            result.SetValue(str);
            str.clear();
            return result;
        }
    }
    else if ( is_string )
    {
        str.append(" " + word);
        return Token(kUnfinishedToken);
    }
    return Token(kUndefinedToken);
}

Token TokenBuilder::CreateNumber(const string& word)
{
    if ( ! IsNumber(word) )
        return Token(kUndefinedToken);

    Token result(kNumberToken);
    /* FIXME: Process the double and long variables */
    result.SetValue(word);
    return result;
}

Token TokenBuilder::CreateKeyword(const string& word)
{
    if ( ! IsKeyword(word) )
        return Token(kUndefinedToken);

    Token result(kKeywordToken);
    result.SetCode(Keywords::GetCode(word));
    return result;
}

Token TokenBuilder::CreateVariable(const string& word)
{
    if ( ! IsVariable(word) )
        return Token(kUndefinedToken);

    Token result(kVariableToken);
    result.SetValue(EraseFirst(word));
    return result;
}
