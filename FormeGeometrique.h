#ifndef FORME_GEOMETRIQUE_H
#define FORME_GEOMETRIQUE_H

#include <string>

class FormeGeometrique {
public:
    virtual ~FormeGeometrique() = default;

    virtual double calculerAire() const = 0;
    virtual double calculerPerimetre() const = 0;
    virtual std::string getNom() const = 0;
    virtual void dessiner() const = 0;
};

#endif
