#ifndef DBQUERIES_H
#define DBQUERIES_H

#include <string>
using std::string;

const string querySelectStyles = "SELECT image_type_name FROM image_types;";

const string queryInsertImageRAW=\
        "INSERT INTO symbol_images"
        "(symbol_image_path, symbol_image_size, symbol_image_width, symbol_image_height, image_type_name, symbol_id)"
        "VALUES(?,?,?,?,?,?)";

#endif // DBQUERIES_H
