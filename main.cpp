#include "Carre.h"
#include "Cercle.h"
#include "Rectangle.h"
#include "Triangle.h"

#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>

void afficherCaracteristiques(const FormeGeometrique& forme) {
    std::cout << "\n--- " << forme.getNom() << " ---\n";
    forme.dessiner();
    std::cout << "Aire      : " << forme.calculerAire() << '\n';
    std::cout << "Perimetre : " << forme.calculerPerimetre() << '\n';
}

int main() {
    std::cout << std::fixed << std::setprecision(2);

    try {
        // Les angles des formes inclinées sont exprimés en radians.
        constexpr double PI = 3.14159265358979323846;
        const double angle45 = PI / 4.0;

        std::vector<std::unique_ptr<FormeGeometrique>> formes;

        formes.push_back(std::make_unique<Cercle>(Point(0, 0), 3));
        formes.push_back(std::make_unique<Triangle>(
            Point(0, 0), Point(4, 0), Point(0, 3)));
        formes.push_back(std::make_unique<Rectangle>(
            Point(1, 1), 6, 3, angle45));
        formes.push_back(std::make_unique<Carre>(
            Point(-2, 0), 4, angle45));

        // Polymorphisme : le même appel fonctionne pour chaque forme.
        for (const auto& forme : formes) {
            afficherCaracteristiques(*forme);
        }

    } catch (const std::exception& erreur) {
        std::cerr << "Erreur : " << erreur.what() << '\n';
        return 1;
    }

    return 0;
}
