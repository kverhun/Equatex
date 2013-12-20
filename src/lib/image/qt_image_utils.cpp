#include "qt_image_utils.h"

#include <QImage>
#include <QColor>

#include "src/model/Database/dbconnection.h"

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

QImage get_image(QString latex_cmd, int width, int height, QString type)
{
    DBConnection* connection = DBConnection::Instance();
    QString path = connection->GetPathByCmd(latex_cmd, type);
    if (path == "error")
    {
        QImage img(width,height,QImage::Format_RGB32);
        img.fill(Qt::white);
        return img;
    }
    QImage img(path);
    img = img.scaled(width,height);
    return img;
}

bool isWhite(QColor color)
{
    if (color.lightness() > 150)
        return true;
    else
        return false;
}

void InsertImage(QImage& dest, QImage& img, int pos_w, int pos_h)
{
    for (int c_w = 0; c_w < img.width(); ++c_w)
    {
        for (int c_h = 0; c_h < img.height(); ++c_h)
        {
            QColor c_color = img.pixel(c_w, c_h);
            if (!isWhite(c_color))
            {
                if (pos_w+c_w < dest.width() && pos_w+c_w > 0 &&  pos_h+c_h < dest.height() && pos_h+c_h>0)
                    dest.setPixel(pos_w+c_w, pos_h+c_h, img.pixel(c_w, c_h));
            }
        }
    }
}
