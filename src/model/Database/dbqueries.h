#ifndef DBQUERIES_H
#define DBQUERIES_H

#include <string>
using std::string;

const string querySelectStyles = "SELECT image_type_name FROM image_types;";

const string queryInsertImageRAW=\
        "INSERT INTO symbol_images"
        "(symbol_image_path, symbol_image_width, symbol_image_height, image_type_name, symbol_id)"
        "VALUES(?,?,?,?,?);";

const string querySymbolIdByCmdRAW=\
        "SELECT symbol_id FROM latex_symbols"
        "WHERE latex_symbol_cmd=?;";

const string querySelectSymbolCmds = "SELECT latex_symbol_cmd FROM latex_symbols;";

#endif // DBQUERIES_H
