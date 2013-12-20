#include "qt_image_utils.h"

#include <QImage>

int get_image_height(QString path)
{
    QImage img(path);
    return img.height();
}

int get_image_width(QString path)
{
    QImage img(path);
    return img.width();
}
