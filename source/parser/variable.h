#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>

#include "statement_element.h"

namespace tiny_au3
{

class Variable : public StatementElement
{
public:
    explicit Variable(const std::string& id);

    virtual ~Variable() {};
    virtual void Reduce(StatementElement* next);
    virtual std::string GetId() const;

private:
    std::string id_;
};

}

#endif
