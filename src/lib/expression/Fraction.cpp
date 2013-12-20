#include "Fraction.h"
#include <QColor>

#include "src/lib/image/qt_image_utils.h"
#include "Symbol.h"
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

QImage Fraction::toImage(int width, int height, QString type, QColor background, QColor font,  bool useFont)
{
    QImage frac_img = QImage(width, height, QImage::Format_RGB32);
    frac_img.fill(background);

    int top_h = height/2;
    int bot_h = height/2;

    int mx = max(top.width_symbols(), bot.width_symbols());

    int top_w = width*top.width_symbols()/mx;
    int bot_w = width*bot.width_symbols()/mx;

    int top_pos_w = (width - top_w)/2;
    int bot_pos_w = (width - bot_w)/2;

    int top_pos_h = 0;
    int bot_pos_h = height/2;

    QImage top_img = top.toImage(top_w, top_h,type, background, font, useFont);
    QImage bot_img = bot.toImage(bot_w, bot_h, type, background, font, useFont);

    InsertImage(frac_img, top_img, top_pos_w, top_pos_h);
    InsertImage(frac_img, bot_img, bot_pos_w, bot_pos_h);

    Symbol line = Symbol("-");
    QImage line_img = line.toImage(100,100, type, background, font, useFont);
    line_img = line_img.scaled(max(top_w, bot_w),height/15);
    InsertImage(frac_img, line_img, 0, height/2-height/15,font,useFont,min_brigth);

    return frac_img;
}

int Fraction::width_symbols()
{
    int w_top = top.width_symbols();
    int w_bot = bot.width_symbols();
    return w_top > w_bot ? w_top : w_bot;
}
