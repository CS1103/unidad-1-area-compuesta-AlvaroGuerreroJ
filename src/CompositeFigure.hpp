#ifndef GUARD_COMPOSITEFIGURE_HPP
#define GUARD_COMPOSITEFIGURE_HPP

#include <initializer_list>
#include <vector>
#include "Figure.hpp"

class CompositeFigure : public Figure
{
private:
    std::vector<Figure*> figs;

public:
    CompositeFigure(std::initializer_list<Figure*> il);

    Position calc_centroid() override;
    double calc_area() override;
    // std::string info_str() override;
};

#endif
