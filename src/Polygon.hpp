#ifndef GUARD_POLYGON_HPP
#define GUARD_POLYGON_HPP

#include <cmath>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include "Figure.hpp"
#include "Position.hpp"

template<unsigned int n_sides>
class Polygon : public Figure
{
private:
    std::vector<Position> vertexes;

public:
    Polygon() = default;

    template<class T, class... T2>
    Polygon(T first, T2... rest)
        : Polygon(rest...)
    {
        this->vertexes.push_back(first);
    }

    Position calc_centroid() override
    {
        double x = 0;
        double y = 0;
        for (const Position& vertex : vertexes)
        {
            x += vertex.x;
            y += vertex.y;
        }
        return Position(x / n_sides, y / n_sides);
    }

    double calc_area() override
    {
        double p0 = 0;
        double p1 = 0;
        for (unsigned int i = 0; i < n_sides - 1; i++)
        {
            p0 += vertexes[i].x * vertexes[i + 1].y;
            p1 += vertexes[i].y * vertexes[i + 1].x;
        }
        p0 += vertexes.back().x * vertexes.front().y;
        p1 += vertexes.back().y * vertexes.front().x;
        return std::abs((p0 - p1) / 2);
    }

    std::string info_str() override
    {
        std::ostringstream os;

        os << Figure::info_str();

        os << "Vertexes:" << std::endl;
        for (const Position& v : this->vertexes)
        {
            os << v << " ";
        }
        os << std::endl;
        return os.str();
    }
};

#endif
