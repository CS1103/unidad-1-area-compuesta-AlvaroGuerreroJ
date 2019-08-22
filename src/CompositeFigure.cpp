#include <algorithm>
#include <initializer_list>
#include <iterator>
#include <numeric>
#include "CompositeFigure.hpp"
#include "Figure.hpp"
#include "Position.hpp"

using std::accumulate;
using std::back_inserter;
using std::copy;
using std::initializer_list;

CompositeFigure::CompositeFigure(initializer_list<Figure*> il)
{
    copy(il.begin(), il.end(), back_inserter(this->figs));
}

Position CompositeFigure::calc_centroid()
{
    double sum_area = 0;
    double sum_x = 0;
    double sum_y = 0;

    for (Figure* figp : this->figs)
    {
        Position fcent = figp->calc_centroid();
        double farea = figp->calc_area();
        sum_x += fcent.x * farea;
        sum_y += fcent.y * farea;
        sum_area += farea;
    }

    return Position(sum_x / sum_area, sum_y / sum_area);
}

double CompositeFigure::calc_area()
{
    return accumulate(figs.cbegin(), figs.cend(), 0.0,
                      [](double d, Figure* f)->double{ return d + f->calc_area(); });
}
