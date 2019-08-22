#include "Figure.hpp"
#include "Position.hpp"

class Circle : public Figure
{
private:
    Position center;
    double radius;

public:
    Circle(Position center, double radius);
    Position calc_centroid() override;
    double calc_area() override;
};
