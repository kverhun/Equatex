#include "Expression.h"
#include "Item.h"
#include "Symbol.h"
#include "Fraction.h"
#include "src/lib/parse/parse_utils.h"

#include <algorithm>
#include <string>
#include <list>

#include <QColor>
#include <QPainter>

using namespace std;

Expression::Expression()
{
    this->items = list<Item*>();
    this->valid = true;
}


size_t Expression::size() const
{
    return this->items.size();
}

bool Expression::isEmpty() const
{
    return this->items.empty();
}

bool Expression::isValid() const
{
    return this->valid;
}

Expression::Expression(string texexpr)
{
    size_t pos = 0;
    texexpr.erase(remove(texexpr.begin(), texexpr.end(), ' '), texexpr.end());
    this->valid = true;
    try
    {
        while (pos < texexpr.length())
        {
            char_type tp = get_type(texexpr[pos]);
            if (tp == char_type::plain_char)
            {
                string str;
                str.push_back(texexpr[pos]);
                items.push_back(new Symbol(str) );
                ++pos;
            }
            if (tp == char_type::cmd)
            {
                ++pos;
                string cmd = "";
                while (isCharacter( texexpr[pos]))
                {
                    cmd += texexpr[pos];
                    ++pos;
                }
                if (cmd == "frac")
                {
                    Fraction* frac = new Fraction();
                    vector<string> args = get_command_args(texexpr, "frac", 2, pos-4);
                    frac->set_top(Expression(args[0]));
                    frac->set_bot(Expression(args[1]));
                    items.push_back(frac);
                    pos += 2 + args[0].length() + 2 + args[1].length();
                }
                if (find(cmd_chars.begin(), cmd_chars.end(),cmd)!= cmd_chars.end())
                {
                    items.push_back(new Symbol(cmd));
                }
            }
            if (tp == char_type::bot_ind)
            {
                string bot_ind_str = *(get_command_args(texexpr,"_",1,pos).begin());
                Expression bot_ind_expr = Expression(bot_ind_str);
                if (this->isEmpty()) throw e_wrong_expr{pos};
                Symbol* cur_symbol = dynamic_cast<Symbol*>(*items.rbegin());
                if (cur_symbol == nullptr) throw e_wrong_expr{pos};
                cur_symbol->set_bot_index(bot_ind_expr);
                pos += bot_ind_str.length() + 3;
            }
            if (tp == char_type::top_ind)
            {
                string top_ind_str = *(get_command_args(texexpr,"^",1,pos).begin());
                Expression top_ind_expr = Expression(top_ind_str);
                if (this->isEmpty()) throw e_wrong_expr{pos};
                Symbol* cur_symbol = dynamic_cast<Symbol*>(*items.rbegin());
                if (cur_symbol == nullptr) throw e_wrong_expr{pos};
                cur_symbol->set_top_index(top_ind_expr);
                pos += top_ind_str.length() + 3;
            }
            if (tp == char_type::space)
                ++pos;
        }
    }
    catch(e_wrong_expr e)
    {
        this->valid = false;
        throw e;
    }
    catch(...)
    {
        this->valid = false;
        throw e_wrong_expr{string::npos};
    }
}



string Expression::toXml() const
{
    if (this->isValid())
    {
        string xml = "";
        xml += "<expression>\n";
        for (Item* it : items)
        {
            xml += it->toXml();
        }
        xml += "</expression>\n";
        return xml;
    }
    else
        return "<expression>\n invalid expr \n </expression>\n";
}

QImage Expression::toImage(int width, int height, QString type, QColor background) const
{
    QImage expr_img(width, height, QImage::Format_RGB32);
    list<QImage> item_imgs = list<QImage>();
    list<int> widths = list<int>();
    int sum_width = 0;
    expr_img.fill(background);
    for (Item* it : items)
    {
        int w = it->width_symbols();
        widths.push_back(w);
        sum_width += w;
    }
    for (int &i : widths)
    {
        i *= width;
        i /= sum_width;
    }

    auto it_w = widths.begin();
    for (Item* it : items)
    {
        item_imgs.push_back(it->toImage(*it_w, height,type));
        ++it_w;
    }

    QPoint pos = QPoint(0,0);
    QPainter painter(&expr_img);
    for (QImage img : item_imgs)
    {
        painter.drawImage(pos, img);
        pos += QPoint(img.width(),0);
    }
    return expr_img;
}

int Expression::width_symbols()
{
    int w = 0;
    for (Item* it : items)
        w += it->width_symbols();
    return w;
}
