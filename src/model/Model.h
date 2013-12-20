#ifndef MODEL_H
#define MODEL_H

#include "Database/dbconnection.h"
#include "src/lib/expression/Expression.h"
#include <QString>
#include <QImage>

class Model
{
public:
    Model();

    // queries to database
    QStringList GetStyles();
    QStringList GetSymbolCmds();

    int GetSymbolIdByCmd(QString cmd);

    bool dbAddImage(QString path, QString type, QString latex_cmd);

    bool dbAddImage(QString path,
                    int width, int height,
                    QString type, int symbol_id);

    bool dbAddImageClass(QString name, QString desc);

    ~Model();

    const Expression& Expr() const;
    void ExpressionConstruct(QString latex_str);
    QString ExpressionLatex() const;

    QImage Image();
    void ImageConstruct(int w, int h, QString type, QColor background);
private:

    // storing current expression
    Expression expr;
    QString expr_latex;

    // storing current image
    QImage img;


};

#endif // MODEL_H
