#ifndef SYMBOL_H
#define SYMBOL_H

#include "Item.h"
#include "Expression.h"
#include <vector>
using std::vector;
#include <string>
using std::string;

extern vector<string> cmd_chars;

class tex_char
{
public:
    tex_char() {char_id = 0;}
    tex_char(char ch) {char_id = ch;}
    int get_id() {return char_id;}
private:
    int char_id;
};

class Symbol : public Item
{
public:
    Symbol(char ch);
    Symbol(tex_char ch, Expression top_ind, Expression bot_ind);
    Symbol(char ch, Expression top_ind, Expression bot_ind);
    Symbol(string cmd);
    Symbol(string cmd, Expression top_ind, Expression bot_ind);
    string get_cmd() {return this->cmd;}
    void set_top_index(Expression expr);
    void set_bot_index(Expression expr);
    string toXml();
    tex_char get_char();
private:
    tex_char ch;
    string cmd;
    Expression top_index;
    Expression bot_index;
};


#endif // SYMBOL_H
