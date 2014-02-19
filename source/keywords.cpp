#include "keywords.h"


using namespace std;
using namespace tiny_au3;

Keywords::KeywordMap Keywords::key_map_ = CreateMap();

Keywords::KeywordMap Keywords::CreateMap()
{
    KeywordMap result;

    result["LOCAL"] = kLocalKey;
}

KeywordCode Keywords::GetCode(const string& keyword)
{
    if (key_map_.count(keyword) != 0)
        return key_map_[keyword];
    else
        return kUndefinedKey;
}
