#include "Rectangle.h"

#include <cmath>
#include <stdexcept>

std::vector<Point> Rectangle::construireSommets(
    const Point& origine, double longueur, double largeur, double angle) {

    if (longueur <= 0.0 || largeur <= 0.0) {
        throw std::invalid_argument("La longueur et la largeur doivent être positives.");
    }

    const double dx = std::cos(angle);
    const double dy = std::sin(angle);
    // Vecteur perpendiculaire au côté de longueur.
    const double px = -dy;
    const double py = dx;

    const double x = origine.getX();
    const double y = origine.getY();

    return {
        origine,
        Point(x + longueur * dx, y + longueur * dy),
        Point(x + longueur * dx + largeur * px,
              y + longueur * dy + largeur * py),
        Point(x + largeur * px, y + largeur * py)
    };
}

Rectangle::Rectangle(const Point& origine, double longueur, double largeur,
                     double angleRadians)
    : Polygone(construireSommets(origine, longueur, largeur, angleRadians)),
      longueur_(longueur), largeur_(largeur), angle_(angleRadians) {}

double Rectangle::getLongueur() const noexcept { return longueur_; }
double Rectangle::getLargeur() const noexcept { return largeur_; }
double Rectangle::getAngle() const noexcept { return angle_; }

std::string Rectangle::getNom() const { return "Rectangle"; }
