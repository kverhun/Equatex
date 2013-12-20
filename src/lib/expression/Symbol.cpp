#include "Symbol.h"

using namespace std;

#include <QString>
#include "src/lib/image/qt_image_utils.h"

vector<string> cmd_chars{"partial", "varepsilon"};

Symbol::Symbol(char ch)
{
    this->ch = tex_char(ch);
}

Symbol::Symbol(string cmd, Expression top_ind, Expression bot_ind)
{
    this->cmd = cmd;
    this->set_bot_index(bot_ind);
    this->set_top_index(top_ind);
}

Symbol::Symbol(string cmd)
{
    this->cmd = cmd;
}

string Symbol::toXml()
{
    string xml;
    xml += "<symbol>\n";
        xml += "<char>\n";
            xml += "<cmd>";
            xml += this->get_cmd();
            xml += "</cmd>\n";

            if ( ! this->top_index.isEmpty())
            {
                xml += "<top_ind>\n";
                    xml += this->top_index.toXml();
                xml += "</top_ind>\n";
            }

            if (! this ->bot_index.isEmpty())
            {
                xml += "<bot_ind>\n";
                    xml += this->bot_index.toXml();
                xml += "</bot_ind>\n";
            }

        xml += "</char>\n";
    xml += "</symbol>\n";
    return xml;
}

void Symbol::set_bot_index(Expression expr)
{
    this->bot_index = expr;
}

void Symbol::set_top_index(Expression expr)
{
    this->top_index = expr;
}

tex_char Symbol::get_char()
{
    return this->ch;
}


QImage Symbol::toImage(int width, int height, QString type, QColor background)
{
    QImage full_img = QImage(width, height, QImage::Format_RGB32);
    full_img.fill(background);

    double symb_part = (double)1/this->width_symbols();

    int symb_w = width * symb_part;
    int symb_h = height;
    symb_w = symb_h = min(symb_w, symb_h);

    int top_h = ind_coef*symb_h;
    int bot_h = ind_coef*symb_h;

    int top_w;
    int bot_w;

    int mx = max(top_index.width_symbols(),bot_index.width_symbols());

    top_w = (width - symb_w)*this->top_index.width_symbols()/(mx?mx:1);
    bot_w = (width - symb_w)*this->bot_index.width_symbols()/(mx?mx:1);


    QImage symb_img = get_image(QString::fromStdString(this->cmd), symb_w, symb_h, type);

    QImage top_img = this->top_index.toImage(top_w, top_h, type, background);
    QImage bot_img = this->bot_index.toImage(bot_w, bot_h, type, background);

    int symb_pos_h = (height-symb_h)/2;
    int symb_pos_w = 0;

    int top_pos_h = symb_pos_h - top_h + symb_h/4;
    int top_pos_w = symb_pos_w+symb_w - symb_w/4;

    int bot_pos_h = symb_pos_h + symb_h - symb_h/4;
    int bot_pos_w = symb_pos_w+symb_w - symb_w/4;

    InsertImage(full_img, symb_img, symb_pos_w, symb_pos_h);
    InsertImage(full_img, top_img, top_pos_w, top_pos_h);
    InsertImage(full_img, bot_img, bot_pos_w, bot_pos_h);

    return full_img;
}


int Symbol::width_symbols()
{
    return 1 + max((this->bot_index.width_symbols()+1)/2, (this->top_index.width_symbols()+1)/2);
}








