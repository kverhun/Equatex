#include "image_utils.h"

#include "src/lib/cimg/CImg.h"

#include <utility>
using namespace std;

pair<int, int> getImageSize(string fname)
{
    using namespace cimg_library;
    CImg<unsigned char> img(fname.c_str());
    try
    {
        pair<int,int> res =  make_pair(img.width(), img.height());
        return res;
    }
    catch(...)
    {
        return make_pair(-1,-1);
    }
}
