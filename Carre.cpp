#include "Carre.h"

#include <cmath>
#include <stdexcept>


std::vector<Point> Carre::construireSommets(
    const Point& origine, double cote, double angle) {

    if (cote <= 0.0) {
        throw std::invalid_argument("Le côté du carré doit être positif.");
    }

    const double dx = std::cos(angle);
    const double dy = std::sin(angle);
    const double px = -dy;
    const double py = dx;
    const double x = origine.getX();
    const double y = origine.getY();

    return {
        origine,
        Point(x + cote * dx, y + cote * dy),
        Point(x + cote * (dx + px), y + cote * (dy + py)),
        Point(x + cote * px, y + cote * py)
    };
}

Carre::Carre(const Point& origine, double cote, double angleRadians)
    : Polygone(construireSommets(origine, cote, angleRadians)),
      cote_(cote), angle_(angleRadians) {}

double Carre::getCote() const noexcept { return cote_; }
double Carre::getAngle() const noexcept { return angle_; }

std::string Carre::getNom() const { return "Carré"; }
