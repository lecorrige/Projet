#include <iostream>
#include <vector>
#include <cmath>
#include <ostream>
#include "Vecteur.h"
#include "balle.h"
using namespace std;


Balle ::Balle(double r, double rho, 
              std::initializer_list<double> const& pos, 
              std::initializer_list<double> const& vit, 
              std::initializer_list<double> const& force) 
: rayon(r), masseVol(rho), pos(pos), vit(vit), force(force)
{}

double Balle::masse() const {
	const double k((M_PI*4)/3);
	return (masseVol*pow(rayon, 3)*k);
}

ostream& Balle::affiche(ostream& sortie) {
	ObjetMobile::affiche(sortie);
	sortie << get_pos() << " # position" << endl;
	sortie << get_vit() << " # vitesse" << endl;
	return sortie;
}
