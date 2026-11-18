#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Polygone.h"

class Triangle : public Polygone {
public:
    Triangle(const Point& a, const Point& b, const Point& c);

    std::string getNom() const override;
};

#endif
