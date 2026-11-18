#include "Point.h"

#include <cmath>
#include <ostream>

Point::Point(double x, double y) : x_(x), y_(y) {}

double Point::getX() const noexcept { return x_; }
double Point::getY() const noexcept { return y_; }

double Point::distanceVers(const Point& autre) const noexcept {
    return std::hypot(autre.x_ - x_, autre.y_ - y_);
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
    return os << '(' << point.getX() << ", " << point.getY() << ')';
}
