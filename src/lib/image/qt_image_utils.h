#ifndef QT_IMAGE_UTILS_H
#define QT_IMAGE_UTILS_H

#include <QString>

#include <QImage>
#include <QColor>



int get_image_width(QString path);
int get_image_height(QString path);

QImage create_image(int width, int height, QColor color);

#endif // QT_IMAGE_UTILS_H
