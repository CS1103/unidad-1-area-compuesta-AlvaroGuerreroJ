#ifndef GUARD_POSITION_HPP
#define GUARD_POSITION_HPP

#include <ostream>

struct Position
{
public:
    double x;
    double y;

    Position();
    Position(double x, double y);
    Position(const Position& p);

    Position& operator=(const Position& other);

    friend std::ostream& operator<<(std::ostream& out, const Position& p);
};

#endif
