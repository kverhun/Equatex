#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <QString>

/*
 *  Class for database connection
 *
 *  Implemented as singleton class
 */
class DBConnection
{
public:
    static DBConnection* Instance();
    bool Connect(QString db_name, QString user_name, QString password);
    bool isSuccessful() {return successful;}

    QStringList GetStyles();
private:
    DBConnection();
    static DBConnection* instance;
    bool successful;
};

#endif // DBCONNECTION_H
