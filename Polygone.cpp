#include "Polygone.h"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <utility>

namespace {
constexpr double EPSILON = 1e-10;

void verifierSommets(const std::vector<Point>& sommets) {
    if (sommets.size() < 3) {
        throw std::invalid_argument("Un polygone doit avoir au moins 3 sommets.");
    }
}
}

Polygone::Polygone(std::vector<Point> sommets) {
    definirSommets(std::move(sommets));
}

void Polygone::definirSommets(std::vector<Point> sommets) {
    verifierSommets(sommets);
    sommets_ = std::move(sommets);

    if (calculerAire() < EPSILON) {
        throw std::invalid_argument("Les sommets doivent former un polygone d'aire non nulle.");
    }
}

const std::vector<Point>& Polygone::getSommets() const noexcept {
    return sommets_;
}

double Polygone::calculerAire() const {
    // Formule du lacet (Shoelace). Le dernier sommet est relié au premier.
    double somme = 0.0;
    const std::size_t n = sommets_.size();

    for (std::size_t i = 0; i < n; ++i) {
        const Point& courant = sommets_[i];
        const Point& suivant = sommets_[(i + 1) % n];
        somme += courant.getX() * suivant.getY()
               - suivant.getX() * courant.getY();
    }

    return std::abs(somme) / 2.0;
}

double Polygone::calculerPerimetre() const {
    double somme = 0.0;
    const std::size_t n = sommets_.size();

    for (std::size_t i = 0; i < n; ++i) {
        somme += sommets_[i].distanceVers(sommets_[(i + 1) % n]);
    }

    return somme;
}

void Polygone::dessiner() const {
    std::cout << getNom() << " - sommets : ";
    for (const Point& point : sommets_) {
        std::cout << point << ' ';
    }
    std::cout << '\n';
}
