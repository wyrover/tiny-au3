#ifndef LIST_ELEMENT_H
#define LIST_ELEMENT_H

namespace tiny_au3
{

class StatementElement;

class ListElement
{
public:
    virtual ~ListElement() {};

    void SetPrev(StatementElement* prev);
    StatementElement* GetPrev();

private:
    StatementElement* prev_;
};

}

#endif
