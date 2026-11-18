#ifndef CERCLE_H
#define CERCLE_H

#include "FormeGeometrique.h"
#include "Point.h"

class Cercle : public FormeGeometrique {
private:
    Point centre_;
    double rayon_;

public:
    Cercle(const Point& centre, double rayon);

    const Point& getCentre() const noexcept;
    double getRayon() const noexcept;

    double calculerAire() const override;
    double calculerPerimetre() const override;
    std::string getNom() const override;
    void dessiner() const override;
};

#endif
