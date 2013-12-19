#ifndef IDBVIEW_H
#define IDBVIEW_H

#include <QString>

class IDView
{
public:
    virtual QString getDBName() = 0;
    virtual QString getDBUser() = 0;
    virtual QString getDBPassword() = 0;

    virtual void outMessage(QString msg) = 0;

    virtual void onConnectClick() = 0;
    virtual void onTestClick() = 0;
    virtual void onCancelClick() = 0;
};

#endif // IDBVIEW_H
