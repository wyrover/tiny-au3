#ifndef KEYWORDS_H
#define KEYWORDS_H

#include <string>
#include <map>

namespace tiny_au3
{

enum KeywordCode
{
    kUndefinedKey = 0,
    kLocalKey
};

class Keywords
{
public:
    typedef std::map<std::string, KeywordCode> KeywordMap;
public:
    static KeywordMap CreateMap();
    static KeywordCode GetCode(const std::string& keyword);

private:
    static KeywordMap key_map_;

};

}

#endif
