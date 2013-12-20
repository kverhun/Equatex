#ifndef ITEM_H
#define ITEM_H

#include <string>
using std::string;

#include <QImage>
#include <QString>

class Item
{
public:
    virtual string toXml() = 0;
    virtual QImage toImage(int width, int height, QString type, QColor background) = 0;
    virtual int width_symbols() = 0;
};

#endif // ITEM_H
