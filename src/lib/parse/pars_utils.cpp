#include "parse_utils.h"

#include <string>
#include <vector>

using namespace std;

string get_arg(const string &str, size_t char_pos)
{

}

bool isCharacter(char c)
{
    if (c >= 'a' && c <= 'z')
        return true;
    if (c >= '0' && c <= '9')
        return true;
    if (c=='+' || c=='-' || c=='=')
        return true;
    if (c=='(' || c==')')
        return true;

    return false;
}

char_type get_type(char c)
{
    if (c == '\\')
        return char_type::cmd;
    if (c=='_')
        return char_type::bot_ind;
    if (c=='^')
        return char_type::top_ind;
    if (c==' ' || c=='\t' || c=='\n')
        return char_type::space;
    return char_type::plain_char;
}

vector<string> get_command_args(const string& str,  // input string
                                const string& cmd,  // command expr
                                int argc,           // args count
                                size_t start_pos       // start position
                                                    //  to find cmd
                                )
{
    vector<string> argv = vector<string>();

    size_t cmd_pos = str.find(cmd, start_pos);
    if (cmd_pos == string::npos)
    {
        e_cmdnotfound exc{start_pos};
        throw exc;
    }

    size_t cur_pos = cmd_pos + cmd.length();

    for (int i = 0; i < argc; ++i)
    {
        size_t open_pos = str.find('{', cur_pos);

        // checking for symbols between } and { or cmd and {
        for (size_t cp = cur_pos; cp < open_pos; ++cp)
            if (str[cp] != ' ' && str[cp != '\t' && str[cp] != '\n'])
            {
                e_invalidStatement exc{cp};
                throw exc;
            }

        //size_t close_pos = str.find('}', open_pos);
        size_t close_pos = open_pos+1;
        int lvl = 0;
        while(close_pos != str.length())
        {
            if (str[close_pos] == '{') ++lvl;
            if (str[close_pos] == '}')
                if (lvl == 0) break;
                else --lvl;
            ++close_pos;
        }
        if (str[close_pos] != '}')
            throw e_invalidStatement{close_pos};

        argv.push_back(string());
        for (size_t cp = open_pos + 1; cp < close_pos; ++cp)
            (*(argv.rbegin())).append(1, str[cp]);
        cur_pos = close_pos+1;
    }

    return argv;
}
