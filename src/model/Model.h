#ifndef MODEL_H
#define MODEL_H

#include "Database/dbconnection.h"
#include <QString>

class Model
{
public:
    Model();

    // queries to database
    QStringList GetStyles();

    bool dbAddImage(QString path, int size,
                    int width, int height,
                    QString type, int symbol_id);
private:

};

#endif // MODEL_H
