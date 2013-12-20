#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <QString>
#include <QtSql>
#include <QtSql/QSqlDatabase>

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
    bool InsertImage(QString path, int size,
                     int width, int height,
                     QString type, int symbol_id);
private:
    DBConnection();
    static DBConnection* instance;
    bool successful;
    QSqlDatabase db;
};

#endif // DBCONNECTION_H
