#ifndef CARRE_H
#define CARRE_H

#include "Polygone.h"

class Carre : public Polygone {
private:
    double cote_;
    double angle_; // En radians.

    static std::vector<Point> construireSommets(
        const Point& origine, double cote, double angle);

public:
    // origine = premier sommet ; angle en radians.
    Carre(const Point& origine, double cote, double angleRadians = 0.0);

    double getCote() const noexcept;
    double getAngle() const noexcept;

    std::string getNom() const override;
};

#endif
