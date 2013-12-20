#ifndef QT_IMAGE_UTILS_H
#define QT_IMAGE_UTILS_H

#include <QString>

#include <QImage>
#include <QColor>



int get_image_width(QString path);
int get_image_height(QString path);

QImage create_image(int width, int height, QColor color);

QImage get_image(QString latex_cmd, int width, int height, QString type);


bool isWhite(QColor color, int min_bright=200);

void InsertImage(QImage& dest, QImage& img, int pos_w, int pos_h);

void InsertImage(QImage& dest, QImage& img, int pos_w, int pos_h, QColor color, bool useFont, int min_bright);

QColor qstring_to_qcolor(QString qstr);

#endif // QT_IMAGE_UTILS_H
