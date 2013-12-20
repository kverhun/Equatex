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
    size_t size() const;
    bool isEmpty() const;
    bool isValid() const;
    string toXml() const;
private:
    list<Item*> items;
    bool valid;
};

struct e_wrong_expr
{
    size_t pos;
};


#endif // EXPRESSION_H
