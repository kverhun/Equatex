#ifndef FRACTION_H
#define FRACTION_H

#include "Item.h"
#include "Expression.h"

class Fraction : public Item
{
public:
    Fraction();
    Fraction(Expression _top, Expression _bot);
    void set_top (Expression expr);
    void set_bot (Expression expr);
    string toXml();

    QImage toImage(int width, int height, QString type);

    int width_symbols();
private:
    Expression top;
    Expression bot;
};

#endif // FRACTION_H
