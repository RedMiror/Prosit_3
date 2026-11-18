#ifndef POINT_H
#define POINT_H

#include <iosfwd>

class Point {
private:
    double x_;
    double y_;

public:
    Point(double x = 0.0, double y = 0.0);

    double getX() const noexcept;
    double getY() const noexcept;

    double distanceVers(const Point& autre) const noexcept;
};

std::ostream& operator<<(std::ostream& os, const Point& point);

#endif
