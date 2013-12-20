#include "model.h"
#include <string>
#include <utility>

#include<QMessageBox>

#include "src/lib/files/file_utils.h"
//#include "src/lib/image/image_utils.h"
#include "src/lib/image/qt_image_utils.h"
#include "src/lib/expression/Expression.h"

using namespace std;

Model::Model()
{
    DBConnection* connection = DBConnection::Instance();
    QMessageBox mb;
    mb.setText(connection->isSuccessful()?"Successful":"Failed");
    mb.exec();

    this->expr = Expression();
    this->expr_latex = "";
}

Model::~Model()
{
}

const Expression& Model::Expr() const
{
    return this->expr;
}

void Model::ExpressionConstruct(QString latex_str)
{
    this->expr_latex = latex_str;
    this->expr = Expression(latex_str.toStdString());
}

QString Model::ExpressionLatex() const
{
    return this->expr_latex;
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
    int w = get_image_width(path);
    int h = get_image_height(path);
    if (w < 0 || h < 0 || w > 200 || h > 200)
        return false;

    DBConnection* connection = DBConnection::Instance();

    int symbol_id = connection->GetSymbolIdByCmd(latex_cmd);

    if (symbol_id == -1)
        return false;

    bool added = connection->InsertImage(path,w,h,type,symbol_id);
    return added;
}


