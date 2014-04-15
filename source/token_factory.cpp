#include "token_factory.h"

#include "functions.h"
#include "keywords.h"

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

Token* TokenFactory::CreateToken(const string& word)
{
    /* FIXME: Implement this method */
    return NULL;
#if 0
    if ( IsStringBegin(word) || is_string_ )
        return CreateString(word);

    if ( IsNumber(word) )
        return CreateNumber(word);

    if ( IsKeyword(word) )
        return CreateKeyword(word);

    if ( IsVariable(word) )
        return CreateVariable(word);

    return new Token(kUndefinedToken);
#endif
}

Token* TokenFactory::CreateString(const string& word)
{
    /* FIXME: Implement this method */
    return NULL;
#if 0
    /* FIXME: Refactor this method */
    static std::string str("");

    if ( IsStringBegin(word) )
    {
        if ( ! is_string_ )
        {
            is_string_ = true;
            str.append(EraseFirst(word));
            return Token(kUnfinishedToken);
        }
    }

    if ( IsStringEnd(word) )
    {
        if (  is_string_ )
        {
            is_string_ = false;
            str.append(" " + EraseLast(word));
            Token result(kStringToken);
            result.SetValue(str);
            str.clear();
            return result;
        }
    }
    else if ( is_string_ )
    {
        str.append(" " + word);
        return Token(kUnfinishedToken);
    }
    return Token(kUndefinedToken);
#endif
}

Token* TokenFactory::CreateNumber(const string& word)
{
    /* FIXME: Implement this method */
    return NULL;
#if 0
    if ( ! IsNumber(word) )
        return Token(kUndefinedToken);

    Token result(kNumberToken);
    /* FIXME: Process the double and long variables */
    result.SetValue(word);
    return result;
#endif
}

Token* TokenFactory::CreateKeyword(const string& word)
{
    /* FIXME: Implement this method */
    return NULL;
#if 0
    if ( ! IsKeyword(word) )
        return Token(kUndefinedToken);

    Token result(kKeywordToken);
    result.SetCode(Keywords::GetCode(word));
    return result;
#endif
}

Token* TokenFactory::CreateVariable(const string& word)
{
    /* FIXME: Implement this method */
    return NULL;
#if 0
    if ( ! IsVariable(word) )
        return Token(kUndefinedToken);

    Token result(kVariableToken);
    result.SetValue(EraseFirst(word));
    return result;
#endif
}
