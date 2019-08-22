#include "Position.hpp"

Position::Position()
    : Position(0, 0)
{
}

Position::Position(const Position& p)
    : Position(p.x, p.y)
{
}

Position::Position(double x, double y)
{
    this->x = x;
    this->y = y;
}

Position& Position::operator=(const Position& other)
{
    this->x = other.x;
    this->y = other.y;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Position& p)
{
    out << "x: " << p.x << " " << "y: " << p.y;
    return out;
}