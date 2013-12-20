#ifndef IMAGE_UTILS_H
#define IMAGE_UTILS_H

#include <utility>
#include <string>
using std::string;
using std::pair;

/*
 *  returns image resolution
 *      <width,height>
 *
 *  returns <-1,-1> if error
 */
pair<int,int> getImageSize(string fname);

#endif // IMAGE_UTILS_H
