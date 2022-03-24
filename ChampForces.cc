#include <iostream>
#include <vector>
#include <cmath>
#include "Vecteur.h"
#include "balle.h"
#include "ChampForces.h"
#include "constantes.h"
#include <ostream>
using namespace std;

ChampForces ::ChampForces(Vecteur v)
: intensite(v)
{}

ostream& operator<<(ostream& sortie, ChampForces const& f) {
	sortie << f.get_intensite() << " # intensite" << endl;
	return sortie;
}

void ChampForces::agit_sur(Balle& balle){
	double k(balle.masse()-4*M_PI*rho_air*pow(balle.get_rayon(), 3)/3);
	Vecteur force(k*intensite);
	balle.ajoute_force(force);
}

	
