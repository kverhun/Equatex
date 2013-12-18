#include "Expression.h"
#include "Item.h"
#include "Symbol.h"
#include "Fraction.h"
#include "src/lib/parse/parse_utils.h"

using namespace std;

Expression::Expression()
{
    this->items = list<Item*>();
}


size_t Expression::size()
{
    return this->items.size();
}

bool Expression::isEmpty()
{
    return this->items.empty();
}


Expression::Expression(string texexpr)
{
    size_t pos = 0;
    while (pos < texexpr.length())
    {
        char_type tp = get_type(texexpr[pos]);
        if (tp == char_type::plain_char)
        {
            items.push_back(new Symbol(texexpr[pos]));
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
                pos += 2 + args[0].length() + 2 + args[1].length()+1;
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
    }
}



string Expression::toXml()
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
