#include "Symbol.h"

using namespace std;

#include <QString>

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


QImage Symbol::toImage(int width, int height, QString type)
{
    QImage symb_img = QImage(width, height, QImage::Format_RGB32);
    symb_img.fill(Qt::blue);
    return symb_img;
}


int Symbol::width_symbols()
{
    return 1 + max(this->bot_index.width_symbols()/2, this->top_index.width_symbols()/2);
}








