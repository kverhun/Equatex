#include "Symbol.h"

using namespace std;

#include <QString>


Symbol::Symbol(char ch)
{
    this->ch = tex_char(ch);
}

string Symbol::toXml()
{
    string xml;
    xml += "<symbol>\n";
        xml += "<char>\n";
            xml += "<id>";
            xml += char(this->ch.get_id());
            xml += "</id>\n";

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
