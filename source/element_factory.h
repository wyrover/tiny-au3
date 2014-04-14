#ifndef ELEMENT_FACTORY_H
#define ELEMENT_FACTORY_H


namespace tiny_au3
{

class Token;
class StatementElement;

class ElementFactory
{
public:
    static StatementElement* CreateElement(const Token& token);
};

}

#endif
