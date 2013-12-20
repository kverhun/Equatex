#include "model.h"
#include <string>
#include <utility>

#include<QMessageBox>

#include "src/lib/files/file_utils.h"
#include "src/lib/image/image_utils.h"

using namespace std;

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

QStringList Model::GetSymbolCmds()
{
    DBConnection* connection = DBConnection::Instance();
    return connection->GetSymbolCmds();
}

bool Model::dbAddImage(QString path,
                       int width, int height,
                       QString type, int symbol_id)
{
    DBConnection* connection = DBConnection::Instance();
    return connection->InsertImage(path, width, height, type, symbol_id);
}

bool Model::dbAddImage(QString path, QString type, QString latex_cmd)
{
    pair<int,int> img_res = getImageSize(path.toStdString());
    if (img_res.first < 0 || img_res.second < 0)
        return false;
    DBConnection* connection = DBConnection::Instance();
    int symbol_id = connection->GetSymbolIdByCmd(latex_cmd);
    if (symbol_id == -1)
        return false;

    bool added = connection->InsertImage(path,img_res.first, img_res.second,type,symbol_id);
    return added;
}


