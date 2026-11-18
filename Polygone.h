#ifndef POLYGONE_H
#define POLYGONE_H

#include "FormeGeometrique.h"
#include "Point.h"

#include <vector>

class Polygone : public FormeGeometrique {
protected:
    std::vector<Point> sommets_;

    explicit Polygone(std::vector<Point> sommets);
    void definirSommets(std::vector<Point> sommets);

public:
    const std::vector<Point>& getSommets() const noexcept;

    double calculerAire() const override;
    double calculerPerimetre() const override;

    // Le dessin dépendra de la bibliothèque graphique choisie (Qt, SFML...).
    // Cette méthode fournit ici une représentation textuelle pour les tests.
    void dessiner() const override;
};

#endif
