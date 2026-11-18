#include "Triangle.h"

Triangle::Triangle(const Point& a, const Point& b, const Point& c)
    : Polygone({a, b, c}) {}

std::string Triangle::getNom() const { return "Triangle"; }
