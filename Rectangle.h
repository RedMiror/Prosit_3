#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Polygone.h"

class Rectangle : public Polygone {
private:
    double longueur_;
    double largeur_;
    double angle_; // En radians.

    static std::vector<Point> construireSommets(
        const Point& origine, double longueur, double largeur, double angle);

public:
    // origine = premier sommet ; angle en radians.
    Rectangle(const Point& origine, double longueur, double largeur,
              double angleRadians = 0.0);

    double getLongueur() const noexcept;
    double getLargeur() const noexcept;
    double getAngle() const noexcept;

    std::string getNom() const override;
};

#endif
