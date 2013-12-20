#include "qt_image_utils.h"

#include <QImage>
#include <QColor>

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


QImage create_image(int width, int height, QColor color)
{
    QImage img;
    img = QImage(width, height,QImage::Format_RGB32);
    img.fill(color);
    return img;
}
