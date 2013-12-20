#include "file_utils.h"

int get_size(QString path)
{
    QFile file(path);
    if (!file.exists())
        return -1;
    else
        return (int)(file.size()/1024);
}
