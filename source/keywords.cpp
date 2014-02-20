#include "keywords.h"

#include "functions.h"

using namespace std;
using namespace tiny_au3;

Keywords::KeywordMap Keywords::key_map_ = CreateMap();

Keywords::KeywordMap Keywords::CreateMap()
{
    KeywordMap result;

    result["LOCAL"] = kLocalKey;

    return result;
}

KeywordCode Keywords::GetCode(const string& keyword)
{
    string upper_key = StringToUpper(keyword);

    if (key_map_.count(upper_key) != 0)
        return key_map_[upper_key];
    else
        return kUndefinedKey;
}
