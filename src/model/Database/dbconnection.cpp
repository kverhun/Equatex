#include "dbconnection.h"

#include "dbqueries.h"

#include <QtSql>
#include <QtSql/QSqlDatabase>

#include <QString>

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
    db = QSqlDatabase::addDatabase("QODBC", db_name);
    db.setDatabaseName(db_name);
    db.setUserName(user_name);
    db.setPassword(password);
    bool success = db.open();

    return success;
}

QStringList DBConnection::GetStyles()
{
    QStringList styles = QStringList();
    QString query = QString::fromStdString(querySelectStyles);

    QSqlQuery q(db);
    q.exec(query);
    while(q.next())
        styles.append(q.value(0).toString());
    return styles;
}

bool DBConnection::InsertImage(QString path, int size,
                               int width, int height,
                               QString type, int symbol_id)
{
    // here to check integrity
    if (false)
    {
        return false;
    }
    QString qquery = QString::fromStdString(queryInsertImageRAW);

    QSqlQuery q(db);
    q.prepare(qquery);
    q.addBindValue(path);
    q.addBindValue(size);
    q.addBindValue(width);
    q.addBindValue(height);
    q.addBindValue(type);
    q.addBindValue(symbol_id);
    q.exec();
    if (!q.isActive())
        return false;
    return true;
}
