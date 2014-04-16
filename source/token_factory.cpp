#include "token_factory.h"

#include "token_null.h"
#include "token_variable.h"
#include "token_literal.h"
#include "token_operator.h"
#include "functions.h"
#include "keywords.h"
#include "error.h"

using namespace std;
using namespace tiny_au3;


bool IsOperator(const string& word)
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
    if ( IsStringBegin(word) || is_string_ )
        return CreateString(word);

    if ( IsNumber(word) )
        return CreateNumber(word);

    if ( IsOperator(word) )
        return CreateOperator(word);

    if ( IsVariable(word) )
        return CreateOperator(word);

    Error::Print(kTokenError, "", 0, word);

    return new TokenNull();
}

Token* TokenFactory::CreateString(const string& word)
{
    /* FIXME: Refactor this method */
    static std::string str("");

    if ( IsStringBegin(word) )
    {
        if ( ! is_string_ )
        {
            is_string_ = true;
            str.append(EraseFirst(word));
            return new TokenNull();
        }
    }

    if ( IsStringEnd(word) )
    {
        if (  is_string_ )
        {
            is_string_ = false;
            str.append(" " + EraseLast(word));
            Token* result = new TokenLiteral();
            result->SetValue(str);
            str.clear();
            return result;
        }
    }
    else if ( is_string_ )
    {
        str.append(" " + word);
        return new TokenNull();
    }
    Error::Print(kTokenError, "", 0, word);
    return new TokenNull();
}

Token* TokenFactory::CreateNumber(const string& word)
{
    Token* result = new TokenLiteral();
    result->SetValue(word);
    return result;
}

Token* TokenFactory::CreateOperator(const string& word)
{
    Token* result = new TokenOperator();
    result->SetValue(word);
    return result;
}

Token* TokenFactory::CreateVariable(const string& word)
{
    Token* result = new TokenVariable();
    result->SetValue(EraseFirst(word));
    return result;
}
