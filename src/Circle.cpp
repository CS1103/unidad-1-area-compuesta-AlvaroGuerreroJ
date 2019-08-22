#include "Circle.hpp"

Circle::Circle(Position center, double radius)
    : center(center), radius(radius)
{
}

Position Circle::calc_centroid()
{
    return this->center;
}

double Circle::calc_area()
{
    return this->radius * this->radius * PI;
}
