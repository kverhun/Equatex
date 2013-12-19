#include "model.h"

#include<QMessageBox>

Model::Model()
{
    DBConnection* connection = DBConnection::Instance();
    QMessageBox mb;
    mb.setText(connection->isSuccessful()?"Successful":"Failed");
    mb.exec();
}
