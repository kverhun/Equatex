#ifndef QT_IMAGE_UTILS_H
#define QT_IMAGE_UTILS_H

#include <QString>

#include <QImage>
#include <QColor>



int get_image_width(QString path);
int get_image_height(QString path);

QImage create_image(int width, int height, QColor color);

QImage get_image(QString latex_cmd, int width, int height, QString type);


bool isWhite(QColor color);

void InsertImage(QImage& dest, QImage& img, int pos_w, int pos_h);


#endif // QT_IMAGE_UTILS_H
