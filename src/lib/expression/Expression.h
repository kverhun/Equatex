#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <list>
using std::list;

#include "Item.h"

class Expression
{
public:
    Expression();
    Expression(string texexpr);
    size_t size();
    bool isEmpty();

    string toXml();
private:
    list<Item*> items;
};

struct e_wrong_expr
{
    size_t pos;
};


#endif // EXPRESSION_H
