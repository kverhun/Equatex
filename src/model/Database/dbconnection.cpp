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

QStringList DBConnection::GetSymbolCmds()
{
    QStringList cmds = QStringList();
    QString query = QString::fromStdString(querySelectSymbolCmds);
    QSqlQuery q(db);
    q.exec(query);
    while(q.next())
        cmds.append(q.value(0).toString());
    return cmds;
}

bool DBConnection::InsertImage(QString path,
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
    q.addBindValue(width);
    q.addBindValue(height);
    q.addBindValue(type);
    q.addBindValue(symbol_id);
    q.exec();
    if (!q.isActive())
        return false;
    return true;
}

int DBConnection::GetSymbolIdByCmd(QString cmd)
{
    QSqlQuery q(db);
    QString qquery = QString::fromStdString(querySymbolIdByCmdRAW);
    q.prepare(qquery);
    q.addBindValue(cmd);
    q.exec();
    if (!q.isActive())
    {
        return -1;
    }
    else
    {
        while(q.next())
            return q.value(0).toInt();
    }
}

bool DBConnection::InsertImageType(QString type_name, QString type_desc)
{
    QSqlQuery q(db);
    QString qquery = QString::fromStdString(queryInsertImageTypeRAW);
    q.prepare(qquery);
    q.addBindValue(type_name);
    q.addBindValue(type_desc);
    q.exec();
    if (!q.isActive())
        return false;
    return true;
}

QString DBConnection::GetPathByCmd(QString cmd, QString type)
{
    QSqlQuery q(db);
    QString qquery = QString::fromStdString(queryImagePathByCmdRAW);
    q.prepare(qquery);
    q.addBindValue(cmd);
    q.addBindValue(type);
    q.exec();
    QString res;
    if (q.isActive())
    {
        while(q.next())
            return q.value(0).toString();
    }
    else
    {
        if (type != "default")
        {
            return this->GetPathByCmd(cmd, "default");
        }
        else
        {
            return "error";
        }
    }
}






