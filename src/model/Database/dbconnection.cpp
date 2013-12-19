#include "dbconnection.h"

#include <QtSql>
#include <QtSql/QSqlDatabase>

DBConnection* DBConnection::instance;

DBConnection::DBConnection()
{
    bool success = Connect("equatex_project", "equatex", "qwerty");
    this->successful = success;
}

DBConnection* DBConnection::Instance()
{
    if (instance == nullptr)
        instance = new DBConnection();
    return instance;
}

bool DBConnection::Connect(QString db_name, QString user_name, QString password)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", db_name);
    db.setDatabaseName(db_name);
    db.setUserName(user_name);
    db.setPassword(password);
    bool success = db.open();
    db.close();
    return success;
}

QStringList DBConnection::GetStyles()
{

}
