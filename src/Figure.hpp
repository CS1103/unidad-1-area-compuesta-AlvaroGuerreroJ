#ifndef GUARD_FIGURE_HPP
#define GUARD_FIGURE_HPP

#include <iostream>
#include <sstream>
#include <string>
#include "Position.hpp"

extern const double PI;

class Figure
{
public:
    virtual Position calc_centroid() = 0;
    virtual double calc_area() = 0;

    virtual std::string info_str();
};

#endif
