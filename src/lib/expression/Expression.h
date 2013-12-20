#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <list>
using std::list;

#include "Item.h"

#include <QImage>
#include <QString>

const double frac_coef = 1;
const double ind_coef = 0.75;

const int min_brigth = 257;

class Expression
{
public:
    Expression();
    Expression(string texexpr);
    size_t size() const;
    bool isEmpty() const;
    bool isValid() const;
    string toXml() const;

    QImage toImage(int width, int height, QString type, QColor background, QColor font=QColor(Qt::black),  bool useFont = false) const;
    int width_symbols();
private:
    list<Item*> items;
    bool valid;
};

struct e_wrong_expr
{
    size_t pos;
};


#endif // EXPRESSION_H
