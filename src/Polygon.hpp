#ifndef GUARD_POLYGON_HPP
#define GUARD_POLYGON_HPP

#include <cmath>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include "Figure.hpp"
#include "Position.hpp"

class Polygon : public Figure
{
private:
    std::vector<Position> vertexes;

public:
    template<class ...T>
    Polygon(T ...points) : vertexes({points...})
    {
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
        return Position(x / this->vertexes.size(), y / this->vertexes.size());
    }

    double calc_area() override
    {
        double p0 = 0;
        double p1 = 0;
        for (unsigned int i = 0; i < this->vertexes.size() - 1; i++)
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
            os << v << "\t";
        }
        os << std::endl;
        return os.str();
    }
};

#endif
