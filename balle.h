#pragma once

#include <iostream>
#include <vector>
#include <ostream>
#include "Vecteur.h"

class Balle {
public:
    Balle (double r=0.0, double rho=0.0, 
           std::initializer_list<double> const& pos={0, 0, 0}, 
           std::initializer_list<double> const& vit={0, 0, 0}, 
           std::initializer_list<double> const& force={0, 0, 0});
    //constructeurs à voir plus tard en fonction de leur initialisation...
   // pareil pour copie et destructeur
    double masse() const;
    void ajoute_force(Vecteur const& df) {force+=df;};
    double get_rayon() const {return rayon;}     // accesseurs
    double get_masseVol() const {return masseVol;}
    Vecteur get_pos() const {return pos;}
    Vecteur get_vit() const {return vit;}
    Vecteur get_force() const {return force;}
private:
    Vecteur pos;
    Vecteur vit;
    double rayon;
    double masseVol;
    Vecteur force;
};

std::ostream& operator<<(std::ostream& sortie, Balle const& b);

