#include "Cercle.h"

#include <cmath>
#include <iostream>
#include <stdexcept>

namespace {
constexpr double PI = 3.14;
}

Cercle::Cercle(const Point& centre, double rayon)
    : centre_(centre), rayon_(rayon) {
    if (rayon <= 0.0) {
        throw std::invalid_argument("Le rayon doit être strictement positif.");
    }
}

const Point& Cercle::getCentre() const noexcept { return centre_; }
double Cercle::getRayon() const noexcept { return rayon_; }

double Cercle::calculerAire() const {
    return PI * rayon_ * rayon_;
}

double Cercle::calculerPerimetre() const {
    return 2.0 * PI * rayon_;
}

std::string Cercle::getNom() const { return "Cercle"; }

void Cercle::dessiner() const {
    std::cout << "Cercle de centre " << centre_
              << " et de rayon " << rayon_ << '\n';
}
