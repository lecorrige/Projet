#pragma once

#include <iostream>
#include <vector>
#include "Vecteur.h"

class Balle {
public:

    //constructeurs

    double masse_volumique();
    void Balle::ajoute_force(Vecteur const& df);

private:
    Vector pos;
    Vector vit;
    double rayon;
    double masse;
    Vector force;
};
