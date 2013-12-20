#ifndef PARSE_UTILS_H
#define PARSE_UTILS_H

#include <string>
using std::string;
#include <vector>
using std::vector;

string get_arg(const string& str, size_t char_pos);

enum char_type
{
    plain_char,
    cmd,
    top_ind,
    bot_ind,
    arg_open,
    arg_close,
    space
};

bool isCharacter(char c);

char_type get_type(char c);


/*
 *  Returns arguments for tex command
 *
 *  Throws: e_invalidStatement with position in input string
 *          e_cmdnotfound
 */
vector<string> get_command_args(const string& str,  // input string
                                const string& cmd,  // command expr
                                int argc,           // args count
                                size_t start_pos       // start position
                                                    //  to find cmd
                                );
/*
 * structs for exceptions
 *
 */
struct e_cmdnotfound
{
    size_t pos;
};

struct e_invalidStatement
{
    size_t pos;
};

#endif // PARSE_UTILS_H
