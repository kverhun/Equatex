#include "Fraction.h"

using namespace std;

Fraction::Fraction()
{

}

Fraction::Fraction(Expression _top, Expression _bot)
{
    this->bot = _bot;
    this->top = _top;
}

void Fraction::set_bot(Expression expr)
{
    this->bot = expr;
}

void Fraction::set_top(Expression expr)
{
    this->top = expr;
}

string Fraction::toXml()
{
    string xml = "<fraction>\n";
        xml += "<top>\n";
            xml += this->top.toXml();
            xml += "\n";
        xml += "</top>\n";

        xml += "<bottom>\n";
            xml += this->bot.toXml();
            xml += "\n";
        xml += "</bottom>\n";
    xml += "</fraction>\n";
    return xml;
}

QImage Fraction::toImage(int width, int height, QString type)
{
    QImage frac_img = QImage(width, height, QImage::Format_RGB32);

    frac_img.fill(Qt::black);

    return frac_img;
}

int Fraction::width_symbols()
{
    int w_top = top.width_symbols();
    int w_bot = bot.width_symbols();
    return w_top > w_bot ? w_top : w_bot;
}
