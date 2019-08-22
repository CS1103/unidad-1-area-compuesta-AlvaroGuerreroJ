#include <iostream>
#include <sstream>
#include <string>
#include "Figure.hpp"

using std::endl;
using std::string;
using std::ostringstream;

const double PI = 3.141592653;

string Figure::info_str()
{
    ostringstream os;
    os << "Area: " << this->calc_area() << endl;
    Position c = this->calc_centroid();
    os << "Centroid:\tx=" << c.x << "\ty=" << c.y << endl;
    return os.str();
}
