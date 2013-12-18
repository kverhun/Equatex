#ifndef ITEM_H
#define ITEM_H

#include <string>
using std::string;


class Item
{
public:
    virtual string toXml() = 0;
};

#endif // ITEM_H
