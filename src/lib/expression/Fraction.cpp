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

