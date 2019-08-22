#include <iostream>
#include "Circle.hpp"
#include "CompositeFigure.hpp"
#include "Figure.hpp"
#include "Polygon.hpp"
#include "Position.hpp"

using std::cout;
using std::endl;

int main()
{
    Circle circle(Position(15, 5.75), 3);
    cout << "Circle: " << endl;
    cout << circle.info_str();
    cout << endl;

    // The arguments to the polygons must be given in clockwise or
    // counter-clockwise order.
    Polygon triangle(Position(0, 0), Position(1, 0), Position(0, 1));
    cout << "Triangle: " << endl;
    cout << triangle.info_str();
    cout << endl;

    Polygon square(Position(0, 0), Position(1, 0), Position(1, 2), Position(0, 1));
    cout << "Square: " << endl;
    cout << square.info_str();
    cout << endl;

    Polygon pentagon(Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2), Position(0, 1));
    cout << "Pentagon: " << endl;
    cout << pentagon.info_str();
    cout << endl;

    CompositeFigure comp{new Circle(Position(0, 0), 10), new Polygon(Position(10, 0), Position(10, 10), Position(0, 10))};
    cout << "Composition: " << endl;
    cout << comp.info_str();
    cout << endl;
}
