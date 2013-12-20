#include "model.h"

#include<QMessageBox>

Model::Model()
{
    DBConnection* connection = DBConnection::Instance();
    QMessageBox mb;
    mb.setText(connection->isSuccessful()?"Successful":"Failed");
    mb.exec();
}

QStringList Model::GetStyles()
{
    DBConnection* connection = DBConnection::Instance();
    return connection->GetStyles();
}

bool Model::dbAddImage(QString path, int size,
                       int width, int height,
                       QString type, int symbol_id)
{
    DBConnection* connection = DBConnection::Instance();
    return connection->InsertImage(path, size, width, height, type, symbol_id);
}
