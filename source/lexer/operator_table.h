#ifndef OPERATOR_TABLE_H
#define OPERATOR_TABLE_H

#include <string>
#include <map>

namespace tiny_au3
{

enum OperatorCode
{
    kUndefinedOperator = 0,
    kEqual,
    kPlus,
    kMinus,
    kMultiply,
    kDivide,
    kPower
};

class OperatorTable
{
public:
    typedef std::map<std::string, OperatorCode> OperatorMap;
public:
    static OperatorMap CreateMap();
    static OperatorCode GetCode(const std::string& oper);

private:
    static OperatorMap operators_;

};

}

#endif
